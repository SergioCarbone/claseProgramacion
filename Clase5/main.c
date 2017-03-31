#include <stdio.h>
#include <stdlib.h>
#include "func.h"

#define MAX 100


int main(){
    int i=5;
//    char respuesta;
//    int buffer;

    int edad[MAX] = {22,11,33,55,66};
    int sizeEdad = 5;

    int edadOrdenada[MAX];

    for(i = 0 ; i < sizeEdad ; i++)
        printf("%d\n",edad[i]);

    nadiaSort(edad,sizeEdad,edadOrdenada);

    for(i = 0 ; i < sizeEdad ; i++)
        printf("\n%d",edadOrdenada[i]);




    /*for(i=0; i<MAX;i++){

        printf("\nIngrese la edad de la persona %d: ", i);
        scanf("%d", &edad[i]);

        printf("\n\nDesea seguir ingresando? [s/n]");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta!='s'&&respuesta!='S'){
            break;
        }

        system("cls");
    }*/

    printf("\nEl promedio de las edades ingresadas es %.2f", promedio(edad, i+1));

    return 0;
}
