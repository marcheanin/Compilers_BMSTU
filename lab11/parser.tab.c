/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include "lexer.h"

#line 76 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EQUAL = 3,                      /* EQUAL  */
  YYSYMBOL_EQUAL_EQUAL = 4,                /* EQUAL_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 5,                  /* NOT_EQUAL  */
  YYSYMBOL_LESS = 6,                       /* LESS  */
  YYSYMBOL_GREATER = 7,                    /* GREATER  */
  YYSYMBOL_LESS_EQUAL = 8,                 /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 9,              /* GREATER_EQUAL  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_MUL = 12,                       /* MUL  */
  YYSYMBOL_REM_OF_DIV = 13,                /* REM_OF_DIV  */
  YYSYMBOL_EXC_OR = 14,                    /* EXC_OR  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_DIV = 17,                       /* DIV  */
  YYSYMBOL_POW = 18,                       /* POW  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_UMINUS = 20,                    /* UMINUS  */
  YYSYMBOL_INT = 21,                       /* INT  */
  YYSYMBOL_CHAR = 22,                      /* CHAR  */
  YYSYMBOL_BOOL = 23,                      /* BOOL  */
  YYSYMBOL_VOID = 24,                      /* VOID  */
  YYSYMBOL_KW_TRUE = 25,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 26,                  /* KW_FALSE  */
  YYSYMBOL_KW_NULL = 27,                   /* KW_NULL  */
  YYSYMBOL_KW_IF = 28,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 29,                   /* KW_ELSE  */
  YYSYMBOL_KW_RETURN = 30,                 /* KW_RETURN  */
  YYSYMBOL_KW_LOOP = 31,                   /* KW_LOOP  */
  YYSYMBOL_KW_WHILE = 32,                  /* KW_WHILE  */
  YYSYMBOL_KW_THEN = 33,                   /* KW_THEN  */
  YYSYMBOL_SEMICOLON = 34,                 /* SEMICOLON  */
  YYSYMBOL_DOT = 35,                       /* DOT  */
  YYSYMBOL_LEFT_ARROW = 36,                /* LEFT_ARROW  */
  YYSYMBOL_LEFT_PAREN = 37,                /* LEFT_PAREN  */
  YYSYMBOL_RIGHT_PAREN = 38,               /* RIGHT_PAREN  */
  YYSYMBOL_LEFT_PAREN2 = 39,               /* LEFT_PAREN2  */
  YYSYMBOL_RIGHT_PAREN2 = 40,              /* RIGHT_PAREN2  */
  YYSYMBOL_LEFT_PAREN3 = 41,               /* LEFT_PAREN3  */
  YYSYMBOL_RIGHT_PAREN3 = 42,              /* RIGHT_PAREN3  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_TILD = 44,                      /* TILD  */
  YYSYMBOL_ASSIGN = 45,                    /* ASSIGN  */
  YYSYMBOL_INTEGER = 46,                   /* INTEGER  */
  YYSYMBOL_CHAR_LITERAL = 47,              /* CHAR_LITERAL  */
  YYSYMBOL_STRING_CONST = 48,              /* STRING_CONST  */
  YYSYMBOL_VARNAME = 49,                   /* VARNAME  */
  YYSYMBOL_COMMENT = 50,                   /* COMMENT  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_FuncDecl = 53,                  /* FuncDecl  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_CommentCheck = 58,              /* CommentCheck  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_FullTypeOrVoid = 60,            /* FullTypeOrVoid  */
  YYSYMBOL_Parameters = 61,                /* Parameters  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_Parameter = 63,                 /* Parameter  */
  YYSYMBOL_Operators = 64,                 /* Operators  */
  YYSYMBOL_65_7 = 65,                      /* $@7  */
  YYSYMBOL_66_8 = 66,                      /* $@8  */
  YYSYMBOL_Operator = 67,                  /* Operator  */
  YYSYMBOL_DeclOperator = 68,              /* DeclOperator  */
  YYSYMBOL_Decls = 69,                     /* Decls  */
  YYSYMBOL_70_9 = 70,                      /* $@9  */
  YYSYMBOL_Decl = 71,                      /* Decl  */
  YYSYMBOL_72_10 = 72,                     /* $@10  */
  YYSYMBOL_AssignOperator = 73,            /* AssignOperator  */
  YYSYMBOL_74_11 = 74,                     /* $@11  */
  YYSYMBOL_ChooseOperator = 75,            /* ChooseOperator  */
  YYSYMBOL_76_12 = 76,                     /* $@12  */
  YYSYMBOL_77_13 = 77,                     /* $@13  */
  YYSYMBOL_78_14 = 78,                     /* $@14  */
  YYSYMBOL_79_15 = 79,                     /* $@15  */
  YYSYMBOL_FuncCallOperator = 80,          /* FuncCallOperator  */
  YYSYMBOL_81_16 = 81,                     /* $@16  */
  YYSYMBOL_EndFuncOperator = 82,           /* EndFuncOperator  */
  YYSYMBOL_83_17 = 83,                     /* $@17  */
  YYSYMBOL_PredLoopOperator = 84,          /* PredLoopOperator  */
  YYSYMBOL_85_18 = 85,                     /* $@18  */
  YYSYMBOL_PostLoopOperator = 86,          /* PostLoopOperator  */
  YYSYMBOL_87_19 = 87,                     /* $@19  */
  YYSYMBOL_88_20 = 88,                     /* $@20  */
  YYSYMBOL_89_21 = 89,                     /* $@21  */
  YYSYMBOL_ForLoopOperator = 90,           /* ForLoopOperator  */
  YYSYMBOL_91_22 = 91,                     /* $@22  */
  YYSYMBOL_92_23 = 92,                     /* $@23  */
  YYSYMBOL_93_24 = 93,                     /* $@24  */
  YYSYMBOL_Expression = 94,                /* Expression  */
  YYSYMBOL_OrOp = 95,                      /* OrOp  */
  YYSYMBOL_MulOp = 96,                     /* MulOp  */
  YYSYMBOL_AddOp = 97,                     /* AddOp  */
  YYSYMBOL_CmpOp = 98,                     /* CmpOp  */
  YYSYMBOL_AndExpression = 99,             /* AndExpression  */
  YYSYMBOL_100_25 = 100,                   /* $@25  */
  YYSYMBOL_CmpExpression = 101,            /* CmpExpression  */
  YYSYMBOL_FuncCallExpression = 102,       /* FuncCallExpression  */
  YYSYMBOL_103_26 = 103,                   /* $@26  */
  YYSYMBOL_ArithmExpressions = 104,        /* ArithmExpressions  */
  YYSYMBOL_105_27 = 105,                   /* $@27  */
  YYSYMBOL_ArithmExpression = 106,         /* ArithmExpression  */
  YYSYMBOL_Term = 107,                     /* Term  */
  YYSYMBOL_Factor = 108,                   /* Factor  */
  YYSYMBOL_109_28 = 109,                   /* $@28  */
  YYSYMBOL_Power = 110,                    /* Power  */
  YYSYMBOL_111_29 = 111,                   /* $@29  */
  YYSYMBOL_112_30 = 112,                   /* $@30  */
  YYSYMBOL_DataExpression = 113,           /* DataExpression  */
  YYSYMBOL_BaseExpression = 114,           /* BaseExpression  */
  YYSYMBOL_115_31 = 115,                   /* $@31  */
  YYSYMBOL_FullType = 116,                 /* FullType  */
  YYSYMBOL_Type = 117,                     /* Type  */
  YYSYMBOL_Ident = 118,                    /* Ident  */
  YYSYMBOL_119_32 = 119,                   /* $@32  */
  YYSYMBOL_120_33 = 120                    /* $@33  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 37 "parser.y"

int yylex(YYSTYPE *yylval_param, YYLTYPE *yylloc_param, yyscan_t scanner);
void yyerror(YYLTYPE *loc, yyscan_t scanner, long env[26], int tab, bool need_tab, const char *message);
#line 42 "parser.y"


void print_tabs(int tab_col) {
    for(int i = 0; i < tab_col; i++) {
        printf("    ");
    }
}


#line 244 "parser.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    55,    58,    58,    58,    58,    59,    59,
      61,    62,    62,    65,    66,    69,    70,    70,    73,    76,
      76,    77,    77,    80,    81,    82,    83,    84,    85,    86,
      87,    90,    93,    94,    94,    97,    98,    98,   101,   101,
     104,   104,   104,   104,   105,   105,   108,   108,   111,   111,
     112,   115,   115,   118,   118,   118,   118,   121,   121,   121,
     121,   124,   125,   128,   129,   132,   133,   134,   137,   138,
     141,   142,   143,   144,   145,   146,   149,   150,   150,   153,
     154,   157,   158,   158,   161,   162,   162,   165,   166,   169,
     170,   173,   174,   174,   177,   178,   178,   179,   179,   180,
     183,   184,   187,   188,   189,   190,   191,   192,   193,   193,
     194,   197,   198,   199,   202,   203,   204,   207,   207,   207
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "EQUAL", "EQUAL_EQUAL",
  "NOT_EQUAL", "LESS", "GREATER", "LESS_EQUAL", "GREATER_EQUAL", "PLUS",
  "MINUS", "MUL", "REM_OF_DIV", "EXC_OR", "OR", "AND", "DIV", "POW", "NOT",
  "UMINUS", "INT", "CHAR", "BOOL", "VOID", "KW_TRUE", "KW_FALSE",
  "KW_NULL", "KW_IF", "KW_ELSE", "KW_RETURN", "KW_LOOP", "KW_WHILE",
  "KW_THEN", "SEMICOLON", "DOT", "LEFT_ARROW", "LEFT_PAREN", "RIGHT_PAREN",
  "LEFT_PAREN2", "RIGHT_PAREN2", "LEFT_PAREN3", "RIGHT_PAREN3", "COMMA",
  "TILD", "ASSIGN", "INTEGER", "CHAR_LITERAL", "STRING_CONST", "VARNAME",
  "COMMENT", "$accept", "Program", "FuncDecl", "$@1", "$@2", "$@3", "$@4",
  "CommentCheck", "$@5", "FullTypeOrVoid", "Parameters", "$@6",
  "Parameter", "Operators", "$@7", "$@8", "Operator", "DeclOperator",
  "Decls", "$@9", "Decl", "$@10", "AssignOperator", "$@11",
  "ChooseOperator", "$@12", "$@13", "$@14", "$@15", "FuncCallOperator",
  "$@16", "EndFuncOperator", "$@17", "PredLoopOperator", "$@18",
  "PostLoopOperator", "$@19", "$@20", "$@21", "ForLoopOperator", "$@22",
  "$@23", "$@24", "Expression", "OrOp", "MulOp", "AddOp", "CmpOp",
  "AndExpression", "$@25", "CmpExpression", "FuncCallExpression", "$@26",
  "ArithmExpressions", "$@27", "ArithmExpression", "Term", "Factor",
  "$@28", "Power", "$@29", "$@30", "DataExpression", "BaseExpression",
  "$@31", "FullType", "Type", "Ident", "$@32", "$@33", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,  -121,  -121,  -121,  -121,    14,  -121,   -24,  -121,   -20,
    -121,  -121,  -121,     6,   -11,   -18,  -121,  -121,    -5,  -121,
    -121,     2,     7,    10,     5,    65,    11,  -121,   -24,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,    43,  -121,
    -121,  -121,  -121,  -121,    13,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,    36,    45,    29,   128,    60,     3,  -121,
      50,   122,  -121,   135,    25,  -121,    70,  -121,    13,   104,
     104,   104,  -121,   104,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,   104,  -121,  -121,  -121,  -121,  -121,  -121,  -121,   104,
    -121,  -121,   104,  -121,  -121,  -121,   104,  -121,  -121,  -121,
    -121,    38,  -121,  -121,    -2,  -121,     2,  -121,    65,  -121,
     135,   135,  -121,  -121,    47,    55,    41,    13,  -121,  -121,
    -121,   104,  -121,   104,  -121,     3,  -121,   104,   104,  -121,
    -121,   104,   104,  -121,  -121,  -121,  -121,    62,  -121,  -121,
     108,    55,   119,    67,  -121,  -121,  -121,   -24,   104,    57,
      60,    57,   130,  -121,  -121,    74,  -121,  -121,  -121,    63,
      60,  -121,  -121,   104,  -121,   -24,   104,    75,  -121,  -121,
      60,  -121,   139,  -121,  -121,   143,  -121
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   114,   115,   116,    14,     0,     2,     0,    13,   113,
       1,     3,   117,     0,     0,     0,     8,     4,   111,   118,
      19,     0,     0,     0,     0,     0,     5,    15,     0,   112,
     119,    21,     9,    97,    95,   103,   104,   105,    48,    53,
     108,   107,   106,   110,    10,    23,    24,    26,    25,    30,
      27,    28,    29,     0,    61,    76,    79,    81,    87,    89,
      91,    94,   100,     0,   102,    16,     0,    18,    10,     0,
       0,     0,    19,     0,    11,    20,    51,    40,    57,    64,
      63,     0,    77,    70,    71,    72,    73,    74,    75,     0,
      68,    69,     0,    65,    67,    66,     0,    92,    38,   101,
     102,    31,    32,    99,   102,    46,     0,     6,     0,    98,
      94,     0,    96,    49,   102,    54,     0,    10,    19,    19,
      19,     0,    62,     0,    80,    88,    90,     0,     0,    33,
      36,     0,     0,    17,    19,    22,    82,     0,   109,    12,
       0,    41,     0,     0,    78,    93,    39,     0,     0,    47,
      84,    83,     0,    55,    52,     0,    45,    58,    34,    35,
      37,    85,     7,     0,    42,     0,     0,     0,    19,    59,
      86,    56,     0,    19,    43,     0,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -121,  -121,   100,  -121,  -121,  -121,  -121,   -64,  -121,  -121,
    -121,  -121,    16,   -69,  -121,  -121,    20,  -121,  -121,  -121,
      -3,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,   -66,  -121,  -121,  -121,  -121,    76,  -121,
      23,    35,  -121,    34,  -121,  -120,    79,   -83,  -121,    69,
    -121,  -121,   -23,   -53,  -121,     1,  -121,    -7,  -121,  -121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,    21,    66,   134,    20,    75,   117,     7,
      26,   106,    27,    24,    25,    68,    44,    45,   101,   147,
     102,   148,    46,   128,    47,   119,   155,   168,   120,    48,
     131,    49,    71,    50,   118,    51,    72,   137,   163,    52,
     121,   165,   173,    53,    81,    96,    92,    89,    54,   123,
      55,    56,   132,   149,   166,    57,    58,    59,   127,    60,
      70,    69,   110,    62,    73,   111,     9,   100,    15,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,     8,    61,   115,   108,   113,     8,   116,    99,    16,
     103,   150,   150,   126,    10,    93,    94,    12,    64,    14,
      95,    67,    28,     1,     2,     3,    63,   -35,   160,    18,
     -35,    19,   -35,   -35,    22,     1,     2,     3,     4,    31,
      32,   -35,    17,   130,   145,    82,   170,    29,   -35,   140,
     141,   142,    30,   139,    65,   143,   104,    99,   103,    79,
      80,   105,   146,    74,   114,   152,   114,    76,    97,    77,
      90,    91,   -50,   107,   114,   -50,    33,   -50,   -50,   138,
      78,   129,   114,   136,    34,    61,     1,     2,     3,    31,
      35,    36,    37,   -50,   153,    38,    39,   167,   157,   172,
     161,    64,    40,   164,   175,    11,    12,    28,   130,    63,
     171,    41,    42,    43,   114,    33,   114,     1,     2,     3,
       4,   114,   133,    34,   124,     1,     2,     3,   135,    35,
      36,    37,    83,    84,    85,    86,    87,    88,   109,   112,
     159,    40,    31,   154,   158,    12,   144,    35,    36,    37,
      41,    42,    43,    31,   156,     0,   114,   122,   169,    40,
      35,    36,    37,    12,    31,   162,   151,    98,    41,    42,
      43,   125,    40,    31,   174,     0,    12,    31,   176,     0,
       0,    41,    42,    43
};

static const yytype_int16 yycheck[] =
{
       7,     0,    25,    72,    68,    71,     5,    73,    61,     3,
      63,   131,   132,    96,     0,    12,    13,    41,    25,    39,
      17,    28,    21,    21,    22,    23,    25,    29,   148,    40,
      32,    49,    34,    35,    39,    21,    22,    23,    24,    34,
      35,    43,    36,    45,   127,    16,   166,    40,    50,   118,
     119,   120,    42,   117,    43,   121,    63,   110,   111,    14,
      15,    36,   128,    50,    71,   134,    73,    31,    18,    33,
      10,    11,    29,     3,    81,    32,    11,    34,    35,    38,
      44,    43,    89,    36,    19,   108,    21,    22,    23,    34,
      25,    26,    27,    50,    32,    30,    31,   163,    31,   168,
      43,   108,    37,    29,   173,     5,    41,   106,    45,   108,
      35,    46,    47,    48,   121,    11,   123,    21,    22,    23,
      24,   128,   106,    19,    89,    21,    22,    23,   108,    25,
      26,    27,     4,     5,     6,     7,     8,     9,    69,    70,
     147,    37,    34,    35,   147,    41,   123,    25,    26,    27,
      46,    47,    48,    34,    35,    -1,   163,    81,   165,    37,
      25,    26,    27,    41,    34,    35,   132,    45,    46,    47,
      48,    92,    37,    34,    35,    -1,    41,    34,    35,    -1,
      -1,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    22,    23,    24,    52,    53,    60,   116,   117,
       0,    53,    41,   118,    39,   119,     3,    36,    40,    49,
      57,    54,    39,   120,    64,    65,    61,    63,   116,    40,
      42,    34,    35,    11,    19,    25,    26,    27,    30,    31,
      37,    46,    47,    48,    67,    68,    73,    75,    80,    82,
      84,    86,    90,    94,    99,   101,   102,   106,   107,   108,
     110,   113,   114,   116,   118,    43,    55,   118,    66,   112,
     111,    83,    87,   115,    50,    58,    31,    33,    44,    14,
      15,    95,    16,     4,     5,     6,     7,     8,     9,    98,
      10,    11,    97,    12,    13,    17,    96,    18,    45,   114,
     118,    69,    71,   114,   118,    36,    62,     3,    58,   110,
     113,   116,   110,    94,   118,    64,    94,    59,    85,    76,
      79,    91,    99,   100,   102,   107,   108,   109,    74,    43,
      45,    81,   103,    63,    56,    67,    36,    88,    38,    58,
      64,    64,    64,    94,   101,   108,    94,    70,    72,   104,
     106,   104,    64,    32,    35,    77,    35,    31,    71,   118,
     106,    43,    35,    89,    29,    92,   105,    94,    78,   118,
     106,    35,    64,    93,    35,    64,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    54,    55,    56,    53,    57,    53,
      58,    59,    58,    60,    60,    61,    62,    61,    63,    65,
      64,    66,    64,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    69,    70,    69,    71,    72,    71,    74,    73,
      76,    77,    78,    75,    79,    75,    81,    80,    83,    82,
      82,    85,    84,    87,    88,    89,    86,    91,    92,    93,
      90,    94,    94,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    98,    98,    98,    98,    99,   100,    99,   101,
     101,   102,   103,   102,   104,   105,   104,   106,   106,   107,
     107,   108,   109,   108,   110,   111,   110,   112,   110,   110,
     113,   113,   114,   114,   114,   114,   114,   114,   115,   114,
     114,   116,   116,   116,   117,   117,   117,   119,   120,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,     0,    10,     0,     6,
       0,     0,     3,     1,     1,     1,     0,     4,     2,     0,
       3,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     4,     1,     0,     4,     0,     4,
       0,     0,     0,     9,     0,     5,     0,     4,     0,     3,
       1,     0,     5,     0,     0,     0,     8,     0,     0,     0,
      10,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       3,     1,     0,     4,     1,     0,     4,     1,     3,     1,
       3,     1,     0,     4,     1,     0,     3,     0,     3,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     3,     5,     1,     1,     1,     1,     0,     0,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, scanner, env, tab, need_tab, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, scanner, env, tab, need_tab); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, long env[26], int tab, bool need_tab)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (env);
  YY_USE (tab);
  YY_USE (need_tab);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, long env[26], int tab, bool need_tab)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner, env, tab, need_tab);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, yyscan_t scanner, long env[26], int tab, bool need_tab)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), scanner, env, tab, need_tab);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, env, tab, need_tab); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, long env[26], int tab, bool need_tab)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  YY_USE (env);
  YY_USE (tab);
  YY_USE (need_tab);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner, long env[26], int tab, bool need_tab)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* $@1: %empty  */
