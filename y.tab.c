/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // strcmp
#include "tabela_de_simbolos.h"
#include "code_generator.h"

void declarar(char* nome) {
    simbolo* s = procurar_simbolo(nome);

    if (s != NULL) {
        printf("ERRO: O identificador \"%s\" já está definido\n", nome);
        exit(1);
    }

    s = adicionar_simbolo(nome);
}

int utilizar(char* nome) {
    simbolo* s = procurar_simbolo(nome);

    if (s == NULL) {
        printf("ERRO: O identificador \"%s\" não foi definido\n", nome);
        exit(1);
    }

    s->usada = 1;
    return s->offset;
}

// prototipos
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

int start_if, start_else, start_comp, start_while, end_while;


#line 122 "y.tab.c"

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


#line 249 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ATRIBUICAO = 3,                 /* ATRIBUICAO  */
  YYSYMBOL_ADICAO = 4,                     /* ADICAO  */
  YYSYMBOL_SUBTRACAO = 5,                  /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 6,              /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 7,                    /* DIVISAO  */
  YYSYMBOL_PONTOVIRGULA = 8,               /* PONTOVIRGULA  */
  YYSYMBOL_VIRGULA = 9,                    /* VIRGULA  */
  YYSYMBOL_PARENTESESQUERDO = 10,          /* PARENTESESQUERDO  */
  YYSYMBOL_PARENTESEDIREITO = 11,          /* PARENTESEDIREITO  */
  YYSYMBOL_COLCHETESQUERDO = 12,           /* COLCHETESQUERDO  */
  YYSYMBOL_COLCHETEDIREITO = 13,           /* COLCHETEDIREITO  */
  YYSYMBOL_CHAVESQUERDA = 14,              /* CHAVESQUERDA  */
  YYSYMBOL_CHAVEDIREITA = 15,              /* CHAVEDIREITA  */
  YYSYMBOL_MENOR = 16,                     /* MENOR  */
  YYSYMBOL_MENORIGUAL = 17,                /* MENORIGUAL  */
  YYSYMBOL_MAIOR = 18,                     /* MAIOR  */
  YYSYMBOL_MAIORIGUAL = 19,                /* MAIORIGUAL  */
  YYSYMBOL_IGUAL = 20,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 21,                 /* DIFERENTE  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_WHILE = 24,                     /* WHILE  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_VOID = 26,                      /* VOID  */
  YYSYMBOL_INT = 27,                       /* INT  */
  YYSYMBOL_FLOAT = 28,                     /* FLOAT  */
  YYSYMBOL_LEIA = 29,                      /* LEIA  */
  YYSYMBOL_ESCREVA = 30,                   /* ESCREVA  */
  YYSYMBOL_MAIN = 31,                      /* MAIN  */
  YYSYMBOL_IDENTIFICADOR = 32,             /* IDENTIFICADOR  */
  YYSYMBOL_NUMERO = 33,                    /* NUMERO  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_UMINUS = 38,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_programa = 40,                  /* programa  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_42_2 = 42,                      /* $@2  */
  YYSYMBOL_lista_declaracoes = 43,         /* lista_declaracoes  */
  YYSYMBOL_declaracao_var = 44,            /* declaracao_var  */
  YYSYMBOL_tipo = 45,                      /* tipo  */
  YYSYMBOL_lista_afirmacoes = 46,          /* lista_afirmacoes  */
  YYSYMBOL_afirmacao = 47,                 /* afirmacao  */
  YYSYMBOL_afirmacao_expressao = 48,       /* afirmacao_expressao  */
  YYSYMBOL_afirmacao_selecao = 49,         /* afirmacao_selecao  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_52_5 = 52,                      /* $@5  */
  YYSYMBOL_afirmacao_iterativa = 53,       /* afirmacao_iterativa  */
  YYSYMBOL_54_6 = 54,                      /* $@6  */
  YYSYMBOL_55_7 = 55,                      /* $@7  */
  YYSYMBOL_56_8 = 56,                      /* $@8  */
  YYSYMBOL_afirmacao_retorno = 57,         /* afirmacao_retorno  */
  YYSYMBOL_afirmacao_leia = 58,            /* afirmacao_leia  */
  YYSYMBOL_afirmacao_escreva = 59,         /* afirmacao_escreva  */
  YYSYMBOL_expressao = 60,                 /* expressao  */
  YYSYMBOL_variavel = 61,                  /* variavel  */
  YYSYMBOL_expressao_simples = 62,         /* expressao_simples  */
  YYSYMBOL_expressao_matematica = 63,      /* expressao_matematica  */
  YYSYMBOL_termo = 64,                     /* termo  */
  YYSYMBOL_operacao_multiplicativa = 65,   /* operacao_multiplicativa  */
  YYSYMBOL_fator = 66                      /* fator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   103

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    36,    35,     2,    34,     2,    37,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   105,   101,   129,   130,   131,   135,   142,
     143,   147,   148,   152,   153,   154,   155,   156,   157,   161,
     164,   169,   174,   179,   168,   197,   199,   202,   197,   218,
     219,   223,   235,   249,   258,   262,   275,   284,   293,   302,
     311,   322,   331,   335,   336,   337,   338,   339,   349,   350,
     354,   357,   361,   362,   363,   367
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ATRIBUICAO", "ADICAO",
  "SUBTRACAO", "MULTIPLICACAO", "DIVISAO", "PONTOVIRGULA", "VIRGULA",
  "PARENTESESQUERDO", "PARENTESEDIREITO", "COLCHETESQUERDO",
  "COLCHETEDIREITO", "CHAVESQUERDA", "CHAVEDIREITA", "MENOR", "MENORIGUAL",
  "MAIOR", "MAIORIGUAL", "IGUAL", "DIFERENTE", "IF", "ELSE", "WHILE",
  "RETURN", "VOID", "INT", "FLOAT", "LEIA", "ESCREVA", "MAIN",
  "IDENTIFICADOR", "NUMERO", "'-'", "'+'", "'*'", "'/'", "UMINUS",
  "$accept", "programa", "$@1", "$@2", "lista_declaracoes",
  "declaracao_var", "tipo", "lista_afirmacoes", "afirmacao",
  "afirmacao_expressao", "afirmacao_selecao", "$@3", "$@4", "$@5",
  "afirmacao_iterativa", "$@6", "$@7", "$@8", "afirmacao_retorno",
  "afirmacao_leia", "afirmacao_escreva", "expressao", "variavel",
  "expressao_simples", "expressao_matematica", "termo",
  "operacao_multiplicativa", "fator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -26,   -27,    12,    13,   -90,    16,    33,    34,   -17,   -90,
     -90,   -17,   -90,    -6,   -90,   -90,    41,    21,   -90,   -90,
      24,    42,    68,     6,    69,    70,    78,   -90,    49,    71,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,    75,   -90,   -90,
      50,    15,   -90,    73,    24,   -90,   -90,    77,    55,    31,
      24,   -90,   -90,   -90,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,   -90,    79,    24,   -90,    80,
     -90,    81,   -90,   -90,   -90,   -90,   -90,   -90,   -90,     0,
       0,     0,     0,   -90,    74,   -90,    85,    86,   -90,   -90,
     -90,    84,   -90,   -90,   -90,    82,     3,   -90,    66,    21,
      83,    87,   -90,   -90,   -90,    21,    88,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     7,     9,
      10,     2,     6,     0,    12,     5,     0,     3,     8,    20,
       0,     0,     0,     0,     0,     0,    35,    54,     0,     0,
      11,    13,    14,    15,    16,    17,    18,     0,    53,    34,
      42,    43,    49,     0,     0,    25,    29,     0,     0,     0,
       0,    55,     4,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,    30,     0,
      35,     0,    33,    36,    37,    38,    39,    40,    41,    44,
      45,    46,    47,    48,     0,    26,     0,     0,    50,    51,
      21,     0,    31,    32,    12,     0,     0,    12,     0,    27,
       0,     0,    22,    28,    12,    23,     0,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,   -90,   -90,    89,   -90,   -89,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -20,   -90,   -90,    18,    -1,   -90,   -47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    14,    29,    11,    12,    13,    17,    30,    31,
      32,    94,   104,   106,    33,    67,    91,   101,    34,    35,
      36,    37,    38,    39,    40,    41,    64,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      43,     1,    71,    47,     3,    96,    88,    89,    99,     9,
      10,    19,     4,    20,    46,   105,    20,    83,    98,    60,
      61,    62,    63,     5,    66,    21,    16,    22,    23,    19,
      72,    20,    24,    25,    20,    26,    27,    28,    26,    27,
      28,    20,     6,    21,     7,    22,    23,    85,     8,    18,
      24,    25,    44,    26,    27,    28,    26,    27,    28,    79,
      80,    81,    82,    70,    27,    28,    54,    55,    56,    57,
      58,    59,    73,    74,    75,    76,    77,    78,    45,    48,
      49,    50,    51,    53,    65,    68,    52,    69,    90,   100,
      84,    86,    87,    92,    93,    95,    97,   102,     0,     0,
      15,     0,   103,   107
};

static const yytype_int8 yycheck[] =
{
      20,    27,    49,    23,    31,    94,     6,     7,    97,    26,
      27,     8,     0,    10,     8,   104,    10,    64,    15,     4,
       5,     6,     7,    10,    44,    22,    32,    24,    25,     8,
      50,    10,    29,    30,    10,    32,    33,    34,    32,    33,
      34,    10,    26,    22,    11,    24,    25,    67,    14,     8,
      29,    30,    10,    32,    33,    34,    32,    33,    34,    60,
      61,    62,    63,    32,    33,    34,    16,    17,    18,    19,
      20,    21,    54,    55,    56,    57,    58,    59,    10,    10,
      10,     3,    33,     8,    11,     8,    15,    32,    14,    23,
      11,    11,    11,     8,     8,    11,    14,    14,    -1,    -1,
      11,    -1,    15,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    40,    31,     0,    10,    26,    11,    14,    26,
      27,    43,    44,    45,    41,    44,    32,    46,     8,     8,
      10,    22,    24,    25,    29,    30,    32,    33,    34,    42,
      47,    48,    49,    53,    57,    58,    59,    60,    61,    62,
      63,    64,    66,    60,    10,    10,     8,    60,    10,    10,
       3,    33,    15,     8,    16,    17,    18,    19,    20,    21,
       4,     5,     6,     7,    65,    11,    60,    54,     8,    32,
      32,    66,    60,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    66,    11,    60,    11,    11,     6,     7,
      14,    55,     8,     8,    50,    11,    46,    14,    15,    46,
      23,    56,    14,    15,    51,    46,    52,    15
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    41,    42,    40,    43,    43,    43,    44,    45,
      45,    46,    46,    47,    47,    47,    47,    47,    47,    48,
      48,    50,    51,    52,    49,    54,    55,    56,    53,    57,
      57,    58,    59,    60,    60,    61,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,    11,     2,     1,     0,     3,     1,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     0,     0,    14,     0,     0,     0,    10,     2,
       3,     5,     5,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     1,
       1,     1,     3,     1,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* $@1: %empty  */
