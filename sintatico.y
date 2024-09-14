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
%token MAIN
%token <cadeia> IDENTIFICADOR
%token <intval> NUMERO

%type <cadeia> variavel

%start programa

%left '-' '+'
%left '*' '/'
%left UMINUS

/* Regras */
%%
programa: INT MAIN PARENTESESQUERDO VOID PARENTESEDIREITO CHAVESQUERDA

    lista_declaracoes
    { initializeProgram(); }
    lista_afirmacoes {
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
    
    CHAVEDIREITA
    ;

lista_declaracoes:
    lista_declaracoes declaracao_var 
    | declaracao_var 
    ;

declaracao_var:
    tipo IDENTIFICADOR PONTOVIRGULA { 
        //printf("declara %s\n", $2);
        declarar($2); 
    }
    ;

tipo:
    VOID
    | INT
    ;

lista_afirmacoes:
    lista_afirmacoes afirmacao
    | /* empty */
    ;

afirmacao:
    afirmacao_expressao
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

afirmacao_leia:
    LEIA PARENTESESQUERDO IDENTIFICADOR PARENTESEDIREITO PONTOVIRGULA { 
        int offset = utilizar($3);

        gen_code(IN, t1, 0, 0); // t1 = input()

        gen_code(LDC, t2, 0, 0); // t2 = 0
        gen_code(LD, t2, 0, t2); // t2 = dMem[0] = 1023
        gen_code(ST, t1, -offset, t2); // dMem[-offset + t2] = reg[t1]
    }
    ;

afirmacao_escreva:
    ESCREVA PARENTESESQUERDO IDENTIFICADOR PARENTESEDIREITO PONTOVIRGULA { 
        int offset = utilizar($3);

        gen_code(LDC, t1, 0, 0); // t1 = 0
        gen_code(LD, t1, 0, t1); // t1 = dMem[0 + t1] = dMem[0] = 1023
        gen_code(LD, t1, -offset, t1); // t1 = dMem[-offset + t1]
        gen_code(OUT, t1, 0, 0);
    }
    ;

expressao:
    IDENTIFICADOR ATRIBUICAO expressao {
        int offset = utilizar($1);

        pop(); // t1 = expressao
        
        gen_code(LDC, t2, 0, 0); // t2 = 0
        gen_code(LD, t2, 0, t2); // t2 = dMem[0] = 1023
        gen_code(ST, t1, -offset, t2); // dMem[-offset + t2] = reg[t1]
    }
    | expressao_simples
    ;

variavel:
    IDENTIFICADOR { 
        int offset = utilizar($1);

        gen_code(LDC, t1, 0, 0); // t1 = 0
        gen_code(LD, t1, 0, t1); // t1 = dMem[0 + t1] = dMem[0] = 1023
        gen_code(LD, t1, -offset, t1); // t1 = dMem[-offset + t1]
        push();
        
        $$ = $1; // Pass the identifier name up the parse tree
    }
    ;

expressao_simples:
    expressao_matematica comparacao expressao_matematica 
    | expressao_matematica
    ;

comparacao:
    MENOR {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 0, 0); 
        gen_code(JLT, t2, 1, pc); 
        gen_code(LDC, t1, 1, 0); 
        push();
    }
    | MENORIGUAL{
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 0, 0); 
        gen_code(JLE, t2, 1, pc); 
        gen_code(LDC, t1, 1, 0); 
        push();
    }
    | MAIOR {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 0, 0); 
        gen_code(JGT, t2, 1, pc); 
        gen_code(LDC, t1, 1, 0); 
        push();
    }
    | MAIORIGUAL {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 0, 0); 
        gen_code(JGE, t2, 1, pc); 
        gen_code(LDC, t1, 1, 0); 
        push();
    }
    | IGUAL {
        //printf("IGUAL\n");
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 0, 0); 
        gen_code(JEQ, t2, 1, pc); 
        gen_code(LDC, t1, 1, 0); 
        push();
    }
    | DIFERENTE {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 0, 0); 
        gen_code(JNE, t2, 1, pc); 
        gen_code(LDC, t1, 1, 0); 
        push();
    }
    ;

expressao_matematica:
    termo
    | termo ADICAO termo { ari_op(ADD); }
    | termo SUBTRACAO termo { ari_op(SUB); }
    | termo MULTIPLICACAO termo { ari_op(MUL); }
    | termo DIVISAO termo { ari_op(DIV); }
    
    ;

operacao_aditiva:
    ADICAO { ari_op(ADD); }
    | SUBTRACAO { ari_op(SUB); }
    ;

termo:
    termo operacao_multiplicativa fator
    | fator 
    ;

operacao_multiplicativa:
    MULTIPLICACAO {
        ari_op(MUL);
    }
    | DIVISAO {ari_op(DIV);}
    ;

fator:
    PARENTESESQUERDO expressao PARENTESEDIREITO
    | variavel { /* // aqui não sei se  preciso fazer algum tipo de tratamento, já que já foi tratado algo na variavel lá em cima */ }
    | NUMERO {
        gen_code(LDC, t1, $1, 0);
        push();
    }
    | '-' NUMERO %prec UMINUS { // números negativos
        gen_code(LDC, t1, -1, 0);
        push();
        ari_op(MUL);
    }
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
