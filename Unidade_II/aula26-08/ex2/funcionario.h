#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Definição de um valor máximo para o vetor de funcionários


typedef struct funcionario Funcionario;

Funcionario **alocafuncionarios();

void liberaFuncionario(Funcionario **funcionarios, int qnt);

Funcionario *buscaFuncionario(Funcionario **funcionarios, int id, int qnt);

Funcionario **adicionaFuncionario(Funcionario **funcionarios, char *nome, int id, float salario, int *qnt);

Funcionario **removerFuncionario(Funcionario **funcionario, int id, int *qnt);

void listarFuncionarios(Funcionario **funcionarios, int qnt);
##endif