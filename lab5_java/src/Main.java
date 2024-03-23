import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Main {

    static Integer[][] table = {
            /*      Wh,Di, |, +, g, s, e, t,Lt,X */
            /*0*/  { 1, 7, 9, 8, 3, 5, 2, 2, 2,15}, // Start
            /*1*/  { 1,-1,-1,-1,-1,-1,-1,-1,-1,15}, // Whitespace
            /*2*/  {-1, 2,-1,-1, 2, 2, 2, 2, 2,15}, // Ident_1
            /*3*/  {-1, 2,-1,-1, 2, 2, 4, 2, 2,15}, // Ident_2
            /*4*/  {-1, 2,-1,-1, 2, 2, 2, 6, 2,15}, // Ident_3
            /*5*/  {-1, 2,-1,-1, 2, 2, 4, 2, 2,15}, // Ident_4
            /*6*/  {-1, 2,-1,-1, 2, 2, 2, 2, 2,15}, // Keyword
            /*7*/  {-1, 7,-1,-1,-1,-1,-1,-1,-1,15}, // Num_Liter
            /*8*/  {-1,-1,-1,-1,-1,-1,-1,-1,-1,15}, // Operation
            /*9*/  {-1,-1, 8,10,-1,-1,-1,-1,-1,15}, // Operation Or Comment
            /*10*/ {10,10,11,13,10,10,10,10,10,10}, // Comment
            /*11*/ {10,10,10,12,10,10,10,10,10,10}, // ErrorComment
            /*12*/ {-1,-1,-1,-1,-1,-1,-1,-1,-1,15}, // Error
            /*13*/ {10,10,14,13,10,10,10,10,10,10}, // RightComment
            /*14*/ {-1,-1,-1,-1,-1,-1,-1,-1,-1,15}, // Commentary
            /*15*/ {-1,-1,-1,-1,-1,-1,-1,-1,-1,15}, // Unknown
    };

    static Integer[][] table1 = {
            /*     Wh,Di,Lt, +, -, n, e, q, :,Any, EndLine */
            /*0*/  {1, 6, 4, 7, 8, 2, 3, 4,10,12, 1}, // Start
            /*1*/  {1,-1,-1,-1,-1,-1,-1,-1,-1,12, 1}, // WhiteSpace
            /*2*/  {-1, 4,4,-1,-1, 4, 3, 4,-1,12, -1}, // Ident1
            /*3*/  {-1, 4,4,-1,-1, 4, 4, 5,-1,12, -1}, // Ident2
            /*4*/  {-1, 4,4,-1,-1, 4, 4, 4,-1,12, -1}, // Ident
            /*5*/  {-1, 4,4,-1,-1, 4, 4, 4,-1,12, -1}, // Keyword
            /*6*/  {-1,6,-1,-1,-1,-1,-1,-1,-1,12, -1}, // NumLiter
            /*7*/  {-1,-1,-1,-1,9,-1,-1,-1,-1,12, -1}, // PreOp_1
            /*8*/  {-1,-1,-1,9,-1,-1,-1,-1,-1,12, -1}, // PreOp_2
            /*9*/  {-1,-1,-1,-1,-1,-1,-1,-1,-1,12,-1}, // Op
            /*10*/ {10,10,10,10,10,10,10,10,11,10, 12}, // Str_Start
            /*11*/ {-1,-1,-1,-1,-1,-1,-1,-1,10,12,-1}, // String_Literal
            /*12*/ {-1,-1,-1,-1,-1,-1,-1,-1,-1,12, -1}, // Error
    };

    static int numberColumn(Position ch){
        if (ch.isEOF())
            return -1;
        else if (ch.isNewLine()) {
            return 10;
        }
        else if (ch.isWhitespace()) {
            return 0;
        }
        else if (Character.isDigit(ch.getCode())) {
            return 1;
        }
        else if (ch.getCode() == '+') {
            return 3;
        }
        else if (ch.getCode() == '-') {
            return 4;
        }
        else if (ch.getCode() == 'n') {
            return 5;
        }
        else if (ch.getCode() == 'e') {
            return 6;
        }
        else if (ch.getCode() == 'q') {
            return 7;
        }
        else if (ch.getCode() == ':') {
            return 8;
        }
        else if (Character.isLetter(ch.getCode())) {
            return 2;
        }
        else {
            return 9;
        }
    }

    static final ArrayList<DomainTag> final_state = new ArrayList<>() {{
        add(DomainTag.WHITESPACE);
        add(DomainTag.IDENT_1);
        add(DomainTag.IDENT_2);
        add(DomainTag.IDENT);
        add(DomainTag.KEYWORD);
        add(DomainTag.NUM_LITER);
        add(DomainTag.OP);
        add(DomainTag.STR_LITERAL);
        add(DomainTag.ERROR);
    }};


    public static void main(String[] args) throws IOException {

        String text_program = new String(Files.readAllBytes(Path.of("text.txt")));

        Position cur = new Position(text_program);

        ArrayList<Token> tokens = new ArrayList<>();
        ArrayList<ErrorMessage> errorMessages = new ArrayList<>();

        Position start,end;
        int state,prev_state;

        System.out.println("TOKENS:");
        while(!cur.isEOF()){
            while (cur.isWhitespace())
                cur = cur.next();
            state = 0;
            prev_state = 0;
            start = new Position(cur);
            while (state != -1) {
                int symbols = numberColumn(cur);
                prev_state=state;
                state = (symbols == -1) ? -1: table1[state][symbols]; // переходим в следующее состояние
                if(state!=-1){
                    cur = cur.next();  // пока не пришли в запрещающее состояние, идём дальше
                }
            }
            if (prev_state!=1 && prev_state!=0 && prev_state!= 15){
                end = new Position(cur);
                if (prev_state==12)
                    errorMessages.add(new ErrorMessage(true,"error: \":\" expected at the end of previous line",cur));
                else if (!final_state.contains(DomainTag.values()[prev_state]) && DomainTag.values()[prev_state] == DomainTag.STR_START)
                    errorMessages.add(new ErrorMessage(true,"error: expected \":\" at the end of string literal",cur));
                else if (!final_state.contains(DomainTag.values()[prev_state]))
                    errorMessages.add(new ErrorMessage(true,"error: unknown token \"" + text_program.substring(start.getIndex(),end.getIndex()) + "\"",cur));
                else
                    tokens.add(new Token(DomainTag.values()[prev_state],text_program.substring(start.getIndex(),end.getIndex()),start,end));
            }
            else {
                while (!cur.isEOF() && numberColumn(cur) == -1) {
                    cur = cur.next();
                }
                end=new Position(cur);
                errorMessages.add(new ErrorMessage(true,"error: unknown token \"" + text_program.substring(start.getIndex(),end.getIndex()) + "\"",cur));
            }
        }

        for(Token token: tokens)
            System.out.println(token);

        if (!errorMessages.isEmpty()) {
            System.out.println("Errors:");
            for(ErrorMessage mes: errorMessages)
                System.out.println(mes.toString());
        }
    }
}