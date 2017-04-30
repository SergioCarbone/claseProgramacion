#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "carga_edicion.h"
#include "validaciones.h"
#define USUARIOS 5

int main()
{
    EPersona listaUsuarios[USUARIOS];
    //---------------------------------------------------------------------
    strcpy(listaUsuarios[0].claveAcceso, "A1");
    strcpy(listaUsuarios[1].claveAcceso, "A2");
    strcpy(listaUsuarios[2].claveAcceso, "A3");

    strcpy(listaUsuarios[0].nombre, "Sergio");
    strcpy(listaUsuarios[1].nombre, "Pablo");
    strcpy(listaUsuarios[2].nombre, "Pablo");

    strcpy(listaUsuarios[0].nick, "zz");
    strcpy(listaUsuarios[1].nick, "gg");
    strcpy(listaUsuarios[2].nick, "aa");

    strcpy(listaUsuarios[0].email, "hola@hola");
    strcpy(listaUsuarios[0].email, "hola@hola");
    strcpy(listaUsuarios[0].email, "hola@hola");

    listaUsuarios[0].id = 10;
    listaUsuarios[1].id = 10;
    listaUsuarios[2].id = 10;

    listaUsuarios[0].isEmpty = 0;
    listaUsuarios[1].isEmpty = 0;
    listaUsuarios[2].isEmpty = 0;


    //-----------------------------------------------------------------------------------------------

    char seguir='s';
    int opcion;
    char auxiliar[20];


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
        case 1:
            getString("Ingrese el nick",auxiliar);
            buscarPorNick(listaUsuarios,auxiliar,USUARIOS);

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }while(seguir=='s');
    return 0;
}
