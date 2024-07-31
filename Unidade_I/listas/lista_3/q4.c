#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAX_NOME 100
#define MAX_PESSOAS 100

int main(void){
    int numPessoas;
    printf("digite o numero de pessoas (maximo %d): ", MAX_PESSOAS);
    scanf("%d", &numPessoas);

    if(numPessoas <= 0 || numPessoas > MAX_PESSOAS){ //verifica se o numPessoas é valido
        printf("numero de pessoas invalido!!\n");
        return 1;
    }

    //alocação de memoria para armazenar nomes e idades
    char **nomes = (char **) malloc(numPessoas *sizeof(char *));
    if(nomes == NULL){
        printf("erro na alocação de memoria!\n");
        return 1;
    }
    int *idades = (int *) malloc(numPessoas *sizeof(int));
    if(idades == NULL){
        printf("erro na alocação de memoria!\n");
        free(nomes); //libera a memoria alocada antes para nomes
        return 1;
    }
    
    for(int i = 0; i < numPessoas; i++){
        nomes[i] = (char *) malloc(MAX_NOME *sizeof(char));
        if(nomes == NULL){
            printf("erro na alocação para o nome da pessoa %d\n.", i + 1);
            for(int j = 0; j < i; j++){ //libera memoria
                free(nomes[j]);
            }
            free(nomes);
            free(idades);
            return 1;
        }
        printf("digite o nome completo da pessoa %d:", i + 1);
        scanf(" %[^\n]", nomes[i]);
    }
    
    return 0; 
}