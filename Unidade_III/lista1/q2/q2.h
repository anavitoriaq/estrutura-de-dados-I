#include <stdio.h>
#include <stdlib.h>
typedef struct lista Lista;

Lista * inserir_no_inicio( Lista * lista, int  valor);

Lista * inserir_no_fim( Lista * lista, int valor);

void exibir_lista(Lista * lista);

Lista * remover_primeiro(Lista * lista);

int buscar(Lista * lista, int valor);

Lista * remove_valor (Lista * lista, int valor);

Lista * inserir_apos(Lista * lista, int valor, int novoValor);