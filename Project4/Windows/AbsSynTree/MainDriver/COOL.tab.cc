/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

/* Line 371 of yacc.c  */
#line 68 "COOL.tab.cc"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "COOL.tab.hh".  */
#ifndef YY_YY_COOL_TAB_HH_INCLUDED
# define YY_YY_COOL_TAB_HH_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 5 "COOL.yy"

#include <iostream>
#include "ErrorMsg.h"
#include "StringTab.h"
#include "Absyn.h"

using namespace absyn;


/* Line 387 of yacc.c  */
#line 110 "COOL.tab.cc"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STR_CONST = 258,
     TYPEID = 259,
     OBJECTID = 260,
     INT_CONST = 261,
     BOOL_CONST = 262,
     CLASS = 263,
     IF = 264,
     ELSE = 265,
     FI = 266,
     LET = 267,
     IN = 268,
     INHERITS = 269,
     THEN = 270,
     WHILE = 271,
     LOOP = 272,
     POOL = 273,
     CASE = 274,
     ESAC = 275,
     OF = 276,
     NOT = 277,
     NEW = 278,
     ISVOID = 279,
     ASSIGN = 280,
     LE = 281,
     DARROW = 282,
     LET_STMT = 283
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 14 "COOL.yy"

	Symbol			symbol;
	bool			boolean;
	Program			program;
	Class_			class_;
	Classes			classes;
	Feature			feature;
	Features		features;
	Formal			formal;
	Formals			formals;
	Branch			branch;
	Branches		branches;
	Expression		expression;
	Expressions		expressions;


/* Line 387 of yacc.c  */
#line 170 "COOL.tab.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_COOL_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */
/* Line 390 of yacc.c  */
#line 30 "COOL.yy"

extern string curr_filename;

int yylex(void);
void yyerror(char *s);

template<typename Item>
List<Item>* single_list(Item i);

template<typename Item>
List<Item>* pair_list(Item head, List<Item>* rest);

Program root;

