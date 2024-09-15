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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ATRIBUICAO = 258,              /* ATRIBUICAO  */
    ADICAO = 259,                  /* ADICAO  */
    SUBTRACAO = 260,               /* SUBTRACAO  */
    MULTIPLICACAO = 261,           /* MULTIPLICACAO  */
    DIVISAO = 262,                 /* DIVISAO  */
    PONTOVIRGULA = 263,            /* PONTOVIRGULA  */
    VIRGULA = 264,                 /* VIRGULA  */
    PARENTESESQUERDO = 265,        /* PARENTESESQUERDO  */
    PARENTESEDIREITO = 266,        /* PARENTESEDIREITO  */
    COLCHETESQUERDO = 267,         /* COLCHETESQUERDO  */
    COLCHETEDIREITO = 268,         /* COLCHETEDIREITO  */
    CHAVESQUERDA = 269,            /* CHAVESQUERDA  */
    CHAVEDIREITA = 270,            /* CHAVEDIREITA  */
    MENOR = 271,                   /* MENOR  */
    MENORIGUAL = 272,              /* MENORIGUAL  */
    MAIOR = 273,                   /* MAIOR  */
    MAIORIGUAL = 274,              /* MAIORIGUAL  */
    IGUAL = 275,                   /* IGUAL  */
    DIFERENTE = 276,               /* DIFERENTE  */
    IF = 277,                      /* IF  */
    ELSE = 278,                    /* ELSE  */
    WHILE = 279,                   /* WHILE  */
    RETURN = 280,                  /* RETURN  */
    VOID = 281,                    /* VOID  */
    INT = 282,                     /* INT  */
    FLOAT = 283,                   /* FLOAT  */
    LEIA = 284,                    /* LEIA  */
    ESCREVA = 285,                 /* ESCREVA  */
    MAIN = 286,                    /* MAIN  */
    IDENTIFICADOR = 287,           /* IDENTIFICADOR  */
    NUMERO = 288,                  /* NUMERO  */
    UMINUS = 289                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ATRIBUICAO 258
#define ADICAO 259
#define SUBTRACAO 260
#define MULTIPLICACAO 261
#define DIVISAO 262
#define PONTOVIRGULA 263
#define VIRGULA 264
#define PARENTESESQUERDO 265
#define PARENTESEDIREITO 266
#define COLCHETESQUERDO 267
#define COLCHETEDIREITO 268
#define CHAVESQUERDA 269
#define CHAVEDIREITA 270
#define MENOR 271
#define MENORIGUAL 272
#define MAIOR 273
#define MAIORIGUAL 274
#define IGUAL 275
#define DIFERENTE 276
#define IF 277
#define ELSE 278
#define WHILE 279
#define RETURN 280
#define VOID 281
#define INT 282
#define FLOAT 283
#define LEIA 284
#define ESCREVA 285
#define MAIN 286
#define IDENTIFICADOR 287
#define NUMERO 288
#define UMINUS 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "sintatico.y"

    char *cadeia;
    int intval;


#line 141 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
