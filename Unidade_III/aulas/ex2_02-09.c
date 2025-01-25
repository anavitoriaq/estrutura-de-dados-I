#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Lista encadeada para guardar nome de fruta

struct no{
    char nome_fruta[20];
    struct no * proxima_fruta;
};
typedef struct no No;

No * adiciona_frutas(No * lista, char * nome_fruta){
    No * nova_fruta = (No*) malloc(sizeof(No)); 
    if (nova_fruta==NULL){
        printf("No memory!\n");
        exit(1);
    }
    strcpy(nova_fruta->nome_fruta,nome_fruta);
    nova_fruta->proxima_fruta=lista;
/*conectando o ultimo elemento com o inicio*/
    if(lista == NULL){
        lista->proxima_fruta = nova_fruta;
        return nova_fruta;
    }
    No *aux = lista;
    No *ant = nova_fruta;
    while(aux != nova_fruta){
        ant = aux;
        aux = aux->proxima_fruta;
    }
    ant->proxima_fruta = nova_fruta;
    return nova_fruta;
}

void imprime_Lista_frutas(No * lista){
    No * count;
    for(count=lista; count!=NULL; count=count->proxima_fruta){
        printf(" %s -> ", count->nome_fruta);
    }
}

int main(void){
    No * lista;
    lista = NULL;
    lista = adiciona_frutas(lista, "Uva");
    lista = adiciona_frutas(lista, "Abacate");
    lista = adiciona_frutas(lista, "Morango");
    imprime_Lista_frutas(lista);
    return 0;
}