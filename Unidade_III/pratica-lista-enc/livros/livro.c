#include<stdio.h>
#include<stdlib.h>
#include "livro.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct livro
{
    int id;
    char titulo[50];
    float preco;
};

struct no
{
    Livro *livro;
    No *prox;
};

void adiciona_livro(No **lista, int id, char *titulo, float preco)
{
    Livro *novo_livro = (Livro *)malloc(sizeof(Livro));
    novo_livro->id = id;
    novo_livro->preco = preco;
    strcpy(novo_livro->titulo, titulo);

    No *novo = (No *)malloc(sizeof(No));
    novo->livro = novo_livro;
    novo->prox = *lista;
    *lista = novo;
}

void imprime_livros(No *lista)
{
    No *aux;
    for (aux = lista; aux != NULL; aux = aux->prox)
    {
        printf("Id:%d\tTitulo:%s\tPreco:%.2f\n",
               aux->livro->id, aux->livro->titulo, aux->livro->preco);
    }
}

void libera_lista(No *lista)
{
    No *aux = lista;
    No *ant = lista;
    while (aux != NULL)
    {
        ant = aux;
        aux = aux->prox;
        free(ant->livro);
        free(ant);
    }
}

void remove_livro(No **lista, int id)
{
    No *aux = *lista;
    No *ant;

    if ((*lista)->livro->id == id)
    {
        ant = aux;
        aux = aux->prox;
        free(ant->livro);
        free(ant);
        *lista = aux;
    }

    while (aux != NULL && aux->livro->id != id)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        printf("Livro nao encontrado\n");
        return;
    }

    ant->prox = aux->prox;
    free(aux->livro);
    free(aux);
}

void adiciona_livro_ordenado(No **lista, int id, char *titulo, float preco)
{
    Livro *novo_livro = (Livro *)malloc(sizeof(Livro));
    novo_livro->id = id;
    novo_livro->preco = preco;
    strcpy(novo_livro->titulo, titulo);

    No *novo = (No *)malloc(sizeof(No));
    novo->livro = novo_livro;
    if (*lista == NULL || id < (*lista)->livro->id)
    {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    No *aux = *lista;
    No *ant;

    while (aux != NULL && aux->livro->id < id)
    {
        ant = aux;
        aux = aux->prox;
    }

    novo->prox = ant->prox;
    ant->prox = novo;
}