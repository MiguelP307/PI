#include <stdio.h>

int bitsUm(unsigned int);
int trailingZ(unsigned int);
int gDig(unsigned int);

int main(){

    unsigned int bin = 20;
    unsigned int dec = 1405;

    printf("O numero %d em base decimal tem %d 1's\n", bin, bitsUm(bin));
    printf("O numero %d em base decimal tem %d 0's no final\n",bin,trailingZ(bin));
    printf("O numero %d precisa de %d digitos para ser escrito na base decimal\n",dec, gDig(dec));

    return 0;
}


// Conta o numeros de um presentes na representacao binaria de um determinado numero n
int bitsUm(unsigned int n){

    int numOfOnes = 0;

    while(n > 0){
        if(n % 2 == 1)
            numOfOnes++;
        n /= 2;
    }

    return numOfOnes;
}


// Conta o numero de zeros consecutivos no final da representacao binaria de um numero n
int trailingZ(unsigned int n){

    int numOfZeros = 0;
    int flag = 1;

    while(n > 0 && flag){
        if(n % 2 == 1)
            flag = 0;
        else
            numOfZeros++;

        n /= 2;
    }

    return numOfZeros;

}


// Retorna o numero de digitos necessarios para conseguir escrever um numero n em base decimal
int gDig(unsigned int n){

    int numDigits = 0;

    while(n > 0){
        numDigits++;
        n /= 10;
    }

    return numDigits;
}