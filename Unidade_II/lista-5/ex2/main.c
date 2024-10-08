#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

#define MAX 100


int main(){
    Funcionario **funcionarios = alocaFuncionarios();
    int qnt = 0;
    int opcao;
    char nome[50];
    int id;
    float salario;
    Funcionario *f;

    do{
        printf("\nMenu:\n");
        printf("1. Adicionar Funcionario\n");
        printf("2. Remover Funcionario\n");
        printf("3. Buscar Funcionario\n");
        printf("4. Listar Funcionarios\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o nome do funcionario: ");
            scanf(" %[^\n]", nome);
            printf("Digite o ID do funcionario: ");
            scanf("%d", &id);
            printf("Digite o salario do funcionario: ");
            scanf("%f", &salario);
            funcionarios = adicionaFuncionario(funcionarios, nome, id, salario, &qnt);
            break;
        case 2:
            printf("Digite o ID do funcionario a ser removido: ");
            scanf("%d", &id);
            funcionarios = removerFuncionario(funcionarios, id, &qnt);
            break;
        case 3:
            printf("Digite o ID do funcionario a ser buscado: ");
            scanf("%d", &id);
            f = buscaFuncionario(funcionarios, id, qnt);
            if (f != NULL)
            {
                printf("Funcionario encontrado");
            }
            else
            {
                printf("Funcionario nao encontrado.\n");
            }
            break;
        case 4:
            listarFuncionarios(funcionarios, qnt);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    liberaFuncionario(funcionarios, qnt);
    return 0;
}