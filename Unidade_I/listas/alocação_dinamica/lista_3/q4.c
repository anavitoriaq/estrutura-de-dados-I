#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_NOME 100 // Tamanho máximo do nome

int main() {
    int numPessoas;
    printf("Digite o numero de pessoas: ");
    scanf("%d", &numPessoas);

    while (getchar() != '\n');
    char **nomes = (char **)malloc(numPessoas * sizeof(char *));

    for (int i = 0; i < numPessoas; i++) {
        nomes[i] = (char *)malloc(TAMANHO_NOME * sizeof(char));
    }

    int *idades = (int *)malloc(numPessoas * sizeof(int));

    if (nomes == NULL || idades == NULL) {
        printf("Erro na alocação de memoria\n");
        return 1;
    }

    for (int i = 0; i < numPessoas; i++) {
        printf("Digite o nome completo da pessoa %d: ", i + 1);
        fgets(nomes[i], TAMANHO_NOME, stdin);
        int j = 0;
        while (nomes[i][j] != '\0') {
            if (nomes[i][j] == '\n') {
                nomes[i][j] = '\0';
                break;
            }
            j++;
        }
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &idades[i]);
        while (getchar() != '\n');
    }
    printf("\nNomes armazenados:\n");
    for (int i = 0; i < numPessoas; i++) {
        printf("Nome: %s, Idade: %d\n", nomes[i], idades[i]);
    }
    for (int i = 0; i < numPessoas; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(idades);

    return 0;
}