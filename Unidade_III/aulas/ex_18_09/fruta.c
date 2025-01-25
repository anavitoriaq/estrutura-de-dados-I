//passo 1: incluir as bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "fruta.h"

//passo 2: definir a estrutura para Fruta
struct fruta{
    char nome[50];
    float valor_por_kg;
};

//passo 3: definir a estrutura para a Lista Duplamente Encadeada para armazenar as Frutas
struct No{
    Fruta * fruta;
    struct No *ant;
    struct No *prox;
};

//passo 4: definir a funcção que cria um nó na lista
No* criaNo(char * nome_da_fruta, float valor_por_kg_da_fruta){
    No * nova_fruta = (No*) malloc(sizeof(No));
    nova_fruta->fruta = (Fruta*) malloc(sizeof(Fruta));
    if(nova_fruta == NULL || nova_fruta->fruta == NULL){
        printf("computador sem memoria!\n");
        exit(1);
    }
    else{
        printf("memoria alocada! \n espaco para fruta reservado!\n");
        strcpy(nova_fruta->fruta->nome, nome_da_fruta);
        nova_fruta->fruta->valor_por_kg = valor_por_kg_da_fruta;
        nova_fruta->prox = NULL;
        nova_fruta->ant = NULL;
    }
    return nova_fruta;
}

//passo 5: definir a função que insere o Nó criado no inicio da lista
No* inserirNoInicio(No * lista, char * nome_da_fruta, float valor_por_kg){
    No * nova_fruta = criaNo(nome_da_fruta, valor_por_kg);
    // verificar se a lista ta vazia
    if(lista == NULL){
        lista = nova_fruta;
    }
    else{
        nova_fruta->prox = lista;
        lista->ant = nova_fruta;
    }
    return nova_fruta;
}

//passo 6: definir a função para exibir as frutas (imprimir)
void exibirListaDeFrutas(No * lista){
    if (!lista){ // == (lista == NULL) verifica se a lista está vazia
        printf("lista vazia! sem frutas cadastradas!\n");
        exit(1);
    }
    No* contador = lista; //contador para percorrer a lista
    while(contador!=NULL){
        printf("fruta: %s, valor (kg): R$ %.2f\n", contador->fruta->nome, contador->fruta->valor_por_kg);
        contador = contador->prox;
    }
}