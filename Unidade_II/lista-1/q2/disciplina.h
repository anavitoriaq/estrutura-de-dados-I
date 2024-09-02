#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct disciplina Disciplina;

Disciplina* cria_disciplina(char nome[], int codigo);
void exclui_disciplina(Disciplina* disciplina);
void exibe_disciplina(Disciplina* disciplina);

#endif