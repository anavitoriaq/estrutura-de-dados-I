#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int tamanho, int* vetor){
    printf("Digite os elementos dos vetores:\n");
    for(int count = 0; count < tamanho; count ++){
        scanf("%d ", &vetor[count]);
    }
}

void imprime_vetor(int tamanho, int* vetor){
    for(int count = tamanho - 1; count >= 0; count--){
        printf("%d\t", vetor[count]);
    }
}

int * aloca_vetor(int tamanho){
    int *vetor = (int*) malloc (tamanho * sizeof(int));
    if(vetor == NULL){
        printf("NO MEMORY");
        exit(1);
    }
    return vetor; 
}

int main(void){
    int tamanho;
    printf("Informe o tamanho do vetor:\n");
    scanf("%d", &tamanho);

    //aloca função
    int * vetor = aloca_vetor(tamanho);
    
    //elementos do vetor
    preenche_vetor(tamanho, vetor);

    //imprime vetor
    imprime_vetor(tamanho, vetor);
    free(vetor);
    return 0;
}