#line 104 "sintatico.y"
    { initializeProgram(); }
#line 1364 "y.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 105 "sintatico.y"
                     {
        gen_code(HALT, 0, 0, 0);

        simbolo* atual = tabela_de_simbolos;

        while (atual != NULL) {
            if (atual->usada == 0) {
                printf("WARNING: O identificador \"%s\" foi declarado mas não foi utilizado\n", atual->nome);
            }

            atual = atual->prox;
            
        } 

        // imprimir_tabela_de_simbolos();
        print_code();
        // printf("Programa sintaticamente e semanticamente correto!\n");
        YYACCEPT;
    }
#line 1388 "y.tab.c"
    break;

  case 8: /* declaracao_var: tipo IDENTIFICADOR PONTOVIRGULA  */
#line 135 "sintatico.y"
                                    { 
        //printf("declara %s\n", $2);
        declarar((yyvsp[-1].cadeia)); 
    }
#line 1397 "y.tab.c"
    break;

  case 19: /* afirmacao_expressao: expressao PONTOVIRGULA  */
#line 161 "sintatico.y"
                           {
        //printf("afirm\n");
    }
#line 1405 "y.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 169 "sintatico.y"
    {
        add_code_offset(4);
        start_if = get_code_offset();
    }
#line 1414 "y.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 174 "sintatico.y"
    {
        add_code_offset(3);
        start_else = get_code_offset();
    }
