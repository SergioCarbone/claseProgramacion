#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "llamada.h"
#include "validar.h"
#define CANTIDAD 5
int main()
{
    sPersona persona[CANTIDAD];
    sLlamada llamada[CANTIDAD];

    persona_initArray(persona,CANTIDAD);
    llamada_initArray(llamada,CANTIDAD);

    char opcion[10];
    int salir = 1;
    do
    {
        val_getUnsignedInt(opcion,"\n\n1- Alta del asociado.\n2- Modificar datos del asociado.\n3- Baja del asociado.\n4- Nueva llamada.\n5- Asignar ambulancia.\n6- Informar.\n7- Salir.\n\nIngrese una opcion: ","\nIngrese una opcion valida.\n",3,10);

        switch(atoi(opcion))
        {
        case 1:
            persona_cargarPersona(persona,persona_buscarProximoId(persona,CANTIDAD),CANTIDAD);
            break;
        case 2:
            persona_modificarPersona(persona,CANTIDAD);
            break;
        case 3:
            persona_darDeBajaPersona(persona,CANTIDAD);
            break;
        case 4:
            llamada_nuevaLlamada(llamada,persona,CANTIDAD,CANTIDAD,"\n\nIngrese un motivo de las opciones:","\n\nEl id posee una llamada pendiente");
            break;
        case 5:
            llamada_finLlamada(llamada,CANTIDAD,"\n\nEl id no posee llamadas pendientes");
            break;
        case 6:
            llamada_printPersona(persona,llamada,CANTIDAD,CANTIDAD);
            break;
        case 7:
            salir = 0;
            break;
        }
    }
    while(salir != 0);
    return 0;
}

