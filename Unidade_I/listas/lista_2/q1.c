#include<stdio.h>

int main(void){
    int N, count, count1;
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

    for(count = 0; count < N; count++){
        printf("informe o sexo (%d) [m/f]: ", count + 1);
        scanf(" %c", &sexo[count]);
        printf("gostou do produto? (%d)[s/n] ", count + 1);
        scanf(" %c", &opiniao[count]);
    }
    //iniciando o laço
    for(count1 = 0; count1 < N; count1++){
        // count para a quantidade e porcentagem de mulheres que gostaram
        if (sexo[count1] == 'f'){
            mulheres++;
            if (opiniao[count1] == 's'){
                porcentagemFem++;
            }
        
        }
        // count para a quantidade e porcentagem de homens que não gostaram
        if (sexo[count1] == 'm'){
            homens++;
            if (opiniao[count1] == 'n'){
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