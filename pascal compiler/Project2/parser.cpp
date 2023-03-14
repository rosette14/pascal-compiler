/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     IDENT = 259,
     INTEGER = 260,
     REAL = 261,
     BOOLEAN = 262,
     STRING = 263,
     CHAR = 264,
     KW_INTEGER = 265,
     KW_REAL = 266,
     KW_BOOLEAN = 267,
     KW_CHAR = 268,
     KW_STRING = 269,
     WRITE = 270,
     KW_IF = 271,
     KW_ELSE = 272,
     KW_THEN = 273,
     KW_WHILE = 274,
     KW_DO = 275,
     KW_END = 276,
     KW_BEGIN = 277,
     KW_TRUE = 278,
     KW_FALSE = 279,
     KW_TO = 280,
     KW_FOR = 281,
     FUNCTION = 282,
     KW_RETURN = 283,
     PROCEDURE = 284,
     VAR = 285,
     ARRAY = 286,
     NOT = 287,
     OF = 288,
     AND = 289,
     OR = 290,
     DIV = 291,
     EQ = 292,
     NEQ = 293,
     LE = 294,
     SE = 295,
     ASSIGN = 296,
     KW_DOTS = 297,
     dec_e = 298,
     OPP1 = 299,
     OP = 300,
     IFPREC = 301,
     prog = 302
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define IDENT 259
#define INTEGER 260
#define REAL 261
#define BOOLEAN 262
#define STRING 263
#define CHAR 264
#define KW_INTEGER 265
#define KW_REAL 266
#define KW_BOOLEAN 267
#define KW_CHAR 268
#define KW_STRING 269
#define WRITE 270
#define KW_IF 271
#define KW_ELSE 272
#define KW_THEN 273
#define KW_WHILE 274
#define KW_DO 275
#define KW_END 276
#define KW_BEGIN 277
#define KW_TRUE 278
#define KW_FALSE 279
#define KW_TO 280
#define KW_FOR 281
#define FUNCTION 282
#define KW_RETURN 283
#define PROCEDURE 284
#define VAR 285
#define ARRAY 286
#define NOT 287
#define OF 288
#define AND 289
#define OR 290
#define DIV 291
#define EQ 292
#define NEQ 293
#define LE 294
#define SE 295
#define ASSIGN 296
#define KW_DOTS 297
#define dec_e 298
#define OPP1 299
#define OP 300
#define IFPREC 301
#define prog 302




/* Copy the first part of user declarations.  */
#line 1 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"

	#include "ast.h"
	#include <iostream>
	using std::cout;
	using std::endl;
	extern int yylex();
	extern int yyerror(const char *);
	Program *root;
	SymbolTable *symbolTable=new SymbolTable();
	int lin = 1, col =1;
	int i=0;
	int ifScope=0;
	int current_type;
	int current_kind=3;
	int error=0;
	int symErr=0;
    int fErr=0;





