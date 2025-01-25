#include<stdio.h>
#include<stdlib.h>

typedef struct lista Lista;

Lista * inserir_no_inicio(Lista * lista, int valor);

Lista * inserir_no_fim(Lista * lista, int valor);

void exibir_lista(Lista * lista);

Lista * remover_primeiro(Lista * lista);

Lista * remover_ultimo(Lista * lista);

Lista * remover_valor(Lista * lista, int valor);