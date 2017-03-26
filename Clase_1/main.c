#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;
    int pos = 0;
    int neg = 0;
    char respuesta;


    do{
        printf("Ingrese un numero: ");
        scanf("%f", &num);

        if( num >= 0 ){
            pos++;
        }
        else {
            neg++;
        }

        printf("Desea continuar?: s/n");
        scanf(" %c", &respuesta);


    } while(respuesta == 's' || respuesta == 'S' );

        printf("La cantidad de numeros positivos es: %d y negativos es: %d" , pos, neg);

    return 0;
}
