#include"pilha.h"

struct lista{
    float info;
    struct lista* prox;
};


struct pilha{
    Lista* prim;
};

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

void pilha_push(Pilha* p, float v){
    Lista* n = (Lista*)malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

float pilha_pop(Pilha* p){
    Lista* t;
    float v;
    if(pilha_vazia(p)){
        printf("pilha vazia\n");
        exit(1);
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

int pilha_vazia(Pilha* p){
    return (p->prim == NULL);
}

void pilha_libera(Pilha* p){
    Lista* q = p->prim;
    Lista* t;
    while(q != NULL){
        t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

void pilha_imprime(Pilha* l){
    Lista*p;
    for(p = l->prim; p != NULL; p = p->prox){
        printf("info = %.2f\n", p->info);
    }
}