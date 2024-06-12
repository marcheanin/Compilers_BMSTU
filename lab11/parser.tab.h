/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EQUAL = 258,                   /* EQUAL  */
    EQUAL_EQUAL = 259,             /* EQUAL_EQUAL  */
    NOT_EQUAL = 260,               /* NOT_EQUAL  */
    LESS = 261,                    /* LESS  */
    GREATER = 262,                 /* GREATER  */
    LESS_EQUAL = 263,              /* LESS_EQUAL  */
    GREATER_EQUAL = 264,           /* GREATER_EQUAL  */
    PLUS = 265,                    /* PLUS  */
    MINUS = 266,                   /* MINUS  */
    MUL = 267,                     /* MUL  */
    REM_OF_DIV = 268,              /* REM_OF_DIV  */
    EXC_OR = 269,                  /* EXC_OR  */
    OR = 270,                      /* OR  */
    AND = 271,                     /* AND  */
    DIV = 272,                     /* DIV  */
    POW = 273,                     /* POW  */
    NOT = 274,                     /* NOT  */
    UMINUS = 275,                  /* UMINUS  */
    INT = 276,                     /* INT  */
    CHAR = 277,                    /* CHAR  */
    BOOL = 278,                    /* BOOL  */
    VOID = 279,                    /* VOID  */
    KW_TRUE = 280,                 /* KW_TRUE  */
    KW_FALSE = 281,                /* KW_FALSE  */
    KW_NULL = 282,                 /* KW_NULL  */
    KW_IF = 283,                   /* KW_IF  */
    KW_ELSE = 284,                 /* KW_ELSE  */
    KW_RETURN = 285,               /* KW_RETURN  */
    KW_LOOP = 286,                 /* KW_LOOP  */
    KW_WHILE = 287,                /* KW_WHILE  */
    KW_THEN = 288,                 /* KW_THEN  */
    SEMICOLON = 289,               /* SEMICOLON  */
    DOT = 290,                     /* DOT  */
    LEFT_ARROW = 291,              /* LEFT_ARROW  */
    LEFT_PAREN = 292,              /* LEFT_PAREN  */
    RIGHT_PAREN = 293,             /* RIGHT_PAREN  */
    LEFT_PAREN2 = 294,             /* LEFT_PAREN2  */
    RIGHT_PAREN2 = 295,            /* RIGHT_PAREN2  */
    LEFT_PAREN3 = 296,             /* LEFT_PAREN3  */
    RIGHT_PAREN3 = 297,            /* RIGHT_PAREN3  */
    COMMA = 298,                   /* COMMA  */
    TILD = 299,                    /* TILD  */
    ASSIGN = 300,                  /* ASSIGN  */
    INTEGER = 301,                 /* INTEGER  */
    CHAR_LITERAL = 302,            /* CHAR_LITERAL  */
    STRING_CONST = 303,            /* STRING_CONST  */
    VARNAME = 304,                 /* VARNAME  */
    COMMENT = 305                  /* COMMENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "parser.y"

    char* integer;
    char* char_literal;
    char* string_const;
    char* varname;
    char* comment;

#line 122 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (yyscan_t scanner, int tab, bool need_tab);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
