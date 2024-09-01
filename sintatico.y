%{
#include <stdio.h>
%}

%union {
    char *cadeia;
}

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
%token <cadeia> IDENTIFICADOR
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
    tipo IDENTIFICADOR PONTOVIRGULA { printf("Declaração da variável \"%s\"\n", $2); }
    | tipo IDENTIFICADOR COLCHETESQUERDO NUMERO COLCHETEDIREITO PONTOVIRGULA { printf("Declaração de variável \"%s\"\n", $2); }
    ;

tipo:
    VOID
    | INT
    ;

declaracao_fun:
    tipo IDENTIFICADOR PARENTESESQUERDO parametros PARENTESEDIREITO afirmacao_funcao { printf("Declaração da função \"%s\"\n", $2); }
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
    tipo IDENTIFICADOR { printf("Parâmetro de função \"%s\"\n", $2); }
    | tipo IDENTIFICADOR COLCHETESQUERDO COLCHETEDIREITO { printf("Parâmetro de função \"%s\"", $2); }
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
    IDENTIFICADOR { printf("Uso do identificador \"%s\"\n", $1); }
    | IDENTIFICADOR COLCHETESQUERDO expressao COLCHETEDIREITO { printf("Uso do identificador \"%s\"\n", $1); }
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
    IDENTIFICADOR PARENTESESQUERDO argumentos PARENTESEDIREITO { printf("Chamada da função \"%s\"\n", $1); }
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
