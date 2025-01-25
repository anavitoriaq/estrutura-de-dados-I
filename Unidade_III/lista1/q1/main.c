#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(void){
    Lista * lista = NULL;
    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 20);
    lista = inserir_no_inicio(lista, 30);
    exibir_lista(lista);
    lista = inserir_no_fim(lista, 40);
    lista = inserir_no_fim(lista, 50);
    lista = inserir_no_fim(lista, 60);
    exibir_lista(lista);

    lista = remover_primeiro(lista);
    exibir_lista(lista);
    return 0;
}