#include <stdio.h>
#include <stdlib.h>

#define MAX 2048

// FIFO
typedef struct staticQueue
{
    int front;
    int length;
    int values[MAX];  
}QUEUE, *SQueue;

void SinitQueue(SQueue);
int SisEmptyQ(SQueue);
int Senqueue(SQueue,int);
int Sdequeue(SQueue,int*);
int Sfront(SQueue,int*);

int main(){

    SQueue queue = malloc(sizeof(struct staticQueue));
    int value;

    SinitQueue(queue);

    printf("isEmpty output: %d\n", SisEmptyQ(queue));
    
    Senqueue(queue,1);
    Senqueue(queue,6);
    Senqueue(queue,3);
    Senqueue(queue,9);
    Senqueue(queue,2);
    Senqueue(queue,4);
    Senqueue(queue,5);
    printf("Value do length %d e front %d\n", queue->length, queue->front);
    
    Sfront(queue,&value);
    printf("O valor do inicio da queue e %d\n", value);

    Sdequeue(queue,&value);
    Sdequeue(queue,&value);
    Sdequeue(queue,&value);
    printf("Valor do dequeue e %d\n", value);

    return 0;
}


// Init Queue
void SinitQueue(SQueue q){
    q->length = -1;
    q->front = 0;
}

int SisEmptyQ(SQueue q){
    if(q->length == -1)
        return 1;
    return 0;
}

int Senqueue(SQueue q, int x){
    if(q->length < MAX){
        q->length++;
        q->values[q->length] = x;
        return 0;
    }
    return 1;
}

int Sdequeue(SQueue q, int* x){
    if(q->front <= q->length){
        *x = q->values[q->front];
        q->front++;
        return 0;
    }
    else
        SinitQueue(q); // Caso o front passe o length, quer dizer q esta vazia, ent podemos voltar ao status inicial
    
    return 1;
}

int Sfront(SQueue q, int* x){
    if(q->front <= q->length){
        *x = q->values[q->front];
        return 0;
    }
    return 1;
}
