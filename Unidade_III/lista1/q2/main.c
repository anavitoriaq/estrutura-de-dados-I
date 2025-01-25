#include<stdio.h>
#include<stdlib.h>
#include "q2.h"

int main(void){
    Lista * lista = NULL;
    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 20);
    lista = inserir_no_inicio(lista, 30);
    lista = inserir_no_fim(lista, 40);   

    exibir_lista(lista);

    lista = inserir_no_fim(lista, 50);
    lista = inserir_no_fim(lista, 60);
    lista = inserir_no_fim(lista, 70);
    lista = inserir_no_fim(lista, 80);

    exibir_lista(lista);

    lista = remover_primeiro(lista);
    exibir_lista(lista);

    int posicao = buscar(lista, 70);
    printf("esta na posicao %d\n", posicao);
    posicao = buscar(lista, 100);
    printf("esta na posicao %d\n", posicao);

    lista = remove_valor(lista, 50);
    lista = remove_valor(lista, 60);
    exibir_lista(lista);

    lista = inserir_apos(lista, 70, 65);
    lista = inserir_apos(lista, 65, 55);
    exibir_lista(lista);
    return 0;
}