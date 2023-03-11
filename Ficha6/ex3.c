#include <stdio.h>
#include <stdlib.h>

typedef struct dinStack{
    int sp;
    int size; // Guarda o tamanho do array de values
    int *values;
}*DStack;

typedef struct dinQueue{
    int size; // guarda o size do array de valores para a queue
    int front;
    int length;
    int *values;
}*DQueue;

void SinitQueue(DQueue);
int SisEmptyQ(DQueue);
int Senqueue(DQueue,int);
int Sdequeue(DQueue,int*);
int Sfront(DQueue,int*);


int main(){



    //QUEUE RELATED

    DQueue queue;

    SinitQueue(queue);
    int value;

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

    free(queue->values);
    free(queue);
    return 0;
}


// Init Queue
void SinitQueue(DQueue q){
    q->length = -1;
    q->front = 0;
    q->size = 2048;
    q->values = malloc(sizeof(int)*q->size);
}

int SisEmptyQ(DQueue q){
    if(q->length == -1)
        return 1;
    return 0;
}

int Senqueue(DQueue q, int x){
    if(q->length < q->size){
        q->length++;
        q->values[q->length] = x;
        return 0;
    }
    else
        q->values = realloc(q->values,sizeof(int)*q->size*2);
    return 1;
}

int Sdequeue(DQueue q, int* x){
    if(q->front <= q->length){
        *x = q->values[q->front];
        q->front++;
        return 0;
    }
    else
        SinitQueue(q); // Caso o front passe o length, quer dizer q esta vazia, ent podemos voltar ao status inicial
    
    return 1;
}

int Sfront(DQueue q, int* x){
    if(q->front <= q->length){
        *x = q->values[q->front];
        return 0;
    }
    return 1;
}
