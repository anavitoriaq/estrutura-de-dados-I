#include "lista2.c"


int main(void){
    Lista2 * lista;
    // NULL <- | 5 | <--> | 3 | -> NULL
    lista = lst2_insere(lista, 3); //insere 3   
    lista = lst2_insere(lista, 5); //insere 5
    //busca elemento 3 na lista
    Lista2 * elemento = lst2_busca(lista, 3); //busca 3
    printf("Elemento: %d\n", elemento->info);
    return 0;
}