#line 58 "parser.y"
                                        {printf(" <- ");}
#line 1743 "parser.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 58 "parser.y"
                                                                     {printf("\n"); tab++; print_tabs(tab);}
#line 1749 "parser.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 58 "parser.y"
                                                                                                                   {printf("= ");}
#line 1755 "parser.tab.c"
    break;

  case 7: /* FuncDecl: FullTypeOrVoid Ident LEFT_ARROW $@1 Parameters $@2 EQUAL $@3 Operators DOT  */
#line 58 "parser.y"
                                                                                                                                                  {printf(".");}
#line 1761 "parser.tab.c"
    break;

  case 8: /* $@4: %empty  */
#line 59 "parser.y"
                                     {printf("= "); need_tab = false; }
#line 1767 "parser.tab.c"
    break;

  case 9: /* FuncDecl: FullTypeOrVoid Ident EQUAL $@4 Operators DOT  */
#line 59 "parser.y"
                                                                                      {printf("."); tab = 0; need_tab = true;}
#line 1773 "parser.tab.c"
    break;

  case 11: /* $@5: %empty  */
#line 62 "parser.y"
                  {printf("%s\n", (yyvsp[0].comment)); if (need_tab) { print_tabs(tab);} }
#line 1779 "parser.tab.c"
    break;

  case 14: /* FullTypeOrVoid: VOID  */
