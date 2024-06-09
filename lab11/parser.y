%{
#include <stdio.h>
#include "lexer.h"
%}

%define parse.error verbose
%define api.pure
%locations
%lex-param {yyscan_t scanner}  /* параметр для yylex() */
/* параметры для yyparse() */
%parse-param {yyscan_t scanner}
%parse-param {long env[26]}
%parse-param {int tab}
%parse-param {bool need_tab}

%union {
    char* integer;
    char* char_literal;
    char* string_const;
    char* varname;
    char* comment;
}

%left EQUAL EQUAL_EQUAL NOT_EQUAL LESS GREATER LESS_EQUAL GREATER_EQUAL
%left PLUS MINUS MUL REM_OF_DIV EXC_OR OR AND DIV
%right POW NOT UMINUS   /* 18 */

%token INT CHAR BOOL VOID KW_TRUE KW_FALSE KW_NULL KW_IF KW_ELSE KW_RETURN KW_LOOP KW_WHILE KW_THEN
%token SEMICOLON DOT LEFT_ARROW LEFT_PAREN RIGHT_PAREN LEFT_PAREN2 RIGHT_PAREN2 LEFT_PAREN3 RIGHT_PAREN3 COMMA TILD ASSIGN /* 23 */

%token <integer> INTEGER
%token <char_literal> CHAR_LITERAL
%token <string_const> STRING_CONST
%token <varname> VARNAME
%token <comment> COMMENT

%{
int yylex(YYSTYPE *yylval_param, YYLTYPE *yylloc_param, yyscan_t scanner);
void yyerror(YYLTYPE *loc, yyscan_t scanner, long env[26], int tab, bool need_tab, const char *message);
%}

%{

void print_tabs(int tab_col) {
    for(int i = 0; i < tab_col; i++) {
        printf("    ");
    }
}

%}

%%
Program:
        FuncDecl
        | Program FuncDecl
        ;
FuncDecl:
        FullTypeOrVoid Ident LEFT_ARROW Parameters EQUAL Operators DOT
        | FullTypeOrVoid Ident EQUAL Operators DOT
        ;
FullTypeOrVoid:
        FullType
        | VOID {printf("void");}
        ;
Parameters:
        Parameter
        | Parameters COMMA Parameter
        ;
Parameter:
        FullType Ident
        ;
Operators:
        Operator
        | Operators SEMICOLON Operator
        ;
Operator:
        DeclOperator
        | AssignOperator
        | FuncCallOperator
        | ChooseOperator
        | PredLoopOperator
        | PostLoopOperator
        | ForLoopOperator
        | EndFuncOperator
        ;
DeclOperator:
        FullType Decls
        ;
Decls:
        Decl
        | Decls COMMA Decl
        ;
Decl:
        Ident
        | Ident ASSIGN  ArithmExpression
        ;
AssignOperator:
       DataExpression ASSIGN  Expression
       ;
ChooseOperator:
        Expression KW_THEN Operators KW_ELSE Operators DOT
        | Expression KW_THEN Operators DOT
        ;
FuncCallOperator:
        Ident LEFT_ARROW ArithmExpressions
        ;
EndFuncOperator:
        KW_RETURN Expression
        | KW_RETURN {printf("return");}
        ;
PredLoopOperator:
        Expression KW_LOOP Operators DOT {printf(".");}
        ;
PostLoopOperator:
        KW_LOOP Operators KW_WHILE Expression DOT {printf(".");}
        ;
ForLoopOperator:
        Expression TILD Expression KW_LOOP Ident Operators DOT {printf(".");}
        ;

Expression:
        AndExpression
        | AndExpression OrOp AndExpression
        ;
OrOp:
        OR { printf("|"); }
        | EXC_OR { printf("@"); }
        ;
MulOp:
        MUL { printf("*"); }
        | DIV { printf("/"); }
        | REM_OF_DIV { printf("%%"); }
        ;
AddOp:
        PLUS { printf("+"); }
        | MINUS { printf("-"); }
        ;
CmpOp:
        EQUAL_EQUAL {printf("==");}
        | NOT_EQUAL {printf("!=");}
        | LESS {printf("<");}
        | GREATER {printf(">");}
        | LESS_EQUAL {printf("<=");}
        | GREATER_EQUAL {printf(">=");}
        ;
AndExpression:
        CmpExpression
        | CmpExpression AND CmpExpression
        ;
CmpExpression:
        FuncCallExpression
        | FuncCallExpression CmpOp FuncCallExpression
        ;
FuncCallExpression:
        ArithmExpression
        | Ident LEFT_ARROW ArithmExpressions
        ;
ArithmExpressions:
        ArithmExpression
        | ArithmExpressions COMMA ArithmExpression
        ;
ArithmExpression:
        Term
        | ArithmExpression AddOp Term
        ;
Term:
        Factor
        | Term MulOp Factor
        ;
Factor:
        Power
        | Power POW Factor
        ;
Power:
        DataExpression
        | NOT Power
        | MINUS Power %prec UMINUS
        | FullType BaseExpression
        ;
DataExpression:
        BaseExpression
        | DataExpression BaseExpression
        ;
BaseExpression:
        Ident
        | KW_TRUE {printf("true");}
        | KW_FALSE {printf("false");}
        | KW_NULL {printf("null");}
        | CHAR_LITERAL {printf("%s", $CHAR_LITERAL);}
        | INTEGER {printf("%s", $INTEGER);}
        | LEFT_PAREN Expression RIGHT_PAREN {printf(")");}
        | STRING_CONST {printf("%s", $STRING_CONST);}
        ;
FullType:
        Type LEFT_PAREN2 RIGHT_PAREN2 {printf("[]");}
        | Type LEFT_PAREN2 RIGHT_PAREN2 LEFT_PAREN2 RIGHT_PAREN2 {printf("[][]");}
        | Type
        ;
Type:
        INT {printf("int");}
        | CHAR {printf("char");}
        | BOOL {printf("bool");}
        ;
Ident:
        LEFT_PAREN3 VARNAME RIGHT_PAREN3 {printf("{%s}", $VARNAME);}
        ;
%%

int main(int argc, char *argv[]) {
    FILE *input = 0;
    long env[26] = { 0 };
    int tab = 0;
    bool need_tab = false;
    yyscan_t scanner;
    struct Extra extra;

    if (argc > 1) {
        printf("Read file %s\n", argv[1]);
        input = fopen(argv[1], "r");
    } else {
        printf("No file in command line, use stdin\n");
        input = stdin;
    }

    init_scanner(input, &scanner, &extra);
    yyparse(scanner, env, tab, need_tab);
    destroy_scanner(scanner);

    if (input != stdin) {
        fclose(input);
    }

    return 0;
}