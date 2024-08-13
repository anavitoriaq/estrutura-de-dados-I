#include<stdio.h> // para scanf e printf
#include<stdlib.h>
#include<string.h> // para usar strcpy
#include "contaBancaria.h"

struct contaBancaria{
    char titular[20];
    long int numero;
    float saldo;
};


ContaBancaria * cria_conta(char * titular, long int numero, float saldo){
    ContaBancaria * conta = (ContaBancaria*) malloc(sizeof(ContaBancaria));
    if(conta==NULL){
        printf("no memory!\n");
        exit(1);
    }
    else{
        printf("conta alocada!\n");
    }
    //inicializar conta
    conta->numero=numero;
    conta->saldo= saldo;
    strcpy(conta->titular, titular); // copia a string titular para conta-:titular
    return conta;
}

void deposita(ContaBancaria * conta, float dinheiro){
    conta->saldo = conta->saldo + dinheiro;
    printf("valor depositado com sucesso.\n novo saldo: %f\n", conta->saldo);
}

void sacar(ContaBancaria * conta, float valor){
    if(conta->saldo>=valor){
        conta->saldo= conta->saldo - valor;
        printf("valor sacado com sucesso!\n");
    }
    else{
        printf("o saldo e insuficiente.\n");
    }
}

float saldo(ContaBancaria * conta){
    printf("saldo retornado: %f", conta->saldo);
    return conta->saldo;
}

