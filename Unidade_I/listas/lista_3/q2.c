#include <stdio.h>
#include <stdlib.h>

int main(void){
    int linhas, colunas;

    printf("Informe o numero de linhas e colunas da matriz: ");
    scanf("%d %d", &linhas, &colunas);

    //alocação da matriz 
    int **matriz = (int**) malloc(linhas *sizeof(int*));
    if(matriz == NULL){
        printf("NO MEMORY");
        exit(1);
    }

    for(int linha = 0; linha < linhas; linha++){ 
        matriz[linha] = (int*) malloc(colunas * sizeof(int));
    }

    //elementos da matriz
    printf("Digite os elementos da matriz: \n");
    for(int linha = 0; linha < linhas; linha++){
        for(int coluna = 0; coluna < colunas; coluna++){
            scanf("%d", &matriz[linha][coluna]);
        }
    }
    //imprime matriz
    printf("Matriz original\n");
    for(int linha = 0; linha < linhas; linha++){
        for(int coluna = 0; coluna < colunas; coluna++){
            printf("%d\t", matriz[linha][coluna]);
        }
        printf("\n");
    }

    //imprime a matriz transposta
    printf("Matriz transposta\n");
    for(int coluna = 0; coluna < colunas; coluna++){
        for(int linha = 0; linha < linhas; linha++){
            printf("%d\t", matriz[linha][coluna]);
        }
        printf("\n");
    }

    //liberando a memoria alocada pra matriz
    for(int linha = 0; linha < linhas; linha++){
        free(matriz[linha]);
    }
    free(matriz);
    return 0;
}