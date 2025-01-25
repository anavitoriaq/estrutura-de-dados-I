#include<stdio.h>
#include<stdlib.h>
#include"q4.h"

struct lista{
    int info;
    struct lista * prox;
};

Lista * inserir_no_inicio(Lista * lista, int){
    Lista * novo = (Lista *) malloc(sizeof(Lista));
    if(novo == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    novo->info = valor;

    if(lista == NULL){
        novo->prox = novo;
        return novo;
    }
    Lista * count = lista;

    while (count->prox != lista){
        count = count->prox;
    }
    count->prox = novo;
    novo->prox = lista;
    return novo;
}

Lista * inserir_no_fim(Lista * lista, int valor){
    Lista * novo = (Lista *) malloc (sizeof(Lista));
    if (novo == NULL){
        exit(1);
    }
    novo->info = valor;

    if(lista == NULL){
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
    int posicao = 0;
    do{
        if (count->info == valor){
            return posicao;
        }
        posicao++;
    }
    while(count != lista);
    printf("valor nao encontrado\n");
}

Lista * remover_primeiro(Lista * lista){
    if (lista == NULL){
        printf("Lista vazia!\n");
        return NULL;
    }
    Lista * ultimo = lista;
    while(ultimo->prox != lista){
        ultimo = ultimo->prox;
    }
    if(lista == lista->prox){
        free(lista);
        return NULL;
    }
    else{
        Lista* novo_inicio = lista->prox;
        ultimo->prox = novo_inicio;
        free(lista);
        return novo_inicio;
    }
}

Lista * remover_ultimo(Lista * lista){
    if (lista == NULL){
        printf("Lista vazia!\n");
        return NULL;
    }
    Lista* atual = lista;
    Lista* ant = NULL;

    while (atual->prox != lista){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == lista){
        free(lista);
        return NULL;
    }
    else{
        ant->prox = lista;
        free(atual);
        return lista;
    }
}

Lista * remover_valor(Lista * lista, int valor){
    if(lista == NULL){
        printf("Lista vazia!\n");
        return NULL;
    }
    Lista * atual = lista;
    Lista * ant = NULL;

    do{
        if(atual->info == valor){
            if(ant == lista){
                return remover_primeiro(lista);
            }
            else{
                ant->prox = atual->prox;
                if(atual->prox == lista){
                    return remover_ultimo(lista);
                }
                free(atual);
                return lista;
            }
        }
        ant = atual;
        atual = atual->prox;
    }
    while(atual != lista);
    printf("valor %d nao encontrado!\n", valor);
    return lista;
}