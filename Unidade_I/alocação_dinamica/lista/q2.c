/*Questão 2) Escreva um programa para corrigir provas de múltipla escolha. Cada prova tem N
questões e cada questão vale 10/N pontos. Os primeiros dados a serem lidos são o número de
questões e o gabarito da prova. Em seguida, serão lidas as respectivas respostas de um total de
10 alunos matriculados. Calcule e mostre:
a) a nota obtida para cada aluno;
b) a porcentagem de aprovação, sabendo-se que a nota mínima para ser aprovado é 6.*/
#include<stdio.h>

int main(void){
    int quantidadeQuestoes, alunos = 10, contador;
    float notas[alunos];
    // primeiro dado: quantidade de questões
    printf("informe a quantidade de questoes:");
    scanf(" %d", &quantidadeQuestoes);
    // cada questão vale 10/N pontos
    float pontos = 10.0/ quantidadeQuestoes;
    char gabarito [quantidadeQuestoes];

    //segundo dado: gabarito da prova
    for(contador = 0; contador < quantidadeQuestoes; contador++){
        printf("digite o gabarito da questao %d: ", contador+1);
        scanf(" %c", &gabarito[contador]);
    }
}