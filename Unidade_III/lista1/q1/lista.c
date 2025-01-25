#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
    int info;
    struct lista *prox;
};

Lista * inserir_no_inicio( Lista * lista, int  valor){
    Lista * inicio = (Lista*)malloc(sizeof(Lista));
    if(inicio == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    inicio->prox = lista;    
    inicio->info= valor;

    return inicio;
}

Lista * inserir_no_fim( Lista * lista, int valor){
    Lista * fim = (Lista*)malloc(sizeof(Lista));
    if (fim == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    fim->prox = NULL;   
    fim->info = valor;

    if (lista == NULL){
        return fim;
    }
    Lista * count;
    for (count = lista; count->prox != NULL; count = count->prox){
    }
    count->prox = fim;
    return lista;
}

void exibir_lista(Lista * lista){
    Lista * count;
    for (count = lista; count != NULL; count = count->prox){
        printf("%d\n", count->info);
    }
    printf("\n");
}

Lista * remover_primeiro(Lista * lista){
    if (lista == NULL){
        return NULL;
    }
    Lista * aux = lista->prox;
    free(lista);
    return aux;
}