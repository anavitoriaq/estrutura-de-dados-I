#include"pilha.h"

struct pilha{
    float info;
    struct pilha* prox;
};

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p = NULL;
    return p;
}

void pilha_push(Pilha* p, float v){
    Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
    novo->info = v;
    novo->prox = p;
    p = novo;
    Pilha
}

float pilha_pop(Pilha* p){
    Pilha* t;
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    v = p->info;
    t = p;
    p = p->prox;
    free(t);
    return v;
}