#line 66 "parser.y"
               {printf("void ");}
#line 1785 "parser.tab.c"
    break;

  case 16: /* $@6: %empty  */
#line 70 "parser.y"
                           {printf(", ");}
#line 1791 "parser.tab.c"
    break;

  case 19: /* $@7: %empty  */
#line 76 "parser.y"
        { if (need_tab) {print_tabs(tab);} need_tab = true;}
#line 1797 "parser.tab.c"
    break;

  case 21: /* $@8: %empty  */
#line 77 "parser.y"
                               {printf(";"); printf("\n"); if (need_tab) {print_tabs(tab);} }
#line 1803 "parser.tab.c"
    break;

  case 33: /* $@9: %empty  */
#line 94 "parser.y"
                      {printf(", ");}
#line 1809 "parser.tab.c"
    break;

  case 36: /* $@10: %empty  */
#line 98 "parser.y"
                       {printf(" := ");}
#line 1815 "parser.tab.c"
    break;

  case 38: /* $@11: %empty  */
#line 101 "parser.y"
                             {printf(" := ");}
#line 1821 "parser.tab.c"
    break;

  case 40: /* $@12: %empty  */
#line 104 "parser.y"
                           {printf(" then "); printf("\n"); tab++;}
#line 1827 "parser.tab.c"
    break;

  case 41: /* $@13: %empty  */