/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 24 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
typedef union YYSTYPE {
		Program *tProgram;
		Identifier_list *tIdentifier_list;
		Declarations *tDeclarations;
		Type *tType;
		int tStandard_type;
		Subprogram_declarations *tSubprogram_declarations;
		Subprogram_declaration *tSubprogram_declaration;
		Subprogram_head *tSubprogram_head;
		Arguments *tArguments;
		Parameter_list *tParameter_list;
		Compound_statement *tCompound_statement;
		Statement_list *tStatement_list;
		Statement *tStatement;
		Variable *tVariable;
		Procedure_statement *tProcedure_statement;
		Expression_list *tExpression_list;
		Expression *tExpression;
		int tUnary_operator ;
		Ident *tIdent ;
		ExpInt *tExpInt;
		ExpReal *tExpReal;
		ExpStr *tExpStr;
		ExpChar *tExpChar;
		Return_stmt *tReturn_stmt;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 228 "parser.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 240 "parser.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   241

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  25
/* YYNRULES -- Number of rules. */
#define YYNRULES  76
/* YYNRULES -- Number of states. */
#define YYNSTATES  167

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    51,    54,    53,    56,    52,    60,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    59,
      47,     2,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
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
      45,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,    11,    13,    17,    19,    20,    27,    33,
      35,    44,    46,    48,    50,    52,    54,    56,    57,    60,
      62,    67,    70,    71,    72,    81,    82,    89,    93,    94,
      98,   104,   108,   110,   111,   114,   116,   121,   124,   127,
     133,   142,   148,   158,   168,   174,   180,   188,   190,   195,
     197,   202,   204,   208,   210,   212,   214,   216,   218,   220,
     222,   227,   231,   235,   238,   240,   242,   244,   246,   248,
     250,   252,   254,   256,   258,   260,   262
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      63,     0,    -1,     3,     4,    59,    65,    69,    78,    60,
      -1,     4,    -1,    64,    56,     4,    -1,    66,    -1,    -1,
      66,    30,    64,    61,    67,    59,    -1,    30,    64,    61,
      67,    59,    -1,    68,    -1,    31,    49,     5,    59,     5,
      50,    33,    68,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    70,    -1,    -1,    70,    71,    -1,
      71,    -1,    73,    78,    72,    59,    -1,    28,    82,    -1,
      -1,    -1,    27,     4,    74,    76,    61,    68,    59,    65,
      -1,    -1,    29,     4,    75,    76,    59,    65,    -1,    48,
      77,    51,    -1,    -1,    64,    61,    67,    -1,    77,    59,
      64,    61,    67,    -1,    22,    79,    21,    -1,    80,    -1,
      -1,    80,    81,    -1,    81,    -1,    82,    41,    85,    59,
      -1,    83,    59,    -1,    78,    59,    -1,    16,    85,    18,
      78,    59,    -1,    16,    85,    18,    78,    59,    17,    78,
      59,    -1,    19,    85,    20,    78,    59,    -1,    26,     4,
      41,     9,    25,     9,    20,    78,    59,    -1,    26,     4,
      41,     5,    25,     5,    20,    78,    59,    -1,    15,    48,
       8,    51,    59,    -1,    15,    48,     4,    51,    59,    -1,
      15,    48,    85,    86,    85,    51,    59,    -1,     4,    -1,
       4,    49,    85,    50,    -1,     4,    -1,     4,    48,    84,
      51,    -1,    85,    -1,    84,    56,    85,    -1,     4,    -1,
       5,    -1,     6,    -1,     9,    -1,     8,    -1,    23,    -1,
      24,    -1,     4,    48,    84,    51,    -1,    48,    85,    51,
      -1,    85,    86,    85,    -1,    32,    85,    -1,    53,    -1,
      52,    -1,    54,    -1,    55,    -1,    36,    -1,    47,    -1,
      46,    -1,    40,    -1,    39,    -1,    37,    -1,    38,    -1,
      34,    -1,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   112,   112,   120,   125,   131,   135,   140,   154,   167,
     171,   176,   180,   184,   188,   192,   197,   202,   206,   212,
     217,   222,   233,   243,   243,   256,   256,   268,   273,   277,
     289,   304,   315,   319,   324,   329,   334,   338,   342,   346,
     350,   354,   358,   363,   368,   372,   377,   382,   387,   393,
     398,   404,   408,   414,   419,   423,   427,   431,   435,   439,
     443,   448,   452,   456,   461,   465,   469,   473,   477,   481,
     485,   489,   493,   497,   501,   505,   509
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "IDENT", "INTEGER", "REAL",
  "BOOLEAN", "STRING", "CHAR", "KW_INTEGER", "KW_REAL", "KW_BOOLEAN",
  "KW_CHAR", "KW_STRING", "WRITE", "KW_IF", "KW_ELSE", "KW_THEN",
  "KW_WHILE", "KW_DO", "KW_END", "KW_BEGIN", "KW_TRUE", "KW_FALSE",
  "KW_TO", "KW_FOR", "FUNCTION", "KW_RETURN", "PROCEDURE", "VAR", "ARRAY",
  "NOT", "OF", "AND", "OR", "DIV", "EQ", "NEQ", "LE", "SE", "ASSIGN",
  "KW_DOTS", "dec_e", "OPP1", "OP", "'>'", "'<'", "'('", "'['", "']'",
  "')'", "'-'", "'+'", "'*'", "'/'", "','", "IFPREC", "prog", "';'", "'.'",
  "':'", "$accept", "program", "identifier_list", "declarations_e",
  "declarations", "type", "standard_type", "subprogram_declarations_e",
  "subprogram_declarations", "subprogram_declaration", "return_stmt",
  "subprogram_head", "@1", "@2", "arguments", "parameter_list",
  "compound_statement", "statement_list_e", "statement_list", "statement",
  "variable", "procedure_statement", "expression_list", "expression",
  "unary_operator", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    62,    60,    40,    91,
      93,    41,    45,    43,    42,    47,    44,   301,   302,    59,
      46,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    72,    72,    74,    73,    75,    73,    76,    76,    77,
      77,    78,    79,    79,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     7,     1,     3,     1,     0,     6,     5,     1,
       8,     1,     1,     1,     1,     1,     1,     0,     2,     1,
       4,     2,     0,     0,     8,     0,     6,     3,     0,     3,
       5,     3,     1,     0,     2,     1,     4,     2,     2,     5,
       8,     5,     9,     9,     5,     5,     7,     1,     4,     1,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     1,     6,     0,    17,     5,     3,
       0,     0,     0,     0,    16,    19,     0,     0,     0,     0,
      23,    25,    33,     0,    18,    22,     0,     4,    11,    12,
      13,    14,    15,     0,     0,     9,    28,    28,    47,     0,
       0,     0,     0,     0,     0,    32,    35,     0,     0,     2,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    57,    56,    58,    59,     0,     0,
       0,     0,     0,    38,    31,    34,     0,    37,    47,    21,
      20,     0,     0,     0,     0,     0,     6,     0,    51,     0,
      53,    57,     0,     0,    63,     0,     0,    75,    76,    68,
      73,    74,    72,    71,    70,    69,    65,    64,    66,    67,
       0,     0,     0,     0,     7,     0,     0,    27,     0,     0,
      26,    50,     0,    48,     0,     0,     0,     0,    61,     0,
      62,     0,     0,     0,    36,     0,    29,     0,     6,    52,
      45,    44,     0,    60,    39,    41,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,    30,    46,     0,     0,
       0,    10,    40,     0,     0,    43,    42
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     2,    10,     7,     8,    34,    35,    13,    14,    15,
      51,    16,    36,    37,    56,    84,    43,    44,    45,    46,
      47,    48,    87,    88,   110
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const short int yypact[] =
{
      28,    37,    51,    -4,   -80,    31,    54,    25,    42,   -80,
     -49,    76,    77,    62,    25,   -80,    62,    54,    83,   110,
     -80,   -80,    63,    47,   -80,    60,   -34,   -80,   -80,   -80,
     -80,   -80,   -80,    59,    68,   -80,    80,    80,   -23,    81,
       5,     5,   132,    78,   119,    63,   -80,   101,    84,   -80,
     140,    86,   110,   157,   -80,    54,   102,   106,     5,     5,
      11,   129,   -80,   -80,   -80,   -80,   -80,   -80,     5,     5,
      57,    10,   137,   -80,   -80,   -80,     5,   -80,   130,   -80,
     -80,   121,   122,    12,    18,   145,    31,    49,   180,   114,
     -30,   133,   180,     5,    36,   136,    62,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
       5,    62,    33,    79,   -80,   181,   110,   -80,    54,   126,
     -80,   -80,     5,   -80,   141,   142,     5,    50,   -80,   143,
     180,   144,   174,   182,   -80,   156,   -80,    74,    31,   180,
     -80,   -80,   158,   -80,   191,   -80,   216,   213,   190,   110,
     -80,   165,    62,   205,   208,   145,   -80,   -80,   170,    62,
      62,   -80,   -80,   171,   172,   -80,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
     -80,   -80,   -16,   -78,   -80,   -50,   -79,   -80,   -80,   222,
     -80,   -80,   -80,   -80,   200,   -80,   -13,   -80,   -80,   193,
     189,   -80,   147,   -36,   149
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const short int yytable[] =
{
      23,    26,    81,    25,    70,    71,   119,    18,   120,    61,
      62,    63,    19,    64,    65,    90,    62,    63,    93,    91,
      65,   124,    18,    89,    92,    58,    59,    52,    66,    67,
     111,     1,    94,    95,    66,    67,   -49,    68,   132,    83,
     113,     3,   133,    68,    97,    98,    99,   100,   101,   102,
     103,     4,    11,    69,    12,     5,   104,   105,     9,    69,
     150,     6,   106,   107,   108,   109,   136,    38,    18,   117,
     -50,   -50,    17,   116,   130,    96,   161,   118,    39,    40,
      20,    21,    41,   129,    22,    22,   139,    27,    50,    42,
     142,    97,    98,    99,   100,   101,   102,   103,   131,   156,
     121,   143,   137,   104,   105,   122,   122,    49,    53,   106,
     107,   108,   109,    97,    98,    99,   100,   101,   102,   103,
      28,    29,    30,    31,    32,   104,   105,    54,    55,    60,
      18,   106,   107,   108,   109,   149,    72,    73,   134,   158,
      74,    33,    76,    77,    78,    80,   163,   164,    97,    98,
      99,   100,   101,   102,   103,    28,    29,    30,    31,    32,
     104,   105,    82,    85,   123,    86,   106,   107,   108,   109,
      97,    98,    99,   100,   101,   102,   103,    93,   112,    59,
     114,   115,   104,   105,   125,   138,   135,   128,   106,   107,
     108,   109,    97,    98,    99,   100,   101,   102,   103,   146,
     140,   141,   144,   145,   104,   105,   148,   147,   152,   151,
     106,   107,   108,   109,    97,    98,    99,   100,   101,   102,
     103,   153,   154,   155,   157,   159,   104,   105,   160,   162,
     165,   166,   106,   107,   108,   109,    24,    57,    75,    79,
     127,   126
};

static const unsigned char yycheck[] =
{
      13,    17,    52,    16,    40,    41,    85,    56,    86,     4,
       5,     6,    61,     8,     9,     4,     5,     6,    48,     8,
       9,    51,    56,    59,    60,    48,    49,    61,    23,    24,
      20,     3,    68,    69,    23,    24,    59,    32,     5,    55,
      76,     4,     9,    32,    34,    35,    36,    37,    38,    39,
      40,     0,    27,    48,    29,    59,    46,    47,     4,    48,
     138,    30,    52,    53,    54,    55,   116,     4,    56,    51,
      34,    35,    30,    61,   110,    18,   155,    59,    15,    16,
       4,     4,    19,    96,    22,    22,   122,     4,    28,    26,
     126,    34,    35,    36,    37,    38,    39,    40,   111,   149,
      51,    51,   118,    46,    47,    56,    56,    60,    49,    52,
      53,    54,    55,    34,    35,    36,    37,    38,    39,    40,
      10,    11,    12,    13,    14,    46,    47,    59,    48,    48,
      56,    52,    53,    54,    55,    61,     4,    59,    59,   152,
      21,    31,    41,    59,     4,    59,   159,   160,    34,    35,
      36,    37,    38,    39,    40,    10,    11,    12,    13,    14,
      46,    47,     5,    61,    50,    59,    52,    53,    54,    55,
      34,    35,    36,    37,    38,    39,    40,    48,    41,    49,
      59,    59,    46,    47,    51,    59,     5,    51,    52,    53,
      54,    55,    34,    35,    36,    37,    38,    39,    40,    25,
      59,    59,    59,    59,    46,    47,    50,    25,    17,    51,
      52,    53,    54,    55,    34,    35,    36,    37,    38,    39,
      40,     5,     9,    33,    59,    20,    46,    47,    20,    59,
      59,    59,    52,    53,    54,    55,    14,    37,    45,    50,
      93,    92
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,    63,     4,     0,    59,    30,    65,    66,     4,
      64,    27,    29,    69,    70,    71,    73,    30,    56,    61,
       4,     4,    22,    78,    71,    78,    64,     4,    10,    11,
      12,    13,    14,    31,    67,    68,    74,    75,     4,    15,
      16,    19,    26,    78,    79,    80,    81,    82,    83,    60,
      28,    72,    61,    49,    59,    48,    76,    76,    48,    49,
      48,     4,     5,     6,     8,     9,    23,    24,    32,    48,
      85,    85,     4,    59,    21,    81,    41,    59,     4,    82,
      59,    67,     5,    64,    77,    61,    59,    84,    85,    85,
       4,     8,    85,    48,    85,    85,    18,    34,    35,    36,
      37,    38,    39,    40,    46,    47,    52,    53,    54,    55,
      86,    20,    41,    85,    59,    59,    61,    51,    59,    68,
      65,    51,    56,    50,    51,    51,    86,    84,    51,    78,
      85,    78,     5,     9,    59,     5,    67,    64,    59,    85,
      59,    59,    85,    51,    59,    59,    25,    25,    50,    61,
      65,    51,    17,     5,     9,    33,    67,    59,    78,    20,
      20,    68,    59,    78,    78,    59,    59
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 116 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  root=new Program((yyvsp[-5].tIdent),(yyvsp[-3].tDeclarations),(yyvsp[-2].tSubprogram_declarations),(yyvsp[-1].tCompound_statement),lin,col);
						 ;}
    break;

  case 3:
#line 121 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tIdentifier_list)= new Identifier_list((yyvsp[0].tIdent),lin,col);
											  
							;}
    break;

  case 4:
#line 126 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tIdentifier_list) = (yyvsp[-2].tIdentifier_list);
								(yyval.tIdentifier_list)->AddIdent((yyvsp[0].tIdent));
							;}
    break;

  case 5:
