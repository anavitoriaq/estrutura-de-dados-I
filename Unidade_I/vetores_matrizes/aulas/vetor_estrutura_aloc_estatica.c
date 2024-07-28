#include<stdio.h>
#define QUANTIDADE_ALUNOS 5 //constante

typedef struct Aluno{
    int matricula, idade;
    char nome[20];
}Aluno;

int main(void){
    Aluno aluno [QUANTIDADE_ALUNOS];
    int count;
    for(count=0; count<QUANTIDADE_ALUNOS; count++){
        printf("digite o nome:\t");
        scanf(" %[^\n]", &aluno[count].nome);
        getchar();
        printf("informe a matricula :\t");
        scanf("%[^\n]", &aluno[count].matricula);
        printf("digite a idade:\t");
        scanf("%d", &aluno[count].idade);
    }
    return 0;
}