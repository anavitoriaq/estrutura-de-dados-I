#include <stdio.h>
#include "aluno.h"
#include "disciplina.h"

int main(){
    Disciplina* matematica = cria_disciplina("Matematica", 101);
    Disciplina* fisica = cria_disciplina("Fisica", 102);
    Disciplina* quimica = cria_disciplina("Quimica", 103);
    Aluno* aluno1 = cria_aluno("Alice", 12345);
    Aluno* aluno2 = cria_aluno("Bob", 67890);

    matricula_disciplina(aluno1, matematica);
    matricula_disciplina(aluno1, fisica);
    matricula_disciplina(aluno2, quimica);
    matricula_disciplina(aluno2, matematica);
    exibe_aluno(aluno1);
    exibe_aluno(aluno2);
    exclui_aluno(aluno1);
    exclui_aluno(aluno2);
    exclui_disciplina(matematica);
    exclui_disciplina(fisica);
    exclui_disciplina(quimica);

    return 0;
}