#include<stdio.h>
#include<stdlib.h>


int main(void){
	int tamanho;
    printf("informe o tamanho do vetor:\t");
    scanf("%d", &tamanho);
    int*vetor=(int*)malloc(tamanho*sizeof(int));
    if(vetor==NULL){
       printf("no memory");
       exit(1);
    }
    else{
        printf("vetor alocado com sucesso!\n");
    }
    //elementos do vetor

    printf("digitar os elementos do vetor:\t");
    for(int count=0; count<tamanho; count++){
        scanf("%d", &vetor[count]);
    }
    //imprima vetor inverso
    int count;
    printf("vetor inverso:\t ");
    for(count=tamanho-1; count>=0; count--){
       printf("%d\t", vetor[count]);
    }
    return 0;
}