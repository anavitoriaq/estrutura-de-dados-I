/*Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um
novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o
produto (gostou/não gostou). Escreva um programa em C que:
a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados,
um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta
para a segunda pergunta.
b) determine a porcentagem de pessoas do sexo feminino que responderam que
gostaram do produto.
c) determine a porcentagem de pessoas do sexo masculino que responderam que não
gostaram do produto.*/

#include<stdio.h>

int main(void){
    int N, contador, contador1;
    // armazena a quantidade e porcentagem de mulheres que gostaram do produto
    int mulheres = 0;
    int porcentagemFem = 0;
    float porcentagemtotalFem = 0;

    // armazena a quantidade e porcentagem de homens que gostaram do produto
    int homens = 0;
    int porcentagemMasc = 0;
    float porcentagemtotalMasc = 0;

    // leitura da quantidade de pessoas que serão entrevistadas
    printf ("digite a quantidade de pessoas que serão entrevistadas: ");
    scanf("%d", &N);

    // criação das matrizes para receber as respostas
    char sexo[N];
    char opiniao[N];

    for(contador = 0; contador < N; contador++){
        printf("informe o sexo (%d) [m/f]: ", contador);
        scanf(" %c", &sexo[contador]);
        printf("gostou do produto? (%d)[s/n] ", contador);
        scanf(" %c", &opiniao[contador]);
    }
    //iniciando o laço
    for(contador1 = 0; contador1 < N; contador1++){
        // contador para a quantidade e porcentagem de mulheres que gostaram
        if (sexo[contador1] == 'f'){
            mulheres++;
            if (opiniao[contador1] == 's'){
                porcentagemFem++;
            }
        
        }
        // contador para a quantidade e porcentagem de homens que não gostaram
        if (sexo[contador1] == 'm'){
            homens++;
            if (opiniao[contador1] == 'n'){
                porcentagemMasc++;
            }
        }
    }
    // calculando a porcentagem feminina
    if (mulheres != 0){
        porcentagemtotalFem = (porcentagemFem * 100)/mulheres;
    }
    //calculando a porcentagem masculina
    if (homens != 0){
        porcentagemtotalMasc = (porcentagemMasc * 100)/homens;
    }
    //imprime as informações
    printf("-------informações sobre a pesquisa-------\n");
    printf(" %d pessoas foram entrevistadas, dentre elas:\n ", N);
    printf("%d sao mulheres e %d sao homens\n", mulheres, homens);
    printf("um total de %.2f por cento das mulheres gostaram do produto\n ", porcentagemtotalFem);
    printf("um total de %.2f por cento dos homens nao gostaram do produto\n ", porcentagemtotalMasc);
    return 0;
}