#line 132 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
					   (yyval.tDeclarations)=(yyvsp[0].tDeclarations);
					   ;}
    break;

  case 6:
#line 136 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
					   (yyval.tDeclarations)=new Declarations(lin,col);
					   ;}
    break;

  case 7:
#line 141 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						    (yyval.tDeclarations)=(yyvsp[-5].tDeclarations);
						    (yyval.tDeclarations)->AddDeclarations((yyvsp[-3].tIdentifier_list),(yyvsp[-1].tType));
							for(int k=0;k<(yyvsp[-3].tIdentifier_list)->idents->size();k++)
						       {
							     if((yyvsp[-1].tType)->isArray==0)
							       symbolTable->AddSymbol((yyvsp[-3].tIdentifier_list)->idents->at(k), current_kind  ,  (yyvsp[-1].tType)->type,0,0 );
								 else
				                   symbolTable->AddSymbol((yyvsp[-3].tIdentifier_list)->idents->at(k), current_kind  ,  (yyvsp[-1].tType)->type,(yyvsp[-1].tType)->beginning->num,(yyvsp[-1].tType)->end->num );
								   

							   }
						    ;}
    break;

  case 8:
#line 155 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						     (yyval.tDeclarations)=new Declarations((yyvsp[-3].tIdentifier_list),(yyvsp[-1].tType),lin,col);
							 for(int k=0;k<(yyvsp[-3].tIdentifier_list)->idents->size();k++)
							   {
							     if((yyvsp[-1].tType)->isArray==0)
							        symbolTable->AddSymbol((yyvsp[-3].tIdentifier_list)->idents->at(k), current_kind  ,  (yyvsp[-1].tType)->type,0,0 );
								 else
								    symbolTable->AddSymbol((yyvsp[-3].tIdentifier_list)->idents->at(k), current_kind  ,  (yyvsp[-1].tType)->type,(yyvsp[-1].tType)->beginning->num,(yyvsp[-1].tType)->end->num );
									
							   }
						   ;}
    break;

  case 9:
