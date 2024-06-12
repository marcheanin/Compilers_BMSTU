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
void yyerror(YYLTYPE *loc, yyscan_t scanner, int tab, bool need_tab, const char *message);
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
        FullTypeOrVoid Ident LEFT_ARROW {printf(" <- ");} Parameters {printf("\n"); tab++; print_tabs(tab);} EQUAL {printf("= ");} Operators DOT  {printf(".");}
        | FullTypeOrVoid Ident EQUAL {printf("= "); need_tab = false; } Operators DOT {printf("."); tab = 0; need_tab = true;}
        ;
CommentCheck:
        | COMMENT {printf("%s\n", $COMMENT); if (need_tab) { print_tabs(tab);} } CommentCheck
        ;
FullTypeOrVoid:
        FullType
        | VOID {printf("void ");}
        ;
Parameters:
        Parameter
        | Parameters COMMA {printf(", ");} Parameter
        ;
Parameter:
        FullType Ident
        ;
Operators:
        { if (need_tab) {print_tabs(tab);} need_tab = true;} Operator CommentCheck
        | Operators SEMICOLON  {printf(";"); printf("\n"); if (need_tab) {print_tabs(tab);} } CommentCheck Operator
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
        | Decls COMMA {printf(", ");} Decl
        ;
Decl:
        Ident
        | Ident ASSIGN {printf(" := ");}  ArithmExpression
        ;
AssignOperator:
       DataExpression ASSIGN {printf(" := ");}  Expression
       ;
ChooseOperator:
        Expression KW_THEN {printf(" then "); printf("\n"); tab++;} Operators {printf("\n"); print_tabs(tab-1);} KW_ELSE {printf("else\n");} Operators DOT {printf("."); tab--;}
        | Expression KW_THEN {printf(" then "); printf("\n"); tab++;} Operators DOT {printf("."); tab--;}
        ;
FuncCallOperator:
        Ident LEFT_ARROW {printf("<-");} ArithmExpressions
        ;
EndFuncOperator:
        KW_RETURN {printf("return ");} Expression
        | KW_RETURN {printf("return");}
        ;
PredLoopOperator:
        Expression KW_LOOP {printf(" loop\n"); tab++;} Operators DOT {printf("."); tab--;}
        ;
PostLoopOperator:
        KW_LOOP {printf(" loop\n"); tab++;} Operators {printf("\n");} KW_WHILE {tab--; print_tabs(tab); printf("while ");} Expression DOT {printf(". ");}
        ;
ForLoopOperator:
        Expression TILD {printf(" ~ ");} Expression KW_LOOP {printf(" loop "); } Ident {printf("\n"); tab++; need_tab = true;} Operators DOT {printf("."); tab--;}
        ;
Expression:
        AndExpression
        | AndExpression OrOp AndExpression
        ;
OrOp:
        OR { printf(" | "); }
        | EXC_OR { printf(" @ "); }
        ;
MulOp:
        MUL { printf(" * "); }
        | DIV { printf(" / "); }
        | REM_OF_DIV { printf(" %% "); }
        ;
AddOp:
        PLUS { printf(" + "); }
        | MINUS { printf(" - "); }
        ;
CmpOp:
        EQUAL_EQUAL {printf(" == ");}
        | NOT_EQUAL {printf(" != ");}
        | LESS {printf(" < ");}
        | GREATER {printf(" > ");}
        | LESS_EQUAL {printf(" <= ");}
        | GREATER_EQUAL {printf(" >= ");}
        ;
AndExpression:
        CmpExpression
        | CmpExpression AND {printf(" & ");} CmpExpression
        ;
CmpExpression:
        FuncCallExpression
        | FuncCallExpression CmpOp FuncCallExpression
        ;
FuncCallExpression:
        ArithmExpression
        | Ident LEFT_ARROW {printf("<- ");} ArithmExpressions
        ;
ArithmExpressions:
        ArithmExpression
        | ArithmExpressions COMMA {printf(", ");} ArithmExpression
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
        | Power POW {printf(" ^ ");} Factor
        ;
Power:
        DataExpression
        | NOT {printf("!");} Power
        | MINUS {printf("-");} Power %prec UMINUS
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
        | LEFT_PAREN {printf("(");} Expression RIGHT_PAREN {printf(")");}
        | STRING_CONST {printf("%s", $STRING_CONST);}
        ;
FullType:
        Type LEFT_PAREN2 RIGHT_PAREN2 {printf("[] ");}
        | Type LEFT_PAREN2 RIGHT_PAREN2 LEFT_PAREN2 RIGHT_PAREN2 {printf("[][] ");}
        | Type {printf(" ");}
        ;
Type:
        INT {printf("int");}
        | CHAR {printf("char");}
        | BOOL {printf("bool");}
        ;
Ident:
        LEFT_PAREN3 {printf("{");} VARNAME {printf("%s", $VARNAME);}  RIGHT_PAREN3 {printf("}");}
        ;
%%

int main(int argc, char *argv[]) {
    FILE *input = 0;
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
    yyparse(scanner, tab, need_tab);
    destroy_scanner(scanner);

    if (input != stdin) {
        fclose(input);
    }

    return 0;
}