#include<stdio.h>
#include<stdlib.h>

typedef struct pilha Pilha;

typedef struct lista Lista;

Pilha* pilha_cria(void);

void pilha_push(Pilha* p, float v);

float pilha_pop(Pilha* p);

int pilha_vazia(Pilha* p);

void pilha_libera(Pilha* p);

void pilha_imprime(Pilha* l);