#line 168 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tType)=new Type((yyvsp[0].tStandard_type),lin,col);
							;}
    break;

  case 10:
#line 172 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tType)=new Array((yyvsp[-5].tExpInt),(yyvsp[-3].tExpInt),(yyvsp[0].tStandard_type),lin,col);
							;}
    break;

  case 11:
#line 177 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tStandard_type)=1;
							;}
    break;

  case 12:
#line 181 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tStandard_type)=2;
							;}
    break;

  case 13:
#line 185 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tStandard_type)=3;
							;}
    break;

  case 14:
#line 189 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tStandard_type)=4;
							;}
    break;

  case 15:
#line 193 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tStandard_type)=5;
							;}
    break;

  case 16:
#line 198 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
									(yyval.tSubprogram_declarations)=(yyvsp[0].tSubprogram_declarations);
								;}
    break;

  case 17:
#line 202 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
									(yyval.tSubprogram_declarations)=new Subprogram_declarations(lin,col);
								;}
    break;

  case 18:
#line 208 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								  (yyval.tSubprogram_declarations)=(yyvsp[-1].tSubprogram_declarations);
								  (yyval.tSubprogram_declarations)->AddSubprogram_declaration((yyvsp[0].tSubprogram_declaration));
							    ;}
    break;

  case 19:
