#include <stdio.h>
#include <stdlib.h>
#include "livro.h"


int main()
{
    No *lista = NULL;
    adiciona_livro_ordenado(&lista, 3, "a menina que roubava livros", 173.2);
    adiciona_livro_ordenado(&lista, 5, "verity", 233.2);
    adiciona_livro_ordenado(&lista, 1, "a biblioteca da meia-noite", 121.2);
    adiciona_livro_ordenado(&lista, 4, "a culpa e das estrelas", 121.2);

    imprime_livros(lista);

    libera_lista(lista);

    return 0;
}