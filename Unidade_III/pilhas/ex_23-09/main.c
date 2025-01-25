#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

int main(){
    Pilha* pilha = pilha_cria();
    int i;
    for(i = 0; i < 10; i++){
        pilha_push(pilha, i);
    }
    while(!pilha_vazia(pilha)){
        printf("%.0f\n", pilha_pop(pilha));
    }
    printf("\n");
    pilha_libera(pilha);
    return 0;
}