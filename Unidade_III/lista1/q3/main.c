#include<stdio.h>
#include<stdlib.h>
#include "q3.h"

int main(void){
    Lista * lista = NULL;
    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 20);
    lista = inserir_no_inicio(lista, 30);
    lista = inserir_no_inicio(lista, 40);
    exibir_lista(lista);

    lista = inserir_no_fim(lista, 50);
    lista = inserir_no_fim(lista, 60);
    lista = inserir_no_fim(lista, 70);
    lista = inserir_no_fim(lista, 80);
    exibir_lista(lista);
    return 0;
}