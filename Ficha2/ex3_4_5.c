#include <stdio.h>

int mdc1(int,int);
int mdc2(int,int);
int mdc3(int,int);

int main(){

    int a, b;

    printf("Insira dois numeros para receber o mdc entre eles: \n");
    scanf("%d %d", &a, &b);

    printf("MDC entre o numero %d e o numero %d e %d\n\n",a,b,mdc1(a,b));
    printf("MDC entre o numero %d e o numero %d e %d\n\n",a,b,mdc2(a,b));
    printf("MDC entre o numero %d e o numero %d e %d\n",a,b,mdc3(a,b));

    return 0;
}

int mdc1(int a, int b){

    int lastDivider = 1;
    int divider = 1;
    int counter = 0;

    while(divider <= a && divider <= b){

        if((a % divider == 0) && (b % divider == 0))
            lastDivider = divider;
    
        divider++;
        counter++;
    }

    printf("MDC1 realizou %d iteracoes\n",counter);

    return lastDivider;
}

void max_and_min(int a, int b, int* max, int* min){

    if(a >= b){
        
        *max = a;
        *min = b;
    }
    else{

        *max = b; 
        *min = a;
    } 

}


int mdc2(int a, int b){

    int counter = 0;

    int max;
    int min;

    max_and_min(a,b,&max,&min);

    while(max > 0){
        
        if(max >= min)
            max -= min;
        else
            min = min - max;

        counter++;
    }


    printf("MDC2 realizou %d iteracoes\n",counter);

    return min;
}

int mdc3(int a, int b){

    int counter = 0;

    int max;
    int min;

    max_and_min(a,b,&max,&min);

    while(max > 0){
        
        if(max >= min)
            max %= min;
        else
            min = min % max;

        counter++;
    }


    printf("MDC3 realizou %d iteracoes\n",counter);

    return min;
}