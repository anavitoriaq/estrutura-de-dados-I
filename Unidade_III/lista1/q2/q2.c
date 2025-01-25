#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

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
    Lista * listasemPrimeiro;
    if (lista == NULL){
        return NULL;
    }
    listasemPrimeiro = lista->prox;
    free(lista);
    return(listasemPrimeiro);
}

int buscar(Lista * lista, int valor){
    int posicao = 0;
    if(lista == NULL){
        printf("Lista vazia!\n");
        exit(1);
    }
    Lista * count;
    for (count = lista; count != NULL; count = count->prox){
        if (count->info == valor){
            return posicao;
        }
        posicao++;
    }
    printf ("valor %d nao encotrado na lista\n", valor);
    exit(1);
}

Lista * remove_valor (Lista * lista, int valor){
    Lista * count = lista;
    Lista * ant = NULL;

    //busca o valor que sera removido
    while (count->info != valor){
        if (count == NULL){
            return NULL;
        }
        ant = count;
        count = count->prox;
    }
    //se for para remover o primeiro valor
    if (ant == NULL){
        lista = lista->prox;
    }
    //se for para remover o ultimo valor
    else{
        ant->prox = count->prox;
    }
    free(count);
    return lista;
}

Lista * inserir_apos(Lista * lista, int valor, int novoValor){
    Lista * count;
    Lista * novo = (Lista*)malloc(sizeof(Lista));
    if(novo == NULL){
        exit(1);
    }
    novo->info = valor;
    for(count = lista; count != NULL; count = count->prox){
        if(count->info = valor){
            novo->prox = count->prox;
            count->prox = novo;
            return lista;
        }
    }
    free(novo);
    return lista;
}