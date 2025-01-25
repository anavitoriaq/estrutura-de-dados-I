/* 
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

 Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
	int info; // campo para armazenar a informação
	struct lista*prox; // ponteiro para o próximo elemento da lista
};


Lista* lst_cria(void){ // função que cria uma lista vazia (NULL)
	return NULL;
}

Lista* lst_insere(Lista* l, int v){ // função que insere um elemento no início da lista
	Lista* novo = (Lista*) malloc(sizeof(Lista)); // aloca memória para o novo elemento
	if (novo == NULL) // verifica se a memória foi alocada corretamente 
    {
        printf("[ERRO] memoria insuficiente!");
        exit(1);
    }
	novo->info = v; // atribui a informação ao novo elemento
	novo->prox = l; // faz o novo elemento apontar para o primeiro elemento da lista
	return novo;

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */

}

int lst_vazia(Lista *l){ // função que verifica se a lista está vazia
	return (l==NULL); // retorna 1 se a lista estiver vazia e 0 caso contrário
}

void lst_imprime(Lista*l){ // função que imprime os elementos da lista

	Lista*p; // ponteiro para percorrer a lista
	for(p=l; p!=NULL; p=p->prox){ // percorre a lista
		printf(" Info = %d \n", p->info); // imprime a informação do elemento
	}

}

Lista * lst_busca(int elemento, Lista* l){ // função que busca um elemento na lista
	Lista * p;  // ponteiro para percorrer a lista
	for(p=l; p!=NULL; p=p->prox){   // percorre a lista
		if(p->info ==elemento)     // verifica se o elemento foi encontrado
		return p; // retorna o ponteiro para o elemento encontrado
	}

	return NULL;    // retorna NULL caso o elemento não seja encontrado

}

Lista * lst_retira(Lista*l, int v){ // função que retira um elemento da lista
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while(p->info!=v){ 
    	if (p==NULL)
        	return l; /* n�o achou: retorna lista original */
        ant = p;
        p = p->prox;
            /* verifica se achou elemento */

    }
    /* retira elemento */
    if (ant==NULL)
    /* retira elemento do inicio */
        l = p->prox;
    else
    /* retira elemento do meio da lista */
        ant->prox = p->prox;
    free(p);
    return l;
}

void lst_libera(Lista* l){ // função que libera a memória alocada para a lista
    Lista* p = l;   // ponteiro para percorrer a lista
    Lista* t;   // ponteiro para guardar o próximo elemento
    while (p != NULL) { // percorre a lista
        t = p->prox;    // guarda o próximo elemento
        free(p);    // libera a memória alocada para o elemento
        p = t;  // faz p apontar para o próximo elemento

    }
}



Lista* lst_insere_ordenada(Lista * l, int v){   // função que insere de forma ordenada um elemento na lista
	Lista * novo;   // ponteiro para o novo elemento
	Lista * ant = NULL; // ponteiro para o elemento anterior
	Lista * p =l;   // ponteiro para percorrer a lista
	while(p!=NULL && p->info<v){    // percorre a lista
		ant = p;    // guarda o elemento anterior
		p = p->prox;    // faz p apontar para o próximo elemento

	}
	novo = (Lista*) malloc(sizeof(Lista));  // aloca memória para o novo elemento
	novo->info = v; // atribui a informação ao novo elemento
	if(ant ==NULL){ // verifica se o elemento deve ser inserido no início da lista
		novo->prox = l; // faz o novo elemento apontar para o primeiro elemento da lista
		l = novo;   // faz a lista apontar para o novo elemento
	}
	else {  // caso o elemento deva ser inserido no meio da lista
		novo->prox = ant-> prox;    // faz o novo elemento apontar para o próximo elemento
		ant->prox = novo;   // faz o elemento anterior apontar para o novo elemento
	}
	return l;
}

 
Lista* lst_ler_arquivo(char* nome_arquivo){
	FILE *arquivo;
	int valor;
	Lista* l = lst_cria();
	arquivo = fopen(nome_arquivo, "r");
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
	while(fscanf(arquivo, "%d", &valor) != EOF){
		l = lst_insere(l, valor);
	}
	fclose(arquivo);
	return l;
}