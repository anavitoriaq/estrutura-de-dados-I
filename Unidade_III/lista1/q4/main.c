#include<stdio.h>
#include<stdlib.h>
#include"q4.h"

int main (void){
    Lista * lista = NULL;
    lista = inserir_no_inicio(lista, 10);
    lista = inserir_no_inicio(lista, 20);
    lista = inserir_no_inicio(lista, 30);

    printf("inseridos no inicio: \n");
    exibir_lista(lista);

    lista = inserir_no_fim(lista, 40);
    lista = inserir_no_fim(lista, 50);
    lista = inserir_no_fim(lista, 60);

    printf("inseridos no fim: \n");
    exibir_lista(lista);

    lista = remover_valor(lista, 20);
    printf("removido o valor 20: \n");
    exibir_lista(lista);

    lista = remover_primeiro(lista);
    printf("removido o primeiro no: \n");
    exibir_lista(lista);

    lista = remover_ultimo(lista);
    printf("removido o ultimo no: \n");
    exibir_lista(lista);

    return 0;
}