#include<stdio.h>
#include<stdlib.h>

/*entrada: tamanho do vetor
elementos o vetor
- alocar dinâmicamente vetor
- imprimir valor inverso
saída: vetor na ordem inversa*/

void preenche_vetor(int tamanho, int* vetor){  
     printf("digite os elementos do vetor: \n");
     for(int count=0; count<tamanho; count++){
        scanf("&d", &vetor[count]);
     }
}  

void imprime_inverso(int tamanho, int * vetor){
     printf("vetor inverso: n");
     for(int count=tamanho-1; count>=0; count--){
         printf("%d\t", vetor[count]);
     }
}

int * aloca_vetor(int tamanho){
     int * vetor = (int*) malloc(tamanho*sizeof(int));
     if(vetor==NULL){
        printf("no memory");
        exit(1);
     }
     else{
         printf("vetor alocado com sucesso!");
     }
     return vetor;
}

int main(void){
    int tamanho;
    printf("informe o tamanho do vetor:\t");
    scanf("%d", &tamanho);


    //aloca vetor
    int * vetor = aloca_vetor(tamanho);
    //elementos do vetor
    preenche_vetor(tamanho, vetor);
    //imprime vetor inverso
    imprime_inverso(tamanho, vetor);
    free(vetor);
    return 0;
}