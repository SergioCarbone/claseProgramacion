#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funciones.h"
#define MAX 5

int main()
{
    char vector[MAX], respuesta;
    int x;

    do
    {
        printf("Ingrese algo: ");
        scanf("%s", vector);
        x = strlen(vector);

        if(x > 0 && x < 6)
        {
            if(Numerico(vector))
            {
                printf("Es un numero\n");
            }
            if (Alfanumerico(vector))
            {
                printf("Es alfanumerico\n");
            }
            if(Telefono(vector))
            {
                printf("Es un telefono\n");
            }
            if(Letras(vector))
            {
                printf("Son solo letras\n");
            }
        }
        else
        {
            printf("No se pueden ingresar mas de 5 caracteres ");
        }
        respuesta = getChar("\nDesea continuar?: ");
    }while(respuesta == 's');
    return 0;
}
