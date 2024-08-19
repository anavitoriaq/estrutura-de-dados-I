#include<stdio.h>
#include<stdlib.h>

typedef struct func{
    char nome[20];
    float salario;
    int id;
    char cargo[20];
}Funcionario;

void preenche(Funcionario *func){
    /*printf("======= preencha =======\n");
    scanf(" %[^\n]", func->nome);*/
    printf("Digite o nome do funcionario:\n");
    scanf(" %[^\n]", func->nome);
    printf("Informe o salario:\n");
    scanf("%f", &func->salario);
    printf("Informe o ID:\n");
    scanf("%d", &func->id);
    printf("Digite o cargo:\n");
    scanf(" %[^\n]", func->cargo);
}

void imprime(Funcionario *func, int qnt){
    for(int i = 0; i < qnt; i++){
        printf("================\n");
        printf("Funcionario %d\n", i + 1);
        printf("Nome: %s\n", func[i].nome);
        printf("Salario: %.2f\n", func[i].salario);
        printf("ID: %d\n", func[i].id);
        printf("Cargo: %s\n", func[i].cargo);
        printf("\n=====================\n");
    }
}

//alterar salario do funcionario
void alterar_salario(Funcionario *func, int novoSalario) {
    novoSalario-=1; 
    printf("Digite o novo salario: ");
    scanf("%f", &func[novoSalario].salario);
    printf("==================================\n");
    printf("Novo salario do %s: %.2f\n", func[novoSalario].cargo, func[novoSalario].salario);
}

//exibir maior salario
void maiorSalario(Funcionario *func, int qnt){
    int maiorSal = 0;
    for(int i = 1; i < qnt; i++){
        if(func[i].salario>func[maiorSal].salario){
            maiorSal = i;
        }
    }
    printf("\nO maior salario e de %.2f do funcionario com cargo %s\n", func[maiorSal].salario, func[maiorSal].cargo);
}

void menorSalario(Funcionario *func, int qnt){
    int menorSal = 0;
    for(int i = 1; i < qnt; i++){
        if(func[i].salario<func[menorSal].salario){
            menorSal = i;
        }
    }
    printf("\nO menor salario e de %.2f do funcionario com cargo %s\n", func[menorSal].salario, func[menorSal].cargo);
}


int main(void){
    int  qnt, i, novoSalario;
    printf("Digite a quantidade de funcionarios: \n");
    scanf("%d", &qnt);

    Funcionario *func = (Funcionario *) malloc(qnt * sizeof(Funcionario));
    if (func == NULL){
        printf("erro");
        exit(1);
    }
    printf("Informações dos funcionarios:\n");
    for (i = 0; i < qnt; i++){
        preenche(&func[i]);
    }
    
    imprime(func, qnt);

    printf("De quem deseja alterar o salario? :\n");
    scanf("%d", &novoSalario);
    alterar_salario(func, novoSalario);
    maiorSalario(func, qnt);
    menorSalario(func, qnt);
    imprime(func, qnt);
    //liberar a memoria
    free(func);
    return 0;
}