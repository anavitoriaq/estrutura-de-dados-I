#include<stdio.h>
#include<stdlib.h>

/*
    entrada:
        - linhas e colunas (tamanho da matriz);
        -os elementos da matriz (uma matriz);
    saida:
        -imprimir/mostrar matriz original e transposta
    */






int main (void){
    int linhas, colunas, count;
    printf ("informe a quantidade de linhas e colunas da matriz: ");
    scanf ("%d %d", &linhas, &colunas);
//alocação dinâmica da matriz
    int ** matriz = (int **) malloc(linhas*sizeof(int*));
    if(matriz[count]==NULL){
        exit(1); // em caso de falha na alocação
    }
    for(int count=0; count<linhas; count++){
        matriz [count] = (int*) malloc(colunas*sizeof(int));
        if(matriz[count]==NULL){
            exit(1);
        }
    }
//ler elementos da matriz
    printf ("informe os elementos:\n ");
    int linha, coluna;
    for(int linha=0; linha<linhas; linha++){
        for(int coluna=0; coluna<colunas; coluna++){
            scanf("%d", &matriz[linha][coluna]);
        }
    }
//imprimir matriz original
    printf ("\nmatriz original\n");
        for(int linha=0; linha<linhas; linha++){
            printf("\n");
        for(int coluna=0; coluna<colunas; coluna++){
            printf("%d\t", matriz[linha][coluna]);
        }
    }
//transposta
    printf ("matriz transposta:\n");
        for(int linha=0; linha<linhas; linha++){
        printf("\n");
        for(int coluna=0; coluna<colunas; coluna++){
            printf("%d\t", matriz[coluna][linha]);
        }
    }
//liberar matriz da memoria
for(int linha=0; linha<linhas; linha++){
  free(matriz[linha]);
}
free(matriz);
return 0;
}
