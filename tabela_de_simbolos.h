struct simbolo {
    char* nome;
    int usada;
    // TODO: tipo
    struct simbolo* prox;
};

typedef struct simbolo simbolo;

simbolo* tabela_de_simbolos = (simbolo *)0;// null
simbolo* adicionar_simbolo();
simbolo* procurar_simbolo();
void imprimir_tabela_de_simbolos();

simbolo* adicionar_simbolo(char* nome) {
    simbolo* ptr = (simbolo*) malloc(sizeof(simbolo));
    ptr->nome = (char *) malloc(strlen(nome) + 1);
    strcpy(ptr->nome, nome);

    ptr->prox = (struct simbolo *) tabela_de_simbolos;
    tabela_de_simbolos = ptr;

    return ptr;
}

simbolo* procurar_simbolo(char* nome) {
    simbolo* atual = tabela_de_simbolos;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome)) {
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

// TODO: implementar e imprimir no final do código
void imprimir_tabela_de_simbolos() {
    // Simbolo* atual = cabeca;

    // while (atual != NULL) {
    //     printf("%d - \n", atual->value); // TODO:
    //     atual = atual->prox;
    // }

    printf("\n");
}