#include <stdio.h>
#include <stdlib.h>

int contaVogais(char*);
int retiraVogaisRep(char*);

int main(){

    char str[] = "Ola meu amigo";
    char strRep[] = "Olaaa meeu amigooo";
    int numReps = retiraVogaisRep(strRep);

    printf("A string \"%s\" tem %d vogais!\n",str,contaVogais(str));
    printf("Foram retiradas %d repeticoes de vogais na string (sem repeticoes) : %s \n", numReps, strRep);

    return 0;
}

int serVogal(char c){

    if(c == 'a' || c == 'e'|| c == 'i'|| c == 'o'|| c == 'u' || c == 'A' || c == 'E'|| c == 'I'|| c == 'O'|| c == 'U')
        return 1;

    return 0;
}

size_t strLen(char* str){

    size_t len = 0;

    while(str[len] != '\0'){
        len++;
    }

    return len + 1;
}


int contaVogais(char* s){

    int numVogais = 0;
    int index = 0;

    while(s[index] != '\0'){

        if(serVogal(s[index]))
            numVogais++;
        index++;
    }

    return numVogais;
}

// To fix!!!!!!!!
int retiraVogaisRep(char* s){

    int numVogaisRemovidas = 0;
    size_t len = strLen(s);
    int indexNew, index;
    int tempindex; 

    for(indexNew = 0, index = 0; index < len - 1; index++, indexNew++){
        
        s[indexNew] = s[index];

        if(serVogal(s[index])){

            for(tempindex = index ; tempindex < len - 1 && (s[index] == s[index + 1]) ; tempindex++){
                index++;
                numVogaisRemovidas++;
            }
        }
        
    }
    s[indexNew] = '\0';

    return numVogaisRemovidas;
}