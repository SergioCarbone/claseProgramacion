#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Funciones/funciones.h"

#define MAX 5
typedef struct
{
    char Nombre[20];
    char Apellido[20];
    int Legajo;
} agenda;


void IniciarVector (agenda VectorAgenda[],int cantidad,int valor);
int BuscarPosicion(agenda VectorAgenda[],int cantidad, int valor);
void OrdenarVector (agenda VectorAgenda[],int cantidad);

int main()
{
    agenda VectorAgenda[MAX];
    char NombreAux[20];
    char ApellidoAux[20];
    char LegajoAux[20];
    int LegajoInt;
    int opcion,lugarLibre, resultadoBusqueda,i;



    IniciarVector(VectorAgenda,MAX,-1);
    do
    {
        IniciarVector(VectorAgenda,MAX,-1);
        opcion = getInt("\n1-Cargar Persona\n2-Borrar\n3-Modificar\n4-Mostrar\n5-Ordenar\n6-Salir\n\nOpcion: ");

        switch(opcion)
        {
        case 1:
            lugarLibre = BuscarPosicion(VectorAgenda,MAX,-1 );
            if(lugarLibre==-1)
            {
                printf("\nNo quedan lugares libres!\n");
                break;
            }
            if(!getStringLetras("Ingrese el Nombre: ",NombreAux))
            {
                printf("\nDebe ingresar solo letras!\n");
                break;
            }

            if(!getStringLetras("Ingrese el Apellido: ",ApellidoAux))
            {
                printf("\nDebe ingresar solo letras!\n");
                break;
            }

            if(!getStringNumeros("Ingrese el numero de legajo: ",LegajoAux))
            {
                printf("\nDebe ser solo numeros!\n");
                break;
            }
            LegajoInt = atoi(LegajoAux);
            if(BuscarPosicion(VectorAgenda,MAX,LegajoInt)!= -1)
            {
                printf("\nEl legajo ya existe!\n");
                break;
            }
            strcpy(VectorAgenda[lugarLibre].Nombre,NombreAux);
            strcpy(VectorAgenda[lugarLibre].Apellido,ApellidoAux);
            VectorAgenda[lugarLibre].Legajo = LegajoInt ;
            break;
        case 2:
            if(!getStringNumeros("\nIngrese el N\247 de legajo: ",LegajoAux))
            {
                printf("\nIngrese solo numeros!\n");
                break;
            }
            resultadoBusqueda = BuscarPosicion(VectorAgenda,MAX,atoi(LegajoAux));
            if(resultadoBusqueda==-1)
            {
                printf("\nEl legajo no existe!\n");
                break;
            }
            VectorAgenda[resultadoBusqueda].Legajo = -1;
            break;
        case 3:
            if(!getStringNumeros("Ingrese el N\247 de legajo: ",LegajoAux))
            {
                printf("\nIngrese solo numeros!\n");
                break;
            }
            resultadoBusqueda = BuscarPosicion(VectorAgenda,MAX,atoi(LegajoAux));
            if(resultadoBusqueda==-1)
            {
                printf("\nEl legajo no existe!\n");
                break;
            }

            if(!getStringLetras("\nIngrese el nuevo Nombre: ",NombreAux))
            {
                printf("\nSolo se aceptan letras!\n");
                break;
            }
            if(!getStringLetras("\nIngrese el nuevo Apellido: ",ApellidoAux))
            {
                printf("\nSolo se aceptan letras!\n");
                break;
            }

            strcpy(VectorAgenda[resultadoBusqueda].Nombre,NombreAux);
            strcpy(VectorAgenda[resultadoBusqueda].Apellido,ApellidoAux);
            break;

        case 4:
            printf("\nLegajo\tNombre\tApellido\n");
            for(i=0;i<MAX;i++)
            {
                if(VectorAgenda[i].Legajo != -1)
                {
                    printf("%d\t%s\t%s\n", VectorAgenda[i].Legajo,VectorAgenda[i].Nombre,VectorAgenda[i].Apellido);
                }
            }
            break;

        case 5:
               OrdenarVector(VectorAgenda, MAX);
            break;
        case 6:
            break;
        }


    }while(opcion !=6);
    return 0;
}

void IniciarVector (agenda VectorAgenda[],int cantidad,int valor)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        VectorAgenda[i].Legajo = valor;
    }
}

int BuscarPosicion(agenda VectorAgenda[],int cantidad, int valor)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(VectorAgenda[i].Legajo == valor)
        {
            return i;
        }
    }
    return -1;
}

void OrdenarVector (agenda VectorAgenda[],int cantidad)
{
    int i;
    agenda AuxAgenda;
    for(i=0;i<cantidad;i++)
    {
        if(VectorAgenda[i].Legajo != -1)
        {
            if(strcmp(VectorAgenda[i].Apellido,VectorAgenda[i+1].Apellido)>0)
            {
                AuxAgenda=VectorAgenda[i];
                VectorAgenda[i]=VectorAgenda[i+1];
                VectorAgenda[i+1]=AuxAgenda;
            }
        }
    }
}
