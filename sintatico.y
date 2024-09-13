%{
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
int add_code_offset();

void gen_code(enum code_ops operation, int arg0, int arg1, int arg2);
void make_code(int addr, enum code_ops operation, int arg0, int arg1, int arg2);

void pop();
void push();
void copy(enum Regs from, enum Regs to);

void initializeProgram();
void ari_op(enum code_ops op);

void print_code();


%}

%union {
    char *cadeia;
    int intval;

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
%token FLOAT
%token LEIA
%token ESCREVA
%token <cadeia> IDENTIFICADOR
%token <intval> NUMERO

%start programa

/* Regras */
%%
programa: {initializeProgram();}
    
    lista_declaracoes {
        simbolo* atual = tabela_de_simbolos;

        while (atual != NULL) {
            if (atual->usada == 0) {
                printf("WARNING: O identificador \"%s\" foi declarado mas não foi utilizado\n", atual->nome);
            }

            atual = atual->prox;
            
        }
        
        imprimir_tabela_de_simbolos();
        print_code();
        printf("Programa sintaticamente e semanticamente correto!\n");
        YYACCEPT;
    }
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
    tipo IDENTIFICADOR PONTOVIRGULA { 
        //printf("declara %s\n", $2);
        
        declarar($2); 


    }
    | tipo IDENTIFICADOR COLCHETESQUERDO NUMERO COLCHETEDIREITO PONTOVIRGULA { 
        
        declarar($2); 
    }
    ;

tipo:
    VOID
    | INT
    | FLOAT
    ;

declaracao_fun:
    tipo IDENTIFICADOR PARENTESESQUERDO parametros PARENTESEDIREITO afirmacao_funcao { declarar($2); }
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
    tipo IDENTIFICADOR { 
        utilizar($2); 
    }
    | tipo IDENTIFICADOR COLCHETESQUERDO COLCHETEDIREITO { 

        utilizar($2); 
    }
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
    | afirmacao_leia
    | afirmacao_escreva
    ;

afirmacao_expressao:
    expressao PONTOVIRGULA {
        //printf("afirm\n");
    }
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

afirmacao_leia: // input
    LEIA PARENTESESQUERDO IDENTIFICADOR PARENTESEDIREITO PONTOVIRGULA { utilizar($3); }
    ;

afirmacao_escreva: // print
    ESCREVA PARENTESESQUERDO IDENTIFICADOR PARENTESEDIREITO PONTOVIRGULA { utilizar($3); }
    ;

expressao:
    variavel ATRIBUICAO expressao {
        //printf("ATRIBUICAO\n");
        
    }
    | IDENTIFICADOR ATRIBUICAO expressao {
        printf("%s\n", $1);
        
    }
    | expressao_simples {
        //printf("aqui dsds \n");
    }
    ;

variavel:
    IDENTIFICADOR { 
        //printf("aqui %s \n", $1);
        int address = utilizar( $1 );
        gen_code(LDC, t1, address, 0);
        gen_code(LD, t1, 0, t1);
        push();
    }
    | IDENTIFICADOR COLCHETESQUERDO expressao COLCHETEDIREITO { utilizar($1); }
    ;

expressao_simples:
    expressao_matematica comparacao expressao_matematica {
        
    }
    | expressao_matematica
    ;

comparacao:
    MENOR {
       
    }
    | MENORIGUAL
    | MAIOR
    | MAIORIGUAL
    | IGUAL {
        //printf("IGUAL\n");
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 0, 0); 
        gen_code(JGE, t2, 1, pc); 
        gen_code(LDC, t1, 1, 0); 
        push();
    }
    | DIFERENTE
    ;

expressao_matematica:
    expressao_matematica operacao_aditiva termo {
        
    }
    | termo
    ;

operacao_aditiva:
    ADICAO {
        //printf("ADICAO\n");
        ari_op(ADD);
    }
    | SUBTRACAO
    ;

termo:
    termo operacao_multiplicativa fator {   
    }
    | fator 
    ;

operacao_multiplicativa:
    MULTIPLICACAO {
        //printf("MULTIPLICACAO\n");
    }
    | DIVISAO
    ;

fator:
    PARENTESESQUERDO expressao PARENTESEDIREITO
    | variavel 
    | chamada_funcao
    | NUMERO {
        //printf("NUMERO: %d\n", $1);
        gen_code( LDC, t1, $1, 0);
        push();
    }
    ;

chamada_funcao:
    IDENTIFICADOR PARENTESESQUERDO argumentos PARENTESEDIREITO { utilizar($1); }
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
    fprintf(stderr, "Problema com a análise sintática! %s\n", s);
    return 0;
}
