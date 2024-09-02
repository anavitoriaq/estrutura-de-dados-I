#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

struct funcionario {
    char nome[50];
    int id;
    float salario;
};

Funcionario **alocaFuncionarios() {
    Funcionario **new = (Funcionario **)malloc(sizeof(Funcionario *) * MAX);
    if (new == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    return new;
}

Funcionario **adicionaFuncionario(Funcionario **funcionarios, char *nome, int id, float salario, int *qnt) {
    if (*qnt >= MAX) {
        printf("Número máximo de funcionários atingido.\n");
        return funcionarios;
    }
    funcionarios[*qnt] = (Funcionario *)malloc(sizeof(Funcionario));
    if (funcionarios[*qnt] == NULL) {
        printf("Erro ao alocar memória para o funcionário.\n");
        exit(1);
    }
    strcpy(funcionarios[*qnt]->nome, nome);
    funcionarios[*qnt]->id = id;
    funcionarios[*qnt]->salario = salario;
    (*qnt)++;
    return funcionarios;
}

Funcionario **removerFuncionario(Funcionario **funcionarios, int id, int *qnt) {
    int i;
    for (i = 0; i < (*qnt); i++) {
        if (funcionarios[i]->id == id) {
            break;
        }
    }
    if (i == *qnt) {
        printf("Funcionário com ID %d não encontrado.\n", id);
        return funcionarios;
    }
    free(funcionarios[i]);
    for (int j = i; j < (*qnt) - 1; j++) {
        funcionarios[j] = funcionarios[j + 1];
    }
    funcionarios[*qnt - 1] = NULL;
    (*qnt)--;
    return funcionarios;
}

Funcionario *buscaFuncionario(Funcionario **funcionarios, int id, int qnt) {
    for (int i = 0; i < qnt; i++) {
        if (funcionarios[i]->id == id) {
            return funcionarios[i];
        }
    }
    return NULL;
}

void listarFuncionarios(Funcionario **funcionarios, int qnt) {
    for (int i = 0; i < qnt; i++) {
        printf("Nome: %s\nID: %d\nSalário: %.2f\n", funcionarios[i]->nome, funcionarios[i]->id, funcionarios[i]->salario);
    }
}

void liberaFuncionario(Funcionario **funcionarios, int qnt) {
    for (int i = 0; i < qnt; i++) {
        free(funcionarios[i]);
    }
    free(funcionarios);
}