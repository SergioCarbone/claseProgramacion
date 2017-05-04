#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <strings.h>
#include "validaciones.h"
#include "estructuras.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"

/**
 * \brief Ordena un array de datos por criterio
 * \param cantidad de subindices/datos
 * \return -
 *
*/
void ordenarPorNombreYApellido(EPersona listaAfiliados[], int cantidad)
{
    int i,j,k;
    int flag;
    comprimirArrayPersonas(listaAfiliados,cantidad,1);
    EPersona auxiliarPersona;
    for(i=0; i<cantidad; i++)
    {
        if(listaAfiliados[i].isEmpty==1)
        {
            break;
        }
        flag=0;
        auxiliarPersona = listaAfiliados[i];
        for(j=i; j > 0 && stricmp(auxiliarPersona.nombre,listaAfiliados[j-1].nombre)<=0 ; j--)
        {
            if(stricmp(auxiliarPersona.nombre,listaAfiliados[j-1].nombre)<0)
            {
                flag=1;
                continue;
            }
            else if((stricmp(auxiliarPersona.nombre,listaAfiliados[j-1].nombre))==0)
            {
                if(stricmp(auxiliarPersona.apellido,listaAfiliados[j-1].apellido)>0)
                {
                    flag=1;
                }
                else if((stricmp(auxiliarPersona.apellido,listaAfiliados[j-1].apellido)<0))
                {
                    break;
                }
            }


        }
        if(flag==1)
        {
            for(k=i; k>j; k--)
            {
                listaAfiliados[k]=listaAfiliados[k-1];
            }
            listaAfiliados[j]=auxiliarPersona;
        }

    }
}

/**
 * \brief Comprime un array de estructuras de tipo EPersona para diversos usos.
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 * \param valor que indica el lugar en el índice donde se encuentra el lugar vacío.
 */
void comprimirArrayPersonas (EPersona arrayPersonas[],int cantidad, int banderaLibre)
{
    int i;
    for (i=0 ; i<cantidad; i++)
    {
        if(arrayPersonas[i].isEmpty==banderaLibre)
        {
            for(; i<cantidad-1; i++)
            {
                arrayPersonas[i]=arrayPersonas[i+1];
            }
            arrayPersonas[cantidad-1].isEmpty=banderaLibre;
        }
    }
}
/**
 * \brief Ordena un array de datos y lo comprime
 * \param array de datos
 * \param cantidad de posiciones que tiene el array.
 */
void ordenarPorNombreYComprimir (EPersona arrayPersona[], int cantidad)
{
    /**Esta funcion primero comprime eel array y luego valida los espacios vacios**/
    comprimirArrayPersonas(arrayPersona,cantidad,0);
    int i,j;
    EPersona auxiliarPersona;
    for(i=0; i<cantidad; i++)
    {
        if(arrayPersona[i].isEmpty==1)
        {
            continue;
        }
        auxiliarPersona = arrayPersona[i];
        j=i;
        for( ; j>0 && stricmp(auxiliarPersona.nombre,arrayPersona[j-1].nombre)<0 ; j--)
        {
            if(arrayPersona[j].isEmpty==1)
            {
                continue;
            }
            arrayPersona[j]=arrayPersona[j-1];
        }
        arrayPersona[j]=auxiliarPersona;
    }
}

/**
 * \brief imprime grafico utilizando cantidad de personas por edad
 * \param estructura y cantidad de personas
 * \return -
 *
*/
void graficoEdad(EPersona listaAfiliados[],int cantidad)
{
    int contMenos18=0;
    int contEntre18y35=0;
    int contMas35=0;
    int i;
    int edad;

    for(i=0; i<cantidad; i++)
    {
        if(listaAfiliados[i].isEmpty==0)
        {


            edad=atoi(listaAfiliados[i].edad);
            if(edad<=18)
            {
                contMenos18++;
            }
            else if(edad>18 && edad<35)
            {
                contEntre18y35++;
            }
            else
            {
                contMas35++;
            }
        }
    }
    for(i=cantidad; i>0; i--)
    {
        if(!(contEntre18y35<i&&contMas35<i &&contMenos18<i))
        {
            if(i==contMenos18)
            {
                printf("\n*\t");
            }
            else
            {
                printf("\n \t");
            }

            if(i==contEntre18y35)
            {
                printf("*\t");
                contEntre18y35--;
            }
            else
            {
                printf("\t");
            }
            if(i==contMas35)
            {
                printf("*\n");
                contMas35--;
            }
            else
                printf("\n");

        }

    }
    printf("\n<18\t19-35\t>35\n");
}