/* Line 390 of yacc.c  */
#line 226 "COOL.tab.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   261

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    32,    31,    44,    30,    36,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    40,
      28,    29,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,    34,     2,     2,     2,
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
      25,    26,    27,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    17,    26,    27,    29,
      32,    36,    46,    50,    56,    57,    59,    61,    65,    69,
      73,    80,    89,    94,   102,   108,   112,   115,   121,   124,
     127,   130,   133,   137,   141,   145,   149,   153,   157,   161,
     165,   167,   169,   171,   173,   174,   176,   178,   182,   185,
     189,   193,   197,   201,   207,   209,   212
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    48,    -1,    48,    47,    -1,
       8,     4,    38,    49,    39,    40,    -1,     8,     4,    14,
       4,    38,    49,    39,    40,    -1,    -1,    50,    -1,    51,
      40,    -1,    51,    40,    50,    -1,     5,    41,    52,    42,
      43,     4,    38,    55,    39,    -1,     5,    43,     4,    -1,
       5,    43,     4,    25,    55,    -1,    -1,    53,    -1,    54,
      -1,    54,    44,    53,    -1,     5,    43,     4,    -1,     5,
      25,    55,    -1,    55,    36,     5,    41,    56,    42,    -1,
      55,    35,     4,    36,     5,    41,    56,    42,    -1,     5,
      41,    56,    42,    -1,     9,    55,    15,    55,    10,    55,
      11,    -1,    16,    55,    17,    55,    18,    -1,    38,    58,
      39,    -1,    12,    59,    -1,    19,    55,    21,    61,    20,
      -1,    23,     4,    -1,    24,    55,    -1,    34,    55,    -1,
      22,    55,    -1,    55,    31,    55,    -1,    55,    30,    55,
      -1,    55,    32,    55,    -1,    55,    33,    55,    -1,    55,
      28,    55,    -1,    55,    26,    55,    -1,    55,    29,    55,
      -1,    41,    55,    42,    -1,     5,    -1,     6,    -1,     3,
      -1,     7,    -1,    -1,    57,    -1,    55,    -1,    55,    44,
      57,    -1,    55,    40,    -1,    55,    40,    58,    -1,    60,
      13,    55,    -1,    60,    44,    59,    -1,     5,    43,     4,
      -1,     5,    43,     4,    25,    55,    -1,    62,    -1,    62,
      61,    -1,     5,    43,     4,    27,    55,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    89,    91,    97,   101,   110,   111,   117,
     119,   125,   127,   129,   136,   137,   143,   145,   150,   157,
     161,   165,   169,   177,   180,   184,   188,   192,   196,   200,
     204,   209,   213,   215,   217,   219,   223,   225,   227,   231,
     235,   237,   239,   241,   248,   249,   255,   257,   263,   265,
     275,   283,   294,   296,   302,   304,   309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STR_CONST", "TYPEID", "OBJECTID",
  "INT_CONST", "BOOL_CONST", "CLASS", "IF", "ELSE", "FI", "LET", "IN",
  "INHERITS", "THEN", "WHILE", "LOOP", "POOL", "CASE", "ESAC", "OF", "NOT",
  "NEW", "ISVOID", "ASSIGN", "LE", "DARROW", "'<'", "'='", "'-'", "'+'",
  "'*'", "'/'", "'~'", "'@'", "'.'", "LET_STMT", "'{'", "'}'", "';'",
  "'('", "')'", "':'", "','", "$accept", "program", "class_list", "class",
  "optional_feature_list", "feature_list", "feature",
  "optional_formal_list", "formal_list", "formal", "expr",
  "optional_arg_list", "arg_list", "expr_seq", "let_list", "let_binding",
  "case_branch_list", "case_branch", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    61,
      45,    43,    42,    47,   126,    64,    46,   283,   123,   125,
      59,    40,    41,    58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    51,    52,    52,    53,    53,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     8,     0,     1,     2,
       3,     9,     3,     5,     0,     1,     1,     3,     3,     3,
       6,     8,     4,     7,     5,     3,     2,     5,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     0,     1,     1,     3,     2,     3,
       3,     3,     3,     5,     1,     2,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,     0,     7,
       0,     0,     0,     8,     0,     7,    14,     0,     0,     9,
       0,     0,     0,    15,    16,    12,     5,    10,     0,     0,
       0,     0,     0,     6,    18,     0,    17,    42,    40,    41,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,    44,     0,     0,    26,     0,     0,
       0,    31,    28,    29,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    46,
       0,    45,     0,     0,     0,     0,     0,     0,    48,    25,
      39,    37,    36,    38,    33,    32,    34,    35,     0,     0,
       0,     0,    22,     0,    52,    50,    51,     0,     0,     0,
      54,    49,     0,    44,    11,    47,     0,     0,    24,     0,
      27,    55,     0,     0,     0,    53,     0,    44,    20,    23,
       0,     0,     0,    21,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    12,    13,    14,    22,    23,    24,
      79,    80,    81,    66,    57,    58,   109,   110
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -100
static const yytype_int16 yypact[] =
{
      -3,     6,     2,  -100,    -3,    -7,  -100,  -100,    31,    43,
      13,   -35,    10,  -100,    20,    43,    48,    58,    23,    43,
      26,    24,    27,  -100,    22,    45,  -100,  -100,    32,    69,
      34,    48,    52,  -100,  -100,    74,  -100,  -100,   -22,  -100,
    -100,    52,    75,    52,    52,    52,    77,    52,    52,    52,
      52,   214,    41,    52,    52,    90,    40,  -100,   -12,   107,
     165,   214,  -100,    -2,    -2,   176,    49,   148,    52,    52,
      52,    52,    52,    52,    52,    83,    84,    52,   214,   118,
      50,  -100,    52,    87,    52,    75,    52,    89,    52,  -100,
    -100,   225,   225,   225,    11,    11,    -2,    -2,    59,    55,
     202,    52,  -100,    -6,    85,  -100,  -100,   137,    65,    91,
      89,  -100,   104,    52,  -100,  -100,    52,    52,  -100,   108,
    -100,  -100,    72,    73,    71,   214,   100,    52,  -100,  -100,
      52,    86,   189,  -100,  -100
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -100,  -100,   110,  -100,   102,   111,  -100,  -100,    98,  -100,
     -32,   -99,    30,    44,    56,  -100,    35,  -100
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      51,    84,     6,    53,   116,     1,    16,     8,    17,    55,
       5,    59,    60,    61,   123,    63,    64,    65,    67,    54,
      68,    78,    69,    70,    71,    72,    73,    74,   131,    75,
      76,     9,    85,    75,    76,    10,    91,    92,    93,    94,
      95,    96,    97,    73,    74,   100,    75,    76,    11,    18,
     103,    15,   105,    21,   107,    37,    65,    38,    39,    40,
      19,    41,    25,    26,    42,    28,    31,    29,    43,    30,
      32,    44,    33,    34,    45,    46,    47,    35,    52,    77,
      56,    62,   129,    83,   124,   125,    48,    98,    89,    99,
      49,   104,   102,    50,   108,   112,   113,    68,   132,    69,
      70,    71,    72,    73,    74,    82,    75,    76,   119,   122,
     117,   120,   126,   127,     7,   128,    68,    20,    69,    70,
      71,    72,    73,    74,    86,    75,    76,   130,   133,    36,
      27,   115,   111,    68,     0,    69,    70,    71,    72,    73,
      74,   106,    75,    76,    68,   121,    69,    70,    71,    72,
      73,    74,     0,    75,    76,   118,     0,     0,     0,     0,
       0,     0,   101,    68,     0,    69,    70,    71,    72,    73,
      74,     0,    75,    76,    68,     0,    69,    70,    71,    72,
      73,    74,     0,    75,    76,     0,    87,     0,     0,     0,
      90,    68,     0,    69,    70,    71,    72,    73,    74,     0,
      75,    76,    68,     0,    69,    70,    71,    72,    73,    74,
       0,    75,    76,     0,     0,    68,    88,    69,    70,    71,
      72,    73,    74,     0,    75,    76,     0,     0,    68,   134,
      69,    70,    71,    72,    73,    74,     0,    75,    76,     0,
      68,   114,    69,    70,    71,    72,    73,    74,     0,    75,
      76,    -1,     0,    -1,    -1,    71,    72,    73,    74,     0,
      75,    76
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-100)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

