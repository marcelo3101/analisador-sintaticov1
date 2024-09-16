/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20221106

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "sintatico.y"
#include <stdio.h>
#include <stdlib.h> /* malloc*/
#include <string.h> /* strcmp*/
#include "tabela_de_simbolos.h"
#include "code_generator.h"

#define MAX_ERRORS 16
#define MAX_STR_SIZE 128

#define MAX_STACK_SIZE 32
#define stack_push(sp, n) (*((sp)++) = (n))
#define stack_pop(sp) (*--(sp))

char errors[MAX_ERRORS][MAX_STR_SIZE];
int number_of_errors = 0;

int declarar(char* nome) {
    simbolo* s = procurar_simbolo(nome);

    if (s != NULL) {
        sprintf(errors[number_of_errors++], "ERRO: O identificador \"%s\" já está definido\n", nome);
        return -1;
    }

    s = adicionar_simbolo(nome);
    return 0;
}

int utilizar(char* nome) {
    simbolo* s = procurar_simbolo(nome);

    if (s == NULL) {
        sprintf(errors[number_of_errors++], "ERRO: O identificador \"%s\" não foi definido\n", nome);
        return -1;
    }

    s->usada = 1;
    return s->offset;
}

/* prototipos*/
int data_location();
int get_code_offset();
int add_code_offset(int amount);

void gen_code(enum code_ops operation, int arg0, int arg1, int arg2);
void make_code(int addr, enum code_ops operation, int arg0, int arg1, int arg2);

void pop();
void push();
void copy(enum Regs from, enum Regs to);

void initializeProgram();
void ari_op(enum code_ops op);

void print_code();

int stack1[MAX_STACK_SIZE], stack2[MAX_STACK_SIZE], stack3[MAX_STACK_SIZE], stack4[MAX_STACK_SIZE], stack5[MAX_STACK_SIZE];

