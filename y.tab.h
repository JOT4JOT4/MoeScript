/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 1 "parser.y"

    #include <vector>
    #include <memory>
    #include "ast.h"


/* Line 2058 of yacc.c  */
#line 53 "y.tab.h"

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
     INTEGER = 262,
     FLOAT = 263,
     BOOLEAN = 264,
     PRINT = 265,
     READ = 266,
     NEW = 267,
     FUNC = 268,
     RETURN = 269,
     IDENTIFICADOR = 270,
     CONST_INTEGER = 271,
     CONST_FLOAT = 272,
     CONST_CADENA = 273,
     OP_SUMA = 274,
     OP_RESTA = 275,
     OP_MULT = 276,
     OP_DIV = 277,
     OP_IGUAL = 278,
     OP_MAYOR = 279,
     OP_MENOR = 280,
     OP_MAYORIGUAL = 281,
     OP_MENORIGUAL = 282,
     OP_COMP_IGUAL = 283,
     OP_NEGACION = 284,
     OP_DISTINTO = 285,
     LLAVE_A = 286,
     LLAVE_C = 287,
     PARENTESIS_A = 288,
     PARENTESIS_C = 289,
     FIN_SENTENCIA = 290,
     CHAR_COMA = 291,
     CHAR_PUNTO = 292,
     CHAR_PUNTOYCOMA = 293,
     CHAR_DOSPUNTOS = 294,
     INI_COMENTARIO = 295,
     FIN_COMENTARIO = 296
   };
#endif
/* Tokens.  */
#define IF 258
#define WHILE 259
#define FOR 260
#define ELSE 261
#define INTEGER 262
#define FLOAT 263
#define BOOLEAN 264
#define PRINT 265
#define READ 266
#define NEW 267
#define FUNC 268
#define RETURN 269
#define IDENTIFICADOR 270
#define CONST_INTEGER 271
#define CONST_FLOAT 272
#define CONST_CADENA 273
#define OP_SUMA 274
#define OP_RESTA 275
#define OP_MULT 276
#define OP_DIV 277
#define OP_IGUAL 278
#define OP_MAYOR 279
#define OP_MENOR 280
#define OP_MAYORIGUAL 281
#define OP_MENORIGUAL 282
#define OP_COMP_IGUAL 283
#define OP_NEGACION 284
#define OP_DISTINTO 285
#define LLAVE_A 286
#define LLAVE_C 287
#define PARENTESIS_A 288
#define PARENTESIS_C 289
#define FIN_SENTENCIA 290
#define CHAR_COMA 291
#define CHAR_PUNTO 292
#define CHAR_PUNTOYCOMA 293
#define CHAR_DOSPUNTOS 294
#define INI_COMENTARIO 295
#define FIN_COMENTARIO 296



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 16 "parser.y"

    int ival;
    float fval;
    char* sval;
    ASTNode* node;
    std::vector<std::unique_ptr<ASTNode>>* vec;
    std::vector<std::string>* strvec;


/* Line 2058 of yacc.c  */
#line 160 "y.tab.h"
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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
