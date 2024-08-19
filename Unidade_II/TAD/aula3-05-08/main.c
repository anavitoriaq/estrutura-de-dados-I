#include<stdio.h>
#include"contaBancaria.h"

int main (void){
    ContaBancaria * conta = cria_conta("Maria", 1000.00, 23455);
    deposita(conta, 2500.00);
    sacar(conta, 3000.00);
    float sal = saldo(conta);
    return 0;
}