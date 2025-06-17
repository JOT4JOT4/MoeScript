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
/* Line 2058 of yacc.c  */
#line 1 "parser.y"

    #include <vector>
    #include <memory>
    #include "ast.hpp"


/* Line 2058 of yacc.c  */
#line 53 "parser.tab.h"

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
/* Line 2058 of yacc.c  */
#line 17 "parser.y"

    int ival;
    float fval;
    char* sval;
    ASTNode* node;
    std::vector<std::unique_ptr<ASTNode>>* vec;
    std::vector<std::string>* strvec;


/* Line 2058 of yacc.c  */
#line 120 "parser.tab.h"
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