#line 213 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tSubprogram_declarations)=new Subprogram_declarations((yyvsp[0].tSubprogram_declaration),lin,col);
					          ;}
    break;

  case 20:
#line 218 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tSubprogram_declaration)=new Subprogram_declaration((yyvsp[-3].tSubprogram_head),(yyvsp[-2].tCompound_statement),(yyvsp[-1].tReturn_stmt),lin,col);
						 ;}
    break;

  case 21:
#line 223 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
			   (yyval.tReturn_stmt)=new Return_stmt((yyvsp[0].tVariable),lin,col);
			    if (ifScope==1)
						     {
						     symbolTable->CloseScope(); 
							  current_kind=3;
						      ifScope=0;
						     }
			 ;}
    break;

  case 22:
#line 233 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
			   (yyval.tReturn_stmt)=new Return_stmt(lin,col);
			    if (ifScope==1)
						     {
						     symbolTable->CloseScope(); 
							  current_kind=3;
						      ifScope=0;
						     }
			 ;}
    break;

  case 23:
#line 243 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {	
                                        symbolTable->NewScope(); 
										 ifScope=1;
								        current_kind=1;
										;}
    break;

  case 24:
#line 248 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						                                                           (yyval.tSubprogram_head)=new Function((yyvsp[-2].tStandard_type),(yyvsp[-6].tIdent),(yyvsp[-4].tArguments),(yyvsp[0].tDeclarations),lin,col);
																				   symbolTable->AddFunc((yyvsp[-6].tIdent),3,(yyvsp[-4].tArguments),(yyvsp[-2].tStandard_type),(yyval.tSubprogram_head));

							                                                      // symbolTable->CloseScope(); 
																				  //   current_kind=3;
				
                                                                                    ;}
    break;

  case 25:
