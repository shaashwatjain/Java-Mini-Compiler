/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gram-2.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "header.c"
	void yyerror(const char *);
	#define YYSTYPE YACC
	FILE *yyin;
	int yylex();
	FILE* fp;
	int ln = 1, tn = 1;
	char* newLabel();
	char* newTemp();
	char* cont;
	char* br;
	char* sw;
	char* snxt;
	char* swt;
	char* tru;
	char* fals;
	extern int line;

#line 93 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_IMPORT = 258,
    T_CLASS = 259,
    T_PUBLIC = 260,
    T_PRIVATE = 261,
    T_PROTECTED = 262,
    T_STATIC = 263,
    T_FINAL = 264,
    T_VOID = 265,
    T_INT = 266,
    T_CHAR = 267,
    T_DOUBLE = 268,
    T_FOR = 269,
    T_SWITCH = 270,
    T_CASE = 271,
    T_DEFAULT = 272,
    T_BREAK = 273,
    T_CONTINUE = 274,
    T_RETURN = 275,
    T_NEW = 276,
    T_INC = 277,
    T_DEC = 278,
    T_SHORTHANDADD = 279,
    T_SHORTHANDSUB = 280,
    T_SHORTHANDMUL = 281,
    T_SHORTHANDDIV = 282,
    T_SHORTHANDAND = 283,
    T_SHORTHANDORE = 284,
    T_SHORTHANDCAR = 285,
    T_SHORTHANDMOD = 286,
    T_OROR = 287,
    T_ANDAND = 288,
    T_EQCOMP = 289,
    T_NOTEQUAL = 290,
    T_GREATEREQ = 291,
    T_LESSEREQ = 292,
    T_LEFTSHIFT = 293,
    T_RIGHTSHIFT = 294,
    T_NUM = 295,
    T_ID = 296
  };
