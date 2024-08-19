#include <stdio.h>
#include <stdlib.h>
#include <time.h> // para a função srand

int main(void) {
    int n;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    
    // verificação positivo
    if (n <= 0) {
        printf("O número deve ser positivo!\n");
        return 1;
    }
    
    // alocação da matriz
    int **matriz = (int **)malloc(n * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    
    for (int linha = 0; linha < n; linha++) {
        matriz[linha] = (int *)malloc(n * sizeof(int));
        if (matriz[linha] == NULL) {
            printf("Erro na alocação de memória!\n");
            for (int i = 0; i < linha; i++) { // liberação da memória já alocada
                free(matriz[i]);
            }
            free(matriz);
            return 1;
        }
    }
    
    // preenchimento da matriz
    srand(time(NULL)); // inicializa o gerador de números aleatórios com base no tempo atual
    printf("Matriz gerada:\n");
    for (int linha = 0; linha < n; linha++) {
        for (int coluna = 0; coluna < n; coluna++) {
            matriz[linha][coluna] = rand() % 100 + 1; // número aleatório entre 1 e 100
            printf("%3d", matriz[linha][coluna]);
        }
        printf("\n");
    }
    
    // liberação da memória
    for (int linha = 0; linha < n; linha++) {
        free(matriz[linha]);
    }
    free(matriz);
    
    return 0;
}