#line 256 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
					                     symbolTable->NewScope(); 
										 ifScope=0; 
										 current_kind=1;
										 ;}
    break;

  case 26:
#line 261 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						                                              (yyval.tSubprogram_head)=new Procedure((yyvsp[-4].tIdent),(yyvsp[-2].tArguments),(yyvsp[0].tDeclarations),lin,col);
																	  symbolTable->AddFunc((yyvsp[-4].tIdent),3,(yyvsp[-2].tArguments),0,(yyval.tSubprogram_head));
						                                             // symbolTable->CloseScope(); 
																	  // current_kind=3;
					                                                  ;}
    break;

  case 27:
#line 269 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tArguments)=new Arguments((yyvsp[-1].tParameter_list),lin,col);
							;}
    break;

  case 28:
#line 273 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						   (yyval.tArguments)=new Arguments(lin,col);
						    ;}
    break;

  case 29:
#line 278 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						   (yyval.tParameter_list)=new Parameter_list((yyvsp[-2].tIdentifier_list),(yyvsp[0].tType),lin,col);
						   for(int l=0;l<(yyvsp[-2].tIdentifier_list)->idents->size();l++)
						    {
							   if((yyvsp[0].tType)->isArray==0)
							     symbolTable->AddSymbol((yyvsp[-2].tIdentifier_list)->idents->at(l), 1  ,  (yyvsp[0].tType)->type,0,0 );
							   else
							     symbolTable->AddSymbol((yyvsp[-2].tIdentifier_list)->idents->at(l), 1  ,  (yyvsp[0].tType)->type,(yyvsp[0].tType)->beginning->num,(yyvsp[0].tType)->end->num );
							}

						   ;}
    break;

  case 30:
