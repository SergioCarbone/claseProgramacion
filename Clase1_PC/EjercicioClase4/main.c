#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int numeroOculto;
    int numeroIngresado;
    char respuesta = 's';
    int jugar;


    do
    {
        jugar = 1;
        numeroOculto = getNumeroAleatorio(1,100,1);

        do
        {
            numeroIngresado = getInt("Ingrese un numero del 1 al 99: ");
            if (numeroIngresado < 0)
            {
                jugar = 0;
            }
            else if(numeroIngresado == numeroOculto)
            {
                printf("Ganaste!!\n");
                jugar = 0;
            }
            else if (numeroIngresado < numeroOculto)
            {
                printf("El numero que ingresaste es mas chico.\n");
            }
            else if (numeroIngresado > numeroOculto)
            {
                printf("El numero que ingresaste es mas grande.\n");
            }

        }while(jugar == 1);

        respuesta = getChar("Desea jugar de nuevo: s/n: ");

    }while(respuesta == 's');

    return 0;
}

