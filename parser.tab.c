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
#line 7 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.hpp"
void yyerror(const char *s);
int yylex(void);
ASTNode* root = nullptr; // Nodo raíz global

/* Line 371 of yacc.c  */
#line 78 "parser.tab.c"

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 1 "parser.y"

    #include <vector>
    #include <memory>
    #include "ast.hpp"


/* Line 387 of yacc.c  */
#line 117 "parser.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     WHILE = 259,
     FOR = 260,
     ELSE = 261,
     ELIF = 262,
     INTEGER = 263,
     FLOAT = 264,
     BOOLEAN = 265,
     PRINT = 266,
     READ = 267,
     NEW = 268,
     FUNC = 269,
     RETURN = 270,
     IDENTIFICADOR = 271,
     CONST_INTEGER = 272,
     CONST_FLOAT = 273,
     CONST_CADENA = 274,
     OP_SUMA = 275,
     OP_RESTA = 276,
     OP_MULT = 277,
     OP_DIV = 278,
     OP_IGUAL = 279,
     OP_MAYOR = 280,
     OP_MENOR = 281,
     OP_MAYORIGUAL = 282,
     OP_MENORIGUAL = 283,
     OP_COMP_IGUAL = 284,
     OP_NEGACION = 285,
     OP_DISTINTO = 286,
     LLAVE_A = 287,
     LLAVE_C = 288,
     PARENTESIS_A = 289,
     PARENTESIS_C = 290,
     FIN_SENTENCIA = 291,
     CHAR_COMA = 292,
     CHAR_PUNTO = 293,
     CHAR_PUNTOYCOMA = 294,
     CHAR_DOSPUNTOS = 295,
     INI_COMENTARIO = 296,
     FIN_COMENTARIO = 297
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 17 "parser.y"

    int ival;
    float fval;
    char* sval;
    ASTNode* node;
    std::vector<std::unique_ptr<ASTNode>>* vec;
    std::vector<std::string>* strvec;