#line 1423 "y.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 179 "sintatico.y"
    {
        int end_else = get_code_offset();

        // jump pro inicio do else se a condicao for falsa
        make_code(start_if - 4, LD, t1, 0, sp); // t1 = stack.top() (resultado da comparacao)
        make_code(start_if - 3, LDA, sp, 1, sp); // stack.pop() (sp = sp + 1)
        make_code(start_if - 2, LDC, t2, start_else, 0); // t2 = start_else
        make_code(start_if - 1, JEQ, t1, 0, t2); // pc = start_else (se a condicao for falsa)

        // jump incodicional pro fim do else
        make_code(start_else - 3, LDC, t1, end_else, 0); // t1 = end_else
        make_code(start_else - 2, LDC, t2, 0, 0); // t2 = 0;
        make_code(start_else - 1, JEQ, t2, 0, t1); // pc = t1
    }
#line 1442 "y.tab.c"
    break;

  case 25: /* $@6: %empty  */
#line 197 "sintatico.y"
                           {
        start_comp = get_code_offset(); // inicio da comparacao do while
    }
#line 1450 "y.tab.c"
    break;

  case 26: /* $@7: %empty  */
#line 199 "sintatico.y"
                {
        add_code_offset(4);
        start_while = get_code_offset(); // inicio do meu codigo dentro do while
    }
