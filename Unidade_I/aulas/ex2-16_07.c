#include <stdio.h>
#include<math.h>
struct ponto{
    float x, y;
};
typedef struct ponto Ponto;
struct circulo{
    Ponto p; //centro do circulo
    float r; //raio do circulo
};
typedef struct circulo Circulo;
float distancia (Ponto* p, Ponto* q){
    float d = sqrt(pow(q->x - p->x, 2));
    return d;
}



int interior (Circulo* c, Ponto* p){
    float d = distancia(&c->p, p);
    return (d < c-> r);
}

int main(){
    Ponto p;
    Ponto q;
    Circulo c;
    printf("informe o ponto x do centro do circulo: ");
    scanf("%f", &c.p.x);
    printf("informe o ponto y do centro do circulo: ");
    scanf("%f", &c.p.y);
    printf("informe o raio do circulo: ");
    scanf("%f", &c.r);
    printf("informe o ponto x a ser testado: ");
    scanf("%f", &p.x);
    printf("informe o ponto y a ser testado: ");
    scanf("%f", &p.y);
    if (interior(&c, &p)){
        printf("o ponto esta dentro do circulo.\n");
    }
    else{
        printf("o ponto esta fora do circulo.\n");
    }
    return 0;
}