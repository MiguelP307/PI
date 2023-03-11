#include <stdio.h>

float multInt1(int,float);
float multInt2(int,float);

int main(){

    int n;
    float m;

    printf("Insira o numero de vezes que pretende repetir e em seguida o numero desejado: \n");
    scanf("%d %f",&n,&m);

    printf("Resultado final de multInt1: %.2f\n\n",multInt1(n,m));
    printf("Resultado final de multInt2: %.2f\n",multInt2(n,m));

    return 0;
}


float multInt1(int n, float m){

    float result = 0;
    int counter = 0;

    while(n>0){
        result += m;
        n--;
        counter++;
    }
    printf("Realizados %d interacoes entre floats\n", counter);
    return result;
}

float multInt2(int n, float m){

    float result = 0;
    int counter = 0;

    while(n >= 1){

        if(n % 2 != 0)
            result += m;

        counter++;
        m *= 2;
        n /= 2;
    }

    printf("Realizados %d interacoes entr float\n", counter);
    return result;
}