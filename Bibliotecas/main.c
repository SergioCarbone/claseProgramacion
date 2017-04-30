#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "carga_edicion.h"
#include "validaciones.h"

#define MAX 20

int main()
{
    char seguir='s';
    int opcion;

    do
    {

        printf("\n\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        opcion = getInt("Ingrese una opcion: ");
        if(opcion <1 || opcion >5)
        {
            printf("Ingrese una opcion del menu!!\n\n");
        }

        switch(opcion)
        {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;

        case '5':
            seguir = 'n';
            break;
        }
    }while(seguir=='s');
    return 0;
}
