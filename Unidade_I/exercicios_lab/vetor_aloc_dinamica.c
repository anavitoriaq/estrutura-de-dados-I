#include<stdio.h> // para a função printf, scanf
#include<stdlib.h> // para usar a função malloc, exit
#define QUANTIDADE_ALUNOS 5 //constante

typedef struct aluno{
    int matricula, idade;
    char nome[20];
}Aluno;

void preenche(Aluno * aluno, int tamanho){
    //#função para preencher um vetor de struct aluno
    int count;
    for(count=0; count<tamanho; count++){
        printf("digite o nome:\t");
        scanf(" %[^\n]", &aluno[count].nome);
        getchar();
        printf("informe a matricula :\t");
        scanf("%[^\n]", &aluno[count].matricula);
        printf("digite a idade:\t");
        scanf("%d", &aluno[count].idade);
    }
}
int main(void){
    Aluno * aluno = (Aluno*) malloc(QUANTIDADE_ALUNOS*sizeof(Aluno));
    if(aluno==NULL){
        printf("no memory RAM");
        exit(1);
    }
    preenche(aluno, QUANTIDADE_ALUNOS);

    int novo_tamanho;
    printf("informe o novo tamanho do vetor: \t");
    scanf("%d", &novo_tamanho);
    aluno = (Aluno*) realloc(aluno, novo_tamanho*sizeof(Aluno));
    if(aluno==NULL){
        exit(1);
    }
    else{
        printf("vetor realocado!\n");
    }
    preenche(aluno, novo_tamanho);
    return 0;
}