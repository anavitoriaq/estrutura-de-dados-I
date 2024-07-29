#include<stdio.h>
#include<stdlib.h>
//exemplo: mudando o tamanho do vetor
int main(void){
    int tamanho, novo_tamanho;
    printf ("digite o tamanho do vetor: ");
    scanf ("%d", &tamanho);
    int * vetor = (int*)calloc(tamanho,sizeof(int));
    if(vetor==NULL){
        printf("nao ha espaço na memoria");
        exit(1);
    }
    else{
        printf("vetor alocado");
    }

    printf ("\ndigite um novo tamanho: ");
    scanf ("%d", &novo_tamanho);
    vetor = (int*)realloc(vetor, novo_tamanho*sizeof(int));
    free(vetor);
    return 0;
}