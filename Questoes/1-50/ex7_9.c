#include <stdio.h>

char* strcat(char[], char[]);
char* strcpy(char*, char[]);
int strcmp(char[], char[]);
char* strstr(char[],char[]);
void strrev(char[]);
void strnoV(char[]);
void truncW(char[],int);
char charMaisFreq(char[]);
int iguaisConsecutivos(char[]);

int main(){

    char s1[100] = "Hello ";
    char s2[] = "World!";
    char s3[200];
    char s4[] = "Hello World!";
    char s5[] = "Hello WOrld!";
    char s6[] = "Elaborar enbarcamento encantamento diamante escolaridade modularidade";

    printf("%s\n",strcat(s1,s2));
    strcpy(s3,s1);
    printf("%s\n",s3);

    printf("Valores de comparacoes entre duas strings %d : %d\n", strcmp(s1,s4), strcmp(s1,s5));
    printf("A substring e de %s e %s ser %s\n",s1, s2, strstr(s1,s2));

    printf("A versao invertida de %s", s1);
    strrev(s1);
    printf("e %s\n",s1);

    strnoV(s1);
    printf("%s\n",s1);

    truncW(s6, 6);
    printf("Depois de usar a funcao truncW a string fica %s \n", s6);

    return 0;
}

size_t strlen(char str[]){
    int len = 0;

    while(str[len] != '\0')
        len++;

    return len;
}

//Assumindo que s1 contem espaco alocado suficiente para guardar s2
char* strcat(char s1[], char s2[]){

    size_t sizeS1 = strlen(s1);
    int index;

    for(index = 0 ; s2[index] != '\0' ; index++, sizeS1++)
        s1[sizeS1] = s2[index];

    s1[sizeS1] = '\0';

    return s1;
}


// Assumindo que dest tem memoria suficiente alocada para receber source[]
char* strcpy(char* dest, char source[]){

    int index;

    for(index = 0 ; source[index] != '\0' ; index++)
        dest[index] = source[index];
    
    dest[index] = '\0';

    return dest;
}

// Return 0 if equal, return <0 if s1<s2, return >0 s2>s1
int strcmp(char s1[], char s2[]){

    int index = 0;

    while(s1[index] != '\0' && s2[index] != '\0'){

        if(s1[index] < s2[index]){
            return -1;
        }
        else if(s1[index] > s2[index]){
            return 1;
        }

        index++;
    }

    return 0;
}

char* strstr(char s1[], char s2[]){

    int index = 0;

    while(s1[index] != '\0'){

        if(!strcmp((s1+index),s2))
            return (s1+index);
        
        index++;
    }

    return NULL;
}


void strrev(char str[]){

    size_t leftIndex;
    size_t rightIndex;

    char charHolder;

    for(leftIndex = 0, rightIndex = strlen(str) - 1 ; leftIndex <= rightIndex ; leftIndex++, rightIndex--){

        charHolder = str[leftIndex];
        str[leftIndex] = str[rightIndex];
        str[rightIndex] = charHolder;

    }
}


int isVogal(char c){

    if(c == 'a' || c == 'e'|| c == 'i'|| c == 'o'|| c == 'u' || c == 'A' || c == 'E'|| c == 'I'|| c == 'O'|| c == 'U')
        return 1;

    return 0;
}


void strnoV(char str[]){

    size_t leftIndex;
    size_t rightIndex;

    for(leftIndex = 0, rightIndex = 0 ; str[rightIndex] != '\0' ; leftIndex++, rightIndex++){

        str[leftIndex] = str[rightIndex];

        if(isVogal(str[rightIndex + 1]))
            rightIndex++;
             
    }
    str[leftIndex] = '\0';

    return;

}


void truncW(char t[], int n){

    size_t leftIndex;
    size_t rightIndex;

    int numWrote;

    for(leftIndex = 0, rightIndex = 0, numWrote = 1; t[rightIndex] != '\0' ; leftIndex++, rightIndex++,numWrote++){
        
        t[leftIndex] = t[rightIndex];

        if(numWrote == n){

            while(t[rightIndex] != ' ' && t[rightIndex] != '\0'){
                rightIndex++;
            }
            rightIndex--;
            numWrote = -1;
        }
        
    }

    t[leftIndex] = '\0';

    return;
}


// TODO, pensar numa maneira efetiva de realizar esta funcao
char charMaisFreq(char s[]){



}


int iguaisConsecutivos(char s[]){

    int numOfChars = 0;
    size_t index;

    for(index = 0 ; s[index] != '\0' ; index++){

        if(s[index] == s[index + 1])
            numOfChars++;

    }


}