%option reentrant noyywrap bison-bridge bison-locations
%option extra-type="struct Extra *"

/* Подавление предупреждений для -Wall */
%option noinput nounput

%{

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "y.tab.h"  /* файл генерируется Bison’ом */

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

void yyerror(YYLTYPE *loc, yyscan_t scanner, long env[26], const char *message) {
    printf("Error (%d,%d): %s\n", loc->first_line, loc->first_column, message);
}

%}

%%

[\t ]+
[\n]+ {
printf("\n");
}

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

"=="                         { return EQUAL; }
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

\$\"[^\"]\"|\$[0-9A-Fa-f]{2}|\$\"%(BEL|LF|CR|BS|VT|FF|\"\")%\"   {
    yylval->char_literal = yytext;
    return CHAR_LITERAL;
}

(\"([^\"]|%(\"[%\\]|[0-9A-Fa-f]{2}|BEL|BS|TAB|LF|VT|FF|CR))*\")|([0-7]|9|[A-Fa-f])  {
    yylval->string_const = yytext;
    return STRING_CONST;
}

([A-Za-z0-9_]+)  {
    yylval->varname = yytext;
    return VARNAME;
}

##.*?##|#\([\s\S]*?\)#  {
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