#include<stdio.h>
#include"aluno.h"

int main(void){
    Aluno *aluno = criarAluno(123, "Maria", 8.5);
    salvarAlunoEmArquivo("alunos.txt", aluno);
    exibirAlunos("alunos.txt");
    return 0;
}