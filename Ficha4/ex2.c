#include <stdio.h>

void printArray(int[], int);

int ordenado(int[],int);
void merge(int[],int,int[],int,int[]);
int partition(int[],int,int);

int main(){

    int arrDesordenado[] = {1,2,3,5,4};
    int arrOrdenado[] = {1,2,3,4,5};

    int len = 5 + 5;
    int arrMerge[len];

    printf("ar1: %d\nar2: %d\n",ordenado(arrDesordenado,5),ordenado(arrOrdenado,5));

    merge(arrDesordenado,5,arrOrdenado,5,arrMerge);
    printf("Array merged: ");
    printArray(arrMerge,len);
    
    printf("\nForam encontrados %d numeros menores ou iguais a %d no array: ",partition(arrMerge,len,2), 2);
    printArray(arrMerge,len);

    printf("\n");
    return 0;
}

void printArray(int array[], int len){

    int index = 0;

    while(index < len){
        printf("%d ",array[index]);
        index++;
    }
}

int ordenado(int v[], int N){

    while(N > 1){
        N--;
        if(v[N] < v[N-1])
            return 0;
    }

    return 1;
}


void merge(int a[], int aN, int b[], int bN, int r[]){

    int lenTotal = aN + bN;
    int index;
    int offset;

    for(index = 0, offset = aN ; offset < lenTotal; index++, offset++){
        r[index + aN] = b[index];
        r[index] = a[index];
    }

}

int partition(int v[], int N, int x){

    int swapAux;
    int backIndex = N - 1;
    int index = 0;

    while(index <= backIndex){

        if(v[index] > x){
            swapAux = v[index];
            v[index] = v[backIndex];
            v[backIndex] = swapAux;
            backIndex--;
        }
        else
            index++;
    }

    return index;
}