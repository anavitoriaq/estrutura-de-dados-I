#include "aluno.h"

int main()
{
    No *lista = NULL;
    lista = adiciona_aluno_ordenado(lista, 4, "Pedro", 7.3);
    lista = adiciona_aluno_ordenado(lista, 2, "Lucas", 8.3);
    lista = adiciona_aluno_ordenado(lista, 5, "Matheus", 6.3);
    lista = adiciona_aluno_ordenado(lista, 1, "Anabel", 5.3);
    lista = adiciona_aluno_ordenado(lista, 3, "Maria", 1.3);
    imprime_alunos(lista);
    lista = remove_aluno(lista, 5);
    printf("======================\n");
    imprime_alunos(lista);
    libera_lista(lista);
    return 0;
}