#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct lista Lista;

struct no
{
    int info;
    No *proximo;
    No *anterior;
};

struct lista
{
    No *inicio;
    No *final;
};

Lista *cria_lista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->final = NULL;
    return lista;
}

Lista *insere_lista(Lista *l, int v)
{
    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->info = v;
    if (l->inicio == NULL)
    {
        l->inicio = novo_no;
        l->final = novo_no;
        novo_no->anterior = novo_no;
        novo_no->proximo = novo_no;
        return l;
    }
    l->final->proximo = novo_no;
    novo_no->anterior = l->final;
    l->final = novo_no;
    l->final->proximo = l->inicio;
    l->inicio->anterior = l->final;
    return l;
}

void imprime_lista(Lista *l)
{
    if (l->inicio == NULL)
    {
        printf("Lista Vazia");
        return;
    }
    No *aux = l->inicio;
    do
    {
        printf("Valor: %d\n", aux->info);
        aux = aux->proximo;
    } while (aux != l->inicio);
}

No *busca_lista(Lista *l, int v)
{
    if (l->inicio == NULL)
    {
        printf("Lista Vazia");
        return NULL;
    }
    No *aux = l->inicio;
    do
    {
        if (aux->info == v)
        {
            return aux;
        }
        aux = aux->proximo;
    } while (aux != l->inicio);
    printf("Nao achou nao parceiro\n");
    return NULL;
}

Lista *remover_lista(Lista *l, int v)
{
    No *aux = busca_lista(l, v);
    if (!aux)
        return l;
    if (aux == l->inicio && aux == l->final)
    {
        free(aux);
        free(l);
        return cria_lista();
    }
    if (aux == l->inicio)
    {
        l->inicio = l->inicio->proximo;
        l->inicio->anterior = l->final;
        l->final->proximo = l->inicio;
        free(aux);
        return l;
    }
    if (aux == l->final)
    {
        l->final = l->final->anterior;
        l->inicio->anterior = l->final;
        l->final->proximo = l->inicio;
        free(aux);
        return l;
    }

    aux->anterior->proximo = aux->proximo;
    aux->proximo->anterior = aux->anterior;
    free(aux);
    return l;
}

int main()
{
    Lista *lista = cria_lista();
    lista = insere_lista(lista, 1);
    lista = insere_lista(lista, 2);
    lista = insere_lista(lista, 3);
    lista = insere_lista(lista, 4);
    lista = insere_lista(lista, 5);
    imprime_lista(lista);
    printf("\n\n\n");
    remover_lista(lista, 10);
    imprime_lista(lista);

    return 0;
}