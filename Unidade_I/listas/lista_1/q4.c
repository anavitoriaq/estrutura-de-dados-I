#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro){
    *perimetro = 6 * l;
    *area = (3 *(pow(l, 2) * sqrt(3)))/2;
}

int main(void){
    float area, perimetro, lado;
    printf("Digite o lado do hexagono para ser calculado area e perimetro: ");
    scanf("%f", &lado);
    calcula_hexagono(lado, &area, &perimetro); 
    printf("O perimetro do hexano de lado %2.f e: %2.f \n", lado, perimetro);
    printf("A sua area e: %2.f", area);
    return 0;
}