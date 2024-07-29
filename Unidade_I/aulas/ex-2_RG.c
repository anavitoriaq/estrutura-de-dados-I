/* union: 
- sao usadas quando queremos armazenar valores heterogêos em um mesmo espaço de memória;
- os parametros compartilham o mesmo espaço de memória;
- só podemos armazenar um parametro por vez
*/
#include<stdio.h>

// exemplo: como usar union e structs
typedef union documentos{
    char CPF[11]; // formato 000.000.000-00
    char RG[11]; // apenas numeros inteiros 00111000111
}Documentos;

typedef struct pessoa{
    char nome[20]; // para guardar o nome completo da pessoa
    Documentos documento; // para guardar o CPF ou RG
}Pessoa;

void preenche_pessoa(Pessoa * pessoa){
    // função para preencher struct pessoa
    int opcao_documento;
    printf("informe o nome:\t");
    scanf(" %[^\n]", pessoa->nome);
    printf("informe o 1- CPF ou 2- RG:\t");
    scanf("%d", &opcao_documento);
    switch (opcao_documento){
    case 1:
        scanf(" %[^\n]", pessoa->documento.CPF);
        break;
    case 2:
        scanf(" %[^\n]", &pessoa->documento.RG);
        break;
    default:
        printf("valor invalido!!\n");
        break;
    }
}

void imprime_pessoa(Pessoa *pessoa){
    // funçaõ para imprimir Pessoa
    printf("Nome: %s\nDocumento:%s\n", pessoa->nome, pessoa->documento.CPF);
}

int main(void){
    Pessoa pessoa;
    preenche_pessoa(&pessoa);
    imprime_pessoa(&pessoa);
    return 0;
}
