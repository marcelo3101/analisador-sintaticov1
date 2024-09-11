
int data_location();

struct simbolo {
    char* nome;
    int usada;
    int offset;
    struct simbolo* prox;
};

typedef struct simbolo simbolo;

simbolo* tabela_de_simbolos = NULL; // cabeça
simbolo* adicionar_simbolo();
simbolo* procurar_simbolo();
void imprimir_tabela_de_simbolos();

simbolo* adicionar_simbolo(char* nome) {
    simbolo* ptr = (simbolo*) malloc(sizeof(simbolo));
    ptr->nome = (char *) malloc(strlen(nome) + 1);
    ptr->offset = data_location();
    strcpy(ptr->nome, nome);

    if (strcmp(nome, "main") == 0) {
        ptr->usada = 1; // por padrão, a função main sempre é chamada no início do código, então ela foi usada
    } else {
        ptr->usada = 0;
    }


    ptr->prox = (struct simbolo *) tabela_de_simbolos;
    tabela_de_simbolos = ptr;

    return ptr;
}

simbolo* procurar_simbolo(char* nome) {
    simbolo* atual = tabela_de_simbolos;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual; // retorna o ponteiro para o símbolo
        }

        atual = atual->prox;
    }

    return NULL;
}

void imprimir_tabela_de_simbolos() {
    printf("\nTabela de Símbolos:\n\n");

    simbolo* atual = tabela_de_simbolos;

    while (atual != NULL) {
        printf("Nome: %s | Usada: %d\n", atual->nome, atual->usada);
        atual = atual->prox;
    }

    printf("\n");
}