#endif
/* Tokens.  */
#define T_IMPORT 258
#define T_CLASS 259
#define T_PUBLIC 260
#define T_PRIVATE 261
#define T_PROTECTED 262
#define T_STATIC 263
#define T_FINAL 264
#define T_VOID 265
#define T_INT 266
#define T_CHAR 267
#define T_DOUBLE 268
#define T_FOR 269
#define T_SWITCH 270
#define T_CASE 271
#define T_DEFAULT 272
#define T_BREAK 273
#define T_CONTINUE 274
#define T_RETURN 275
#define T_NEW 276
#define T_INC 277
#define T_DEC 278
#define T_SHORTHANDADD 279
#define T_SHORTHANDSUB 280
#define T_SHORTHANDMUL 281
#define T_SHORTHANDDIV 282
#define T_SHORTHANDAND 283
#define T_SHORTHANDORE 284
#define T_SHORTHANDCAR 285
#define T_SHORTHANDMOD 286
#define T_OROR 287
#define T_ANDAND 288
#define T_EQCOMP 289
#define T_NOTEQUAL 290
#define T_GREATEREQ 291
#define T_LESSEREQ 292
#define T_LEFTSHIFT 293
#define T_RIGHTSHIFT 294
#define T_NUM 295
#define T_ID 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,     2,     2,    60,    56,     2,
      47,    48,    43,    57,    49,    58,    42,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    44,
      61,    51,    62,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    54,    46,    64,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    28,    28,    29,    33,    37,    41,    42,    43,    47,
      51,    52,    56,    57,    58,    59,    63,    64,    68,    69,
      73,    77,    78,    79,    83,    87,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    91,    92,    92,    92,
      93,    94,    95,    96,   100,   100,   100,   101,   105,   106,
     110,   111,   115,   116,   117,   121,   122,   123,   127,   128,
     129,   130,   134,   135,   136,   137,   141,   142,   143,   147,
     148,   149,   153,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   170,   171,   172,   173,   174,   175,   176,   177,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     194,   195,   196,   197,   198,   199,   203,   204,   208,   209,
     210,   214,   215,   216,   217,   221,   222,   223
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IMPORT", "T_CLASS", "T_PUBLIC",
  "T_PRIVATE", "T_PROTECTED", "T_STATIC", "T_FINAL", "T_VOID", "T_INT",
  "T_CHAR", "T_DOUBLE", "T_FOR", "T_SWITCH", "T_CASE", "T_DEFAULT",
  "T_BREAK", "T_CONTINUE", "T_RETURN", "T_NEW", "T_INC", "T_DEC",
  "T_SHORTHANDADD", "T_SHORTHANDSUB", "T_SHORTHANDMUL", "T_SHORTHANDDIV",
  "T_SHORTHANDAND", "T_SHORTHANDORE", "T_SHORTHANDCAR", "T_SHORTHANDMOD",
  "T_OROR", "T_ANDAND", "T_EQCOMP", "T_NOTEQUAL", "T_GREATEREQ",
  "T_LESSEREQ", "T_LEFTSHIFT", "T_RIGHTSHIFT", "T_NUM", "T_ID", "'.'",
  "'*'", "';'", "'{'", "'}'", "'('", "')'", "','", "':'", "'='", "'['",
  "']'", "'|'", "'^'", "'&'", "'+'", "'-'", "'/'", "'%'", "'<'", "'>'",
  "'!'", "'~'", "$accept", "CompilationUnit", "ImportDec", "ClassDec",
  "ClassBody", "GlobVarDec", "MethodDec", "Modifier", "Modifier1",
  "Modifier2", "Params", "ParamList", "Block", "Statement", "$@1", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "SwitchBlock", "@10",
  "$@11", "SwitchLabel", "VarDec", "DecIdenList", "ArrDec", "ArrList",
  "ArrInit", "ArrExp", "Type", "Assign", "AssignOp", "InfixOp", "InfixOp1",
  "PrefixOp", "PostfixOp", "Expression", "Expr", "Epr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    46,    42,    59,   123,   125,    40,    41,    44,
      58,    61,    91,    93,   124,    94,    38,    43,    45,    47,
      37,    60,    62,    33,   126
};
# endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     149,   -29,    26,    26,    26,    37,  -161,    38,   149,  -161,
      50,  -161,  -161,     6,  -161,  -161,  -161,  -161,  -161,  -161,
      53,    59,    69,    62,     1,    78,    82,     1,     1,    55,
      85,  -161,  -161,  -161,    89,  -161,  -161,  -161,  -161,    94,
    -161,    90,    52,    66,    66,    95,    75,    96,    93,  -161,
     112,   113,   -20,  -161,  -161,  -161,   110,    75,  -161,  -161,
    -161,  -161,  -161,    15,   114,   163,    87,  -161,   122,   120,
     122,    75,  -161,    75,   123,    87,   128,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,    75,    75,  -161,  -161,  -161,
      72,  -161,    66,  -161,   114,   124,  -161,  -161,  -161,  -161,
    -161,   126,   127,   131,   132,    75,   183,   134,    72,    72,
      72,   119,   -15,    72,  -161,  -161,   130,  -161,    75,  -161,
    -161,   139,   137,    17,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,    75,    44,
     133,  -161,    75,    66,  -161,    72,    72,    72,   136,   138,
     140,   150,   -11,   151,  -161,   148,   143,  -161,  -161,  -161,
     152,   162,  -161,    56,   141,   173,  -161,    75,    22,   171,
     175,   179,   208,   177,   187,   212,   195,  -161,   101,   184,
    -161,    66,   188,  -161,    66,   189,   194,    75,  -161,   196,
    -161,  -161,   191,   220,   192,   224,    75,  -161,  -161,   197,
      75,    66,    75,    66,  -161,    72,    72,   193,   198,   199,
     201,   200,  -161,  -161,   205,    75,   207,    75,   122,   101,
    -161,   202,  -161,   203,  -161,  -161,   206,   209,    72,    75,
      75,  -161,   204,   210,   215,   216,  -161,  -161
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      19,     0,    19,    19,    19,    19,    18,     0,    19,     3,
       0,    15,    17,     0,    12,    13,    14,    16,     1,     2,
       0,     0,     0,     0,    19,     0,     0,    19,    19,     0,
       0,     5,     6,     7,     0,    69,    71,    70,     9,     0,
       4,     0,    54,    23,    23,     0,     0,     0,     0,    20,
       0,     0,    54,   100,   101,   117,    68,     0,   104,   105,
     102,   103,   116,     0,    54,   108,   112,    51,     0,    21,
       0,     0,    53,     0,     0,   111,     0,    90,    91,    92,
      93,    97,    96,    98,    99,    87,    82,    83,    84,    85,
      86,    88,    89,    94,    95,     0,     0,   106,   107,   113,
      43,    11,    23,    10,    54,     0,   115,   114,    50,   109,
     110,     0,     0,     0,     0,     0,    61,     0,    43,    43,
      43,     0,     0,    43,    22,    52,    66,    30,     0,    26,
      28,     0,     0,     0,    57,    24,    40,    41,    42,    74,
      75,    76,    77,    78,    79,    80,    81,    73,     0,    54,
       0,    25,     0,     0,    37,    43,    43,    43,    60,     0,
       0,     0,     0,     0,    31,     0,     0,    27,    29,    36,
       0,     0,    72,    61,     0,     0,    67,     0,    54,     0,
      58,    61,     0,     0,     0,     0,     0,    32,    47,     0,
      56,     0,     0,    55,     0,     0,     0,     0,    49,     0,
      44,    59,     0,     0,     0,     0,     0,    48,    38,     0,
       0,     0,     0,     0,    33,    43,    43,     0,     0,     0,
       0,     0,    39,    45,     0,     0,     0,     0,     0,    47,
      62,     0,    64,     0,    34,    46,     0,     0,    43,     0,
       0,    35,     0,     0,     0,     0,    63,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,   246,  -161,  -161,    61,  -161,  -161,    28,   121,  -161,
     -39,  -161,   -69,  -104,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,    33,  -161,  -161,  -161,   -27,   -32,  -161,
    -160,  -161,   -96,   -26,  -161,  -161,  -161,  -161,  -161,   190,
     -46,  -161,   211
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    26,    27,    28,    29,    11,    12,
      48,    49,   101,   117,   155,   156,   153,   177,   196,   221,
     238,   166,   215,   199,   209,   229,   200,   118,    47,   119,
     134,   120,    62,   122,   123,   148,    95,    96,    63,    99,
     105,    65,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,   103,    38,    39,   121,    51,     2,     3,     4,     5,
       6,    74,    13,   184,   136,   137,   138,    50,    50,   151,
      72,   190,   121,   121,   121,   104,   149,   121,    10,    45,
     174,    71,    76,    17,     5,     6,    10,   150,    18,    53,
      54,   175,     2,     3,     4,     5,     6,    -8,    21,   109,
     110,   167,   168,   169,    20,    55,    56,    55,    56,   121,
     121,   121,    57,   124,    57,    34,    35,    36,    37,   131,
     159,    45,   125,    46,    58,    59,    50,    35,    36,    37,
      60,    61,   154,    35,    36,    37,   111,   112,    32,    33,
     113,   114,   115,    45,    22,    46,   161,    53,    54,    44,
      23,    45,   160,    46,    25,   132,   163,   182,   183,    97,
      98,   222,   223,   116,    24,    55,    56,   197,   198,   121,
     121,    30,    57,    14,    15,    16,   164,   165,    31,    40,
      41,   187,    58,    59,   241,    42,    52,    43,    60,    61,
      67,    68,   121,   139,   140,   141,   142,   143,   144,   145,
     146,   207,     1,    69,     2,     3,     4,     5,     6,   234,
     214,    70,    73,    45,   217,   202,   219,   100,   204,   102,
     147,   106,   108,   127,   128,   129,   130,   126,   158,   231,
     135,   233,   152,   157,   172,   218,   162,   220,   170,   178,
     171,   179,   185,   242,   243,    77,    78,    79,    80,    81,
      82,    83,    84,   173,   176,   180,    85,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   181,   188,    86,    87,    88,
      89,    90,    91,    92,    93,    94,   186,   189,   132,   191,
     192,   193,   132,   194,   -68,   133,   195,   201,   206,   203,
     205,   211,   208,   210,   212,   213,   224,   216,   228,   230,
     225,   232,   226,   227,    19,   236,   237,   244,   239,   246,
     247,   240,   235,   245,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,    75
};