#line 290 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						   (yyval.tParameter_list)=(yyvsp[-4].tParameter_list);
						   (yyval.tParameter_list)->AddParameter_list((yyvsp[-2].tIdentifier_list),(yyvsp[0].tType));
						   for(int l=0;l<(yyvsp[-2].tIdentifier_list)->idents->size();l++)
						   {
						    if((yyvsp[0].tType)->isArray==0)
						       symbolTable->AddSymbol((yyvsp[-2].tIdentifier_list)->idents->at(l), 1  ,  (yyvsp[0].tType)->type,0,0 );
							else
			                   symbolTable->AddSymbol((yyvsp[-2].tIdentifier_list)->idents->at(l), 1  ,  (yyvsp[0].tType)->type,(yyvsp[0].tType)->beginning->num,(yyvsp[0].tType)->end->num );

						   }

						   ;}
    break;

  case 31:
#line 305 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						   (yyval.tCompound_statement)=new Compound_statement ((yyvsp[-1].tStatement_list),lin,col);
						//   if (ifScope==1)
						  //   {
						//     symbolTable->CloseScope(); 
							//  current_kind=3;
						   //   ifScope=0;
						    // }
						   ;}
    break;

  case 32:
#line 316 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement_list)=(yyvsp[0].tStatement_list);
						  ;}
    break;

  case 33:
#line 320 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						   (yyval.tStatement_list)=new Statement_list(lin,col);
						   ;}
    break;

  case 34:
#line 325 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tStatement_list)=(yyvsp[-1].tStatement_list);
						 (yyval.tStatement_list)->AddStatement_list((yyvsp[0].tStatement));
						 ;}
    break;

  case 35:
#line 330 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tStatement_list)=new Statement_list((yyvsp[0].tStatement),lin,col);
						 ;}
    break;

  case 36:
#line 335 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement)=new StmtAssign((yyvsp[-3].tVariable), (yyvsp[-1].tExpression),lin,col);
						 ;}
    break;

  case 37:
#line 339 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement)=new StmtProcedure((yyvsp[-1].tProcedure_statement),lin,col);
					     ;}
    break;

  case 38:
#line 343 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement)=new StmtCompound((yyvsp[-1].tCompound_statement),lin,col);
					     ;}
    break;

  case 39:
#line 347 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement)=new StmtIf((yyvsp[-3].tExpression),(yyvsp[-1].tCompound_statement),lin,col);
					     ;}
    break;

  case 40:
#line 351 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement)=new StmtIfElse((yyvsp[-6].tExpression),(yyvsp[-4].tCompound_statement),(yyvsp[-1].tCompound_statement),lin,col);
					     ;}
    break;

  case 41:
#line 355 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement)=new StmtWhile((yyvsp[-3].tExpression),(yyvsp[-1].tCompound_statement),lin,col);
					     ;}
    break;

  case 42:
#line 359 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement)=new StmtFor((yyvsp[-7].tIdent),(yyvsp[-5].tExpChar),(yyvsp[-3].tExpChar),(yyvsp[-1].tCompound_statement),lin,col);
						   symbolTable->LookUpSymbol((yyvsp[-7].tIdent));
					     ;}
    break;

  case 43:
#line 364 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement)=new StmtFor((yyvsp[-7].tIdent),(yyvsp[-5].tExpInt),(yyvsp[-3].tExpInt),(yyvsp[-1].tCompound_statement),lin,col);
						  symbolTable->LookUpSymbol((yyvsp[-7].tIdent));
					      ;}
    break;

  case 44:
#line 369 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						   (yyval.tStatement)=new StmtWriteStr((yyvsp[-2].tExpStr),lin,col);
						  ;}
    break;

  case 45:
#line 373 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement)=new StmtWriteId((yyvsp[-2].tIdent),lin,col);
						  symbolTable->LookUpSymbol((yyvsp[-2].tIdent));
						 ;}
    break;

  case 46:
