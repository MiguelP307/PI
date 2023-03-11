#include <stdio.h>

int fib1(int);
int fib2(int);

int main(){

    int n;

    printf("Insira o numero: ");
    scanf("%d",&n);

    printf("O n-esimo numero da sequencia de fibonacci e %d\n",fib1(n));
    printf("O n-esimo numero da sequencia de fibonacci e %d\n",fib2(n));

    return 0;
}

int fib1(int n){

    int result;

    if(n < 2)
        result = 1;
    else
        result = fib1(n-1) + fib1(n-2);

    return result;
}

int fib2(int n){

    int n1 = fib1(n-1);
    int n2 = fib1(n-2);

    return n1 + n2;
}