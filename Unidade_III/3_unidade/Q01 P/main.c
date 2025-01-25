#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} No;

typedef struct pilha
{
    No *topo;
    int *tamanho;
} Pilha;

Pilha *cria_pilha()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));  
    if (!pilha) exit(1);
    pilha->tamanho = 0;
    pilha->topo = NULL;
    return pilha;
}

void push(Pilha *p, int v)
{
    No *novo_no = malloc(sizeof(No));
    if (!novo_no) exit(1);
    novo_no->valor = v;
    novo_no->prox = p->topo;
    p->topo = novo_no;
    p->tamanho++;
}

int pop(Pilha *p){
    if (!p->topo)
    {
        printf("Aborta missao\n");
        return -1;
    }
    No *aux = p->topo;
    int valor = aux->valor;
    p->topo = aux->prox;
    free(aux);
    return valor;
}

int main (){
    Pilha *p = cria_pilha();
    push(p, 1);
    push(p, 2);
    push(p, 3);
    printf("%d\n", pop(p));
    return 0;
}