
typedef struct contaBancaria ContaBancaria;


/*função que aloca memoria para struct conta e retorna seu endereço Parms:
    char* titular: nome do titular da conta
    long int numero: numero da conta
    float saldo: saldo disponivel na conta
    */
ContaBancaria * cria_conta(char * titular, long int numero, float saldo);


/*função que simula a operação de deposita
Parms:
    ContaBancaria * conta: representa conta bancaria
    float dinheiro: saldo para ser adicionado na conta
 */
void deposita(ContaBancaria * conta, float dinheiro);


/*função que simula a operação de sacar valor de uma conta
Parms:
    ContaBancaria * conta: representa conta bancaria
    float valor: o valor que sera decrementado da conta
*/
void sacar(ContaBancaria * conta, float valor);

/*função para retornar o saldo*/
float saldo(ContaBancaria * conta);