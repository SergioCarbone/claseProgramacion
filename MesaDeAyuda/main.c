#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abonado.h"
#include "llamada.h"
#include "validar.h"
#include "informes.h"

#define CANTIDAD 5
int main()
{
    sAbonado abonado[CANTIDAD];
    sLlamada llamada[CANTIDAD];

    abonado_initArray(abonado,CANTIDAD);
    llamada_initArray(llamada,CANTIDAD);

    char opcion[10];
    int salir = 1;
    do
    {
        val_getUnsignedInt(opcion,"\n\n1- Alta del abonado.\n2- Modificar datos del abonado.\n3- Baja del abonado.\n4- Nueva llamada.\n5- Fin llamada.\n6- Informar.\n7- Salir.\n\nIngrese una opcion: ","\nIngrese una opcion valida.\n",3,10);

        switch(atoi(opcion))
        {
        case 1:
            abonado_cargarAbonado(abonado,CANTIDAD);
            break;
        case 2:
            abonado_modificarAbonado(abonado,CANTIDAD);
            break;
        case 3:
            abonado_darDeBajaAbonado(abonado,CANTIDAD);
            break;
        case 4:
            llamada_nuevaLlamada(llamada,abonado,CANTIDAD,CANTIDAD,"El abonado posee una llamada en curso");
            break;
        case 5:
            llamada_finLlamada(abonado,llamada,CANTIDAD,CANTIDAD,"El abonado no posee ninguna llamada en curso");
            break;
        case 6:
            informes_imprimir(llamada,abonado,CANTIDAD,CANTIDAD);
            break;
        case 7:
            salir = 0;
            break;
        }
    }
    while(salir != 0);
    return 0;
}

