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
   long int RG, CPF, passaporte, NumSus;
}Documentos; 

typedef struct pessoa{
    char nome[10];
    int idade;
    Documentos doc;
    Generos generos;
    int opcao_documento;
}Pessoa;

void preencha(Pessoa * pessoa){
    printf("\nInforme o nome: ");
    scanf(" %[^\n]", pessoa->nome);
    printf("\nEscolha o documento:\n1. RG\n2. CPF\n3. Passaporte\n4. Numero do SUS\n");
    scanf("%d", &pessoa->opcao_documento);
    switch(pessoa->opcao_documento){
        case 1:
           printf("Informe o RG: ");
           scanf("%ld", &pessoa->doc.RG);
           break;
        case 2: 
            printf("Informe o CPF: ");
            scanf("%ld", &pessoa->doc.CPF);
            break;
        case 3: 
            printf("Informe o passaporte: ");
            scanf("%ld", &pessoa->doc.passaporte);
            break;
        case 4:
            printf("Informe o numero do SUS: ");
            scanf("%ld", &pessoa->doc.NumSus);
            break;
        default:
            printf("Opcao invalida! Tente novamente.");
            break;
    }
    printf("\nInforme a idade: ");
    scanf("%d", &pessoa->idade);
    printf("\nEscolha o genero:\n 1. Masculino\n 2. Feminino\n 3. Transgenero\n 4. Neutro\n 5. Nao binario\n");
    scanf("%d", &pessoa->generos);
    printf("===================================\n");

    
}

void imprima(Pessoa *pessoa, int quant){
    int i;
    for(i = 0; i < quant; i++){
        printf("===================================\n");
        printf("Nome: %s\n", pessoa[i].nome);
    /*printf("Documento: %d", pessoa->doc);*/
        switch(pessoa->opcao_documento){
            case 1:
                printf("Documento: %ld\n", pessoa[i].doc.RG);
                break;
            case 2:
                printf("Documento: %ld\n", pessoa[i].doc.CPF);
                break;
            case 3:
                printf("Documento: %ld\n", pessoa[i].doc.passaporte);
                break;
            case 4:
                printf("Documento: %ld\n", pessoa[i].doc.NumSus);
                break;
            default: 
                printf("Documento invalido!\n");
                break;
        }   
        printf("Idade: %d\n", pessoa[i].idade);
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
                printf("Genero: Nao-binario\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    printf("===================================\n");
    }
}
//ATUALIZAÇAO DE IDADE
void atualiza_idade(Pessoa * pessoa, int idadeAlterar){
    idadeAlterar -= 1;
    printf("Informe a nova idade: \n");
    scanf("%d", &pessoa[idadeAlterar].idade);
}

//FUNCAO PARA IMPRIMIR DA PESSOA
void pessoas_velhas(Pessoa *pessoa, int tamanho){
    int count, maisVelha = 0, maisNova = 0;
    for(count = 0; count < tamanho; count++){
        if(pessoa[count].idade > pessoa[maisVelha].idade){
            maisVelha = count;
        }
        if(pessoa[count].idade < pessoa[maisNova].idade){
            maisNova = count;
        }
    }
    printf("\nPessoa mais velha: %s,\nPessoa mais nova: %s", pessoa[maisVelha].nome, pessoa[maisNova].nome);

}

int main(void){
    int quant_pessoas, idadeAlterar;
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &quant_pessoas);
    Pessoa pessoa[quant_pessoas];
    int count;
    for(count = 0; count < quant_pessoas; count++){
        preencha(&pessoa[count]);
    }
    imprima(pessoa, quant_pessoas);
    printf("Qual pessoa quer mudar idade? ");
    scanf("%d", &idadeAlterar);
    atualiza_idade(pessoa, idadeAlterar);
    imprima(pessoa, quant_pessoas);
    pessoas_velhas(pessoa, quant_pessoas);
    free(pessoa);
    return 0;
}