static const yytype_int16 yycheck[] =
{
      32,    13,     0,    25,    10,     8,    41,    14,    43,    41,
       4,    43,    44,    45,   113,    47,    48,    49,    50,    41,
      26,    53,    28,    29,    30,    31,    32,    33,   127,    35,
      36,    38,    44,    35,    36,     4,    68,    69,    70,    71,
      72,    73,    74,    32,    33,    77,    35,    36,     5,    39,
      82,    38,    84,     5,    86,     3,    88,     5,     6,     7,
      40,     9,     4,    40,    12,    39,    44,    43,    16,    42,
      25,    19,    40,     4,    22,    23,    24,    43,     4,    38,
       5,     4,    11,    43,   116,   117,    34,     4,    39,     5,
      38,     4,    42,    41,     5,    36,    41,    26,   130,    28,
      29,    30,    31,    32,    33,    15,    35,    36,    43,     5,
      25,    20,     4,    41,     4,    42,    26,    15,    28,    29,
      30,    31,    32,    33,    17,    35,    36,    27,    42,    31,
      19,   101,    88,    26,    -1,    28,    29,    30,    31,    32,
      33,    85,    35,    36,    26,   110,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    26,    -1,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    26,    -1,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    21,    -1,    -1,    -1,
      42,    26,    -1,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    26,    -1,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    -1,    -1,    26,    40,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    -1,    -1,    26,    40,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    -1,
      26,    39,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    26,    -1,    28,    29,    30,    31,    32,    33,    -1,
      35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    46,    47,    48,     4,     0,    47,    14,    38,
       4,     5,    49,    50,    51,    38,    41,    43,    39,    40,
      49,     5,    52,    53,    54,     4,    40,    50,    39,    43,
      42,    44,    25,    40,     4,    43,    53,     3,     5,     6,
       7,     9,    12,    16,    19,    22,    23,    24,    34,    38,
      41,    55,     4,    25,    41,    55,     5,    59,    60,    55,
      55,    55,     4,    55,    55,    55,    58,    55,    26,    28,
      29,    30,    31,    32,    33,    35,    36,    38,    55,    55,
      56,    57,    15,    43,    13,    44,    17,    21,    40,    39,
      42,    55,    55,    55,    55,    55,    55,    55,     4,     5,
      55,    44,    42,    55,     4,    55,    59,    55,     5,    61,
      62,    58,    36,    41,    39,    57,    10,    25,    18,    43,
      20,    61,     5,    56,    55,    55,     4,    41,    42,    11,
      27,    56,    55,    42,    40
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
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
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 85 "COOL.yy"
    { root = new Program_class((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yyvsp[(1) - (1)].classes)); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 90 "COOL.yy"
    { (yyval.classes) = single_list((yyvsp[(1) - (1)].class_)); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 92 "COOL.yy"
    { (yyval.classes) = pair_list((yyvsp[(1) - (2)].class_), (yyvsp[(2) - (2)].classes)); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 98 "COOL.yy"
    { (yyval.class_) = new Class_class((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,
					stringtable.add_string(curr_filename),
					(yyvsp[(2) - (6)].symbol), idtable.add_string("Object"), (yyvsp[(4) - (6)].features)); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 102 "COOL.yy"
    { (yyval.class_) = new Class_class((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column,
					stringtable.add_string(curr_filename),
					(yyvsp[(2) - (8)].symbol), (yyvsp[(4) - (8)].symbol), (yyvsp[(6) - (8)].features)); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 110 "COOL.yy"
    { (yyval.features) = nullptr; }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 112 "COOL.yy"
    { (yyval.features) = (yyvsp[(1) - (1)].features); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 118 "COOL.yy"
    { (yyval.features) = single_list((yyvsp[(1) - (2)].feature)); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 120 "COOL.yy"
    { (yyval.features) = pair_list((yyvsp[(1) - (3)].feature), (yyvsp[(3) - (3)].features)); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 126 "COOL.yy"
    { (yyval.feature) = new Method((yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column, (yyvsp[(1) - (9)].symbol), (yyvsp[(3) - (9)].formals), (yyvsp[(6) - (9)].symbol), (yyvsp[(8) - (9)].expression)); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 128 "COOL.yy"
    { (yyval.feature) = new Attr((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol), nullptr); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 130 "COOL.yy"
    { (yyval.feature) = new Attr((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yyvsp[(1) - (5)].symbol), (yyvsp[(3) - (5)].symbol), (yyvsp[(5) - (5)].expression)); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 136 "COOL.yy"
    { (yyval.formals) = nullptr; }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 138 "COOL.yy"
    { (yyval.formals) = (yyvsp[(1) - (1)].formals); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 144 "COOL.yy"
    { (yyval.formals) = single_list((yyvsp[(1) - (1)].formal)); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 146 "COOL.yy"
    { (yyval.formals) = pair_list((yyvsp[(1) - (3)].formal), (yyvsp[(3) - (3)].formals)); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 151 "COOL.yy"
    { (yyval.formal) = new Formal_class((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol)); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 158 "COOL.yy"
    { (yyval.expression) = new AssignExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].expression)); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 162 "COOL.yy"
    { (yyval.expression) = new CallExp((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, (yyvsp[(1) - (6)].expression), (yyvsp[(3) - (6)].symbol), (yyvsp[(5) - (6)].expressions)); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 166 "COOL.yy"
    { (yyval.expression) = new StaticCallExp((yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, (yyvsp[(1) - (8)].expression), (yyvsp[(3) - (8)].symbol), (yyvsp[(5) - (8)].symbol), (yyvsp[(7) - (8)].expressions)); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 170 "COOL.yy"
    {
				Expression self_obj = new absyn::ObjectExp((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column,
									idtable.add_string("self"));
				(yyval.expression) = new CallExp((yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, self_obj, (yyvsp[(1) - (4)].symbol), (yyvsp[(3) - (4)].expressions));
			}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 178 "COOL.yy"
    { (yyval.expression) = new IfExp((yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column, (yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].expression), (yyvsp[(6) - (7)].expression)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 181 "COOL.yy"
    { (yyval.expression) = new WhileExp((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].expression)); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 185 "COOL.yy"
    { (yyval.expression) = new BlockExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(2) - (3)].expressions)); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 189 "COOL.yy"
    { (yyval.expression) = (yyvsp[(2) - (2)].expression); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 193 "COOL.yy"
    { (yyval.expression) = new CaseExp((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].branches)); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 197 "COOL.yy"
    { (yyval.expression) = new NewExp((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yyvsp[(2) - (2)].symbol)); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 201 "COOL.yy"
    { (yyval.expression) = new IsvoidExp((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yyvsp[(2) - (2)].expression)); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 205 "COOL.yy"
    { (yyval.expression) = new OpExp((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column,
					new IntExp((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, inttable.add_int(0)),
					OpExp::MINUS, (yyvsp[(2) - (2)].expression)); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 210 "COOL.yy"
    { (yyval.expression) = new NotExp((yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yyvsp[(2) - (2)].expression)); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 214 "COOL.yy"
    { (yyval.expression) = new OpExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].expression), OpExp::PLUS, (yyvsp[(3) - (3)].expression)); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 216 "COOL.yy"
    { (yyval.expression) = new OpExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].expression), OpExp::MINUS, (yyvsp[(3) - (3)].expression)); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 218 "COOL.yy"
    { (yyval.expression) = new OpExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].expression), OpExp::MUL, (yyvsp[(3) - (3)].expression)); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 220 "COOL.yy"
    { (yyval.expression) = new OpExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].expression), OpExp::DIV, (yyvsp[(3) - (3)].expression)); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 224 "COOL.yy"
    { (yyval.expression) = new OpExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].expression), OpExp::LT, (yyvsp[(3) - (3)].expression)); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 226 "COOL.yy"
    { (yyval.expression) = new OpExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].expression), OpExp::LE, (yyvsp[(3) - (3)].expression)); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 228 "COOL.yy"
    { (yyval.expression) = new OpExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].expression), OpExp::EQ, (yyvsp[(3) - (3)].expression)); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 232 "COOL.yy"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 236 "COOL.yy"
    { (yyval.expression) = new ObjectExp((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yyvsp[(1) - (1)].symbol)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 238 "COOL.yy"
    { (yyval.expression) = new IntExp((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yyvsp[(1) - (1)].symbol)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 240 "COOL.yy"
    { (yyval.expression) = new StringExp((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yyvsp[(1) - (1)].symbol)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 242 "COOL.yy"
    { (yyval.expression) = new BoolExp((yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yyvsp[(1) - (1)].boolean)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 248 "COOL.yy"
    { (yyval.expressions) = nullptr; }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 250 "COOL.yy"
    { (yyval.expressions) = (yyvsp[(1) - (1)].expressions); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 256 "COOL.yy"
    { (yyval.expressions) = single_list((yyvsp[(1) - (1)].expression)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 258 "COOL.yy"
    { (yyval.expressions) = pair_list((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expressions)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 264 "COOL.yy"
    { (yyval.expressions) = single_list((yyvsp[(1) - (2)].expression)); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 266 "COOL.yy"
    { (yyval.expressions) = pair_list((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expressions)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 276 "COOL.yy"
    {
				LetExp* let = dynamic_cast<LetExp*>((yyvsp[(1) - (3)].expression));
				(yyval.expression) = new LetExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,
						let->getVarName(), let->getVarType(),
						const_cast<Expression>(let->getInit()), (yyvsp[(3) - (3)].expression));
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 284 "COOL.yy"
    {
				LetExp* let = dynamic_cast<LetExp*>((yyvsp[(1) - (3)].expression));
				(yyval.expression) = new LetExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column,
						let->getVarName(), let->getVarType(),
						const_cast<Expression>(let->getInit()), (yyvsp[(3) - (3)].expression));
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 295 "COOL.yy"
    { (yyval.expression) = new LetExp((yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol), nullptr, nullptr); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 297 "COOL.yy"
    { (yyval.expression) = new LetExp((yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yyvsp[(1) - (5)].symbol), (yyvsp[(3) - (5)].symbol), (yyvsp[(5) - (5)].expression), nullptr); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 303 "COOL.yy"
    { (yyval.branches) = single_list((yyvsp[(1) - (1)].branch)); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 305 "COOL.yy"
    { (yyval.branches) = pair_list((yyvsp[(1) - (2)].branch), (yyvsp[(2) - (2)].branches)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 310 "COOL.yy"
    { (yyval.branch) = new Branch_class((yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, (yyvsp[(1) - (6)].symbol), (yyvsp[(3) - (6)].symbol), (yyvsp[(5) - (6)].expression)); }
    break;


/* Line 1792 of yacc.c  */
#line 2017 "COOL.tab.cc"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 313 "COOL.yy"


#include <FlexLexer.h>
extern yyFlexLexer lexer;

void yyerror(char *s)
{
	extern ErrorMsg errormsg;
	errormsg.error(yylloc.first_line, yylloc.first_column, s);
}

int yylex(void)
{
	return lexer.yylex();
}

template<typename Item>
List<Item>* single_list(Item i)
{
	return new List<Item>(i, nullptr);
}

template<typename Item>
List<Item>* pair_list(Item head, List<Item>* rest)
{
	return new List<Item>(head, rest);
}