#line 104 "parser.y"
                                                                              {printf("\n"); print_tabs(tab-1);}
#line 1833 "parser.tab.c"
    break;

  case 42: /* $@14: %empty  */
#line 104 "parser.y"
                                                                                                                         {printf("else\n");}
#line 1839 "parser.tab.c"
    break;

  case 43: /* ChooseOperator: Expression KW_THEN $@12 Operators $@13 KW_ELSE $@14 Operators DOT  */
#line 104 "parser.y"
                                                                                                                                                           {printf("."); tab--;}
#line 1845 "parser.tab.c"
    break;

  case 44: /* $@15: %empty  */
#line 105 "parser.y"
                             {printf(" then "); printf("\n"); tab++;}
#line 1851 "parser.tab.c"
    break;

  case 45: /* ChooseOperator: Expression KW_THEN $@15 Operators DOT  */
#line 105 "parser.y"
                                                                                    {printf("."); tab--;}
#line 1857 "parser.tab.c"
    break;

  case 46: /* $@16: %empty  */
#line 108 "parser.y"
                         {printf("<-");}
#line 1863 "parser.tab.c"
    break;

  case 48: /* $@17: %empty  */
#line 111 "parser.y"
                  {printf("return ");}
#line 1869 "parser.tab.c"
    break;

  case 50: /* EndFuncOperator: KW_RETURN  */
