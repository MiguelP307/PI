#include <stdio.h>
#include <stdlib.h>
// Buffer tipo abstrato de dado para armazenar items (acrescentar ou retirar um elemento)

// We'll use Stack and Queues

#define MAX 2048

typedef struct staticStack{
    int sp;
    int values[MAX];

} STACK, *SStack;
 
void SinitStack(SStack);
int SisEmpty(SStack);
int Spush(SStack,int);
int Spop(SStack, int*);
int Stop(SStack, int*);

int main(){

    SStack stack = malloc(sizeof(struct staticStack));
    int value;

    SinitStack(stack);
    printf("isEmpty result: %d\n", SisEmpty(stack));

    Spush(stack,1);
    Spush(stack,2);
    Spush(stack,3);
    Spush(stack,4);
    Spush(stack,5);

    printf("O valor do stackPointer no momento e %d\n", stack->sp);

    Spop(stack,&value);

    printf("Poped value %d\n", value);

    Stop(stack,&value);

    printf("O valor do top da stack e %d\n", value);

    return 0;
}

void SinitStack(SStack s){
    s->sp = -1;
}

int SisEmpty(SStack s){
    
    if(s->sp == -1)
        return 1;

    return 0;
}

int Spush(SStack s, int x){

    if(s->sp < MAX - 1){
        s->sp++;
        s->values[s->sp] = x;
        return 0;
    }

    return 1;
}

int Spop(SStack s, int* x){

    if(s->sp > -1){
        *x = s->values[s->sp];
        s->sp--;
        return 0;
    }

    return 1;
}


int Stop(SStack s, int* x){

    if(s->sp > -1){
        *x = s->values[s->sp];
        return 0;
    }

    return 1;
}