#include <stdio.h>
#include <stdlib.h>

typedef enum generos{
    MASCULINO = 1, 
    FEMININO, 
    TRANSGENERO, 
    NEUTRO,
    NAO_BINARIO
}Generos;

typedef union documentos{
   long int RG, CPF, passaporte, Num_SUS;
}Documentos; 

typedef struct pessoa{
    char nome[10];
    int idade;
    Documentos documentos;
    Generos generos;
    int opcao_documento;
}Pessoa;

void preencha(Pessoa *pessoa){
    printf("\nInforme o nome:\n");
    scanf(" %[^\n]", pessoa->nome);
    printf("\nEscolha o documento:\n1.RG\n2.CPF\n3.Passaporte\n4.Numero do SUS\n");
    scanf("%d", &pessoa->opcao_documento);
    switch(pessoa->opcao_documento){
        case 1:
           printf("Informe o RG: ");
           scanf("%ld", &pessoa->documentos.RG);
           break;
        case 2: 
            printf("Informe o CPF: ");
            scanf("%ld", &pessoa->documentos.CPF);
            break;
        case 3: 
            printf("Informe o passaporte: ");
            scanf("%ld", &pessoa->documentos.passaporte);
            break;
        case 4:
            printf("Informe o numero do SUS: ");
            scanf("%ld", &pessoa->documentos.Num_SUS);
            break;
        default:
            printf("Opcao invalida! Tente novamente.");
            break;
    }
    printf("\nInforme a idade: ");
    scanf("%d", &pessoa->idade);
    printf("\nEscolha o genero:\n 1. Masculino\n 2. Feminino\n 3. Transgenero\n 4. Neutro\n 5. Nao binario\n");
    scanf("%d", &pessoa->generos);
}
void imprima(Pessoa *pessoa){
    printf("==========================================\n");
    printf("Nome: %s\n", pessoa->nome);
    //printf("Documento: %d", pessoa->documentos);
    switch(pessoa->opcao_documento){
        case 1:
            printf("Documento: %ld\n", pessoa->documentos.RG);
            break;
        case 2:
            printf("Documento: %ld\n", pessoa->documentos.CPF);
            break;
        case 3:
            printf("Documento: %ld\n", pessoa->documentos.passaporte);
            break;
        case 4:
            printf("Documento: %ld\n", pessoa->documentos.Num_SUS);
            break;
        default: 
            printf("Documento invalido!\n");
            break;
    }
    printf("Idade: %d\n", pessoa->idade);
    switch(pessoa->generos){
        case MASCULINO:
            printf("Genero: Masculino\n");
            break;
        case FEMININO:
            printf("Genero: Feminino\n");
            break;
        case TRANSGENERO:
            printf("Genero: Transgenero\n");
            break;
        case NEUTRO:
            printf("Genero: Neutro\n");
            break;
        case NAO_BINARIO:
            printf("Genero: Nao binario\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}
//ATUALIZAÇAO DE IDADE
void atualiza_idade(Pessoa *pessoa){
    printf("Informe a nova idade:\n");
    scanf("%d", &pessoa->idade);
}

//FUNCAO PARA IMPRIMIR DA PESSOA

int main(void){
    /*int tamanho;
    Pessoa pessoa = (Pessoa) malloc(tamanho sizeof(Pessoa));*/
    Pessoa pessoa;
    preencha(&pessoa);
    imprima(&pessoa);
    atualiza_idade(&pessoa);
    return 0;
}