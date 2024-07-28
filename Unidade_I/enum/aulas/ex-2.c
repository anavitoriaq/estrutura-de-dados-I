#include<stdio.h>

typedef enum dias_semana{
    SEGUNDA=2,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO,
    DOMINGO
}DiaSemana;

int main(){
    DiaSemana dia;
    printf("informe o dia da semana: 2 - 8 \t");
    scanf("%d", &dia);
    switch (dia){
    case SEGUNDA:
        printf(" Segunda-feira\n");
        break;
    case TERCA:
        printf(" Terça-feira\n");
        break;
    case QUARTA:
        printf(" Quarta-feira\n");
        break;
    case QUINTA:
        printf(" Quinta-feira\n");
        break;
    case SEXTA:
        printf(" Sexta-feira\n");
        break;
    case SABADO:
        printf(" Sabado\n");
        break;
    case DOMINGO:
        printf(" Domingo\n");
    default:
        printf("Dia nao cadastrado!\n");
        break;
    }
    return 0;
}