/* Line 387 of yacc.c  */
#line 184 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 212 "parser.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    15,    18,    21,
      23,    25,    27,    31,    38,    39,    41,    43,    47,    52,
      55,    60,    62,    64,    66,    70,    74,    76,    80,    84,
      88,    92,    96,   100,   104,   108,   112,   115,   119,   121,
     123,   125,   127,   129,   135,   146,   154,   160,   170,   173,
     177,   182,   184,   188,   190,   192,   197,   201,   204,   206,
     208,   210,   212,   214,   216,   218,   220,   222,   224,   226,
     228,   230,   232,   234,   236,   238,   240,   242,   244,   246
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    -1,    46,    45,    -1,    -1,    51,
      36,    -1,    53,    36,    -1,    57,    36,    -1,    60,    36,
      -1,    55,    -1,    61,    -1,    47,    -1,    15,    54,    36,
      -1,    14,    16,    34,    48,    35,    56,    -1,    -1,    49,
      -1,    16,    -1,    49,    37,    16,    -1,    16,    34,    58,
      35,    -1,    52,    16,    -1,    52,    16,    24,    54,    -1,
       8,    -1,     9,    -1,    10,    -1,    16,    24,    54,    -1,
      54,    20,    54,    -1,    16,    -1,    54,    21,    54,    -1,
      54,    22,    54,    -1,    54,    23,    54,    -1,    54,    29,
      54,    -1,    54,    31,    54,    -1,    54,    25,    54,    -1,
      54,    26,    54,    -1,    54,    27,    54,    -1,    54,    28,
      54,    -1,    30,    54,    -1,    34,    54,    35,    -1,    17,
      -1,    18,    -1,    19,    -1,    16,    -1,    50,    -1,     3,
      34,    54,    35,    56,    -1,     3,    34,    54,    35,    56,
       7,    34,    54,    35,    56,    -1,     3,    34,    54,    35,
      56,     6,    56,    -1,     4,    34,    54,    35,    56,    -1,
       5,    34,    53,    39,    54,    39,    53,    35,    56,    -1,
       6,    56,    -1,    32,    45,    33,    -1,    11,    34,    58,
      35,    -1,    59,    -1,    59,    37,    58,    -1,    19,    -1,
      54,    -1,    12,    34,    16,    35,    -1,    41,    62,    42,
      -1,    62,    63,    -1,    63,    -1,    19,    -1,    16,    -1,
      17,    -1,    18,    -1,    20,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,    31,    -1,    37,    -1,
      38,    -1,    39,    -1,    40,    -1,    36,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    57,    68,    72,    73,    74,    75,    76,
      77,    78,    79,    85,    93,    96,   100,   106,   114,   122,
     126,   133,   134,   135,   139,   146,   152,   156,   162,   168,
     174,   180,   186,   192,   198,   204,   210,   215,   216,   217,
     218,   219,   220,   224,   233,   254,   271,   280,   289,   300,
     304,   313,   318,   326,   327,   331,   338,   342,   343,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "WHILE", "FOR", "ELSE", "ELIF",
  "INTEGER", "FLOAT", "BOOLEAN", "PRINT", "READ", "NEW", "FUNC", "RETURN",
  "IDENTIFICADOR", "CONST_INTEGER", "CONST_FLOAT", "CONST_CADENA",
  "OP_SUMA", "OP_RESTA", "OP_MULT", "OP_DIV", "OP_IGUAL", "OP_MAYOR",
  "OP_MENOR", "OP_MAYORIGUAL", "OP_MENORIGUAL", "OP_COMP_IGUAL",
  "OP_NEGACION", "OP_DISTINTO", "LLAVE_A", "LLAVE_C", "PARENTESIS_A",
  "PARENTESIS_C", "FIN_SENTENCIA", "CHAR_COMA", "CHAR_PUNTO",
  "CHAR_PUNTOYCOMA", "CHAR_DOSPUNTOS", "INI_COMENTARIO", "FIN_COMENTARIO",
  "$accept", "programa", "sentencia_lista", "sentencia", "funcion",
  "parametros", "lista_parametros", "llamada_funcion", "declaracion",
  "tipo", "asignacion", "expresion", "estructura_control",
  "bloque_sentencias", "impresion", "argumentos", "argumento", "lectura",
  "comentario", "texto", "elemento_texto", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    52,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    56,
      57,    58,    58,    59,    59,    60,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     2,     2,     2,     1,
       1,     1,     3,     6,     0,     1,     1,     3,     4,     2,
       4,     1,     1,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     1,
       1,     1,     1,     5,    10,     7,     5,     9,     2,     3,
       4,     1,     3,     1,     1,     4,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     2,     4,    11,     0,     0,
       0,     9,     0,     0,    10,     0,     0,     0,     4,    48,
       0,     0,     0,    26,    38,    39,    40,     0,     0,    42,
       0,     0,    60,    61,    62,    59,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    79,    75,
      76,    77,    78,     0,    58,     1,     3,     5,    19,     6,
       7,     8,     0,     0,     0,     0,    40,    54,     0,    51,
       0,    14,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    24,    56,    57,     0,
       0,     0,     0,    49,    50,     0,    55,    16,     0,    15,
       0,    37,    25,    27,    28,    29,    32,    33,    34,    35,
      30,    31,    20,    43,    46,     0,    52,     0,     0,    18,
       0,     0,     0,    13,    17,    45,     0,     0,     0,     0,
       0,    47,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    16,    17,   108,   109,    39,    18,    19,
      20,    77,    21,    29,    22,    78,    79,    23,    24,    63,
      64
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
      43,   -13,    -9,    -3,     6,   -99,   -99,   -99,     9,    10,
       3,   -10,    -2,   118,    23,   -99,    43,   -99,     4,    29,
      14,   -99,    20,    28,   -99,   -10,   -10,    54,    43,   -99,
     155,    56,    39,    51,   -99,   -99,   -99,   -10,   -10,   -99,
     170,   -10,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,    91,   -99,   -99,   -99,   -99,    62,   -99,
     -99,   -99,   182,   198,    48,    64,   -99,    40,    69,    86,
      89,   110,   155,    40,   214,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -10,   -10,   -99,    40,   -99,   -99,   -10,
       6,     6,   -10,   -99,   -99,   155,   -99,   -99,    97,   113,
     116,   -99,    67,    67,     8,     8,   -15,   -15,   -15,   -15,
      74,    74,    40,    11,   -99,   139,   -99,     6,   136,   -99,
       6,   119,    54,   -99,   -99,   -99,   -10,   128,   230,     6,
       6,   -99,   -99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   -12,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -26,   -11,   -99,   -98,   -99,   -77,   -99,   -99,   -99,   -99,
     106
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      40,    74,   123,   124,    66,   110,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    72,    73,    75,   130,   131,    32,
      37,    25,    41,    65,    38,    26,    83,    84,   126,   133,
      96,    27,   135,    89,    90,    91,    92,    93,    28,    94,
      67,   141,   142,    30,    31,    68,     1,     2,     3,     4,
      69,     5,     6,     7,     8,     9,    70,    10,    11,    12,
      85,    86,    87,    88,    71,    89,    90,    91,    92,    93,
      12,    94,    80,    81,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    13,    82,    99,   102,   122,    87,
      88,   125,    89,    90,    91,    92,    93,   103,    94,    89,
      90,    91,    92,    -1,   104,    -1,   137,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   105,   106,   138,   107,    58,    59,    60,
      61,    62,   127,    97,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
     128,   129,   134,   136,    58,    59,    60,    61,    62,    85,
      86,    87,    88,   139,    89,    90,    91,    92,    93,    98,
      94,    33,    34,    35,    76,     0,     0,     0,   132,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,    38,
      85,    86,    87,    88,     0,    89,    90,    91,    92,    93,
       0,    94,    85,    86,    87,    88,    95,    89,    90,    91,
      92,    93,     0,    94,     0,     0,     0,   100,    85,    86,
      87,    88,     0,    89,    90,    91,    92,    93,     0,    94,
       0,     0,     0,   101,    85,    86,    87,    88,     0,    89,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   111,
      85,    86,    87,    88,     0,    89,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   140
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

