#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} Lista;

Lista* ultimo(Lista* l) {
    if (l == NULL) {
        return NULL;
    }
    while (l->prox != NULL) {
        l = l->prox;
    }
    
    return l; 
}

Lista* cria_no(int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo != NULL) {
        novo->info = valor;
        novo->prox = NULL;
    }
    return novo;
}

Lista* insere_inicio(Lista* l, int valor) {
    Lista* novo = cria_no(valor);
    novo->prox = l;
    return novo;
}

void libera_lista(Lista* l) {
    Lista* temp;
    while (l != NULL) {
        temp = l;
        l = l->prox;
        free(temp);
    }
}

void imprime_lista(Lista* l) {
    while (l != NULL) {
        printf("%d -> ", l->info);
        l = l->prox;
    }
    printf("NULL\n");
}

int main() {
    Lista* l = NULL;

    l = insere_inicio(l, 10);
    l = insere_inicio(l, 20);
    l = insere_inicio(l, 30);
    l = insere_inicio(l, 5);
    l = insere_inicio(l, 15);

    imprime_lista(l);

    Lista* ult = ultimo(l);
    if (ult != NULL) {
        printf("O último nó contém o valor: %d\n", ult->info);
    } else {
        printf("A lista está vazia.\n");
    }
    libera_lista(l);

    return 0;
}