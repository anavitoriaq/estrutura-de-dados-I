#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} Lista;

Lista* retira_n(Lista* l, int n) {
    Lista* anterior = NULL;
    Lista* atual = l;

    while (atual != NULL) {
        if (atual->info == n) {
            if (anterior == NULL) {
                l = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            Lista* temp = atual;
            atual = atual->prox;
            free(temp);  
        } else {
            anterior = atual;
            atual = atual->prox;
        }
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
    l = insere_inicio(l, 10);
    l = insere_inicio(l, 30);
    l = insere_inicio(l, 10);

    printf("Lista original: ");
    imprime_lista(l);

    l = retira_n(l, 10);

    printf("Lista após remoção: ");
    imprime_lista(l);

    libera_lista(l);

    return 0;
}