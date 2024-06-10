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
  YYSYMBOL_FullTypeOrVoid = 58,            /* FullTypeOrVoid  */
  YYSYMBOL_Parameters = 59,                /* Parameters  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_Parameter = 61,                 /* Parameter  */
  YYSYMBOL_Operators = 62,                 /* Operators  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_64_8 = 64,                      /* $@8  */
  YYSYMBOL_Operator = 65,                  /* Operator  */
  YYSYMBOL_DeclOperator = 66,              /* DeclOperator  */
  YYSYMBOL_Decls = 67,                     /* Decls  */
  YYSYMBOL_68_9 = 68,                      /* $@9  */
  YYSYMBOL_Decl = 69,                      /* Decl  */
  YYSYMBOL_70_10 = 70,                     /* $@10  */
  YYSYMBOL_AssignOperator = 71,            /* AssignOperator  */
  YYSYMBOL_72_11 = 72,                     /* $@11  */
  YYSYMBOL_ChooseOperator = 73,            /* ChooseOperator  */
  YYSYMBOL_74_12 = 74,                     /* $@12  */
  YYSYMBOL_75_13 = 75,                     /* $@13  */
  YYSYMBOL_76_14 = 76,                     /* $@14  */
  YYSYMBOL_77_15 = 77,                     /* $@15  */
  YYSYMBOL_FuncCallOperator = 78,          /* FuncCallOperator  */
  YYSYMBOL_79_16 = 79,                     /* $@16  */
  YYSYMBOL_EndFuncOperator = 80,           /* EndFuncOperator  */
  YYSYMBOL_81_17 = 81,                     /* $@17  */
  YYSYMBOL_PredLoopOperator = 82,          /* PredLoopOperator  */
  YYSYMBOL_83_18 = 83,                     /* $@18  */
  YYSYMBOL_PostLoopOperator = 84,          /* PostLoopOperator  */
  YYSYMBOL_85_19 = 85,                     /* $@19  */
  YYSYMBOL_86_20 = 86,                     /* $@20  */
  YYSYMBOL_87_21 = 87,                     /* $@21  */
  YYSYMBOL_ForLoopOperator = 88,           /* ForLoopOperator  */
  YYSYMBOL_89_22 = 89,                     /* $@22  */
  YYSYMBOL_90_23 = 90,                     /* $@23  */
  YYSYMBOL_91_24 = 91,                     /* $@24  */
  YYSYMBOL_Expression = 92,                /* Expression  */
  YYSYMBOL_OrOp = 93,                      /* OrOp  */
  YYSYMBOL_MulOp = 94,                     /* MulOp  */
  YYSYMBOL_AddOp = 95,                     /* AddOp  */
  YYSYMBOL_CmpOp = 96,                     /* CmpOp  */
  YYSYMBOL_AndExpression = 97,             /* AndExpression  */
  YYSYMBOL_98_25 = 98,                     /* $@25  */
  YYSYMBOL_CmpExpression = 99,             /* CmpExpression  */
  YYSYMBOL_FuncCallExpression = 100,       /* FuncCallExpression  */
  YYSYMBOL_101_26 = 101,                   /* $@26  */
  YYSYMBOL_ArithmExpressions = 102,        /* ArithmExpressions  */
  YYSYMBOL_103_27 = 103,                   /* $@27  */
  YYSYMBOL_ArithmExpression = 104,         /* ArithmExpression  */
  YYSYMBOL_Term = 105,                     /* Term  */
  YYSYMBOL_Factor = 106,                   /* Factor  */
  YYSYMBOL_107_28 = 107,                   /* $@28  */
  YYSYMBOL_Power = 108,                    /* Power  */
  YYSYMBOL_109_29 = 109,                   /* $@29  */
  YYSYMBOL_110_30 = 110,                   /* $@30  */
  YYSYMBOL_DataExpression = 111,           /* DataExpression  */
  YYSYMBOL_BaseExpression = 112,           /* BaseExpression  */
  YYSYMBOL_113_31 = 113,                   /* $@31  */
  YYSYMBOL_FullType = 114,                 /* FullType  */
  YYSYMBOL_Type = 115,                     /* Type  */
  YYSYMBOL_Ident = 116,                    /* Ident  */
  YYSYMBOL_117_32 = 117,                   /* $@32  */
  YYSYMBOL_118_33 = 118                    /* $@33  */
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