#line 112 "parser.y"
                    {printf("return");}
#line 1875 "parser.tab.c"
    break;

  case 51: /* $@18: %empty  */
#line 115 "parser.y"
                           {printf(" loop\n"); tab++;}
#line 1881 "parser.tab.c"
    break;

  case 52: /* PredLoopOperator: Expression KW_LOOP $@18 Operators DOT  */
#line 115 "parser.y"
                                                                     {printf("."); tab--;}
#line 1887 "parser.tab.c"
    break;

  case 53: /* $@19: %empty  */
#line 118 "parser.y"
                {printf(" loop\n"); tab++;}
#line 1893 "parser.tab.c"
    break;

  case 54: /* $@20: %empty  */
#line 118 "parser.y"
                                                      {printf("\n");}
#line 1899 "parser.tab.c"
    break;

  case 55: /* $@21: %empty  */
#line 118 "parser.y"
                                                                               {tab--; print_tabs(tab); printf("while ");}
#line 1905 "parser.tab.c"
    break;

  case 56: /* PostLoopOperator: KW_LOOP $@19 Operators $@20 KW_WHILE $@21 Expression DOT  */
#line 118 "parser.y"
                                                                                                                                          {printf(". ");}
#line 1911 "parser.tab.c"
    break;

  case 57: /* $@22: %empty  */
