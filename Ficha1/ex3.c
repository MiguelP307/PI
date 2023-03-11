#include <stdio.h>

void print_quadrado(int);
void print_tabuleiro_xadrez(int);
void print_triangulo_horizontal(int n);
void print_triangulo_vertical(int n);
void print_circulo(int);

int main(){

    int alinea;

    int arg;

    printf("Insira o numero de 1 a 4 para chamar a alinea desejada: ");
    scanf("%d",&alinea);

    printf("\n\nAlinea %d \n",alinea);

    switch(alinea){

        case 1:
            printf("Insira o tamanho do quadrado: ");
            scanf("%d",&arg);
            print_quadrado(arg);
            break;

        case 2:
            printf("Insira o tamanho do tabuleiro: ");
            scanf("%d",&arg);
            print_tabuleiro_xadrez(arg);
            break;
            
        case 3:
            printf("Insira a altura do triangulo: ");
            scanf("%d",&arg);
            printf("Triangulo Horizontal: \n");
            print_triangulo_horizontal(arg);
            printf("\n\nTriangulo Vertical: \n");
            print_triangulo_vertical(arg);
            break;

        case 4:
            printf("Insira o raio do circulo: ");
            scanf("%d",&arg);
            print_circulo(arg);
            break;


        default:
            printf("Numero de alinea invalido!");
            break;

    }

    return 0;
}


void print_quadrado(int n){

    int width;
    int length;

    for(width = n ; width > 0 ; width--){

        for(length = n; length > 0 ; length--)
            printf("#");
        
        printf("\n");
    }

    return;
}

void print_tabuleiro_xadrez(int n){

    int width;
    int length;

    int casas = 0;

    for(width = n ; width > 0 ; width--){

        for(length = n; length > 0 ; length--){

            if(casas)
                printf("_");
            else
                printf("#");
            
            casas = (!casas);
        }

        if(n % 2 == 0)
            casas = (!casas);
        
        printf("\n");
    }

    return;
}

void print_c(int numTimes, char c){
    
    int counter = 0;

    while(counter < numTimes){
        printf("%c",c);
        counter++;
    }
}

void print_triangulo_horizontal(int n){

    int empty = n - 1;
    int full = 1;
    int heigth;

    for(heigth = n ; heigth > 0 ;  heigth--){
        print_c(empty,' ');
        print_c(full,'#');
        printf("\n");

        empty--;
        full += 2;
    }

}


void print_triangulo_vertical(int n){
    
    int empty = n - 1;
    int full = 1;
    int base = (n * 2) - 1;

    int maxHeightFlag = 0;

    while(base > 0){
        
        print_c(full,'#');
        printf("\n");

        if(full == n)
            maxHeightFlag = 1;

        if(maxHeightFlag){
            empty++;
            full--;
        }
        else{
            empty--;
            full++;
        }
        base--;
    }

    return;
}

void print_circulo(int radius){

    // TO DO, or not, cuz its hard.

}