int *start_if_ptr = stack1, *start_else_ptr = stack2, *start_comp_ptr = stack3, *start_while_ptr = stack4, *end_while_ptr = stack5;

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 65 "sintatico.y"
typedef union YYSTYPE {
    char *cadeia;
    int intval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 98 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ATRIBUICAO 257
#define ADICAO 258
#define SUBTRACAO 259
#define MULTIPLICACAO 260
#define DIVISAO 261
#define PONTOVIRGULA 262
#define VIRGULA 263
#define PARENTESESQUERDO 264
#define PARENTESEDIREITO 265
#define COLCHETESQUERDO 266
#define COLCHETEDIREITO 267
#define CHAVESQUERDA 268
#define CHAVEDIREITA 269
#define MENOR 270
#define MENORIGUAL 271
#define MAIOR 272
#define MAIORIGUAL 273
#define IGUAL 274
#define DIFERENTE 275
#define IF 276
#define ELSE 277
#define WHILE 278
#define RETURN 279
#define VOID 280
#define INT 281
#define FLOAT 282
#define LEIA 283
#define ESCREVA 284
#define MAIN 285
#define THEN 286
#define IDENTIFICADOR 287
#define NUMERO 288
#define UMINUS 289
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    4,    5,    0,    2,    2,    2,    6,    7,    7,    3,
    3,    8,    8,    8,    8,    8,    8,    9,    9,   16,
   10,   17,   18,   19,   10,   20,   21,   22,   11,   12,
   12,   13,   14,   15,   15,    1,   24,   24,   24,   24,
   24,   24,   24,   25,   25,   25,   25,   25,   26,   26,
   23,   23,   23,   23,   23,   23,   23,   23,
};
static const YYINT yylen[] = {                            2,
    0,    0,   11,    2,    1,    0,    3,    1,    1,    2,
    0,    1,    1,    1,    1,    1,    1,    2,    1,    0,
    9,    0,    0,    0,   14,    0,    0,    0,   10,    2,
    3,    5,    5,    3,    1,    1,    3,    3,    3,    3,
    3,    3,    1,    1,    3,    3,    3,    3,    0,    1,
    3,    3,    3,    3,    3,    1,    1,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    8,    9,    0,
    5,    0,   11,    4,    0,    0,    7,   19,    0,    0,
    0,    0,    0,    0,    0,   57,    0,   56,    0,   10,
   12,   13,   14,   15,   16,   17,    0,    0,   35,    0,
    0,    0,    0,   26,   30,    0,    0,    0,    0,   58,
    3,   18,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   51,    0,    0,   31,
    0,   36,    0,   34,    0,    0,   54,   55,   37,   38,
   39,   40,   41,   42,   45,   46,   47,   48,    0,   27,
    0,    0,   22,    0,    0,   32,   33,   11,   20,    0,
    0,   11,   11,    0,    0,    0,    0,   21,    0,   23,
   29,   11,    0,    0,   25,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  281,  291,  285,  264,  280,  265,  268,  280,  281,  293,
  297,  298,  295,  297,  287,  294,  262,  262,  264,  276,
  278,  279,  283,  284,  287,  288,   45,  292,  296,  299,
  300,  301,  302,  303,  304,  305,  306,  314,  315,  316,
  317,  306,  264,  264,  262,  306,  264,  264,  257,  288,
  269,  262,  258,  259,  260,  261,  270,  271,  272,  273,
  274,  275,  258,  259,  260,  261,  265,  306,  311,  262,
  287,  287,  314,  306,  314,  314,  314,  314,  316,  316,
  316,  316,  316,  316,  317,  317,  317,  317,  265,  306,
  265,  265,  268,  286,  312,  262,  262,  308,  268,  265,
  294,  307,  268,  269,  294,  294,  277,  269,  313,  268,
  269,  309,  294,  310,  269,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          2,
   28,   10,   16,   13,   29,   11,   12,   30,   31,   32,
   33,   34,   35,   36,   37,  102,   98,  112,  114,   69,
   95,  109,   38,   39,   40,   41,
};
static const YYINT yysindex[] = {                      -277,
 -278,    0, -248, -266, -235, -227, -252,    0,    0, -252,
    0, -245,    0,    0, -219,   44,    0,    0,   -1, -213,
 -207,   53, -177, -176, -167,    0, -229,    0, -178,    0,
    0,    0,    0,    0,    0,    0, -163, -179,    0, -147,
 -113, -168,   -1,    0,    0, -151, -158,   47,   -1,    0,
    0,    0,   47,   47,   47,   47,   47,   47,   47,   47,
   47,   47,   47,   47,   47,   47,    0, -126,   -1,    0,
 -125,    0,   20,    0, -222, -222,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -267,    0,
 -120, -119,    0, -111, -107,    0,    0,    0,    0, -108,
   13,    0,    0, -116,   26,   44,  -94,    0,  -92,    0,
    0,    0,   44,  -91,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,  -45,    0,    0,  -14,
    0,    0,    0,    0,    0, -205,    0,    0, -165,    0,
    0, -198,    0,    0, -250,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -89,    0, -259,
  -75,    0, -165,    0,    0,    0,    0,    0, -225,    0,
    0,    0,    0,    0,    0,    0,  -57,  -57,  -57,  -57,
  -57,  -57,   74,   74,   74,   74,    0,    0, -165,    0,
    0,    0,    0,    0, -121, -103,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -198,    0,    0,    0, -198, -157,    0,    0,    0,    0,
    0,    0, -139,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,    0,  -85,    0,    0,  165,    0,    0,    0,    0,
    0,    0,    0,    0,  -17,    0,    0,    0,    0,    0,
    0,    0,   30,    0,  293,  100,
};
#define YYTABLESIZE 355
static const YYINT yytable[] = {                          6,
   93,   42,   43,    1,   46,   43,    3,   36,   36,   36,
   36,   36,  101,    5,   36,    4,  105,  106,   94,   36,
   36,   36,   36,   36,   36,   68,  113,    8,    9,    6,
    1,   74,   49,   49,   49,   49,   49,   55,   56,   49,
    7,   15,   17,   27,   49,   49,   49,   49,   49,   49,
   43,   90,   49,   49,   49,   49,   44,   27,   50,   49,
   49,   49,   49,    2,   49,   49,   49,   49,   49,   49,
   27,   49,   49,   49,   49,   49,   49,   73,   53,   54,
   55,   56,   75,   76,   77,   78,   47,   48,   27,   49,
   51,   27,   49,   49,   49,   49,   67,   27,   52,   49,
   49,   49,   49,   49,   49,   49,   49,   49,   49,   49,
   70,   28,   49,   49,   49,   49,   49,   49,   49,   49,
   49,   49,   57,   58,   59,   60,   61,   62,   71,   24,
   49,   49,   49,   49,   49,   49,   52,   52,   89,   91,
   52,   96,   97,   52,   63,   64,   65,   66,   52,   52,
   52,   52,   52,   52,   53,   53,   99,  100,   53,  103,
  107,   53,   85,   86,   87,   88,   53,   53,   53,   53,
   53,   53,   50,  110,   14,   50,  111,  115,    0,    0,
   50,   50,   50,   50,   50,   50,   44,    0,    0,   44,
    0,    0,    0,    0,   44,   44,   44,   44,   44,   44,
   49,   49,   49,   49,   49,    0,    0,   49,    0,    0,
    0,    0,    6,    6,    6,    6,    6,    0,    6,    0,
    0,    0,    0,    6,    6,    6,    6,    6,    6,    6,
    6,    0,    6,    6,    0,    0,    0,    6,    6,    0,
    0,    6,    6,    1,    1,    1,    1,    1,    0,    1,
    0,    0,    0,    0,    1,    1,    1,    1,    1,    1,
    1,    1,   19,    1,    1,    0,    0,    0,    1,    1,
    0,    0,    1,    1,   18,    0,   19,   53,   54,   55,
   56,  104,    0,    0,   92,   25,   26,   18,   20,   19,
   21,   22,    0,    0,  108,   23,   24,    0,    0,   25,
   26,   20,    0,   21,   22,   18,    0,   19,   23,   24,
   19,    0,   25,   26,   45,    0,   19,    0,    0,   20,
    0,   21,   22,    0,    0,    0,   23,   24,    0,    0,
   25,   26,    0,   72,   26,   49,    0,    0,   49,   25,
   26,    0,    0,   49,   49,   49,   49,   49,   49,   79,
   80,   81,   82,   83,   84,
};
static const YYINT yycheck[] = {                         45,
  268,   19,  262,  281,   22,  265,  285,  258,  259,  260,
  261,  262,   98,  280,  265,  264,  102,  103,  286,  270,
  271,  272,  273,  274,  275,   43,  112,  280,  281,  265,
   45,   49,  258,  259,  260,  261,  262,  260,  261,  265,
  268,  287,  262,   45,  270,  271,  272,  273,  274,  275,
  264,   69,  258,  259,  260,  261,  264,   45,  288,  258,
  259,  260,  261,  269,  270,  271,  272,  273,  274,  275,
   45,  270,  271,  272,  273,  274,  275,   48,  258,  259,
  260,  261,   53,   54,   55,   56,  264,  264,   45,  257,
  269,   45,  258,  259,  260,  261,  265,   45,  262,  265,
  258,  259,  260,  261,  270,  271,  272,  273,  274,  275,
  262,  269,  270,  271,  272,  273,  274,  275,  258,  259,
  260,  261,  270,  271,  272,  273,  274,  275,  287,  269,
  270,  271,  272,  273,  274,  275,  258,  259,  265,  265,
  262,  262,  262,  265,  258,  259,  260,  261,  270,  271,
  272,  273,  274,  275,  258,  259,  268,  265,  262,  268,
  277,  265,   63,   64,   65,   66,  270,  271,  272,  273,
  274,  275,  262,  268,   10,  265,  269,  269,   -1,   -1,
  270,  271,  272,  273,  274,  275,  262,   -1,   -1,  265,
   -1,   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,
  258,  259,  260,  261,  262,   -1,   -1,  265,   -1,   -1,
   -1,   -1,  258,  259,  260,  261,  262,   -1,  264,   -1,
   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,  275,
  276,   -1,  278,  279,   -1,   -1,   -1,  283,  284,   -1,
   -1,  287,  288,  258,  259,  260,  261,  262,   -1,  264,
   -1,   -1,   -1,   -1,  269,  270,  271,  272,  273,  274,
  275,  276,  264,  278,  279,   -1,   -1,   -1,  283,  284,
   -1,   -1,  287,  288,  262,   -1,  264,  258,  259,  260,
  261,  269,   -1,   -1,  265,  287,  288,  262,  276,  264,
  278,  279,   -1,   -1,  269,  283,  284,   -1,   -1,  287,
  288,  276,   -1,  278,  279,  262,   -1,  264,  283,  284,
  264,   -1,  287,  288,  262,   -1,  264,   -1,   -1,  276,
   -1,  278,  279,   -1,   -1,   -1,  283,  284,   -1,   -1,
  287,  288,   -1,  287,  288,  262,   -1,   -1,  265,  287,
  288,   -1,   -1,  270,  271,  272,  273,  274,  275,   57,
   58,   59,   60,   61,   62,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 289
#define YYUNDFTOKEN 318
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'-'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","ATRIBUICAO","ADICAO",
"SUBTRACAO","MULTIPLICACAO","DIVISAO","PONTOVIRGULA","VIRGULA",
"PARENTESESQUERDO","PARENTESEDIREITO","COLCHETESQUERDO","COLCHETEDIREITO",
"CHAVESQUERDA","CHAVEDIREITA","MENOR","MENORIGUAL","MAIOR","MAIORIGUAL","IGUAL",
"DIFERENTE","IF","ELSE","WHILE","RETURN","VOID","INT","FLOAT","LEIA","ESCREVA",
"MAIN","THEN","IDENTIFICADOR","NUMERO","UMINUS","$accept","programa","variavel",
"lista_declaracoes","lista_afirmacoes","$$1","$$2","declaracao_var","tipo",
"afirmacao","afirmacao_expressao","afirmacao_selecao","afirmacao_iterativa",
"afirmacao_retorno","afirmacao_leia","afirmacao_escreva","expressao","$$3",
"$$4","$$5","$$6","$$7","$$8","$$9","fator","expressao_simples",
"expressao_matematica","termo","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"$$1 :",
"$$2 :",
"programa : INT MAIN PARENTESESQUERDO VOID PARENTESEDIREITO CHAVESQUERDA lista_declaracoes $$1 lista_afirmacoes $$2 CHAVEDIREITA",
"lista_declaracoes : lista_declaracoes declaracao_var",
"lista_declaracoes : declaracao_var",
"lista_declaracoes :",
"declaracao_var : tipo IDENTIFICADOR PONTOVIRGULA",
"tipo : VOID",
"tipo : INT",
"lista_afirmacoes : lista_afirmacoes afirmacao",
"lista_afirmacoes :",
"afirmacao : afirmacao_expressao",
"afirmacao : afirmacao_selecao",
"afirmacao : afirmacao_iterativa",
"afirmacao : afirmacao_retorno",
"afirmacao : afirmacao_leia",
"afirmacao : afirmacao_escreva",
"afirmacao_expressao : expressao PONTOVIRGULA",
"afirmacao_expressao : PONTOVIRGULA",
"$$3 :",
"afirmacao_selecao : IF PARENTESESQUERDO expressao PARENTESEDIREITO THEN CHAVESQUERDA $$3 lista_afirmacoes CHAVEDIREITA",
"$$4 :",
"$$5 :",
"$$6 :",
"afirmacao_selecao : IF PARENTESESQUERDO expressao PARENTESEDIREITO CHAVESQUERDA $$4 lista_afirmacoes CHAVEDIREITA ELSE CHAVESQUERDA $$5 lista_afirmacoes $$6 CHAVEDIREITA",
"$$7 :",
"$$8 :",
"$$9 :",
"afirmacao_iterativa : WHILE PARENTESESQUERDO $$7 expressao $$8 PARENTESEDIREITO CHAVESQUERDA lista_afirmacoes $$9 CHAVEDIREITA",
"afirmacao_retorno : RETURN PONTOVIRGULA",
"afirmacao_retorno : RETURN expressao PONTOVIRGULA",
"afirmacao_leia : LEIA PARENTESESQUERDO IDENTIFICADOR PARENTESEDIREITO PONTOVIRGULA",
"afirmacao_escreva : ESCREVA PARENTESESQUERDO fator PARENTESEDIREITO PONTOVIRGULA",
"expressao : IDENTIFICADOR ATRIBUICAO expressao",
"expressao : expressao_simples",
"variavel : IDENTIFICADOR",
"expressao_simples : expressao_matematica MENOR expressao_matematica",
"expressao_simples : expressao_matematica MENORIGUAL expressao_matematica",
"expressao_simples : expressao_matematica MAIOR expressao_matematica",
"expressao_simples : expressao_matematica MAIORIGUAL expressao_matematica",
"expressao_simples : expressao_matematica IGUAL expressao_matematica",
"expressao_simples : expressao_matematica DIFERENTE expressao_matematica",
"expressao_simples : expressao_matematica",
"expressao_matematica : termo",
"expressao_matematica : termo ADICAO termo",
"expressao_matematica : termo SUBTRACAO termo",
"expressao_matematica : termo MULTIPLICACAO termo",
"expressao_matematica : termo DIVISAO termo",
"termo :",
"termo : fator",
"fator : PARENTESESQUERDO expressao PARENTESEDIREITO",
"fator : fator ADICAO fator",
"fator : fator SUBTRACAO fator",
"fator : fator MULTIPLICACAO fator",
"fator : fator DIVISAO fator",
"fator : variavel",
"fator : NUMERO",
"fator : '-' NUMERO",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 418 "sintatico.y"

int main(int argc, char **argv) {
    FILE *output_file = fopen("OUT.tm", "w");
    if (!output_file) {
        fprintf(stderr, "Erro ao abrir o arquivo de saída!\n");
        return 1;
    }

    // Redireciona stdout para o arquivo de saída
    int stdout_fd = dup(fileno(stdout));
    dup2(fileno(output_file), fileno(stdout));

    yyparse();

    // Restaura stdout
    fflush(stdout);
    dup2(stdout_fd, fileno(stdout));
    close(stdout_fd);
    fclose(output_file);
    
    // print no terminal
    // print_code();

    for (int i = 0; i < number_of_errors; i++) {
        printf("%s", errors[i]);
    }

    return 0;
}

int yyerror(char *s) {
    

    fprintf(stderr, "Problema com a análise sintática! %s\n", s);
    
    return 0;
}


#line 646 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 118 "sintatico.y"
	{ initializeProgram(); }
#line 1319 "y.tab.c"
break;
case 2:
#line 119 "sintatico.y"
	{
        gen_code(HALT, 0, 0, 0);

        simbolo* atual = tabela_de_simbolos;

        while (atual != NULL) {
            if (atual->usada == 0) {
                sprintf(errors[number_of_errors++], "WARNING: O identificador \"%s\" foi declarado mas não foi utilizado\n", atual->nome);
            }

            atual = atual->prox;
            
        } 

        /* imprimir_tabela_de_simbolos();*/
        print_code();
        /* printf("Programa sintaticamente e semanticamente correto!\n");*/
        YYACCEPT;
    }
#line 1342 "y.tab.c"
break;
case 7:
#line 149 "sintatico.y"
	{
        /*printf("declara %s\n", $2);*/
        if (declarar(yystack.l_mark[-1].cadeia) < 0) {
            return 1;
        } 
    }
#line 1352 "y.tab.c"
break;
case 18:
#line 177 "sintatico.y"
	{
        /*printf("afirm\n");*/
    }
#line 1359 "y.tab.c"
break;
case 20:
#line 185 "sintatico.y"
	{
        add_code_offset(4);
        /* start_if = get_code_offset();*/
        stack_push(start_if_ptr, get_code_offset());
    }
#line 1368 "y.tab.c"
break;
case 21:
#line 190 "sintatico.y"
	{
        int start_else = get_code_offset();
        int start_if = stack_pop(start_if_ptr);

        /* jump pro fim do if se a condicao for falsa*/
        make_code(start_if - 4, LD, t1, 0, sp); /* t1 = stack.top() (resultado da comparacao)*/
        make_code(start_if - 3, LDA, sp, 1, sp); /* stack.pop() (sp = sp + 1)*/
        make_code(start_if - 2, LDC, t2, start_else, 0); /* t2 = start_else*/
        make_code(start_if - 1, JEQ, t1, 0, t2); /* pc = start_else (se a condicao for falsa)*/
    }
#line 1382 "y.tab.c"
break;
case 22:
#line 201 "sintatico.y"
	{
        add_code_offset(4);
        /* start_if = get_code_offset();*/
        stack_push(start_if_ptr, get_code_offset());
    }
#line 1391 "y.tab.c"
break;
case 23:
#line 207 "sintatico.y"
	{
        add_code_offset(3);
        /* start_else = get_code_offset();*/
        stack_push(start_else_ptr, get_code_offset());
    }
#line 1400 "y.tab.c"
break;
case 24:
#line 213 "sintatico.y"
	{
        int end_else = get_code_offset();
        int start_else = stack_pop(start_else_ptr);
        int start_if = stack_pop(start_if_ptr);

        /* jump pro inicio do else se a condicao for falsa*/
        make_code(start_if - 4, LD, t1, 0, sp); /* t1 = stack.top() (resultado da comparacao)*/
        make_code(start_if - 3, LDA, sp, 1, sp); /* stack.pop() (sp = sp + 1)*/
        make_code(start_if - 2, LDC, t2, start_else, 0); /* t2 = start_else*/
        make_code(start_if - 1, JEQ, t1, 0, t2); /* pc = start_else (se a condicao for falsa)*/

        /* jump incodicional pro fim do else*/
        make_code(start_else - 3, LDC, t1, end_else, 0); /* t1 = end_else*/
        make_code(start_else - 2, LDC, t2, 0, 0); /* t2 = 0;*/
        make_code(start_else - 1, JEQ, t2, 0, t1); /* pc = t1*/
    }
#line 1420 "y.tab.c"
break;
case 26:
#line 233 "sintatico.y"
	{
        /* start_comp = get_code_offset(); // inicio da comparacao do while*/
        stack_push(start_comp_ptr, get_code_offset());
    }
#line 1428 "y.tab.c"
break;
case 27:
#line 236 "sintatico.y"
	{
        add_code_offset(4);
        /* start_while = get_code_offset(); // inicio do meu codigo dentro do while*/
        stack_push(start_while_ptr, get_code_offset());
    }
#line 1437 "y.tab.c"
break;
case 28:
#line 240 "sintatico.y"
	{
        int start_while = stack_pop(start_while_ptr);
        int start_comp = stack_pop(start_comp_ptr);

        /* jump incondicional pro inicio do while*/
        gen_code(LDC, t1, start_comp, 0);
        gen_code(LDC, t2, 0, 0);
        gen_code(JEQ, t2, 0, t1);

        int end_while = get_code_offset();

        make_code(start_while - 4, LD, t1, 0, sp); /* t1 = stack.top() (resultado da comparacao)*/
        make_code(start_while - 3, LDA, sp, 1, sp); /* stack.pop() (sp = sp + 1)*/
        make_code(start_while - 2, LDC, t2, end_while, 0); /* t2 = end_while*/
        make_code(start_while - 1, JEQ, t1, 0, t2); /* pc = start_else (se a condicao for falsa)*/
    }
#line 1457 "y.tab.c"
break;
case 32:
#line 264 "sintatico.y"
	{ 
        int offset = utilizar(yystack.l_mark[-2].cadeia);

        if (offset < 0) {
            return 1;
        }

        gen_code(IN, t1, 0, 0); /* t1 = input()*/

        gen_code(LDC, t2, 0, 0); /* t2 = 0*/
        gen_code(LD, t2, 0, t2); /* t2 = dMem[0] = 1023*/
        gen_code(ST, t1, -offset, t2); /* dMem[-offset + t2] = reg[t1]*/
    }
#line 1474 "y.tab.c"
break;
case 33:
#line 280 "sintatico.y"
	{ 
        pop(); /* t1 = fator*/
        gen_code(OUT, t1, 0, 0);

        /* int offset = utilizar($3);*/

        /* gen_code(LDC, t1, 0, 0); // t1 = 0*/
        /* gen_code(LD, t1, 0, t1); // t1 = dMem[0 + t1] = dMem[0] = 1023*/
        /* gen_code(LD, t1, -offset, t1); // t1 = dMem[-offset + t1]*/
        /* gen_code(OUT, t1, 0, 0);*/
    }
#line 1489 "y.tab.c"
break;
case 34:
#line 294 "sintatico.y"
	{
        int offset = utilizar(yystack.l_mark[-2].cadeia);

        if (offset < 0) {
            return 1;
        }

        pop(); /* t1 = expressao*/
        
        gen_code(LDC, t2, 0, 0); /* t2 = 0*/
        gen_code(LD, t2, 0, t2); /* t2 = dMem[0] = 1023*/
        gen_code(ST, t1, -offset, t2); /* dMem[-offset + t2] = reg[t1]*/
    }
#line 1506 "y.tab.c"
break;
case 36:
#line 311 "sintatico.y"
	{ 
        int offset = utilizar(yystack.l_mark[0].cadeia);

        if (offset < 0) {
            return 1;
        }

        gen_code(LDC, t1, 0, 0); /* t1 = 0*/
        gen_code(LD, t1, 0, t1); /* t1 = dMem[0 + t1] = dMem[0] = 1023*/
        gen_code(LD, t1, -offset, t1); /* t1 = dMem[-offset + t1]*/
        push();
        
        yyval.cadeia = yystack.l_mark[0].cadeia; /* Pass the identifier name up the parse tree*/
    }
#line 1524 "y.tab.c"
break;
case 37:
#line 328 "sintatico.y"
	{
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0);
        gen_code(JLT, t2, 1, pc);
        gen_code(LDC, t1, 0, 0);
        push();
    }