#line 378 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tStatement)=new StmtWriteExp((yyvsp[-4].tExpression),(yyvsp[-3].tUnary_operator),(yyvsp[-2].tExpression),lin,col);
					     ;}
    break;

  case 47:
#line 383 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tVariable)=new Variable((yyvsp[0].tIdent),lin,col);
						 symbolTable->LookUpSymbol((yyvsp[0].tIdent));
						 ;}
    break;

  case 48:
#line 388 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tVariable)=new Variable((yyvsp[-3].tIdent),(yyvsp[-1].tExpression),lin,col); 
						 symbolTable->LookUpSymbol((yyvsp[-3].tIdent));
						 ;}
    break;

  case 49:
#line 394 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tProcedure_statement)=new Procedure_statement((yyvsp[0].tIdent),lin,col);
								symbolTable->LookUpSymbol((yyvsp[0].tIdent));
							;}
    break;

  case 50:
#line 399 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
								(yyval.tProcedure_statement)=new Procedure_statement((yyvsp[-3].tIdent),(yyvsp[-1].tExpression_list),lin,col);
								//symbolTable->LookUpFunc($1,$3);
					   ;}
    break;

  case 51:
#line 405 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tExpression_list)=new Expression_list((yyvsp[0].tExpression),lin,col);
						;}
    break;

  case 52:
#line 409 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tExpression_list)=(yyvsp[-2].tExpression_list);
							(yyval.tExpression_list)->AddExpression((yyvsp[0].tExpression));
					   ;}
    break;

  case 53:
#line 415 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tExpression)=new ExpIdent((yyvsp[0].tIdent),lin,col);
						 symbolTable->LookUpSymbol((yyvsp[0].tIdent));
						 ;}
    break;

  case 54:
#line 420 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tExpression)=(yyvsp[0].tExpInt);
						 ;}
    break;

  case 55:
#line 424 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tExpression)=(yyvsp[0].tExpReal);
						 ;}
    break;

  case 56:
#line 428 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						  (yyval.tExpression)=(yyvsp[0].tExpChar);
						 ;}
    break;

  case 57:
#line 432 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tExpression)=(yyvsp[0].tExpStr);
					     ;}
    break;

  case 58:
#line 436 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tExpression)=new ExpTrue(lin,col);
						 ;}
    break;

  case 59:
#line 440 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tExpression)=new ExpFalse(lin,col);
						 ;}
    break;

  case 60:
#line 444 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tExpression)=new ExpInner ((yyvsp[-3].tIdent),(yyvsp[-1].tExpression_list),lin,col);
						 //symbolTable->LookUpSymbol($1);
						 ;}
    break;

  case 61:
#line 449 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tExpression)=new Expr((yyvsp[-1].tExpression),lin,col);
						 ;}
    break;

  case 62:
#line 453 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tExpression)=new ExpOpt((yyvsp[-2].tExpression),(yyvsp[-1].tUnary_operator),(yyvsp[0].tExpression),lin,col);
						 ;}
    break;

  case 63:
#line 457 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
						 (yyval.tExpression)=new ExpNot((yyvsp[0].tExpression),lin,col);
						 ;}
    break;

  case 64:
#line 462 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=1;
						;}
    break;

  case 65:
#line 466 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=2;
						;}
    break;

  case 66:
#line 470 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=3;
						;}
    break;

  case 67:
#line 474 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=4;
						;}
    break;

  case 68:
#line 478 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=5;
						;}
    break;

  case 69:
#line 482 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=6;
						;}
    break;

  case 70:
#line 486 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=7;
						;}
    break;

  case 71:
#line 490 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=8;
						;}
    break;

  case 72:
#line 494 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=9;
						;}
    break;

  case 73:
#line 498 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=10;
						;}
    break;

  case 74:
#line 502 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=11;
						;}
    break;

  case 75:
#line 506 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=12;
						;}
    break;

  case 76:
#line 510 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"
    {
							(yyval.tUnary_operator)=13;
						;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 1996 "parser.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 514 "C:\\Users\\hp\\Documents\\Visual Studio 2015\\Projects\\Project2\\Project2\\parser.y"

int yyerror(const char* s){
cout<<"something went wrong"<<endl;
return 1;
}
