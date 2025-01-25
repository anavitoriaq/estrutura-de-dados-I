#include<stdio.h>
#include<stdlib.h>

typedef struct lista2 Lista2;

Lista2* lst2_insere(Lista2 *l, int v);

Lista2* lst2_busca(Lista2 *l, int v);

Lista2* lst2_retira(Lista2 *l, int v);

void l2circ_imprime_rev(Lista2 *l);