#line 1459 "y.tab.c"
    break;

  case 27: /* $@8: %empty  */
#line 202 "sintatico.y"
                                                     {
        // jump incondicional pro inicio do while
        gen_code(LDC, t1, start_comp, 0);
        gen_code(LDC, t2, 0, 0);
        gen_code(JEQ, t2, 0, t1);

        end_while = get_code_offset();

        make_code(start_while - 4, LD, t1, 0, sp); // t1 = stack.top() (resultado da comparacao)
        make_code(start_while - 3, LDA, sp, 1, sp); // stack.pop() (sp = sp + 1)
        make_code(start_while - 2, LDC, t2, end_while, 0); // t2 = end_while
        make_code(start_while - 1, JEQ, t1, 0, t2); // pc = start_else (se a condicao for falsa)
    }
#line 1477 "y.tab.c"
    break;

  case 31: /* afirmacao_leia: LEIA PARENTESESQUERDO IDENTIFICADOR PARENTESEDIREITO PONTOVIRGULA  */
#line 223 "sintatico.y"
                                                                      { 
        int offset = utilizar((yyvsp[-2].cadeia));

        gen_code(IN, t1, 0, 0); // t1 = input()

        gen_code(LDC, t2, 0, 0); // t2 = 0
        gen_code(LD, t2, 0, t2); // t2 = dMem[0] = 1023
        gen_code(ST, t1, -offset, t2); // dMem[-offset + t2] = reg[t1]
    }
#line 1491 "y.tab.c"
    break;

  case 32: /* afirmacao_escreva: ESCREVA PARENTESESQUERDO fator PARENTESEDIREITO PONTOVIRGULA  */
#line 235 "sintatico.y"
                                                                 { 
        pop(); // t1 = fator
        gen_code(OUT, t1, 0, 0);

        // int offset = utilizar($3);

        // gen_code(LDC, t1, 0, 0); // t1 = 0
        // gen_code(LD, t1, 0, t1); // t1 = dMem[0 + t1] = dMem[0] = 1023
        // gen_code(LD, t1, -offset, t1); // t1 = dMem[-offset + t1]
        // gen_code(OUT, t1, 0, 0);
    }
#line 1507 "y.tab.c"
    break;

  case 33: /* expressao: IDENTIFICADOR ATRIBUICAO expressao  */
#line 249 "sintatico.y"
                                       {
        int offset = utilizar((yyvsp[-2].cadeia));

        pop(); // t1 = expressao
        
        gen_code(LDC, t2, 0, 0); // t2 = 0
        gen_code(LD, t2, 0, t2); // t2 = dMem[0] = 1023
        gen_code(ST, t1, -offset, t2); // dMem[-offset + t2] = reg[t1]
    }
#line 1521 "y.tab.c"
    break;

  case 35: /* variavel: IDENTIFICADOR  */
