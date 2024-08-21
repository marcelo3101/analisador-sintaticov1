%{
#include <stdio.h>
%}

/* Definicoes de tokens */
%token ATRIBUICAO
%token ADICAO
%token SUBTRACAO
%token MULTIPLICACAO
%token DIVISAO
%token PONTOVIRGULA
%token VIRGULA
%token PARENTESESQUERDO
%token PARENTESEDIREITO
%token COLCHETESQUERDO
%token COLCHETEDIREITO
%token CHAVESQUERDA
%token CHAVEDIREITA
%token MENOR
%token MENORIGUAL
%token MAIOR
%token MAIORIGUAL
%token IGUAL
%token DIFERENTE
%token IF
%token ELSE
%token WHILE
%token RETURN
%token VOID
%token INT
%token IDENTIFICADOR
%token NUMERO

%start programa

/* Regras */
%%
programa:
    lista_declaracoes { printf("Programa sintaticamente correto!\n"); YYACCEPT; }
    ;

lista_declaracoes:
    lista_declaracoes declaracao
    | declaracao
    ;

declaracao:
    declaracao_var
    | declaracao_fun
    ;

declaracao_var:
    tipo IDENTIFICADOR PONTOVIRGULA
    | tipo IDENTIFICADOR COLCHETESQUERDO NUMERO COLCHETEDIREITO PONTOVIRGULA
    ;

tipo:
    VOID
    | INT
    ;

declaracao_fun:
    tipo IDENTIFICADOR PARENTESESQUERDO parametros PARENTESEDIREITO afirmacao_funcao
    ;

parametros:
    lista_parametros
    | VOID
    ;

lista_parametros:
    lista_parametros VIRGULA parametro
    | parametro
    ;

parametro:
    tipo IDENTIFICADOR
    | tipo IDENTIFICADOR COLCHETESQUERDO COLCHETEDIREITO
    ;

afirmacao_funcao:
    CHAVESQUERDA declaracoes_locais lista_afirmacoes CHAVEDIREITA
    ;

declaracoes_locais:
    declaracoes_locais declaracao_var
    | /* empty */
    ;

lista_afirmacoes:
    lista_afirmacoes afirmacao
    | /* empty */
    ;

afirmacao:
    afirmacao_expressao
    | afirmacao_funcao
    | afirmacao_selecao
    | afirmacao_iterativa
    | afirmacao_retorno
    ;

afirmacao_expressao:
    expressao PONTOVIRGULA
    | PONTOVIRGULA
    ;

afirmacao_selecao:
    IF PARENTESESQUERDO expressao PARENTESEDIREITO afirmacao
    | IF PARENTESESQUERDO expressao PARENTESEDIREITO afirmacao ELSE afirmacao
    ;

afirmacao_iterativa:
    WHILE PARENTESESQUERDO expressao PARENTESEDIREITO afirmacao
    ;

afirmacao_retorno:
    RETURN PONTOVIRGULA
    | RETURN expressao PONTOVIRGULA
    ;

expressao:
    variavel ATRIBUICAO expressao
    | expressao_simples
    ;

variavel:
    IDENTIFICADOR
    | IDENTIFICADOR COLCHETESQUERDO expressao COLCHETEDIREITO
    ;

expressao_simples:
    expressao_matematica comparacao expressao_matematica
    | expressao_matematica
    ;

comparacao:
    MENOR
    | MENORIGUAL
    | MAIOR
    | MAIORIGUAL
    | IGUAL
    | DIFERENTE
    ;

expressao_matematica:
    expressao_matematica operacao_aditiva termo
    | termo
    ;

operacao_aditiva:
    ADICAO
    | SUBTRACAO
    ;

termo:
    termo operacao_multiplicativa fator
    | fator
    ;

operacao_multiplicativa:
    MULTIPLICACAO
    | DIVISAO
    ;

fator:
    PARENTESESQUERDO expressao PARENTESEDIREITO
    | variavel
    | chamada_funcao
    | NUMERO
    ;

chamada_funcao:
    IDENTIFICADOR PARENTESESQUERDO argumentos PARENTESEDIREITO
    ;

argumentos:
    lista_argumentos
    | /* empty */
    ;

lista_argumentos:
    lista_argumentos VIRGULA expressao
    | expressao
    ;

%%

int main(int argc, char **argv) {
    yyparse();
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Problema com a analise sintatica! %s\n", s);
    return 0;
}
