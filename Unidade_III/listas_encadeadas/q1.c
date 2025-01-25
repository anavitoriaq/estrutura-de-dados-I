#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

int maiores(Lista *l, int n){
    int count = 0;

    while(l != NULL){
        if(l -> info > n){
            count++;
        }
        l = l -> prox;
    }
    return count;
}

Lista *cria_no(int valor){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (novo != NULL){
        novo -> info = valor;
        novo -> prox = NULL;
    }
    return novo;
}

Lista* insere_no_inicio (Lista *l, int valor){
    Lista *novo = cria_no(valor);
    novo -> prox = l;
    return novo;
}

void libera_lista(Lista *l){
    Lista* temp;
    while(l != NULL){
        temp = l;
        l = l -> prox;
        free(temp);
    }
}

void imprime_lista(Lista* l){
    while (l != NULL){
        printf("%d ->", l -> info);
        l = l -> prox;
    }
    printf("NULL\n");
}

int main(void){
    Lista *l = NULL;
    l = insere_no_inicio(l, 10);
    l = insere_no_inicio(l, 20);
    l = insere_no_inicio(l, 30);
    l = insere_no_inicio(l, 5);
    l = insere_no_inicio(l, 15);

    imprime_lista(l);

    int n = 10;
    printf("numeros maiores que %d: %d\n", n, maiores(l, n));

    libera_lista(l);
    return 0;
}