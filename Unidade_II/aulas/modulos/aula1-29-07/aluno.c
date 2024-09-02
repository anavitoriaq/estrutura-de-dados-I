#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
//aula 29-07

struct aluno {
    char nome[20];
    int idade;
    long int matricula; 
}; 

Aluno * aloca_aluno(void){
    Aluno * aluno = (Aluno*) malloc(sizeof(Aluno));
    if(aluno==NULL){
        printf("No memory!");
        exit(1);
    }
    else{
        printf("Aluno alocado!\n");
    }
    return aluno;
}

void preenche(Aluno * aluno){
    printf("informe o nome:\t");
    scanf(" %[^\n]", aluno->nome);
    printf("informe idade e matricula:\t");
    scanf("%d %ld", &aluno->idade, &aluno->matricula);
}

void imprime(Aluno * aluno){
    printf("Nome:%s \t Idade: %d \t Matricula: %ld", aluno->nome, aluno->idade, aluno->matricula);
}


/*Para compilar: 
gcc -c aluno.c
gcc -c main.c 
gcc -o main.exe aluno.o main.o 
./main*/