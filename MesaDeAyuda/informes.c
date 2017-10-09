#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abonado.h"
#include "llamada.h"
#include "validar.h"
#include "informes.h"


int informes_buscarMayorCantLlamadas (sLlamada* arrayLlamada, sAbonado* arrayAbonado, int longitudAbonado, int longitudLlamada, char* mensajeError)
{
    int retorno = -1;
    int llamadasArray[longitudLlamada];
    int idLlamada[longitudLlamada];
    int posicionAbonado, posicionLlamada;
    int i, id, max = 0;

    for(i= 0; i<longitudLlamada; i++)
    {
        llamadasArray[i] = 0;
        idLlamada[i] = -1;
    }

    if((arrayLlamada != NULL && arrayAbonado!= NULL) && (longitudLlamada > 0 && longitudAbonado > 0))
    {
        for(posicionAbonado=0; posicionAbonado<longitudAbonado; posicionAbonado++)
        {
            if(arrayAbonado[posicionAbonado].estado == ABONADO_OCUPADO)
            {
                for(i=0; i<longitudLlamada; i++)
                {
                    if(idLlamada[i] == -1)
                    {
                        idLlamada[i] = arrayAbonado[posicionAbonado].id;
                        for(posicionLlamada=0; posicionLlamada<longitudLlamada; posicionLlamada++)
                        {
                            if((arrayLlamada[posicionLlamada].idAbonado == arrayAbonado[posicionAbonado].id) && ((arrayLlamada[posicionLlamada].estadoLlamada == ESTADO_NO_SOLUCIONADO) || (arrayLlamada[posicionLlamada].estadoLlamada == ESTADO_SOLUCIONADO)))
                            {
                                llamadasArray[i]++;
                            }
                        }
                        break;
                    }
                }
            }
        }
        for(i=0; i<longitudLlamada; i++)
        {
            if(llamadasArray[i] > max)
            {
                max = llamadasArray[i];
                id = idLlamada[i];
            }
        }
        retorno = id;
    }

    if(retorno == -1)
    {
        printf("%s", mensajeError);
    }
    return retorno;
}



void informes_imprimir (sLlamada* arrayLlamada, sAbonado* arrayAbonado, int longitudAbonado, int longitudLlamada)
{
    int idAux;

    idAux = informes_buscarMayorCantLlamadas(arrayLlamada,arrayAbonado,longitudAbonado,longitudLlamada,"No se registraron llamadas");

    if(idAux != -1)
        printf("El usuario con mas llamadas es: %s %s, id: %d", arrayAbonado[idAux].nombre, arrayAbonado[idAux].apellido, arrayAbonado[idAux].id);

}












