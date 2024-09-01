#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#define IDENTIFICADOR 282
#define NUMERO 283
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    char *cadeia;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
