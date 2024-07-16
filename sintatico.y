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
    ;

afirmacao_expressao:
    expressao PONTOVIRGULA
    | PONTOVIRGULA
    ;

expressao:
    variavel ATRIBUICAO expressao
    | expressao_simples
    ;

variavel:
    IDENTIFICADOR
    ;

expressao_simples:
    expressao_matematica
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
    PARENTESESQUERDO expressao_matematica PARENTESEDIREITO
    | variavel
    | NUMERO
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
