#include<stdio.h>
#include<stdlib.h>
#include "q3.h"

struct lista{
    int info;
    struct lista *prox;
};

Lista * inserir_no_inicio(Lista * lista, int valor){
    Lista * novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL){
        printf("Memoria insuficiente\n");
        exit(1);
    }
    novo->info = valor;

    if (lista == NULL){
        novo->prox = novo;
        return novo;
    }
    Lista * count = lista;

    while(count->prox != lista){
        count = count->prox;
    }
    count->prox = novo;
    novo->prox = lista;
    return novo;
}

Lista * inserir_no_fim(Lista * lista, int valor){
    Lista * novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL){
        exit(1);
    }
    novo->info = valor;
    if (lista == NULL){
        novo->prox = novo;
        return novo;
    }
    Lista * count = lista;

    while(count->prox != lista){
        count = count->prox;
    }
    count->prox = novo;
    novo->prox = lista;
    return lista;
}

void exibir_lista(Lista * lista){
    Lista * count = lista;
    do{
        printf("-> %d", count->info);
        count = count->prox;
    }
    while(count != lista);
    printf("\n");
}