static const yytype_int16 yycheck[] =
{
      46,    70,    29,    29,   100,    44,     5,     6,     7,     8,
       9,    57,    41,   173,   118,   119,   120,    43,    44,   123,
      52,   181,   118,   119,   120,    71,    41,   123,     0,    49,
      41,    51,    64,     5,     8,     9,     8,    52,     0,    22,
      23,    52,     5,     6,     7,     8,     9,    46,    42,    95,
      96,   155,   156,   157,     4,    40,    41,    40,    41,   155,
     156,   157,    47,   102,    47,    10,    11,    12,    13,   115,
      53,    49,   104,    51,    57,    58,   102,    11,    12,    13,
      63,    64,   128,    11,    12,    13,    14,    15,    27,    28,
      18,    19,    20,    49,    41,    51,    52,    22,    23,    47,
      41,    49,   148,    51,    42,    49,   152,    51,    52,    22,
      23,   215,   216,    41,    45,    40,    41,    16,    17,   215,
     216,    43,    47,     2,     3,     4,   153,   153,    46,    44,
      41,   177,    57,    58,   238,    41,    41,    47,    63,    64,
      44,    48,   238,    24,    25,    26,    27,    28,    29,    30,
      31,   197,     3,    41,     5,     6,     7,     8,     9,   228,
     206,    48,    52,    49,   210,   191,   212,    45,   194,    49,
      51,    48,    44,    47,    47,    44,    44,    53,    41,   225,
      46,   227,    52,    44,    44,   211,    53,   213,    52,    41,
      52,    48,    51,   239,   240,    32,    33,    34,    35,    36,
      37,    38,    39,    53,    53,    53,    43,    24,    25,    26,
      27,    28,    29,    30,    31,    53,    45,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    53,    52,    49,    21,
      53,    44,    49,    21,    51,    52,    41,    53,    44,    51,
      51,    21,    46,    52,    52,    21,    53,    50,    48,    44,
      52,    44,    53,    52,     8,    53,    53,    53,    52,    44,
      44,    52,   229,    53,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    66,    67,    68,
      72,    73,    74,    41,    73,    73,    73,    72,     0,    66,
       4,    42,    41,    41,    45,    42,    69,    70,    71,    72,
      43,    46,    69,    69,    10,    11,    12,    13,    92,    98,
      44,    41,    41,    47,    47,    49,    51,    93,    75,    76,
      98,    75,    41,    22,    23,    40,    41,    47,    57,    58,
      63,    64,    97,   103,   105,   106,   107,    44,    48,    41,
      48,    51,    93,    52,   105,   107,    93,    32,    33,    34,
      35,    36,    37,    38,    39,    43,    54,    55,    56,    57,
      58,    59,    60,    61,    62,   101,   102,    22,    23,   104,
      45,    77,    49,    77,   105,   105,    48,   104,    44,   105,
     105,    14,    15,    18,    19,    20,    41,    78,    92,    94,
      96,    97,    98,    99,    75,    93,    53,    47,    47,    44,
      44,   105,    49,    52,    95,    46,    78,    78,    78,    24,
      25,    26,    27,    28,    29,    30,    31,    51,   100,    41,
      52,    78,    52,    81,   105,    79,    80,    44,    41,    53,
     105,    52,    53,   105,    92,    98,    86,    78,    78,    78,
      52,    52,    44,    53,    41,    52,    53,    82,    41,    48,
      53,    53,    51,    52,    95,    51,    53,   105,    45,    52,
      95,    21,    53,    44,    21,    41,    83,    16,    17,    88,
      91,    53,    98,    51,    98,    51,    44,   105,    46,    89,
      52,    21,    52,    21,   105,    87,    50,   105,    98,   105,
      98,    84,    78,    78,    53,    52,    53,    52,    48,    90,
      44,   105,    44,   105,    77,    88,    53,    53,    85,    52,
      52,    78,   105,   105,    53,    53,    44,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    67,    68,    69,    69,    69,    70,
      71,    71,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    76,    76,    76,    77,    78,    79,    78,    80,    78,
      81,    82,    83,    84,    85,    78,    78,    86,    87,    78,
      78,    78,    78,    78,    89,    90,    88,    88,    91,    91,
      92,    92,    93,    93,    93,    94,    94,    94,    95,    95,
      95,    95,    96,    96,    96,    96,    97,    97,    97,    98,
      98,    98,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   103,   103,   103,   103,   104,   104,   105,   105,
     105,   106,   106,   106,   106,   107,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     7,     6,     2,     2,     0,     2,
       7,     7,     2,     2,     2,     1,     2,     1,     1,     0,
       1,     2,     4,     0,     3,     2,     0,     4,     0,     4,
       0,     0,     0,     0,     0,    14,     4,     0,     0,    10,
       2,     2,     2,     0,     0,     0,     6,     0,     2,     1,
       6,     4,     5,     3,     0,     6,     6,     2,     4,     6,
       2,     0,    11,    16,    11,    16,     4,     7,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     2,     1,     2,     3,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 26:
#line 88 "gram-2.y"
                    {int l=strlen(br)-1; if(l == -1){printf("Error - break not Expected"); YYACCEPT;} while(br[l]!='L')l--; char s1[3]; strcpy(s1,&br[l]); fprintf(fp,"goto %s\n",s1);}
#line 1576 "y.tab.c"
    break;

  case 28:
#line 89 "gram-2.y"
                       {int l=strlen(cont)-1; if(l == -1){printf("Error - continue not Expected"); YYACCEPT;} while(cont[l]!='L')l--; char s1[3]; strcpy(s1,&cont[l]); fprintf(fp,"goto %s\n",s1);}
#line 1582 "y.tab.c"
    break;

  case 30:
#line 90 "gram-2.y"
                  {yyvsp[-1].next = newLabel();  fprintf(fp,"%s:\n",yyvsp[-1].next); yyvsp[-1].next = newLabel(); yyvsp[-1].tr = newLabel(); strcat(cont,yyvsp[-1].tr); yyvsp[-1].fal = newLabel(); strcat(br, yyvsp[-1].fal); tru = yyvsp[-1].tr; fals = yyvsp[-1].fal;}
#line 1588 "y.tab.c"
    break;

  case 31:
#line 90 "gram-2.y"
                                                                                                                                                                                                                {fprintf(fp,"%s:\n",yyvsp[-3].next);}
#line 1594 "y.tab.c"
    break;

  case 32:
#line 90 "gram-2.y"
                                                                                                                                                                                                                                                        {fprintf(fp," goto %s\n", yyvsp[-5].tr); yyvsp[-5].next = newLabel(); fprintf(fp, "goto %s \n%s:\n",yyvsp[-5].fal,yyvsp[-5].next);}
#line 1600 "y.tab.c"
    break;

  case 33:
#line 90 "gram-2.y"
                                                                                                                                                                                                                                                                                                                                                                            {fprintf(fp,"goto %s\n%s:\n", tru,yyvsp[-8].tr);}
#line 1606 "y.tab.c"
    break;

  case 34:
#line 90 "gram-2.y"
                                                                                                                                                                                                                                                                                                                                                                                                                                {fprintf(fp,"goto %s\n%s:\n", yyvsp[-11].next, yyvsp[-11].fal);int l; l=strlen(br); while(br[l-1]!='L')l--; br[l-1]='\0'; l=strlen(cont); while(cont[l-1]!='L')l--; cont[l-1]='\0';}
#line 1612 "y.tab.c"
    break;

  case 37:
#line 92 "gram-2.y"
                               {strcpy(sw,yyvsp[0].v); strcpy(br,newLabel()); strcpy(snxt,newLabel());}
#line 1618 "y.tab.c"
    break;

  case 38:
#line 92 "gram-2.y"
                                                                                                                         {fprintf(fp,"%s:\n",br);}
#line 1624 "y.tab.c"
    break;

  case 44:
#line 100 "gram-2.y"
                    {if(strcmp(yyvsp[0].v,"default")){yyval.v = newLabel(); strcpy(swt,yyval.v); yyvsp[0].a = newTemp(); fprintf(fp,"%s = %s == %s\n",yyvsp[0].a,yyvsp[0].v,sw); fprintf(fp,"if %s goto %s\ngoto %s\n%s:\n",yyvsp[0].a,snxt,yyval.v,snxt);} }
#line 1630 "y.tab.c"
    break;

  case 45:
#line 100 "gram-2.y"
                                                                                                                                                                                                                                    {if(strcmp(yyvsp[-3].v,"default")){fprintf(fp,"%s:\n",swt);}}
#line 1636 "y.tab.c"
    break;

  case 48:
#line 105 "gram-2.y"
                                {yyval.v = yyvsp[-1].v;}
#line 1642 "y.tab.c"
    break;

  case 49:
#line 106 "gram-2.y"
                                        {yyval.v = "default";}
#line 1648 "y.tab.c"
    break;

  case 50:
#line 110 "gram-2.y"
                                                        {fprintf(fp,"%s = %s\n",yyvsp[-4].v,yyvsp[-2].v);}
#line 1654 "y.tab.c"
    break;

  case 52:
#line 115 "gram-2.y"
                                                                {fprintf(fp,"%s = %s\n",yyvsp[-3].v,yyvsp[-1].v);}
#line 1660 "y.tab.c"
    break;

  case 66:
#line 141 "gram-2.y"
                                                                {yyval.a = newTemp(); fprintf(fp,"%s = %s * 4\n",yyval.a,yyvsp[-1].v); sprintf(yyvsp[-3].v,"%s[%s]",yyvsp[-3].v,yyval.a); yyval.v=yyvsp[-3].v; }
#line 1666 "y.tab.c"
    break;

  case 67:
#line 142 "gram-2.y"
                                                {yyval.a = newTemp(); yyval.v = "A"; fprintf(fp,"%s = %s * 4\n",yyval.a,yyvsp[-4].v); yyval.fal = newTemp(); fprintf(fp,"%s = %s * 4\n",yyval.fal,yyvsp[-2].v); yyval.tr = newTemp(); fprintf(fp,"%s = %s + %s\n",yyval.tr,yyval.fal,yyval.a); sprintf(yyvsp[-6].v,"%s[%s]",yyvsp[-6].v,yyval.tr); yyval.v=yyvsp[-6].v; }
#line 1672 "y.tab.c"
    break;

  case 72:
#line 153 "gram-2.y"
                                  {if(strlen(yyvsp[-2].v)==1)fprintf(fp,"%s %s %s\n",yyvsp[-3].v,yyvsp[-2].v,yyvsp[-1].v); else
    {yyval.a = newTemp(); fprintf(fp,"%s = %s %c %s\n",yyval.a,yyvsp[-3].v,yyvsp[-2].v[0],yyvsp[-1].v); fprintf(fp,"%s = %s\n",yyvsp[-3].v,yyval.a);}}
#line 1679 "y.tab.c"
    break;

  case 73:
#line 158 "gram-2.y"
                                        {yyval.v = "=";}
#line 1685 "y.tab.c"
    break;

  case 74:
#line 159 "gram-2.y"
                                {yyval.v = "+=";}
#line 1691 "y.tab.c"
    break;

  case 75:
#line 160 "gram-2.y"
                                {yyval.v = "-=";}
#line 1697 "y.tab.c"
    break;

  case 76:
#line 161 "gram-2.y"
                                {yyval.v = "*=";}
#line 1703 "y.tab.c"
    break;

  case 77:
#line 162 "gram-2.y"
                                {yyval.v = "/=";}
#line 1709 "y.tab.c"
    break;

  case 78:
#line 163 "gram-2.y"
                                {yyval.v = "&=";}
#line 1715 "y.tab.c"
    break;

  case 79:
#line 164 "gram-2.y"
                                {yyval.v = "|=";}
#line 1721 "y.tab.c"
    break;

  case 80:
#line 165 "gram-2.y"
                                {yyval.v = "^=";}
#line 1727 "y.tab.c"
    break;

  case 81:
#line 166 "gram-2.y"
                                {yyval.v = "%=";}
#line 1733 "y.tab.c"
    break;

  case 82:
#line 170 "gram-2.y"
                        {yyval.v = "|";}
#line 1739 "y.tab.c"
    break;

  case 83:
#line 171 "gram-2.y"
                        {yyval.v = "^";}
#line 1745 "y.tab.c"
    break;

  case 84:
#line 172 "gram-2.y"
                        {yyval.v = "&";}
#line 1751 "y.tab.c"
    break;

  case 85:
#line 173 "gram-2.y"
                        {yyval.v = "+";}
#line 1757 "y.tab.c"
    break;

  case 86:
#line 174 "gram-2.y"
                        {yyval.v = "-";}
#line 1763 "y.tab.c"
    break;

  case 87:
#line 175 "gram-2.y"
                        {yyval.v = "*";}
#line 1769 "y.tab.c"
    break;

  case 88:
#line 176 "gram-2.y"
                        {yyval.v = "/";}
#line 1775 "y.tab.c"
    break;

  case 89:
#line 177 "gram-2.y"
                        {yyval.v = "%";}
#line 1781 "y.tab.c"
    break;

  case 93:
#line 184 "gram-2.y"
                {yyval.v = "!=";}
#line 1787 "y.tab.c"
    break;

  case 94:
#line 185 "gram-2.y"
                {yyval.v = "<";}
#line 1793 "y.tab.c"
    break;

  case 95:
#line 186 "gram-2.y"
                {yyval.v = ">";}
#line 1799 "y.tab.c"
    break;

  case 100:
#line 194 "gram-2.y"
                        {yyval.v = "++";}
#line 1805 "y.tab.c"
    break;

  case 101:
#line 195 "gram-2.y"
                        {yyval.v = "--";}
#line 1811 "y.tab.c"
    break;

  case 102:
#line 196 "gram-2.y"
                        {yyval.v = "!";}
#line 1817 "y.tab.c"
    break;

  case 103:
#line 197 "gram-2.y"
                        {yyval.v = "~";}
#line 1823 "y.tab.c"
    break;

  case 104:
#line 198 "gram-2.y"
                        {yyval.v = "";}
#line 1829 "y.tab.c"
    break;

  case 105:
#line 199 "gram-2.y"
                        {yyval.v = "MINUS";}
#line 1835 "y.tab.c"
    break;

  case 106:
#line 203 "gram-2.y"
                        {yyval.v = "++";}
#line 1841 "y.tab.c"
    break;

  case 107:
#line 204 "gram-2.y"
                        {yyval.v = "--";}
#line 1847 "y.tab.c"
    break;

  case 109:
#line 209 "gram-2.y"
                                        {yyval.v = newTemp(); fprintf(fp,"%s = %s %s %s\n",yyval.v,yyvsp[-2].v,yyvsp[-1].v,yyvsp[0].v); }
#line 1853 "y.tab.c"
    break;

  case 110:
#line 210 "gram-2.y"
                                        {if(strcmp(yyvsp[-1].v,"&&") && strcmp(yyvsp[-1].v,"||")){yyval.v = newTemp(); fprintf(fp,"%s = %s %s %s\n",yyval.v,yyvsp[-2].v,yyvsp[-1].v,yyvsp[0].v);  fprintf(fp,"if %s",yyval.v); }else if(!strcmp(yyvsp[-1].v,"&&")) {yyvsp[-1].a = newLabel(); fprintf(fp," goto %s\ngoto %s\n%s:\n",yyvsp[-1].a,fals,yyvsp[-1].a);} else if(!strcmp(yyvsp[-1].v,"||")) {yyvsp[-1].a = newLabel(); fprintf(fp," goto %s\ngoto %s\n%s:\n",tru,yyvsp[-1].a,yyvsp[-1].a);}}
#line 1859 "y.tab.c"
    break;

  case 111:
#line 214 "gram-2.y"
                                {if(strlen(yyvsp[-1].v)==2){yyval.v = newTemp(); fprintf(fp,"%s = %s %c 1\n",yyval.v,yyvsp[0].v,yyvsp[-1].v[0]); fprintf(fp,"%s = %s\n",yyvsp[0].v,yyval.v);} else {yyval.v = newTemp(); fprintf(fp,"%s = %s %s\n",yyval.v,yyvsp[-1].v,yyvsp[0].v);} }
#line 1865 "y.tab.c"
    break;

  case 113:
#line 216 "gram-2.y"
                                                {yyval.v = newTemp(); yyval.a = newTemp(); fprintf(fp,"%s = %s\n",yyval.v,yyvsp[-1].v); fprintf(fp,"%s = %s %c 1\n",yyval.a,yyvsp[-1].v,yyvsp[0].v[0]); fprintf(fp,"%s = %s\n",yyvsp[-1].v,yyval.a);}
#line 1871 "y.tab.c"
    break;

  case 114:
#line 217 "gram-2.y"
                                        {yyval.v = newTemp(); yyval.a = newTemp(); fprintf(fp,"%s = %s %c 1\n",yyval.v,yyvsp[-1].v,yyvsp[-2].v[0]); fprintf(fp,"%s = %s %c 1\n",yyval.a,yyvsp[-1].v,yyvsp[0].v[0]); fprintf(fp,"%s = %s\n",yyvsp[-1].v,yyval.a);}
#line 1877 "y.tab.c"
    break;

  case 117:
#line 223 "gram-2.y"
                                        {sprintf(yyval.v,"%d",yyvsp[0].val);}
#line 1883 "y.tab.c"
    break;


#line 1887 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 226 "gram-2.y"

void yyerror(const char *s)
{
	printf("%s", s);
}
int main(int argc, char* argv[])
{
	fp = fopen("icg.txt","w");

	cont = (char*)malloc(sizeof(char)*10);
	br = (char*)malloc(sizeof(char)*10);
	sw = (char*)malloc(sizeof(char)*10);
	snxt = (char*)malloc(sizeof(char)*10);
	swt = (char*)malloc(sizeof(char)*10);
	tru = (char*)malloc(sizeof(char)*10);
	fals = (char*)malloc(sizeof(char)*10);
	yyin = fopen(argv[1], "r"); 
	if(!yyparse())
	{
		printf("Parsing successful \n");
	}
	else
		printf("Unsuccessful \n");
	return 0;

	//start

}

char* newLabel()
{
	char *s = (char*)malloc(4*sizeof(char));
	sprintf(s,"L%d",ln);
	ln++;
	return s;
}

char* newTemp()
{
	char *s = (char*)malloc(4*sizeof(char));
	sprintf(s,"r%d",tn);
	tn++;
	return s;
}
