#include<stdio.h>
#include<stdlib.h>

typedef enum genero{
    MASCULINO=1,
    FEMININO
}Genero;

typedef struct pessoa{
    char nome[20];
    int idade;
    Genero gen;
}Pessoa;

void preenche_pessoa(Pessoa *pessoa){
    printf("digite o nome:\n");
    scanf(" %[^\n]", &pessoa->nome);
    printf("digite a idade:\n");
    scanf(" %d", &pessoa->idade);
    printf("informe o genero:\n");
    scanf(" %d", &pessoa->gen);
}

void imprime_pessoa(Pessoa *pessoa){
    printf("Nome: %s, &pessoa->nome");
    printf("Idade: %d, &pessoa->idade");
    printf("Genero: %d, &pessoa->gen");
}

int main(void){
    Pessoa *pessoa;

    printf("====Dados da pessoa====\n");
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Genero: %d\n", pessoa->gen);
    
    free(pessoa);
    return 0;
}