static const yytype_int16 yycheck[] =
{
      11,    27,   100,   101,    16,    82,    16,    17,    18,    19,
      25,    26,    27,    28,    25,    26,    28,     6,     7,    16,
      30,    34,    24,     0,    34,    34,    37,    38,   105,   127,
      41,    34,   130,    25,    26,    27,    28,    29,    32,    31,
      36,   139,   140,    34,    34,    16,     3,     4,     5,     6,
      36,     8,     9,    10,    11,    12,    36,    14,    15,    16,
      20,    21,    22,    23,    36,    25,    26,    27,    28,    29,
      16,    31,    16,    34,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    41,    34,    24,    39,    99,    22,
      23,   102,    25,    26,    27,    28,    29,    33,    31,    25,
      26,    27,    28,    29,    35,    31,   132,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    37,    35,   136,    16,    36,    37,    38,
      39,    40,    35,    42,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      37,    35,    16,    34,    36,    37,    38,    39,    40,    20,
      21,    22,    23,    35,    25,    26,    27,    28,    29,    63,
      31,    16,    17,    18,    19,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      -1,    31,    20,    21,    22,    23,    36,    25,    26,    27,
      28,    29,    -1,    31,    -1,    -1,    -1,    35,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    29,    -1,    31,
      -1,    -1,    -1,    35,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,    35,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      -1,    31,    -1,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    10,    11,    12,
      14,    15,    16,    41,    44,    45,    46,    47,    51,    52,
      53,    55,    57,    60,    61,    34,    34,    34,    32,    56,
      34,    34,    16,    16,    17,    18,    19,    30,    34,    50,
      54,    24,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    36,    37,
      38,    39,    40,    62,    63,     0,    45,    36,    16,    36,
      36,    36,    54,    54,    53,    45,    19,    54,    58,    59,
      16,    34,    34,    54,    54,    20,    21,    22,    23,    25,
      26,    27,    28,    29,    31,    36,    54,    42,    63,    24,
      35,    35,    39,    33,    35,    37,    35,    16,    48,    49,
      58,    35,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    56,    56,    54,    58,    35,    37,    35,
       6,     7,    39,    56,    16,    56,    34,    53,    54,    35,
      35,    56,    56
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


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 53 "parser.y"
    { root = (yyvsp[(1) - (1)].node); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 57 "parser.y"
    {
        auto prog = new ProgramaNode();
        prog->sentencias.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (2)].node)));
        if ((yyvsp[(2) - (2)].node)) {
            auto next = static_cast<ProgramaNode*>((yyvsp[(2) - (2)].node));
            for (auto& s : next->sentencias)
                prog->sentencias.push_back(std::move(s));
            delete next;
        }
        (yyval.node) = prog;
    }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 68 "parser.y"
    { (yyval.node) = new ProgramaNode(); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 72 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 73 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 75 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 76 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 77 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 78 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 79 "parser.y"
    { 
        (yyval.node) = new ReturnNode(std::unique_ptr<ASTNode>((yyvsp[(2) - (3)].node))); 
    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 85 "parser.y"
    {
        (yyval.node) = new FuncionNode((yyvsp[(2) - (6)].sval), *(yyvsp[(4) - (6)].strvec), std::unique_ptr<ASTNode>((yyvsp[(6) - (6)].node)));
        free((yyvsp[(2) - (6)].sval));
        delete (yyvsp[(4) - (6)].strvec);
    }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    { 
        (yyval.strvec) = new std::vector<std::string>(); 
    }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    { (yyval.strvec) = (yyvsp[(1) - (1)].strvec); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 100 "parser.y"
    { 
        auto v = new std::vector<std::string>(); 
        v->push_back((yyvsp[(1) - (1)].sval)); 
        free((yyvsp[(1) - (1)].sval)); 
        (yyval.strvec) = v; 
    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 106 "parser.y"
    { 
        (yyvsp[(1) - (3)].strvec)->push_back((yyvsp[(3) - (3)].sval)); 
        free((yyvsp[(3) - (3)].sval)); 
        (yyval.strvec) = (yyvsp[(1) - (3)].strvec);
    }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    {
        (yyval.node) = new LlamadaFuncionNode((yyvsp[(1) - (4)].sval), std::move(*(yyvsp[(3) - (4)].vec)));
        free((yyvsp[(1) - (4)].sval));
        delete (yyvsp[(3) - (4)].vec);
    }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 122 "parser.y"
    {
        (yyval.node) = new DeclaracionNode(std::string((yyvsp[(1) - (2)].sval)), std::string((yyvsp[(2) - (2)].sval)), nullptr);
        free((yyvsp[(1) - (2)].sval)); free((yyvsp[(2) - (2)].sval));
    }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 126 "parser.y"
    {
        (yyval.node) = new DeclaracionNode(std::string((yyvsp[(1) - (4)].sval)), std::string((yyvsp[(2) - (4)].sval)), std::unique_ptr<ASTNode>((yyvsp[(4) - (4)].node)));
        free((yyvsp[(1) - (4)].sval)); free((yyvsp[(2) - (4)].sval));
    }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 133 "parser.y"
    { (yyval.sval) = strdup("senpai"); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 134 "parser.y"
    { (yyval.sval) = strdup("kohai"); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    { (yyval.sval) = strdup("bool"); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    {
        (yyval.node) = new AsignacionNode((yyvsp[(1) - (3)].sval), std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        free((yyvsp[(1) - (3)].sval));
    }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 146 "parser.y"
    {
        auto node = new ExpresionNode("+");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        (yyval.node) = node;
    }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    { 
        (yyval.node) = new IdentificadorNode((yyvsp[(1) - (1)].sval)); 
        free((yyvsp[(1) - (1)].sval)); 
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    {
        auto node = new ExpresionNode("-");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        (yyval.node) = node;
    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    {
        auto node = new ExpresionNode("*");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        (yyval.node) = node;
    }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 168 "parser.y"
    {
        auto node = new ExpresionNode("/");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        (yyval.node) = node;
    }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 174 "parser.y"
    {
        auto node = new ExpresionNode("==");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        (yyval.node) = node;
    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    {
        auto node = new ExpresionNode("!=");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        (yyval.node) = node;
    }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    {
        auto node = new ExpresionNode(">");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        (yyval.node) = node;
    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    {
        auto node = new ExpresionNode("<");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        (yyval.node) = node;
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 198 "parser.y"
    {
        auto node = new ExpresionNode(">=");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        (yyval.node) = node;
    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 204 "parser.y"
    {
        auto node = new ExpresionNode("<=");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(3) - (3)].node)));
        (yyval.node) = node;
    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 210 "parser.y"
    {
        auto node = new ExpresionNode("!");
        node->operandos.push_back(std::unique_ptr<ASTNode>((yyvsp[(2) - (2)].node)));
        (yyval.node) = node;
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 215 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 216 "parser.y"
    { (yyval.node) = new LiteralNode(std::to_string((yyvsp[(1) - (1)].ival))); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    { (yyval.node) = new LiteralNode(std::to_string((yyvsp[(1) - (1)].fval))); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 218 "parser.y"
    { (yyval.node) = new LiteralNode((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 219 "parser.y"
    { (yyval.node) = new IdentificadorNode((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 220 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 224 "parser.y"
    {
        auto node = new ControlNode("if");
        node->condicion = std::unique_ptr<ASTNode>((yyvsp[(3) - (5)].node));
        auto cuerpo = static_cast<ProgramaNode*>((yyvsp[(5) - (5)].node));
        for (auto& s : cuerpo->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpo;
        (yyval.node) = node;
    }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 233 "parser.y"
    {
        // Crear nodo if principal
        auto node = new ControlNode("if");
        node->condicion = std::unique_ptr<ASTNode>((yyvsp[(3) - (10)].node));
        auto cuerpoIf = static_cast<ProgramaNode*>((yyvsp[(5) - (10)].node));
        for (auto& s : cuerpoIf->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpoIf;

        // Crear nodo elif
        auto elifNode = new ControlNode("if");
        elifNode->condicion = std::unique_ptr<ASTNode>((yyvsp[(8) - (10)].node));
        auto cuerpoElif = static_cast<ProgramaNode*>((yyvsp[(10) - (10)].node));
        for (auto& s : cuerpoElif->sentencias)
            elifNode->cuerpo.push_back(std::move(s));
        delete cuerpoElif;

        // Conectar elif como elseCuerpo del if principal
        node->elseCuerpo = std::unique_ptr<ASTNode>(elifNode);
        (yyval.node) = node;
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 254 "parser.y"
    {
        auto node = new ControlNode("if");
        node->condicion = std::unique_ptr<ASTNode>((yyvsp[(3) - (7)].node));
        auto cuerpoIf = static_cast<ProgramaNode*>((yyvsp[(5) - (7)].node));
        for (auto& s : cuerpoIf->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpoIf;

        auto elseNode = new ControlNode("else");
        auto cuerpoElse = static_cast<ProgramaNode*>((yyvsp[(7) - (7)].node));
        for (auto& s : cuerpoElse->sentencias)
            elseNode->cuerpo.push_back(std::move(s));
        delete cuerpoElse;
        
        node->elseCuerpo = std::unique_ptr<ASTNode>(elseNode);
        (yyval.node) = node;
    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 271 "parser.y"
    {
        auto node = new ControlNode("while");
        node->condicion = std::unique_ptr<ASTNode>((yyvsp[(3) - (5)].node));
        auto cuerpo = static_cast<ProgramaNode*>((yyvsp[(5) - (5)].node));
        for (auto& s : cuerpo->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpo;
        (yyval.node) = node;
    }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 280 "parser.y"
    {
        auto node = new ControlNode("for");
        node->condicion = std::unique_ptr<ASTNode>((yyvsp[(5) - (9)].node));
        auto cuerpo = static_cast<ProgramaNode*>((yyvsp[(9) - (9)].node));
        for (auto& s : cuerpo->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpo;
        (yyval.node) = node;
    }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 289 "parser.y"
    {
        auto node = new ControlNode("else");
        auto cuerpo = static_cast<ProgramaNode*>((yyvsp[(2) - (2)].node));
        for (auto& s : cuerpo->sentencias)
            node->cuerpo.push_back(std::move(s));
        delete cuerpo;
        (yyval.node) = node;
    }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 300 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 304 "parser.y"
    {
        auto node = new ImpresionNode();
        node->argumentos = std::move(*(yyvsp[(3) - (4)].vec));
        delete (yyvsp[(3) - (4)].vec);
        (yyval.node) = node;
    }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 313 "parser.y"
    {
        auto vec = new std::vector<std::unique_ptr<ASTNode>>();
        vec->push_back(std::unique_ptr<ASTNode>((yyvsp[(1) - (1)].node)));
        (yyval.vec) = vec;
    }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 318 "parser.y"
    {
        auto vec = (yyvsp[(3) - (3)].vec);
        vec->insert(vec->begin(), std::unique_ptr<ASTNode>((yyvsp[(1) - (3)].node)));
        (yyval.vec) = vec;
    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 326 "parser.y"
    { (yyval.node) = new LiteralNode((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 327 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 331 "parser.y"
    {
        (yyval.node) = new LecturaNode((yyvsp[(3) - (4)].sval));
        free((yyvsp[(3) - (4)].sval));
    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 338 "parser.y"
    { (yyval.node) = nullptr; }
    break;


/* Line 1792 of yacc.c  */
#line 2066 "parser.tab.c"
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
#line 370 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}

