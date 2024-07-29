#include <stdio.h>
#include <stdlib.h>

void elementos(int * vetor, int tamanho){
        for(int count=0; count<tamanho; count++){
        scanf("%d", &vetor[count]);
    }
}
void verificar(int *vetor){
    if (vetor==NULL){
        printf("No memory");
        exit(1);
    }
    else{
        printf("Vetor alocado com sucesso\n");
    }
}

void inverso(int * vetor, int tamanho){
    for (int count=tamanho-1; count >= 0; count--){
    printf("%d \t", vetor[count]);
    }
}
int main(void){
    int tamanho;
    int *vetor;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &tamanho);

    vetor = (int*) malloc(tamanho*sizeof(int));

    verificar (vetor);

    printf("Digite os elementos do vetor:\n");

    elementos (vetor, tamanho);

    printf("Vetor inverso:\n");

    inverso (vetor, tamanho);
    
    free(vetor);
    return 0;
}