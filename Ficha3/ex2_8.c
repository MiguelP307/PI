#include <stdio.h>

void swapM(int*,int*);
void swap(int[],int,int);
int soma(int[],int);
void inverteArraySwapM(int[],int);
void inverteArraySwap(int[],int);
int maximus(int[],int,int*);
void quadrados(int[],int);
void pascal(int[],int);

int main(){

    int index = 0;
    int max = -1;
    int returned;
    int v[5] = {1,2,3,4,5};
    
    size_t len = 10;
    int q[len];


    swapM(&v[2],&v[1]);
    swap(v,1,2);

    inverteArraySwapM(v,5);
    inverteArraySwap(v,5);

    printf("Array: ");
    while(index < 5){
        
        printf("%d,",v[index]); 
        index++;
    }

    printf("\nSoma do array : %d\n",soma(v,5));
    returned = maximus(v,5,&max);
    printf("O numero maximo do array e %d com return de %d\n",max, returned);


    quadrados(q,len);
    pascal(q,len);
    printf("Array dos quadrados: ");
    index = 0;
    while(index < len){
        
        printf("%d ",q[index]); 
        index++;
    }
    printf("\n");

    return 0;
}

void swapM(int* x, int* y){

    int temp = *y;
    *y = *x;
    *x = temp;
}

void swap(int v[],int i,int j){

    int temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}

int soma(int v[], int N){

    int total = 0;

    while(N > 0){
        N--;
        total += v[N];
    }

    return total;
}

void inverteArraySwapM(int v[],int N){

    int fstIndex = 0;
    int lstIndex = N - 1;
    size_t middle = N / 2;


    while(fstIndex < middle){
        swapM(&v[fstIndex],&v[lstIndex]);
        fstIndex++;
        lstIndex--;
    }

}

void inverteArraySwap(int v[],int N){

    int fstIndex = 0;
    int lstIndex = N - 1;
    size_t middle = N / 2;


    while(fstIndex < middle){
        swap(v,fstIndex,lstIndex);
        fstIndex++;
        lstIndex--;
    }

}

int maximus(int v[], int N, int* m){

    *m = v[0];
    int index = 1;

    if(N <= 0)
        return -1;

    while(index < N){

        if(v[index] > *m)
            *m = v[index];

        index++;
    }

    return 0;
}

void quadrados(int q[], int N){

    int index = 0;

    while(index < N){

        q[index] = index*index;

        index++;
    }

    return;
}



void pascal(int v[],int N){
    
    int index;
    int lastLen = N - 1;
    int temp[lastLen];

    if(N == 0)
        return;
        
    v[0] = 1;

    pascal(temp,lastLen);

    for(index = 1; index < lastLen; index++){

        v[index] = temp[index-1] + temp[index];

    }

    v[lastLen] = 1;

    for(index = 0; index < N; index++){
        printf("%d ",v[index]);
    }
    printf("\n");
}