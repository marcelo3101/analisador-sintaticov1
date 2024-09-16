%{
#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // strcmp
#include "tabela_de_simbolos.h"
#include "code_generator.h"

#define MAX_STACK_SIZE 32
#define stack_push(sp, n) (*((sp)++) = (n))
#define stack_pop(sp) (*--(sp))

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

int stack1[MAX_STACK_SIZE], stack2[MAX_STACK_SIZE], stack3[MAX_STACK_SIZE], stack4[MAX_STACK_SIZE], stack5[MAX_STACK_SIZE];

int *start_if_ptr = stack1, *start_else_ptr = stack2, *start_comp_ptr = stack3, *start_while_ptr = stack4, *end_while_ptr = stack5;

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
%token THEN
%token <cadeia> IDENTIFICADOR
%token <intval> NUMERO

%type <cadeia> variavel

%start programa

%left SUBTRACAO ADICAO
%left MULTIPLICACAO DIVISAO

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
    | 
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
    |
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
    IF PARENTESESQUERDO expressao PARENTESEDIREITO THEN CHAVESQUERDA
    {
        add_code_offset(4);
        // start_if = get_code_offset();
        stack_push(start_if_ptr, get_code_offset());
    }
    lista_afirmacoes CHAVEDIREITA {
        int start_else = get_code_offset();
        int start_if = stack_pop(start_if_ptr);

        // jump pro fim do if se a condicao for falsa
        make_code(start_if - 4, LD, t1, 0, sp); // t1 = stack.top() (resultado da comparacao)
        make_code(start_if - 3, LDA, sp, 1, sp); // stack.pop() (sp = sp + 1)
        make_code(start_if - 2, LDC, t2, start_else, 0); // t2 = start_else
        make_code(start_if - 1, JEQ, t1, 0, t2); // pc = start_else (se a condicao for falsa)
    }
    | IF PARENTESESQUERDO expressao PARENTESEDIREITO CHAVESQUERDA
    {
        add_code_offset(4);
        // start_if = get_code_offset();
        stack_push(start_if_ptr, get_code_offset());
    }
    lista_afirmacoes CHAVEDIREITA ELSE CHAVESQUERDA
    {
        add_code_offset(3);
        // start_else = get_code_offset();
        stack_push(start_else_ptr, get_code_offset());
    }
    lista_afirmacoes
    {
        int end_else = get_code_offset();
        int start_else = stack_pop(start_else_ptr);
        int start_if = stack_pop(start_if_ptr);

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
    CHAVEDIREITA
    ;

afirmacao_iterativa:
    WHILE PARENTESESQUERDO {
        // start_comp = get_code_offset(); // inicio da comparacao do while
        stack_push(start_comp_ptr, get_code_offset());
    } expressao {
        add_code_offset(4);
        // start_while = get_code_offset(); // inicio do meu codigo dentro do while
        stack_push(start_while_ptr, get_code_offset());
    } PARENTESEDIREITO CHAVESQUERDA lista_afirmacoes {
        int start_while = stack_pop(start_while_ptr);
        int start_comp = stack_pop(start_comp_ptr);

        // jump incondicional pro inicio do while
        gen_code(LDC, t1, start_comp, 0);
        gen_code(LDC, t2, 0, 0);
        gen_code(JEQ, t2, 0, t1);

        int end_while = get_code_offset();

        make_code(start_while - 4, LD, t1, 0, sp); // t1 = stack.top() (resultado da comparacao)
        make_code(start_while - 3, LDA, sp, 1, sp); // stack.pop() (sp = sp + 1)
        make_code(start_while - 2, LDC, t2, end_while, 0); // t2 = end_while
        make_code(start_while - 1, JEQ, t1, 0, t2); // pc = start_else (se a condicao for falsa)
    } CHAVEDIREITA
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
    ESCREVA PARENTESESQUERDO fator PARENTESEDIREITO PONTOVIRGULA { 
        pop(); // t1 = fator
        gen_code(OUT, t1, 0, 0);

        // int offset = utilizar($3);

        // gen_code(LDC, t1, 0, 0); // t1 = 0
        // gen_code(LD, t1, 0, t1); // t1 = dMem[0 + t1] = dMem[0] = 1023
        // gen_code(LD, t1, -offset, t1); // t1 = dMem[-offset + t1]
        // gen_code(OUT, t1, 0, 0);
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
    expressao_matematica MENOR expressao_matematica {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0);
        gen_code(JLT, t2, 1, pc);
        gen_code(LDC, t1, 0, 0);
        push();
    }
    | expressao_matematica MENORIGUAL expressao_matematica {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JLE, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
    | expressao_matematica MAIOR expressao_matematica {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JGT, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
    | expressao_matematica MAIORIGUAL expressao_matematica {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JGE, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
    | expressao_matematica IGUAL expressao_matematica {
        ari_op(SUB);
        pop(); // t1 = stack.top(); stack.pop();
        copy(t1, t2); // t2 = t1;
        
        gen_code(LDC, t1, 1, 0); // resposta da comparacao = 1
        gen_code(JEQ, t2, 1, pc); // subtracao == 0 (os dois caras sao iguais, pula a prox. instrucao)
        gen_code(LDC, t1, 0, 0); // resposta da comparacao = 0
        
        push(); // push(t1) (t1 = {0 ou 1})
    }
    | expressao_matematica DIFERENTE expressao_matematica {
        ari_op(SUB);
        pop();
        copy(t1, t2);
        gen_code(LDC, t1, 1, 0); 
        gen_code(JNE, t2, 1, pc); 
        gen_code(LDC, t1, 0, 0); 
        push();
    }
    | expressao_matematica
    ;

expressao_matematica:
    termo
    | termo ADICAO termo { ari_op(ADD); }
    | termo SUBTRACAO termo { ari_op(SUB); }
    | termo MULTIPLICACAO termo { ari_op(MUL); }
    | termo DIVISAO termo { ari_op(DIV); }
    ;

termo:
    | fator
    ;

fator:
    PARENTESESQUERDO expressao PARENTESEDIREITO
    | fator ADICAO fator { ari_op(ADD); }
    | fator SUBTRACAO fator { ari_op(SUB); }
    | fator MULTIPLICACAO fator { ari_op(MUL); }
    | fator DIVISAO fator { ari_op(DIV); }
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

%%

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
    //print_code();

    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Problema com a análise sintática! %s\n", s);
    return 0;
}


