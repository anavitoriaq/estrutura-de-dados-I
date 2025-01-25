#include <stdio.h>
#include <stdlib.h>

typedef struct livro Livro;

typedef struct no No;

void adiciona_livro(No **lista, int id, char *titulo, float preco);

void imprime_livros(No *lista);

void libera_lista(No* lista);

void remove_livro(No** lista, int id);

void adiciona_livro_ordenado(No** lista, int id, char* titulo,float preco);