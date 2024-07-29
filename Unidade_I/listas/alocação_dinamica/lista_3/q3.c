#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite um número inteiro positivo n: ");
    scanf("%d", &n);

    int **matriz = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }
    if (matriz == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1; // gera um número entre 1 e 100
        }
    }
    printf("Matriz gerada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}