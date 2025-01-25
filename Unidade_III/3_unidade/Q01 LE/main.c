#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int info;
    struct lista * proximo;
}Lista;

Lista *insere_elemento(Lista *l, int v){
    Lista *novo_no = (Lista*) malloc(sizeof(Lista));
    novo_no->info = v;
    novo_no->proximo = l;
    return novo_no;
}

void imprime_maiores_que_n(Lista *l, int n){
    Lista *aux;
    for (aux = l; aux != NULL; aux = aux->proximo)
    {
        if (aux->info > n)
        {
            printf("Valor: %d\n", aux->info);
        }
        
    }
    
}

int main(){
    Lista *lista = NULL;
    lista = insere_elemento(lista, 7);
    lista = insere_elemento(lista, 12);
    lista = insere_elemento(lista, 1);
    lista = insere_elemento(lista, 3);
    imprime_maiores_que_n(lista, 0);
    return 0;
}