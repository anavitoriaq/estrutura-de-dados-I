#include <stdio.h>
#include <stdlib.h>

void elementos(int **matriz, int linhas, int colunas){
    printf("Digite os elementos da matriz:\n");
    for(int linha=0; linha<linhas; linha++){
        for(int coluna=0; coluna<colunas; coluna++){
            scanf("%d", &matriz[linha][coluna]);
        }
    }
}
void imprimirOG(int **matriz, int linhas, int colunas){
        printf("\nMatriz Original:\n");
        for(int linha=0; linha<linhas; linha++){
        printf("\n");
        for(int coluna=0; coluna<colunas; coluna++){
        printf("%d\t", matriz[linha][coluna]);
        }
        printf("\n");
    }
}
void imprimirTP(int **matriz,int linhas,int colunas){
        printf("\nMatriz Transposta:\n");
        for(int linha=0; linha<linhas; linha++){
        printf("\n");
        for(int coluna=0; coluna<colunas; coluna++){
        printf("%d\t", matriz[coluna][linha]);
        }
        printf("\n");
    }
}

void liberar(int **matriz, int linhas){
    for(int linha=0; linha<linhas; linha++){
    free(matriz[linha]);
    }
    free(matriz);
}

void verificar(void *ptr){
        if (ptr==NULL){
            printf("Error.");
       exit(1);
    }
}
int main(void){
    int linhas, colunas;
    printf("Digite a quantidade de linhas e colunas da matriz:\n");
    scanf("%d %d", &linhas, &colunas);
    int ** matriz = (int **) malloc(linhas*sizeof(int*));
    verificar (matriz);
    for(int count = 0; count<linhas; count++){
        matriz[count] = (int*) malloc(colunas*sizeof(int));
        verificar (matriz[count]);
    }
    elementos(matriz, linhas, colunas);
    imprimirOG(matriz, linhas, colunas);
    imprimirTP(matriz, linhas, colunas);
    liberar (matriz, linhas);
    return 0;
}