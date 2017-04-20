#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define CANTIDAD 3
#define ATENDIDO 1

typedef struct
{
    int DNI[8];
    int turno;

} urgente;

typedef struct
{
    int DNI[8];
    int turno;
} regular;

int BuscarPosicion(vec[],int cantidad, int valor);

int main()
{
    urgente vecUrgente[CANTIDAD];
    regular vecRegular[CANTIDAD];
    int DNIAux[8];
    int opcion;
    int TurnoUrgente = 0;
    int TurnoRegular = 0;
    int turnoLibre, resultadoBusqueda;

    do
    {
        opcion = getInt("\n1-Tramite urgente\n2-Tramite regular\n3-Proximo cliente\n4-Listar\n5-Informar\nIngrese una opcion: ");

        switch(opcion)
        {
        case 1:
            turnoLibre = BuscarPosicion(vecUrgente,CANTIDAD,0);
            if(!Numerico("Ingrese su numero de DNI: ",DNIAux))
            {
                printf("Solo debe igresar numeros!!");
                break;
            }
            vecUrgente[turnoLibre].DNI = DNIAux;
            vecUrgente[turnoLibre].turno = TurnoUrgente;
            TurnoUrgente++;
            break;
        case 2:
            turnoLibre = BuscarPosicion(vecRegular,CANTIDAD,0);
            if(!Numerico("Ingrese su numero de DNI: ",DNIAux))
            {
                printf("Solo debe igresar numeros!!");
                break;
            }
            vecRegular[turnoLibre].DNI = DNIAux;
            vecRegular[turnoLibre].turno = TurnoUrgente;
            TurnoUrgente++;
            break;
        case 3:

            break;
        case 4:
            break;
        case 5:
            break;
        }


    }



    return 0;
}


int BuscarPosicion(vec[],int cantidad, int valor)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(vec[i].turno == valor)
        {
            return i;
        }
    }
    return 0;
}

