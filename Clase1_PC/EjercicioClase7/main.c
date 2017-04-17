/*********** Objetivo:
*   Realizar una agenda para guardar los datos de hasta 200 personas
*   de las cuales se toman los siguientes datos:
*       Nombre
*       Apellido
*       legajo (NO SE PUEDE REPETIR)
*
*   a- Realizar un programa con un menú de opciones para hacer altas ,
*      bajas y modificaciones (ABM) de una agenda.
*   b- Mostrar un listado ordenado por Apellido
*
* Aspectos a destacar:
*   Manipulación y chequeo de cadena de caracteres
*   arrays paraleos
*   bajas logicas
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Funciones/funciones.h"
#define MAX 5
void IniciarVector(int array[], int cantidad, int valor);
int BuscarPosicion(int array[],int cantidad, int valor);


int main()
{
    char vecNombre[MAX][50];
    char vecApellido[MAX][50], opcion;
    int vecLegajo[MAX];

    char NombreAux[50], ApellidoAux[50];
    char LegajoAux[50];
    int legajoAuxiliar;
    int lugarLibre;
    int resultadoBusqueda;
    int i;

    IniciarVector(vecLegajo,MAX,-1);

    do
    {
        opcion = getInt("\n1-Dar de alta un nuevo empleado. \n2-Dar de baja un empleado. \n3-Modificar. \n4-Mostrar listado. \n5-Ordenar por Apellido. \n6-Salir.\n\nIngrese una opcion del menu: ");

        switch(opcion)
        {
        case 1:
            lugarLibre = BuscarPosicion(vecLegajo,MAX,-1);
            if(lugarLibre == -1)
            {
                printf("\nNo hay lugar libre\n");
                break;
            }

            if(!getStringNumeros("\nIngrese el numero de legajo: ", LegajoAux))
            {
                printf("Solo deben ser numeros!!");
                break;
            }

            legajoAuxiliar = atoi(LegajoAux);

            if(BuscarPosicion(vecLegajo,MAX,legajoAuxiliar)!= -1)
            {
                printf("\nEl legajo ya existe!\n");
                break;
            }

            if(!getStringLetras("Ingrese el Nombre: ", NombreAux))
            {
                printf("\nDebe ingresar solo letras!!\n");
                break;
            }

            if(!getStringLetras("Ingrese el Apellido: ", ApellidoAux))
            {
                printf("\nDebe ingresar solo letras!!\n");
                break;
            }
            strcpy(vecNombre[lugarLibre], NombreAux);
            strcpy(vecApellido[lugarLibre], ApellidoAux);
            vecLegajo[lugarLibre]=legajoAuxiliar;
            break;

        case 2:
            if(!getStringNumeros("Ingrese el N\247 de legajo: ",LegajoAux))
            {
                printf("\nSolo pueden ser numeros\n");
                break;
            }
            resultadoBusqueda = BuscarPosicion(vecLegajo,MAX,atoi(LegajoAux));
            if(resultadoBusqueda == -1)
            {
                printf("\nEl legajo no existe\n");
                break;
            }
            vecLegajo[resultadoBusqueda] = -1;
            break;

        case 3:
            if(!getStringNumeros("Ingrese N\247 de legajo: ",LegajoAux))
            {
                printf("\nSolo pueden ser numeros\n");
                break;
            }
            resultadoBusqueda = BuscarPosicion(vecLegajo,MAX,atoi(LegajoAux));
            if(resultadoBusqueda == -1)
            {
                printf("\nEl legajo no existe\n");
                break;
            }
            if(!getStringLetras("Ingrese el Nombre: ", NombreAux))
            {
                printf("\nDebe ingresar solo letras!!\n");
                break;
            }

            if(!getStringLetras("Ingrese el Apellido: ", ApellidoAux))
            {
                printf("\nDebe ingresar solo letras!!\n");
                break;
            }
            strcpy(vecNombre[resultadoBusqueda], NombreAux);
            strcpy(vecApellido[resultadoBusqueda], ApellidoAux);
            break;

        case 4:
            printf("\nLegajo\tNombre\tApellido\n");
            for(i=0; i<MAX; i++)
            {
                if(vecLegajo[i]!= -1)
                {
                    printf("%d\t%s\t%s\n",vecLegajo[i],vecNombre[i],vecApellido[i]);
                }
            }
            break;

        case 5:
            for(i=0;i<MAX;i++)
            {
                if(strcmp(vecApellido[i],vecApellido[i+1])>0)
                {
                    legajoAuxiliar = vecLegajo[i];
                    vecLegajo[i] = vecLegajo[i+1];
                    vecLegajo[i+1] = legajoAuxiliar;

                    strcpy(NombreAux,vecNombre[i]);
                    strcpy(vecNombre[i],vecNombre[i+1]);
                    strcpy(vecNombre[i+1],NombreAux);

                    strcpy(ApellidoAux,vecApellido[i]);
                    strcpy(vecApellido[i],vecApellido[i+1]);
                    strcpy(vecApellido[i+1],ApellidoAux);
                }
            }

            break;
        case 6:
            break;
        }

    }while(opcion !=6);
    return 0;
}



void IniciarVector(int array[], int cantidad, int valor)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        array[i] = valor;
    }
}
/***************
*
*
*
*/
int BuscarPosicion(int array[],int cantidad, int valor)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(array[i] == valor)
        {
            return i;
        }
    }
    return -1;
}