#line 262 "sintatico.y"
                  { 
        int offset = utilizar((yyvsp[0].cadeia));

        gen_code(LDC, t1, 0, 0); // t1 = 0
        gen_code(LD, t1, 0, t1); // t1 = dMem[0 + t1] = dMem[0] = 1023
        gen_code(LD, t1, -offset, t1); // t1 = dMem[-offset + t1]
        push();
        
        (yyval.cadeia) = (yyvsp[0].cadeia); // Pass the identifier name up the parse tree
    }
#line 1536 "y.tab.c"
    break;

  case 36: /* expressao_simples: expressao_matematica MENOR expressao_matematica  */
#line 275 "sintatico.y"
                                                    {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0);
        gen_code(JLT, t2, 1, pc);
        gen_code(LDC, t1, 0, 0);
        push();
    }
#line 1550 "y.tab.c"
    break;

  case 37: /* expressao_simples: expressao_matematica MENORIGUAL expressao_matematica  */
#line 284 "sintatico.y"
                                                           {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JLE, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
#line 1564 "y.tab.c"
    break;

  case 38: /* expressao_simples: expressao_matematica MAIOR expressao_matematica  */
#line 293 "sintatico.y"
                                                      {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JGT, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
#line 1578 "y.tab.c"
    break;

  case 39: /* expressao_simples: expressao_matematica MAIORIGUAL expressao_matematica  */
#line 302 "sintatico.y"
                                                           {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JGE, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
#line 1592 "y.tab.c"
    break;

  case 40: /* expressao_simples: expressao_matematica IGUAL expressao_matematica  */
#line 311 "sintatico.y"
                                                      {
        ari_op(SUB);
        pop(); // t1 = stack.top(); stack.pop();
        copy(t1, t2); // t2 = t1;
        
        gen_code(LDC, t1, 1, 0); // resposta da comparacao = 1
        gen_code(JEQ, t2, 1, pc); // subtracao == 0 (os dois caras sao iguais, pula a prox. instrucao)
        gen_code(LDC, t1, 0, 0); // resposta da comparacao = 0
        
        push(); // push(t1) (t1 = {0 ou 1})
    }
#line 1608 "y.tab.c"
    break;

  case 41: /* expressao_simples: expressao_matematica DIFERENTE expressao_matematica  */
#line 322 "sintatico.y"
                                                          {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JNE, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
#line 1622 "y.tab.c"
    break;

  case 44: /* expressao_matematica: termo ADICAO termo  */
#line 336 "sintatico.y"
                         { ari_op(ADD); }
#line 1628 "y.tab.c"
    break;

  case 45: /* expressao_matematica: termo SUBTRACAO termo  */
#line 337 "sintatico.y"
                            { ari_op(SUB); }
#line 1634 "y.tab.c"
    break;

  case 46: /* expressao_matematica: termo MULTIPLICACAO termo  */
#line 338 "sintatico.y"
                                { ari_op(MUL); }
#line 1640 "y.tab.c"
    break;

  case 47: /* expressao_matematica: termo DIVISAO termo  */
#line 339 "sintatico.y"
                          { ari_op(DIV); }
#line 1646 "y.tab.c"
    break;

  case 50: /* operacao_multiplicativa: MULTIPLICACAO  */
#line 354 "sintatico.y"
                  {
        ari_op(MUL);
    }
#line 1654 "y.tab.c"
    break;

  case 51: /* operacao_multiplicativa: DIVISAO  */
#line 357 "sintatico.y"
              {ari_op(DIV);}
#line 1660 "y.tab.c"
    break;

  case 53: /* fator: variavel  */
#line 362 "sintatico.y"
               { /* // aqui não sei se  preciso fazer algum tipo de tratamento, já que já foi tratado algo na variavel lá em cima */ }
#line 1666 "y.tab.c"
    break;

  case 54: /* fator: NUMERO  */
#line 363 "sintatico.y"
             {
        gen_code(LDC, t1, (yyvsp[0].intval), 0);
        push();
    }
#line 1675 "y.tab.c"
    break;

  case 55: /* fator: '-' NUMERO  */
#line 367 "sintatico.y"
                              { // números negativos
        gen_code(LDC, t1, -1, 0);
        push();
        ari_op(MUL);
    }
#line 1685 "y.tab.c"
    break;


#line 1689 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 384 "sintatico.y"


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
    
    print_code();

    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Problema com a análise sintática! %s\n", s);
    return 0;
}