#line 242 "parser.tab.c"


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
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

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
      65,    66,    69,    70,    70,    73,    76,    76,    77,    77,
      80,    81,    82,    83,    84,    85,    86,    87,    90,    93,
      94,    94,    97,    98,    98,   101,   101,   104,   104,   104,
     104,   105,   105,   108,   108,   111,   111,   112,   115,   115,
     118,   118,   118,   118,   121,   121,   121,   121,   124,   125,
     128,   129,   132,   133,   134,   137,   138,   141,   142,   143,
     144,   145,   146,   149,   150,   150,   153,   154,   157,   158,
     158,   161,   162,   162,   165,   166,   169,   170,   173,   174,
     174,   177,   178,   178,   179,   179,   180,   183,   184,   187,
     188,   189,   190,   191,   192,   193,   193,   194,   197,   198,
     199,   202,   203,   204,   207,   207,   207
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
  "FullTypeOrVoid", "Parameters", "$@6", "Parameter", "Operators", "$@7",
  "$@8", "Operator", "DeclOperator", "Decls", "$@9", "Decl", "$@10",
  "AssignOperator", "$@11", "ChooseOperator", "$@12", "$@13", "$@14",
  "$@15", "FuncCallOperator", "$@16", "EndFuncOperator", "$@17",
  "PredLoopOperator", "$@18", "PostLoopOperator", "$@19", "$@20", "$@21",
  "ForLoopOperator", "$@22", "$@23", "$@24", "Expression", "OrOp", "MulOp",
  "AddOp", "CmpOp", "AndExpression", "$@25", "CmpExpression",
  "FuncCallExpression", "$@26", "ArithmExpressions", "$@27",
  "ArithmExpression", "Term", "Factor", "$@28", "Power", "$@29", "$@30",
  "DataExpression", "BaseExpression", "$@31", "FullType", "Type", "Ident",
  "$@32", "$@33", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-120)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,  -120,  -120,  -120,  -120,    12,  -120,   -18,  -120,   -10,
    -120,  -120,  -120,     8,    -3,    11,  -120,  -120,     0,  -120,
    -120,    32,    23,    34,   -19,    56,    55,  -120,   -18,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,    36,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,    -6,    17,    92,   125,    47,    28,  -120,
      96,   118,  -120,   131,    79,  -120,   113,  -120,    56,   101,
     101,   101,  -120,   101,  -120,  -120,  -120,  -120,  -120,   101,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,   101,  -120,  -120,
     101,  -120,  -120,  -120,   101,  -120,  -120,  -120,  -120,    74,
    -120,  -120,   -15,  -120,    32,  -120,  -120,  -120,   131,   131,
    -120,  -120,    83,    87,    98,  -120,  -120,  -120,   101,  -120,
     101,  -120,    28,  -120,   101,   101,  -120,  -120,   101,   101,
    -120,  -120,  -120,    93,  -120,    39,    87,    50,   106,  -120,
    -120,  -120,   -18,   101,    97,    47,    97,    61,  -120,  -120,
     110,  -120,  -120,  -120,   105,    47,  -120,  -120,   101,  -120,
     -18,   101,   111,  -120,  -120,    47,  -120,    66,  -120,  -120,
      72,  -120
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   111,   112,   113,    11,     0,     2,     0,    10,   110,
       1,     3,   114,     0,     0,     0,     8,     4,   108,   115,
      16,     0,     0,     0,     0,     0,     5,    12,     0,   109,
     116,    18,     9,    94,    92,   100,   101,   102,    45,    50,
     105,   104,   103,   107,    17,    20,    21,    23,    22,    27,
      24,    25,    26,     0,    58,    73,    76,    78,    84,    86,
      88,    91,    97,     0,    99,    13,     0,    15,     0,     0,
       0,     0,    16,     0,    48,    37,    54,    61,    60,     0,
      74,    67,    68,    69,    70,    71,    72,     0,    65,    66,
       0,    62,    64,    63,     0,    89,    35,    98,    99,    28,
      29,    96,    99,    43,     0,     6,    19,    95,    91,     0,
      93,    46,    99,    51,     0,    16,    16,    16,     0,    59,
       0,    77,    85,    87,     0,     0,    30,    33,     0,     0,
      14,    16,    79,     0,   106,     0,    38,     0,     0,    75,
      90,    36,     0,     0,    44,    81,    80,     0,    52,    49,
       0,    42,    55,    31,    32,    34,    82,     7,     0,    39,
       0,     0,     0,    16,    56,    83,    53,     0,    16,    40,
       0,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,   136,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
      48,   -69,  -120,  -120,    86,  -120,  -120,  -120,    18,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,   -66,  -120,  -120,  -120,  -120,    82,  -120,    42,    80,
    -120,    41,  -120,  -119,    81,   -81,  -120,    40,  -120,  -120,
     -17,   -59,  -120,     1,  -120,    -7,  -120,  -120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,    21,    66,   131,    20,     7,    26,   104,
      27,    24,    25,    68,    44,    45,    99,   142,   100,   143,
      46,   125,    47,   116,   150,   163,   117,    48,   128,    49,
      71,    50,   115,    51,    72,   133,   158,    52,   118,   160,
     168,    53,    79,    94,    90,    87,    54,   120,    55,    56,
     129,   144,   161,    57,    58,    59,   124,    60,    70,    69,
     108,    62,    73,   109,     9,    98,    15,    23
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,     8,    97,   113,   101,   111,     8,   114,    61,   145,
     145,    16,    10,   123,   -32,    31,    32,   -32,    64,   -32,
     -32,    67,    28,    12,   155,    74,    63,    75,   -32,    14,
     127,    77,    78,     1,     2,     3,     4,    18,    76,    22,
      91,    92,   165,   140,    17,    93,   135,   136,   137,    97,
     101,    61,   138,     1,     2,     3,   102,    88,    89,   141,
      19,    64,   147,    29,   112,   -47,   112,    33,   -47,    63,
     -47,   -47,   112,    31,   149,    34,    30,     1,     2,     3,
     112,    35,    36,    37,    31,   151,    38,    39,     1,     2,
       3,     4,   162,    40,   167,    31,   157,    12,    65,   170,
      31,   169,    41,    42,    43,    28,    31,   171,    80,   107,
     110,   112,    33,   112,    95,   103,   105,   126,   112,   132,
      34,    31,     1,     2,     3,   148,    35,    36,    37,    81,
      82,    83,    84,    85,    86,   154,   134,   152,    40,   159,
     156,    11,    12,    35,    36,    37,   166,    41,    42,    43,
     127,   112,   130,   164,   106,    40,    35,    36,    37,    12,
     153,   119,   139,    96,    41,    42,    43,   121,    40,     0,
     146,   122,    12,     0,     0,     0,     0,    41,    42,    43
};