#line 121 "parser.y"
                        {printf(" ~ ");}
#line 1917 "parser.tab.c"
    break;

  case 58: /* $@23: %empty  */
#line 121 "parser.y"
                                                            {printf(" loop "); }
#line 1923 "parser.tab.c"
    break;

  case 59: /* $@24: %empty  */
#line 121 "parser.y"
                                                                                       {printf("\n"); tab++; need_tab = true;}
#line 1929 "parser.tab.c"
    break;

  case 60: /* ForLoopOperator: Expression TILD $@22 Expression KW_LOOP $@23 Ident $@24 Operators DOT  */
#line 121 "parser.y"
                                                                                                                                             {printf("."); tab--;}
#line 1935 "parser.tab.c"
    break;

  case 63: /* OrOp: OR  */
#line 128 "parser.y"
           { printf(" | "); }
#line 1941 "parser.tab.c"
    break;

  case 64: /* OrOp: EXC_OR  */
#line 129 "parser.y"
                 { printf(" @ "); }
#line 1947 "parser.tab.c"
    break;

  case 65: /* MulOp: MUL  */
#line 132 "parser.y"
            { printf(" * "); }
#line 1953 "parser.tab.c"
    break;

  case 66: /* MulOp: DIV  */
#line 133 "parser.y"
              { printf(" / "); }
