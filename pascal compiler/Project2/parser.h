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
/* Line 1447 of yacc.c.  */
#line 159 "parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