static const yytype_int16 yycheck[] =
{
       7,     0,    61,    72,    63,    71,     5,    73,    25,   128,
     129,     3,     0,    94,    29,    34,    35,    32,    25,    34,
      35,    28,    21,    41,   143,    31,    25,    33,    43,    39,
      45,    14,    15,    21,    22,    23,    24,    40,    44,    39,
      12,    13,   161,   124,    36,    17,   115,   116,   117,   108,
     109,    68,   118,    21,    22,    23,    63,    10,    11,   125,
      49,    68,   131,    40,    71,    29,    73,    11,    32,    68,
      34,    35,    79,    34,    35,    19,    42,    21,    22,    23,
      87,    25,    26,    27,    34,    35,    30,    31,    21,    22,
      23,    24,   158,    37,   163,    34,    35,    41,    43,   168,
      34,    35,    46,    47,    48,   104,    34,    35,    16,    69,
      70,   118,    11,   120,    18,    36,     3,    43,   125,    36,
      19,    34,    21,    22,    23,    32,    25,    26,    27,     4,
       5,     6,     7,     8,     9,   142,    38,    31,    37,    29,
      43,     5,    41,    25,    26,    27,    35,    46,    47,    48,
      45,   158,   104,   160,    68,    37,    25,    26,    27,    41,
     142,    79,   120,    45,    46,    47,    48,    87,    37,    -1,
     129,    90,    41,    -1,    -1,    -1,    -1,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    22,    23,    24,    52,    53,    58,   114,   115,
       0,    53,    41,   116,    39,   117,     3,    36,    40,    49,
      57,    54,    39,   118,    62,    63,    59,    61,   114,    40,
      42,    34,    35,    11,    19,    25,    26,    27,    30,    31,
      37,    46,    47,    48,    65,    66,    71,    73,    78,    80,
      82,    84,    88,    92,    97,    99,   100,   104,   105,   106,
     108,   111,   112,   114,   116,    43,    55,   116,    64,   110,
     109,    81,    85,   113,    31,    33,    44,    14,    15,    93,
      16,     4,     5,     6,     7,     8,     9,    96,    10,    11,
      95,    12,    13,    17,    94,    18,    45,   112,   116,    67,
      69,   112,   116,    36,    60,     3,    65,   108,   111,   114,
     108,    92,   116,    62,    92,    83,    74,    77,    89,    97,
      98,   100,   105,   106,   107,    72,    43,    45,    79,   101,
      61,    56,    36,    86,    38,    62,    62,    62,    92,    99,
     106,    92,    68,    70,   102,   104,   102,    62,    32,    35,
      75,    35,    31,    69,   116,   104,    43,    35,    87,    29,
      90,   103,    92,    76,   116,   104,    35,    62,    91,    35,
      62,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    54,    55,    56,    53,    57,    53,
      58,    58,    59,    60,    59,    61,    63,    62,    64,    62,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    67,
      68,    67,    69,    70,    69,    72,    71,    74,    75,    76,
      73,    77,    73,    79,    78,    81,    80,    80,    83,    82,
      85,    86,    87,    84,    89,    90,    91,    88,    92,    92,
      93,    93,    94,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    97,    98,    97,    99,    99,   100,   101,
     100,   102,   103,   102,   104,   104,   105,   105,   106,   107,
     106,   108,   109,   108,   110,   108,   108,   111,   111,   112,
     112,   112,   112,   112,   112,   113,   112,   112,   114,   114,
     114,   115,   115,   115,   117,   118,   116
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     0,     0,    10,     0,     6,
       1,     1,     1,     0,     4,     2,     0,     2,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     4,     1,     0,     4,     0,     4,     0,     0,     0,
       9,     0,     5,     0,     4,     0,     3,     1,     0,     5,
       0,     0,     0,     8,     0,     0,     0,    10,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     3,     1,     0,
       4,     1,     0,     4,     1,     3,     1,     3,     1,     0,
       4,     1,     0,     3,     0,     3,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     3,     5,
       1,     1,     1,     1,     0,     0,     5
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
#line 1739 "parser.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 58 "parser.y"
                                                                     {printf("\n"); tab++; print_tabs(tab);}
#line 1745 "parser.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 58 "parser.y"
                                                                                                                   {printf("= ");}
#line 1751 "parser.tab.c"
    break;

  case 7: /* FuncDecl: FullTypeOrVoid Ident LEFT_ARROW $@1 Parameters $@2 EQUAL $@3 Operators DOT  */
#line 58 "parser.y"
                                                                                                                                                  {printf(".");}
#line 1757 "parser.tab.c"
    break;

  case 8: /* $@4: %empty  */
#line 59 "parser.y"
                                     {printf("= "); need_tab = false; }
#line 1763 "parser.tab.c"
    break;

  case 9: /* FuncDecl: FullTypeOrVoid Ident EQUAL $@4 Operators DOT  */
#line 59 "parser.y"
                                                                                      {printf("."); tab = 0; need_tab = true;}
#line 1769 "parser.tab.c"
    break;

  case 11: /* FullTypeOrVoid: VOID  */
#line 66 "parser.y"
               {printf("void ");}
#line 1775 "parser.tab.c"
    break;

  case 13: /* $@6: %empty  */
#line 70 "parser.y"
                           {printf(", ");}
#line 1781 "parser.tab.c"
    break;

  case 16: /* $@7: %empty  */
#line 76 "parser.y"
        { if (need_tab) {print_tabs(tab);} need_tab = true;}
#line 1787 "parser.tab.c"
    break;

  case 18: /* $@8: %empty  */
#line 77 "parser.y"
                              {printf(";"); printf("\n"); if (need_tab) {print_tabs(tab);} }
#line 1793 "parser.tab.c"
    break;

  case 30: /* $@9: %empty  */
#line 94 "parser.y"
                      {printf(", ");}
#line 1799 "parser.tab.c"
    break;

  case 33: /* $@10: %empty  */
#line 98 "parser.y"
                       {printf(" := ");}
#line 1805 "parser.tab.c"
    break;

  case 35: /* $@11: %empty  */
#line 101 "parser.y"
                             {printf(" := ");}
#line 1811 "parser.tab.c"
    break;

  case 37: /* $@12: %empty  */
#line 104 "parser.y"
                           {printf(" then "); printf("\n"); tab++;}
#line 1817 "parser.tab.c"
    break;

  case 38: /* $@13: %empty  */
#line 104 "parser.y"
                                                                              {printf("\n"); print_tabs(tab-1);}
#line 1823 "parser.tab.c"
    break;

  case 39: /* $@14: %empty  */
#line 104 "parser.y"
                                                                                                                         {printf("else\n");}
#line 1829 "parser.tab.c"
    break;

  case 40: /* ChooseOperator: Expression KW_THEN $@12 Operators $@13 KW_ELSE $@14 Operators DOT  */
#line 104 "parser.y"
                                                                                                                                                           {printf("."); tab--;}
#line 1835 "parser.tab.c"
    break;

  case 41: /* $@15: %empty  */
#line 105 "parser.y"
                             {printf(" then "); printf("\n"); tab++;}
#line 1841 "parser.tab.c"
    break;

  case 42: /* ChooseOperator: Expression KW_THEN $@15 Operators DOT  */
#line 105 "parser.y"
                                                                                    {printf("."); tab--;}
#line 1847 "parser.tab.c"
    break;

  case 43: /* $@16: %empty  */
#line 108 "parser.y"
                         {printf("<-");}
#line 1853 "parser.tab.c"
    break;

  case 45: /* $@17: %empty  */
#line 111 "parser.y"
                  {printf("return ");}
#line 1859 "parser.tab.c"
    break;

  case 47: /* EndFuncOperator: KW_RETURN  */
#line 112 "parser.y"
                    {printf("return");}
#line 1865 "parser.tab.c"
    break;

  case 48: /* $@18: %empty  */
#line 115 "parser.y"
                           {printf(" loop\n"); tab++;}
#line 1871 "parser.tab.c"
    break;

  case 49: /* PredLoopOperator: Expression KW_LOOP $@18 Operators DOT  */
#line 115 "parser.y"
                                                                     {printf("."); tab--;}
#line 1877 "parser.tab.c"
    break;

  case 50: /* $@19: %empty  */
#line 118 "parser.y"
                {printf(" loop\n"); tab++;}
#line 1883 "parser.tab.c"
    break;

  case 51: /* $@20: %empty  */
#line 118 "parser.y"
                                                      {printf("\n");}
#line 1889 "parser.tab.c"
    break;

  case 52: /* $@21: %empty  */
#line 118 "parser.y"
                                                                               {tab--; print_tabs(tab); printf("while ");}
#line 1895 "parser.tab.c"
    break;

  case 53: /* PostLoopOperator: KW_LOOP $@19 Operators $@20 KW_WHILE $@21 Expression DOT  */
#line 118 "parser.y"
                                                                                                                                          {printf(". ");}
#line 1901 "parser.tab.c"
    break;

  case 54: /* $@22: %empty  */
#line 121 "parser.y"
                        {printf(" ~ ");}
#line 1907 "parser.tab.c"
    break;

  case 55: /* $@23: %empty  */
#line 121 "parser.y"
                                                            {printf(" loop "); }
#line 1913 "parser.tab.c"
    break;

  case 56: /* $@24: %empty  */
#line 121 "parser.y"
                                                                                       {printf("\n"); tab++; need_tab = true;}
#line 1919 "parser.tab.c"
    break;

  case 57: /* ForLoopOperator: Expression TILD $@22 Expression KW_LOOP $@23 Ident $@24 Operators DOT  */
#line 121 "parser.y"
                                                                                                                                             {printf("."); tab--;}
#line 1925 "parser.tab.c"
    break;

  case 60: /* OrOp: OR  */
#line 128 "parser.y"
           { printf(" | "); }
#line 1931 "parser.tab.c"
    break;

  case 61: /* OrOp: EXC_OR  */
#line 129 "parser.y"
                 { printf(" @ "); }
#line 1937 "parser.tab.c"
    break;

  case 62: /* MulOp: MUL  */
#line 132 "parser.y"
            { printf(" * "); }
#line 1943 "parser.tab.c"
    break;

  case 63: /* MulOp: DIV  */
#line 133 "parser.y"
              { printf(" / "); }
#line 1949 "parser.tab.c"
    break;

  case 64: /* MulOp: REM_OF_DIV  */
#line 134 "parser.y"
                     { printf(" %% "); }
#line 1955 "parser.tab.c"
    break;

  case 65: /* AddOp: PLUS  */
#line 137 "parser.y"
             { printf(" + "); }
#line 1961 "parser.tab.c"
    break;

  case 66: /* AddOp: MINUS  */
#line 138 "parser.y"
                { printf(" - "); }
#line 1967 "parser.tab.c"
    break;

  case 67: /* CmpOp: EQUAL_EQUAL  */
#line 141 "parser.y"
                    {printf(" == ");}
#line 1973 "parser.tab.c"
    break;

  case 68: /* CmpOp: NOT_EQUAL  */
#line 142 "parser.y"
                    {printf(" != ");}
#line 1979 "parser.tab.c"
    break;

  case 69: /* CmpOp: LESS  */
#line 143 "parser.y"
               {printf(" < ");}
#line 1985 "parser.tab.c"
    break;

  case 70: /* CmpOp: GREATER  */
#line 144 "parser.y"
                  {printf(" > ");}
#line 1991 "parser.tab.c"
    break;

  case 71: /* CmpOp: LESS_EQUAL  */
#line 145 "parser.y"
                     {printf(" <= ");}
#line 1997 "parser.tab.c"
    break;

  case 72: /* CmpOp: GREATER_EQUAL  */
#line 146 "parser.y"
                        {printf(" >= ");}
#line 2003 "parser.tab.c"
    break;

  case 74: /* $@25: %empty  */
#line 150 "parser.y"
                            {printf(" & ");}
#line 2009 "parser.tab.c"
    break;

  case 79: /* $@26: %empty  */
#line 158 "parser.y"
                           {printf("<- ");}
#line 2015 "parser.tab.c"
    break;

  case 82: /* $@27: %empty  */
#line 162 "parser.y"
                                  {printf(", ");}
#line 2021 "parser.tab.c"
    break;

  case 89: /* $@28: %empty  */
#line 174 "parser.y"
                    {printf(" ^ ");}
#line 2027 "parser.tab.c"
    break;

  case 92: /* $@29: %empty  */
#line 178 "parser.y"
              {printf("!");}
#line 2033 "parser.tab.c"
    break;

  case 94: /* $@30: %empty  */
#line 179 "parser.y"
                {printf("-");}
#line 2039 "parser.tab.c"
    break;

  case 100: /* BaseExpression: KW_TRUE  */
#line 188 "parser.y"
                  {printf("true");}
#line 2045 "parser.tab.c"
    break;

  case 101: /* BaseExpression: KW_FALSE  */
#line 189 "parser.y"
                   {printf("false");}
#line 2051 "parser.tab.c"
    break;

  case 102: /* BaseExpression: KW_NULL  */
#line 190 "parser.y"
                  {printf("null");}
#line 2057 "parser.tab.c"
    break;

  case 103: /* BaseExpression: CHAR_LITERAL  */
#line 191 "parser.y"
                       {printf("%s", (yyvsp[0].char_literal));}
#line 2063 "parser.tab.c"
    break;

  case 104: /* BaseExpression: INTEGER  */
#line 192 "parser.y"
                  {printf("%s", (yyvsp[0].integer));}
#line 2069 "parser.tab.c"
    break;

  case 105: /* $@31: %empty  */
#line 193 "parser.y"
                     {printf("(");}
#line 2075 "parser.tab.c"
    break;

  case 106: /* BaseExpression: LEFT_PAREN $@31 Expression RIGHT_PAREN  */
#line 193 "parser.y"
                                                           {printf(")");}
#line 2081 "parser.tab.c"
    break;

  case 107: /* BaseExpression: STRING_CONST  */
#line 194 "parser.y"
                       {printf("%s", (yyvsp[0].string_const));}
#line 2087 "parser.tab.c"
    break;

  case 108: /* FullType: Type LEFT_PAREN2 RIGHT_PAREN2  */
#line 197 "parser.y"
                                      {printf("[] ");}
#line 2093 "parser.tab.c"
    break;

  case 109: /* FullType: Type LEFT_PAREN2 RIGHT_PAREN2 LEFT_PAREN2 RIGHT_PAREN2  */
#line 198 "parser.y"
                                                                 {printf("[][] ");}
#line 2099 "parser.tab.c"
    break;

  case 110: /* FullType: Type  */
#line 199 "parser.y"
               {printf(" ");}
#line 2105 "parser.tab.c"
    break;

  case 111: /* Type: INT  */
#line 202 "parser.y"
            {printf("int");}
#line 2111 "parser.tab.c"
    break;

  case 112: /* Type: CHAR  */
#line 203 "parser.y"
               {printf("char");}
#line 2117 "parser.tab.c"
    break;

  case 113: /* Type: BOOL  */
#line 204 "parser.y"
               {printf("bool");}
#line 2123 "parser.tab.c"
    break;

  case 114: /* $@32: %empty  */
#line 207 "parser.y"
                    {printf("{");}
#line 2129 "parser.tab.c"
    break;

  case 115: /* $@33: %empty  */
#line 207 "parser.y"
                                           {printf("%s", (yyvsp[0].varname));}
#line 2135 "parser.tab.c"
    break;

  case 116: /* Ident: LEFT_PAREN3 $@32 VARNAME $@33 RIGHT_PAREN3  */
#line 207 "parser.y"
                                                                                   {printf("}");}
#line 2141 "parser.tab.c"
    break;


#line 2145 "parser.tab.c"

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
