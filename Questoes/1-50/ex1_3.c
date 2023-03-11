#include <stdio.h>

int main(){

    int currentValue;

    int highestValue = 0;
    int sndHighestValue = 0;
    int sumValues = 0;
    int numOfValues = -1;

    do{
        scanf("%d",&currentValue);

        if(currentValue > highestValue){
            sndHighestValue = highestValue;
            highestValue = currentValue;
        }

        sumValues += currentValue;
        numOfValues++;

    }   
    while(currentValue != 0);

    printf("O maior valor inserido foi %d e o segundo maior foi %d\n", highestValue, sndHighestValue);
    printf("Foram inseridos %d numeros e a sua media e de %d\n", numOfValues, sumValues/numOfValues);

    return 0;
}