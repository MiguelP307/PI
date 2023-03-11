#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT[6];
    float teste;
} Aluno;

int nota(Aluno);
int procuraNum(int, Aluno[], int);
void ordenaPorNum(Aluno[],int);
void criaIndPorNum(Aluno[],int, int[]);
void imprimeTurma (int[], Aluno[], int);
void criaIndPorNome(Aluno[], int, int[]);

int comparaNomes(char*,char*);


void printAluno(Aluno aluno){

    int j;
    printf("Aluno %d: %s\n", aluno.numero, aluno.nome);
        printf("Mini testes: ");
        for (j = 0; j < 6; j++) {
            printf("%d ", aluno.miniT[j]);
        }
        printf("\n");
        printf("Teste: %.1f\n", aluno.teste);
        printf("Nota final: %d\n", nota(aluno));
        printf("\n");
}

void printAlunos(Aluno alunos[], int size) {

    int i;
    for (i = 0; i < size; i++)
        printAluno(alunos[i]);
}

int main(){


    Aluno a1 = {91971, "Rabanete Jordanio", {10, 14, 12, 9, 11, 10}, 12.1};
    Aluno alunos[13] = {
        {91974, "Cenoura Carlos", {11, 10, 12, 13, 14, 16}, 18.3},
        {91982, "Kiwi Kevin", {10, 12, 13, 14, 11, 15}, 16.7},
        {91973, "Alface Antonio", {12, 11, 10, 14, 15, 13}, 16.2},
        {91975, "Tomate Tiago", {15, 12, 11, 13, 16, 14}, 13.2},
        {91972, "Beterraba Joana", {9, 12, 13, 15, 14, 11}, 14.5},
        {91976, "Abacate Ana", {10, 13, 14, 12, 11, 9}, 19.1},
        {91971, "Rabanete Jordanio", {10, 14, 12, 9, 11, 10}, 12.1},
        {91981, "Morango Marina", {12, 13, 11, 9, 14, 12}, 14.6},
        {91983, "Banana Bruna", {11, 14, 12, 13, 9, 16}, 18.9},
        {91977, "Laranja Luiza", {12, 14, 13, 16, 11, 10}, 15.9},
        {91979, "Pera Paula", {13, 15, 11, 10, 12, 14}, 11.5},
        {91980, "Uva Umberto", {11, 10, 14, 16, 15, 13}, 12.7},
        {91978, "Maça Marcelo", {14, 11, 12, 13, 15, 16}, 17.8},
    };

    int indices[13];


    criaIndPorNome(alunos,13,indices);
    
    int i;
    for(i = 0; i < 13 ; i++)
        printf("%d ", indices[i]);

    printf("\n");
    
    criaIndPorNum(alunos,13,indices);

    for(i = 0; i < 13 ; i++)
        printf("%d ", indices[i]);

    printf("\n");
    imprimeTurma(indices,alunos,13);

    ordenaPorNum(alunos,13);
    //printAlunos(alunos,13);
    printf("Nota final do aluno %s foi %d\n", a1.nome, nota(a1));
    printf("Index do aluno %d e %d\n",91971,procuraNum(91971,alunos,13));

    return 0;
}

int nota(Aluno a){

    size_t index;
    float nota;
    int miniTMedia = 0;

    for(index = 0; index < 6; index++){
        miniTMedia += a.miniT[index];
    }

    nota = (miniTMedia / 6.0)* 0.2 + a.teste * 0.8;
    
    if(nota - (int)nota >= 0.45)
        nota++;

    return (int)nota;
}

// Using binary search
int procuraNum(int num, Aluno t[], int N){

    int lowerIndex = 0;
    int higherIndex = N - 1;
    int middleIndex;
    int currentNum;

    while(lowerIndex <= higherIndex){

        middleIndex = (lowerIndex + higherIndex) / 2;
        
        currentNum = t[middleIndex].numero;

        if(currentNum == num){
            return middleIndex;
        }

        if(num < currentNum)
            higherIndex = middleIndex - 1;
        else
            lowerIndex = middleIndex + 1;

    }

    return -1;
}


