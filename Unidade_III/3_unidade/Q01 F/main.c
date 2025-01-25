#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} No;

typedef struct fila
{
    No *ini;
    No *fim;
    int *tamanho;
} Fila;

Fila * cria_fila(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if (!fila) exit(1);
    fila->ini = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

void fila_insere(Fila *f, int v){
    No* novo_no = (No*) malloc(sizeof(No));
    if(!novo_no) exit(1);
    novo_no->valor = v;
    if (!f->ini)
    {
        f->fim = novo_no;
        f->ini = novo_no;
        novo_no->prox = NULL;
    }
    f->fim->prox = novo_no;
    f->fim = novo_no;
    novo_no->prox = NULL;
    f->tamanho++;
}

int fila_remove(Fila *f){
    if(!f->ini){
        printf("TA vazia cara, nao foi dessa vez\n");
        return -1;
    }
    No *aux = f->ini;
    f->ini = f->ini->prox;
    int valor = aux->valor;
    free(aux);
    return valor;
}

int main (){
    Fila *f = cria_fila();
    fila_insere(f, 1);
    fila_insere(f, 11);
    fila_insere(f, 221);
    printf("%d\n", fila_remove(f));
    printf("%d\n", fila_remove(f));
    return 0;
}