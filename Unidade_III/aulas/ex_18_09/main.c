#include<stdio.h>
#include"fruta.c"

int main (void){
    No * lista_de_frutas = NULL;
    int opcao;
    char nome_da_fruta[50];
    float valor_por_kg;
    // criar menu
    do{
        printf("1. cadastrar fruta\n");
        printf("2. exibir lista de frutas\n");
        printf("3. sair\n");
        printf("opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("digite o nome da fruta: ");
                scanf(" %[^\n]", nome_da_fruta);
                printf("digite o valor em (kg): ");
                scanf("%f", &valor_por_kg);
                lista_de_frutas = inserirNoInicio(lista_de_frutas, nome_da_fruta, valor_por_kg);
                break;
            case 2:
                exibirListaDeFrutas(lista_de_frutas);
                break;
            default:
                printf("opcao invalida!\n");
                break;
        }
    }
    while(opcao != 3);
    return 0;
}