#line 1537 "y.tab.c"
break;
case 38:
#line 337 "sintatico.y"
	{
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JLE, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
#line 1550 "y.tab.c"
break;
case 39:
#line 346 "sintatico.y"
	{
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JGT, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
#line 1563 "y.tab.c"
break;
case 40:
#line 355 "sintatico.y"
	{
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JGE, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
#line 1576 "y.tab.c"
break;
case 41:
#line 364 "sintatico.y"
	{
        ari_op(SUB);
        pop(); /* t1 = stack.top(); stack.pop();*/
        copy(t1, t2); /* t2 = t1;*/
        
        gen_code(LDC, t1, 1, 0); /* resposta da comparacao = 1*/
        gen_code(JEQ, t2, 1, pc); /* subtracao == 0 (os dois caras sao iguais, pula a prox. instrucao)*/
        gen_code(LDC, t1, 0, 0); /* resposta da comparacao = 0*/
        
        push(); /* push(t1) (t1 = {0 ou 1})*/
    }
#line 1591 "y.tab.c"
break;
case 42:
#line 375 "sintatico.y"
	{
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JNE, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
#line 1604 "y.tab.c"
break;
case 45:
#line 389 "sintatico.y"
	{ ari_op(ADD); }
#line 1609 "y.tab.c"
break;
case 46:
#line 390 "sintatico.y"
	{ ari_op(SUB); }
#line 1614 "y.tab.c"
break;
case 47:
#line 391 "sintatico.y"
	{ ari_op(MUL); }
#line 1619 "y.tab.c"
break;
case 48:
#line 392 "sintatico.y"
	{ ari_op(DIV); }
#line 1624 "y.tab.c"
break;
case 52:
#line 401 "sintatico.y"
	{ ari_op(ADD); }
#line 1629 "y.tab.c"
break;
case 53:
#line 402 "sintatico.y"
	{ ari_op(SUB); }
#line 1634 "y.tab.c"
break;
case 54:
#line 403 "sintatico.y"
	{ ari_op(MUL); }
#line 1639 "y.tab.c"
break;
case 55:
#line 404 "sintatico.y"
	{ ari_op(DIV); }
#line 1644 "y.tab.c"
break;
case 56:
#line 405 "sintatico.y"
	{ /* // aqui não sei se  preciso fazer algum tipo de tratamento, já que já foi tratado algo na variavel lá em cima */ }
#line 1649 "y.tab.c"
break;
case 57:
#line 406 "sintatico.y"
	{
        gen_code(LDC, t1, yystack.l_mark[0].intval, 0);
        push();
    }
#line 1657 "y.tab.c"
break;
case 58:
#line 410 "sintatico.y"
	{ /* números negativos*/
        gen_code(LDC, t1, -1, 0);
        push();
        ari_op(MUL);
    }
#line 1666 "y.tab.c"
break;
#line 1668 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