#line 1959 "parser.tab.c"
    break;

  case 67: /* MulOp: REM_OF_DIV  */
#line 134 "parser.y"
                     { printf(" %% "); }
#line 1965 "parser.tab.c"
    break;

  case 68: /* AddOp: PLUS  */
#line 137 "parser.y"
             { printf(" + "); }
#line 1971 "parser.tab.c"
    break;

  case 69: /* AddOp: MINUS  */
#line 138 "parser.y"
                { printf(" - "); }
#line 1977 "parser.tab.c"
    break;

  case 70: /* CmpOp: EQUAL_EQUAL  */
#line 141 "parser.y"
                    {printf(" == ");}
#line 1983 "parser.tab.c"
    break;

  case 71: /* CmpOp: NOT_EQUAL  */
#line 142 "parser.y"
                    {printf(" != ");}
#line 1989 "parser.tab.c"
    break;

  case 72: /* CmpOp: LESS  */
#line 143 "parser.y"
               {printf(" < ");}
#line 1995 "parser.tab.c"
    break;

  case 73: /* CmpOp: GREATER  */
#line 144 "parser.y"
                  {printf(" > ");}
#line 2001 "parser.tab.c"
    break;

  case 74: /* CmpOp: LESS_EQUAL  */
#line 145 "parser.y"
                     {printf(" <= ");}
#line 2007 "parser.tab.c"
    break;

  case 75: /* CmpOp: GREATER_EQUAL  */
#line 146 "parser.y"
                        {printf(" >= ");}
#line 2013 "parser.tab.c"
    break;

  case 77: /* $@25: %empty  */
