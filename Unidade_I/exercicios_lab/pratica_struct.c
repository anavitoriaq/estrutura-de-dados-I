#include<stdio.h>

typedef struct Funcionario{
    char nome[20], cargo[20];
    float salario; 
    long int identificador; // guarda inteiros maiores
}Funcionario;

// função para preencher dados
void preenche(Funcionario * servidor){
    // função para preencher variavel do tipo funcionario
    printf("digite o nome: \t");
    scanf("%[^\n]", servidor->nome);
    getchar();
    printf("digite seu salario: \t");
    scanf("%f", &servidor->salario);
    printf("digite o identificador: \t");
    scanf("%d", &servidor->identificador);
    printf("digite o cargo: \t");
    scanf("%[^\n]", servidor->cargo);
    getchar();
}

//função para imprimir dados
void imprimi(Funcionario * servidor){
    printf("nome: %[^\n] ", servidor->nome);
    printf("salario: %f", servidor->salario);
    printf("identificador: %d", servidor->identificador);
    printf("cargo: %[^\n]", servidor->cargo);
}

// função para alterar o salario
void alterar_salario(){
    int novo_salario;
    printf("digite o novo salario: \t");
    scanf("%f", &novo_salario);
}