// MergeSort [Failed Try!]
/* // Functions for a mergeSort

// Function that merge two subarrays
// [leftIndex ... middleIndex]
// [middleIndex + 1 ... rightIndex]
void merge(Aluno turma[], int leftIndex, int middleIndex, int rightIndex){

    int initIndexLA, initIndexRA, initIndexMA;

    int leftArraySize = middleIndex - leftIndex + 1;
    int rightArraySize = rightIndex - middleIndex;
  
    //Temporary arrays
    Aluno leftArray[leftArraySize];
    Aluno rightArray[rightArraySize];

    //Copy data to temp
    for(initIndexLA = 0 ; initIndexLA < leftArraySize ; initIndexLA++)
        leftArray[initIndexLA] = turma[leftIndex + initIndexLA];

    for(initIndexRA = 0 ; initIndexRA < rightArraySize ; initIndexRA++)
        rightArray[initIndexRA] = turma[middleIndex + 1 + initIndexRA];

    //Merge data from temporary arrays back to the merge subarray
    initIndexMA = leftIndex; // First index from the merged subarray

    for(initIndexLA = 0, initIndexRA = 0 ; initIndexLA < leftArraySize && initIndexRA < rightArraySize ; initIndexMA++){

        // Sort data from the lowest to the highest
        if(leftArray[initIndexLA].numero <= rightArray[initIndexRA].numero){
            turma[initIndexMA] = leftArray[initIndexLA];
            initIndexLA++;
        }
        else{
            turma[initIndexMA] = rightArray[initIndexRA];
            initIndexRA++;
        }

    }


    //Copy the remaining data to the merged array
    //Since the last for stop when one of each reach the limit, we need to take the data from the other subarrays that didn't end the iteration

    while(initIndexLA < leftArraySize){
        turma[middleIndex] = leftArray[initIndexLA];
        initIndexLA++;
        middleIndex++;
    }

    while(initIndexRA < rightArraySize){
        turma[middleIndex] = rightArray[initIndexLA];
        initIndexRA++;
        middleIndex++;
    }
}



// Recursive function that divide the array in two subarrays
void mergeSort(Aluno turma[], int leftIndex, int rightIndex){

    if(leftIndex < rightIndex){

        // Get the middle index
        int middleIndex = (leftIndex + rightIndex) / 2;

        //Recursive call to the left array
        // [1, 2, 3, 4, 5, 6, 7]
        //  0  1  2  3  4  5  6
        //  L     M M+1       R

        // [1, 2, 3]
        mergeSort(turma,leftIndex,middleIndex);

        // [4, 5, 6, 7]
        mergeSort(turma,middleIndex + 1, rightIndex);

        merge(turma,leftIndex, middleIndex, rightIndex);
    }


} */

// Using InsertSort, keep a key, and insert on the right position
void ordenaPorNum(Aluno t[], int N){
    
    int i, j;
    Aluno alunoChave;

    for(i = 1; i < N; i++){
        alunoChave = t[i];
        j = i - 1;

        while(j >= 0 && t[j].numero > alunoChave.numero){
            t[j + 1] = t[j];
            j--;
        }
        t[j+1] = alunoChave;

    }

}

void criaIndPorNum(Aluno t[],int N, int ind[]){

    size_t index;
    Aluno copy[N];

    for(index = 0; index < N ; index++)
        copy[index] = t[index];

    ordenaPorNum(copy,N);

    for(index = 0; index < N ; index++)
        ind[index] = procuraNum(t[index].numero,copy,N);

    return;
}

void imprimeTurma (int ind[], Aluno t[], int N){

    int index;
    int currentIndex;

    for(currentIndex = 0; currentIndex < N ; currentIndex++){
        for(index = 0; index < N ; index++){
            if(ind[index] == currentIndex){
                printAluno(t[ind[index]]);
                index = N;
            }
        }
    }

}


// Nao entendi o proposito do exercicio 6

// Assumindo que no nome so constam char de a -> z e A -> Z e spaces
int comparaNomes(char* n1, char* n2){

    int indexN1;
    int indexN2;
    char asciiValueN1;
    char asciiValueN2;

    for(indexN1 = 0, indexN2 = 0 ; n1[indexN1] != '\0' && n2[indexN2] != '\0' ; indexN1++ , indexN2++){
        asciiValueN1 = n1[indexN1];
        asciiValueN2 = n2[indexN2];

        if(asciiValueN1 == 32){
            indexN1++;
        }
        else if(asciiValueN2 == 32){
            indexN2++;
        }
        else{

            //Lowcase
            if(asciiValueN1 < 97)
                asciiValueN1 += 32;

            if(asciiValueN2 < 97)
                asciiValueN2 += 32;

            if(asciiValueN1 < asciiValueN2)
                return -1;
            else if(asciiValueN1 > asciiValueN2)
                return 1;
        }
        return 0;
    }

    return 0;
}

void ordenaPorNome(Aluno t[], int N){

    int i, j;
    Aluno alunoChave;

    for(i = 1; i < N; i++){
        alunoChave = t[i];
        j = i - 1;
        
        while(j >= 0 && comparaNomes(t[j].nome,alunoChave.nome) >= 0){
            t[j + 1] = t[j];
            j--;
        }
        t[j+1] = alunoChave;
    }
}

int procuraNome(char* nome, Aluno t[], int N){

    /* int lowerIndex = 0;
    int higherIndex = N - 1;
    int middleIndex;
    char* currentNum;

    while(lowerIndex <= higherIndex){

        middleIndex = (lowerIndex + higherIndex) / 2;
        
        currentNum = t[middleIndex].nome;

        if(!comparaNomes(currentNum,nome)){
            return middleIndex;
        }

        if(comparaNomes(currentNum,nome) == 1)
            lowerIndex = middleIndex + 1;
        else
            higherIndex = middleIndex - 1;

    }

    return -1; */

    int index = 0;

    for( ; index < N ; index++)
        if(!strcmp(t[index].nome,nome))
            return index;

    
    return -1;
}

void criaIndPorNome(Aluno t[], int N, int ind[]){

    size_t index;
    Aluno copy[N];

    for(index = 0; index < N ; index++)
        copy[index] = t[index];

    ordenaPorNome(copy,N);

    // Ver compare de nomes para ver se sao iguais!!!
    for(index = 0; index < N ; index++)
        ind[index] = procuraNome(t[index].nome,copy,N);

    return;

}