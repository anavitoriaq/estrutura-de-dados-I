#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    char nome[50];
    int idade;
    float notas[3];
    float media;
} Aluno;

Aluno *bubble_sort(Aluno *vet, int tam) {
    int i, j;
    Aluno aux;
    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - 1 - i; j++) {
            if (vet[j].media < vet[j + 1].media) {  
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
    return vet;
}

int main() {
    FILE *arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    int linhas = 0;
    char linha[200];
    
    while (fgets(linha, 200, arquivo) != NULL) {
        linhas++;
    }

    Aluno *alunos = (Aluno *)malloc(sizeof(Aluno) * linhas);
    if (alunos == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    rewind(arquivo);  
    int i = 0;

    while (fscanf(arquivo, "%[^,],%d,%f,%f,%f\n", alunos[i].nome, &alunos[i].idade, 
                  &alunos[i].notas[0], &alunos[i].notas[1], &alunos[i].notas[2]) != EOF) {
        alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3.0;
        i++;
    }

    alunos = bubble_sort(alunos, linhas);

    for (i = 0; i < linhas; i++) {
        printf("Aluno %d: %s  :  %.1f\n", i + 1, alunos[i].nome, alunos[i].media);
    }

    fclose(arquivo);

    arquivo = fopen("resultados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo resultados.txt\n");
        free(alunos);  
        exit(1);
    }

    for (i = 0; i < linhas; i++) {
        fprintf(arquivo, "Nome: %s\tMedia: %.1f\n", alunos[i].nome, alunos[i].media);
    }

    fclose(arquivo);
    free(alunos);  
    return 0;
}