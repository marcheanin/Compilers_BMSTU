% "Лабораторная работа 3.2 «Форматтер исходных текстов»"
% 10 июня 2024 г.
% Андрей Марченко, ИУ9-62Б

# Цель работы
Целью данной работы является приобретение навыков 
использования генератора синтаксических анализаторов bison.

# Индивидуальный вариант
Язык L2.

# Реализация
Лексер
```lex
%option reentrant noyywrap bison-bridge bison-locations
%option extra-type="struct Extra *"

/* Подавление предупреждений для -Wall */
%option noinput nounput

%{

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.tab.h"  /* файл генерируется Bison’ом */

#define YY_USER_ACTION \
  { \
    int i; \
    struct Extra *extra = yyextra; \
    if (! extra->continued ) { \
      yylloc->first_line = extra->cur_line; \
      yylloc->first_column = extra->cur_column; \
    } \
    extra->continued = false; \
    for (i = 0; i < yyleng; ++i) { \
      if (yytext[i] == '\n') { \
        extra->cur_line += 1; \
        extra->cur_column = 1; \
      } else { \
        extra->cur_column += 1; \
      } \
    } \
    yylloc->last_line = extra->cur_line; \
    yylloc->last_column = extra->cur_column; \
  }

void yyerror(YYLTYPE *loc, yyscan_t scanner, long env[26], int tab, bool need_tab, const char *message) {
    printf("Error (%d,%d): %s\n", loc->first_line, loc->first_column, message);
}

%}

%%

[\t\r\n ]+


int                          { return INT; }
char                         { return CHAR; }
bool                         { return BOOL; }
void                         { return VOID; }

true                         { return KW_TRUE; }
false                        { return KW_FALSE; }
null                         { return KW_NULL; }

if                           { return KW_IF; }
else                         { return KW_ELSE; }
return                       { return KW_RETURN; }
loop                         { return KW_LOOP; }
while                        { return KW_WHILE; }

"=="                         { return EQUAL_EQUAL; }
"="                          { return EQUAL; }
"!="                         { return NOT_EQUAL; }
"<"                          { return LESS; }
">"                          { return GREATER; }
"<="                         { return LESS_EQUAL; }
">="                         { return GREATER_EQUAL; }

"+"                          { return PLUS; }
"-"                          { return MINUS; }
"*"                          { return MUL; }
"%"                          { return REM_OF_DIV; }
"@"                          { return EXC_OR; }
"|"                          { return OR; }
";"                          { return SEMICOLON; }
"<-"                         { return LEFT_ARROW; }
"("                          { return LEFT_PAREN; }
")"                          { return RIGHT_PAREN; }
"["                          { return LEFT_PAREN2; }
"]"                          { return RIGHT_PAREN2; }
"{"                          { return LEFT_PAREN3; }
"}"                          { return RIGHT_PAREN3; }
"^"                          { return POW; }
"/"                          { return DIV; }
"!"                          { return NOT; }
"&"                          { return AND; }
","                          { return COMMA; }
"~"                          { return TILD; }
"."                          { return DOT; }

":="                         { return ASSIGN; }
then                         { return KW_THEN; }

[0-9]+  {
    yylval->integer = yytext;
    return INTEGER;
}

(\$\"[^\"]\"|\$[0-9A-Fa-f]{2}|\$\"%(BEL|LF|CR|BS|VT|FF|\"\")%\")   {
    yylval->char_literal = yytext;
    return CHAR_LITERAL;
}

(\"([^\"]|%(\"[%\\]|[0-9A-Fa-f]{2}|BEL|BS|TAB|LF|VT|FF|CR))*\")  {
    yylval->string_const = yytext;
    return STRING_CONST;
}

[A-Za-z0-9_]+ {
    yylval->varname = yytext;
    return VARNAME;
}

(##.*?##|#\([\s\S]*?\)#)  {
    yylval->comment = yytext;
    return COMMENT;
}

%%

void init_scanner(FILE *input, yyscan_t *scanner, struct Extra *extra) {
    extra->continued = false;
    extra->cur_line = 1;
    extra->cur_column = 1;

    yylex_init(scanner);
    yylex_init_extra(extra, scanner);
    yyset_in(input, *scanner);
}

void destroy_scanner(yyscan_t scanner) {
    yylex_destroy(scanner);
}
```

Парсер
```bison
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
%token SEMICOLON DOT LEFT_ARROW LEFT_PAREN RIGHT_PAREN LEFT_PAREN2 RIGHT_PAREN2 
%token LEFT_PAREN3 RIGHT_PAREN3 COMMA TILD ASSIGN /* 23 */

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
        FullTypeOrVoid Ident LEFT_ARROW {printf(" <- ");} Parameters {printf("\n"); tab++; 
        print_tabs(tab);} EQUAL {printf("= ");} Operators DOT  {printf(".");}
        | FullTypeOrVoid Ident EQUAL {printf("= "); need_tab = false; } 
        Operators DOT {printf("."); tab = 0; need_tab = true;}
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
        | Operators SEMICOLON  {printf(";"); printf("\n"); if (need_tab) {print_tabs(tab);} } 
        CommentCheck Operator
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
        Expression KW_THEN {printf(" then "); printf("\n"); tab++;} 
        Operators {printf("\n"); print_tabs(tab-1);} 
        KW_ELSE {printf("else\n");} Operators DOT {printf("."); tab--;}
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
        KW_LOOP {printf(" loop\n"); tab++;} Operators {printf("\n");} KW_WHILE {tab--; 
        print_tabs(tab); printf("while ");} Expression DOT {printf(". ");}
        ;
ForLoopOperator:
        Expression TILD {printf(" ~ ");} Expression KW_LOOP {printf(" loop "); } 
        Ident {printf("\n"); tab++; need_tab = true;} Operators DOT {printf("."); tab--;}
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
```

# Тестирование

Входные данные

```
int[] {SumVectors}
    <- int[] {A}, int[] {B}
    = int {size} := {Length} + {A};
    int[] {C} := {size};
    char[] {D} := "Hello world";
    {FuncName} <- {A}, {B}, 5 / (10 * 3);
    int {res_func} := (65 + 7) * {A} ;
    0 ~ {size} loop {i}
        loop
            {A}0 := {A}0 + 1
        while {A}0 < 10 .;
        {C}{i} := {A}{i} + {B} .;
    {A}5 < 7 then return 7
    else return 8 . ;
    return {C} .
```

Вывод на `stdout`

```
int[] {SumVectors} <- int[] {A}, int[] {B}
    = int {size} := {Length} + {A};
    int[] {C} := {size};
    char[] {D} := "Hello world";
    {FuncName}<-{A}, {B}, 5 / (10 * 3);
    int {res_func} := (65 + 7) * {A};
    0 ~ {size} loop {i}
         loop
            {A}0 := {A}0 + 1
        while {A}0 < 10. ;
        {C}{i} := {A}{i} + {B}.;
    {A}5 < 7 then
        return 7
    else
        return 8.;

```

# Вывод
В данной лабораторной работе я научился работать с новым генератором правил, теперь 
синтаксических - bison, что было логическим продолжением лабораторной работы про 
генератор лексических анализаторов flex. При этом, дополнительным заданием было написание
форматтера, что также оказалось очень интересным, так как я раньше не представлял как это 
делают, например, среды разработки. По моему мнению, работа для меня была полезной, и я
освоил все инструменты для выполнения такого рода задач.