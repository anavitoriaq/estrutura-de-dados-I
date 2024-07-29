#include <stdio.h>
#include <stdlib.h>


typedef union documentos{
   long int RG, CPF, passaporte, Num_SUS;
}Documentos; 

typedef struct pessoa{
    char nome[20];
    int idade;
    Documentos documentos;
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
}

//FUNCAO PARA IMPRIMIR DA PESSOA
void imprima(Pessoa *pessoa, int tamanho){
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
}
//ATUALIZAÇAO DE IDADE
void atualiza_idade(Pessoa *pessoa, int idade_alterar){
    idade_alterar-=1;
    printf("Informe a nova idade:\n");
    scanf("%d", &pessoa[idade_alterar].idade);
}

void velhaNovaPessoa(Pessoa *pessoa, int tamanho){
    int i, maior = 0, menor = 0;
    for(i = 1; i < tamanho; i++){
        if(pessoa[i].idade > pessoa[maior].idade){
        maior = i;
        } 
        if(pessoa[i].idade < pessoa[menor].idade){
        menor = i;
        }
    }
    printf("Pessoa com maior idade: %s\nIdade: %d\n", pessoa[maior].nome, pessoa[maior].idade);
    printf("Pessoa com menor idade: %s\nIdade: %d\n", pessoa[menor].nome, pessoa[menor].idade);
}
int main(void){
    int tamanho, i, idade_alterar;
    printf("Digite a quantidade de pessoas:\n");
    scanf("%d", &tamanho);
    Pessoa *pessoa = (Pessoa *) malloc(tamanho * sizeof(Pessoa));
    if (pessoa == NULL){
        printf("erro\n");
        exit (1);
    }
    for(i = 0; i < tamanho; i++){
        printf("\nPreenchendo dados da pessoa %d:\n", i + 1);
        preencha(&pessoa[i]);
    }
    imprima(pessoa, tamanho);
    printf("qual pessoa quer mudar idade:\n");
    scanf("%d", &idade_alterar);
    atualiza_idade(pessoa, idade_alterar);
    velhaNovaPessoa(pessoa, tamanho);
    free(pessoa);
    return 0;
}