#line 150 "parser.y"
                            {printf(" & ");}
#line 2019 "parser.tab.c"
    break;

  case 82: /* $@26: %empty  */
#line 158 "parser.y"
                           {printf("<- ");}
#line 2025 "parser.tab.c"
    break;

  case 85: /* $@27: %empty  */
#line 162 "parser.y"
                                  {printf(", ");}
#line 2031 "parser.tab.c"
    break;

  case 92: /* $@28: %empty  */
#line 174 "parser.y"
                    {printf(" ^ ");}
#line 2037 "parser.tab.c"
    break;

  case 95: /* $@29: %empty  */
#line 178 "parser.y"
              {printf("!");}
#line 2043 "parser.tab.c"
    break;

  case 97: /* $@30: %empty  */
#line 179 "parser.y"
                {printf("-");}
#line 2049 "parser.tab.c"
    break;

  case 103: /* BaseExpression: KW_TRUE  */
#line 188 "parser.y"
                  {printf("true");}
#line 2055 "parser.tab.c"
    break;

  case 104: /* BaseExpression: KW_FALSE  */
#line 189 "parser.y"
                   {printf("false");}
#line 2061 "parser.tab.c"
    break;

  case 105: /* BaseExpression: KW_NULL  */
#line 190 "parser.y"
                  {printf("null");}
#line 2067 "parser.tab.c"
    break;

  case 106: /* BaseExpression: CHAR_LITERAL  */
#line 191 "parser.y"
                       {printf("%s", (yyvsp[0].char_literal));}
#line 2073 "parser.tab.c"
    break;

  case 107: /* BaseExpression: INTEGER  */
#line 192 "parser.y"
                  {printf("%s", (yyvsp[0].integer));}
#line 2079 "parser.tab.c"
    break;

  case 108: /* $@31: %empty  */
#line 193 "parser.y"
                     {printf("(");}
#line 2085 "parser.tab.c"
    break;

  case 109: /* BaseExpression: LEFT_PAREN $@31 Expression RIGHT_PAREN  */
#line 193 "parser.y"
                                                           {printf(")");}
#line 2091 "parser.tab.c"
    break;

  case 110: /* BaseExpression: STRING_CONST  */
#line 194 "parser.y"
                       {printf("%s", (yyvsp[0].string_const));}
#line 2097 "parser.tab.c"
    break;

  case 111: /* FullType: Type LEFT_PAREN2 RIGHT_PAREN2  */
#line 197 "parser.y"
                                      {printf("[] ");}
#line 2103 "parser.tab.c"
    break;

  case 112: /* FullType: Type LEFT_PAREN2 RIGHT_PAREN2 LEFT_PAREN2 RIGHT_PAREN2  */
#line 198 "parser.y"
                                                                 {printf("[][] ");}
#line 2109 "parser.tab.c"
    break;

  case 113: /* FullType: Type  */
#line 199 "parser.y"
               {printf(" ");}
#line 2115 "parser.tab.c"
    break;

  case 114: /* Type: INT  */
#line 202 "parser.y"
            {printf("int");}
#line 2121 "parser.tab.c"
    break;

  case 115: /* Type: CHAR  */
#line 203 "parser.y"
               {printf("char");}
#line 2127 "parser.tab.c"
    break;

  case 116: /* Type: BOOL  */
#line 204 "parser.y"
               {printf("bool");}
#line 2133 "parser.tab.c"
    break;

  case 117: /* $@32: %empty  */
#line 207 "parser.y"
                    {printf("{");}
#line 2139 "parser.tab.c"
    break;

  case 118: /* $@33: %empty  */
#line 207 "parser.y"
                                           {printf("%s", (yyvsp[0].varname));}
#line 2145 "parser.tab.c"
    break;

  case 119: /* Ident: LEFT_PAREN3 $@32 VARNAME $@33 RIGHT_PAREN3  */
#line 207 "parser.y"
                                                                                   {printf("}");}
#line 2151 "parser.tab.c"
    break;


#line 2155 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, scanner, env, tab, need_tab, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, scanner, env, tab, need_tab);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, scanner, env, tab, need_tab);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, env, tab, need_tab, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner, env, tab, need_tab);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, scanner, env, tab, need_tab);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 209 "parser.y"


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
