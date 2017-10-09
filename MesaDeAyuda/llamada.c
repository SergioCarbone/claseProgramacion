#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abonado.h"
#include "llamada.h"
#include "validar.h"
#include "informes.h"

int llamada_initArray (sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayLlamada[i].estadoLlamada = ESTADO_SIN_USO;
            arrayLlamada[i].idAbonado = -1;
            arrayLlamada[i].motivo = -1;
            arrayLlamada[i].idLlamada = -1;
        }
        retorno = 0;
    }
    return retorno;
}

static int idLlamadaAutoincrementable = -1;

int llamada_generarProximoIndice (void)
{
    idLlamadaAutoincrementable++;
    return idLlamadaAutoincrementable;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int llamada_nuevaLlamada (sLlamada* arrayLlamada,sAbonado* arrayAbonado,int longitudAbonado, int longitudLlamada, char* mensajeError)
{
    int retorno = -1;
    int idAux, indice;
    char buffer[10];
    int flagMotivo = 0;
    int contadorIntentos = 0;
    int indiceAbonado;
    int i;

    if((arrayLlamada != NULL && arrayAbonado!= NULL) && (longitudLlamada >= 0 && longitudAbonado>= 0))
    {
        for(i=0; i<longitudLlamada; i++)
        {
            if(arrayLlamada[i].estadoLlamada == ESTADO_SIN_USO)
            {
                indice = i;
                break;
            }
        }
        val_getUnsignedInt(buffer,"\nIngrese su Id: ", "\nIngrese solo numeros",3,10);

        idAux = atoi(buffer);
        indiceAbonado = abonado_buscarIndicePorId(arrayAbonado,longitudAbonado,idAux, "\nNo se encontro el id");

        if(indiceAbonado != -1)
        {
            if(llamada_buscarLlamadasEnCurso(arrayAbonado, arrayLlamada,longitudAbonado,longitudLlamada,idAux)== -1)
            {
                printf("%s", mensajeError);
            }
            else
            {
                for(i=0; i<longitudLlamada; i++)
                {
                    do
                    {
                        val_getUnsignedInt(buffer,"\n1-FALLA 3G.\n2-FALLA LTE.\n3-FALLA EQUIPO.\n\nIngrese un motivo: ","\nError, ingrese un numero",3,10);
                        switch(atoi(buffer))
                        {
                        case 1:
                            arrayLlamada[indice].motivo = MOTIVO_FALLA_3G;
                            flagMotivo = 1;
                            break;
                        case 2:
                            arrayLlamada[indice].motivo = MOTIVO_FALLA_LTE;
                            flagMotivo = 1;
                            break;
                        case 3:
                            arrayLlamada[indice].motivo = MOTIVO_FALLA_EQUIPO;
                            flagMotivo = 1;
                            break;
                        }
                    }
                    while(flagMotivo == 0 && contadorIntentos < 3);

                    if(flagMotivo == 1)
                    {
                        arrayLlamada[indice].idAbonado = arrayAbonado[indiceAbonado].id;
                        arrayLlamada[indice].estadoLlamada = ESTADO_EN_CURSO;
                        arrayLlamada[indice].idLlamada = llamada_generarProximoIndice();
                        retorno = 0;
                        break;
                    }

                }
            }
        }
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int llamada_buscarLlamadasEnCurso (sAbonado* arrayAbonado, sLlamada* arrayLlamada, int lontidudAbonado, int lontigudLlamada, int id)
{
    int retorno = 0;
    int i;

    for(i=0; i<lontidudAbonado; i++)
    {
        if(id == arrayAbonado[i].id)
        {
            for(i=0; i<lontigudLlamada; i++)
            {
                if(arrayLlamada[i].estadoLlamada == ESTADO_EN_CURSO && arrayLlamada[i].idAbonado == id)
                {
                    retorno = -1;
                    break;
                }
            }
        }
    }
    return retorno;
}


int llamada_finLlamada (sAbonado* arrayAbonado,sLlamada* arrayLlamada,int longitudAbonado, int longitudLlamada, char* mensaje)
{
    int retorno = -1;
    char buffer[10];
    char tiempo[100];
    int flagMotivo = 0;
    int contadorIntentos = 0;
    int idAux, i;
    int indice;

    val_getUnsignedInt(buffer,"Ingrese su id: ","Ingrese un id valido",2,10);
    idAux = atoi(buffer);

    indice = abonado_buscarIndicePorId(arrayAbonado,longitudAbonado,idAux,"El id no existe");

    if(indice != -1 )
    {
        if(llamada_buscarLlamadasEnCurso(arrayAbonado, arrayLlamada,longitudAbonado,longitudLlamada,idAux)== 0)
        {
            printf("%s", mensaje);
        }
        else
        {
            for(i=0; i<longitudLlamada; i++)
            {
                if(arrayLlamada[i].estadoLlamada == ESTADO_EN_CURSO && arrayLlamada[i].idAbonado == idAux)
                {
                    if(val_getUnsignedInt(tiempo, "Ingrese el tiempo que llevo la llamada (en minutos): ", "Error, solo se permiten numeros: ",3,10)== 0)
                    {
                        do
                        {
                            val_getUnsignedInt(buffer,"\n1-SOLUCIONADO.\n2-NO SOLUCIONADO.\n\nIngrese si el problema se soluciono: ","\nError, ingrese un numero",3,10);
                            switch(atoi(buffer))
                            {
                            case 1:
                                arrayLlamada[i].estadoLlamada = ESTADO_SOLUCIONADO;
                                flagMotivo = 1;
                                break;
                            case 2:
                                arrayLlamada[i].estadoLlamada = ESTADO_NO_SOLUCIONADO;
                                flagMotivo = 1;
                                break;
                            }
                        }
                        while(flagMotivo == 0 && contadorIntentos < 3);

                        if(flagMotivo == 1)
                        {
                            arrayLlamada[i].tiempo = atoi(tiempo);
                            retorno = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

