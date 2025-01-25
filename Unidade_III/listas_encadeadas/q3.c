#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    float info;
    struct lista* prox;
} Lista;

Lista* concatena(Lista* l1, Lista* l2) {
    if (l1 == NULL) return l2;

    if (l2 == NULL) return l1;

    Lista* p = l1;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = l2;

    return l1;
}

Lista* cria_no(float valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (novo != NULL) {
        novo->info = valor;
        novo->prox = NULL;
    }
    return novo;
}

Lista* insere_inicio(Lista* l, float valor) {
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
        printf("%.2f -> ", l->info);
        l = l->prox;
    }
    printf("NULL\n");
}

int main() {
    Lista* l1 = NULL;
    Lista* l2 = NULL;

    l1 = insere_inicio(l1, 10.5);
    l1 = insere_inicio(l1, 20.5);
    l1 = insere_inicio(l1, 30.5);

    l2 = insere_inicio(l2, 40.5);
    l2 = insere_inicio(l2, 50.5);

    printf("Lista 1: ");
    imprime_lista(l1);
    printf("Lista 2: ");
    imprime_lista(l2);

    Lista* l_concat = concatena(l1, l2);

    printf("Lista concatenada: ");
    imprime_lista(l_concat);

    libera_lista(l_concat);

    return 0;
}