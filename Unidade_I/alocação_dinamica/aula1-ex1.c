#include <stdio.h>  // printf = scanf 
#include <stdlib.h> // malloc, exit, free

float * cria_vetor(int tamanho){
    //função que cria vetor de números reais
    float * vetor = (float*) malloc (tamanho*sizeof(float));
        if (vetor == NULL){
            printf ("não ha espaço na memória!\n");
            exit (1);
        }
        else{
            printf ("alocação bem sucedida!\n");
        }
    return vetor;
}
void ler_vetor(float * vetor, int tamanho){
    //função que ler valores para um vetor de números reais
    printf ("informe os valores para o vetor: \t");
    for (int index=0; index<tamanho; index++){
        scanf ("%f", &vetor[index]);
    }
}
void imprime_vetor (float * vetor, int tamanho){
    for (int index=0; index<tamanho; index++){
        printf ("%f\t", vetor[index]);
    }
}
int main (void){
    float * vetor = cria_vetor(5);
//chamada das funções ler e imprimir
ler_vetor(vetor, tamanho);
imprime_vetor(vetor, tamanho);
//libera vetor da memoria
free (vetor);
return 0;
}