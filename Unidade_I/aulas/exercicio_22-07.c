/*criar uma struct para manipular dados de um aluno.
um aluno deve ter os campos:
nome, matricula, documentos.
os documentos devem ser representados por uma união (union). 
os documentos são CPF, RG, SUS, titulo eleitor, passaporte*.
o programa deve receber os dados de N alunos, preencher e imprimir.*/

#include <stdio.h>
#include <stdlib.h> //mudanças

int opcao_documento; //nao tava declarado na main, pq declarou no struct

typedef union documentos{
    int CPF, RG, SUS, titulo_eleitor, passaporte; //muda int p long int
}Documentos;

typedef struct alunos{
    char nome[20]; //matricula como char
    int matricula, opcao_documento;
    Documentos documentos;
}Alunos;

void preenche_aluno(Alunos *alunos){
    printf("digite o nome do aluno:\t");
    scanf(" %[^\n]", alunos->nome);
    printf("digite a matricula do aluno:\t");
    scanf("%d", &alunos->matricula);//nao precisa de &
    printf("escolha o documento e informe a opçao escolhida:\n1.CPF:\t\n2.RG:\t\n3.SUS:\t\n4.titulo de eleitor:\t\n5.passaporte:\t\n");
    scanf("%d", &alunos->opcao_documento);
    switch(alunos->opcao_documento){
    case 1:
        scanf(" %d", &alunos->documentos.CPF);
        break;
    case 2:
        scanf(" %d", &alunos->documentos.RG);
        break;
    case 3:
        scanf(" %d", &alunos->documentos.SUS);
        break;
    case 4:
        scanf(" %d", &alunos->documentos.titulo_eleitor);
        break;
    case 5:
        scanf(" %d", &alunos->documentos.passaporte);
        break;
    default:
        printf("opcao invalida!\n");
        break;
    }
}

void imprime_aluno(Alunos *alunos){
    switch(alunos->opcao_documento){
    case 1:
        printf("Nome:\t%s\n Matricula:\t%d\n CPF:\t%d\n", alunos->nome, alunos->matricula, alunos->documentos.CPF);
        break;
    case 2:
        printf("Nome:\t%s\n Matricula:\t%d\n RG:\t%d\n", alunos->nome, alunos->matricula, alunos->documentos.RG);
        break;
    case 3:
        printf("Nome:\t%s\n Matricula:\t%d\n SUS:\t%d\n", alunos->nome, alunos->matricula, alunos->documentos.SUS);
        break;
    case 4:
        printf("Nome:\t%s\n Matricula:\t%d\n Titulo eleitor :\t%d\n", alunos->nome, alunos->matricula, alunos->documentos.titulo_eleitor);
        break;
    case 5:
        printf("Nome:\t%s\n Matricula:\t%d\n Passaporte:\t%d\n", alunos->nome, alunos->matricula, alunos->documentos.passaporte);
        break;
    default:
        break;
    }
}

int main(void){
    /*Alunos *alunos = (Alunos *)malloc(sizeof(Alunos));
    int quant_alunos;
    printf("informe a quantidade de alunos:\n");
    scanf("%d", &quant_alunos);

*/


    int quant_alunos;

    printf("informe a quantidade de alunos:\n");
    scanf("%d", &quant_alunos);
    Alunos alunos[quant_alunos];
    for (int count = 0; count < quant_alunos; count++){
        printf("\nAluno %d:\n", count + 1);
        preenche_aluno( &alunos[count]);
    }
    printf("\n-----informaçoes dos alunos:-----\n");
    for(int count = 0; count < quant_alunos; count++){
        printf("\nAluno %d:\n", count + 1);
        imprime_aluno(&alunos[count]);
    }
    return 0;
}