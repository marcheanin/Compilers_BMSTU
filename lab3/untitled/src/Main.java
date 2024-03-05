import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

    static class Position {
        private int line, pos;

        Position(int line,int pos) {
            this.line = line;
            this.pos = pos;
        }

        void next_line() {
            this.line += 1;
            this.pos = 1;
        }

        void next_pos(int pos) {
            this.pos += pos;
        }

        public String toString() {
            return "(" + this.line + "," + this.pos + ")";
        }
    }

    private static ArrayList<String> text_match(String line, Position pos) {
        String ident = "\\p{L}+|\\(\\d+\\)";
        String num_literal = "[1-9][0-9]*|0";
        String operations = "\\(\\)|:=|:";
        String full_pattern = "(^" + ident + ")|(^" + num_literal + ")|(^" + operations + ")";

        Pattern p = Pattern.compile(full_pattern);
        Matcher m;

        ArrayList<String> tokens = new ArrayList<>();

        while(!line.isEmpty()) {
            m = p.matcher(line);
            if (m.find()) {
                if (m.group(1) != null) {
                    String item = m.group(1);
                    tokens.add("IDENT: " + pos + ": " + item);
                    pos.next_pos(item.length());
                    line = line.substring(line.indexOf(item) + item.length());
                }
                else if (m.group(2) != null) {
                    String item = m.group(2);
                    tokens.add("NUM_LITERAL: " + pos + ": " + item);
                    pos.next_pos(item.length());
                    line = line.substring(line.indexOf(item) + item.length());
                }
                else if (m.group(3) != null){
                    String item = m.group(3);
                    tokens.add("OPERATION: " + pos + ": " + item);
                    pos.next_pos(item.length());
                    line = line.substring(line.indexOf(item) + item.length());
                }
            }
            else {
                if (Character.isWhitespace(line.charAt(0))) {
                    while (Character.isWhitespace(line.charAt(0))) {
                        line = line.substring(1);
                        pos.next_pos(1);
                    }
                }
                else{
                    tokens.add("error : " + pos.toString());
                    while (!m.find() && !line.isEmpty()) {
                        line = line.substring(1);
                        pos.next_pos(1);
                        m = p.matcher(line);
                    }
                }
            }
        }

        return tokens;
    }

    public static void main(String[] args) {
        Position pos = new Position(1, 1);
        List<String> lines;
        ArrayList<String> tokens;

        try {
            lines = Files.readAllLines(Paths.get("src/input.txt"), StandardCharsets.UTF_8);
            for (String line : lines) {
                tokens = text_match(line, pos);
                for (String token : tokens) {
                    System.out.println(token);
                }
                pos.next_line();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }

}
}