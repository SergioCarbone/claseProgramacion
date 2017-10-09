#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "llamada.h"
#include "validar.h"

/** \brief Inicializa los campos del array
 *
 * \param arrayLlamada estructura recibida por referencia
 * \param longitud tamaño del array
 * \return 0 ok -1 error
 *
 */
int llamada_initArray (sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayLlamada[i].estadoLlamada = ESTADO_SIN_USO;
            arrayLlamada[i].tiempo = 0;
            arrayLlamada[i].idAsociado = -1;
            arrayLlamada[i].motivo = -1;
        }
        retorno = 0;
    }
    return retorno;
}

/****************************************************************************************************/

/** \brief Genera un id autoincrementable
 *
 * \return id a utilizar
 *
 */
static int idLlamadaAutoincrementable = -1;

int llamada_generarProximoIndice (void)
{
    idLlamadaAutoincrementable++;
    return idLlamadaAutoincrementable;
}

/****************************************************************************************************/


/** \brief recorre el array y busca si hay llamadas pendientes
 *
 * \param array estructura recibida por referencia
 * \param longitud tamaño del array
 * \param id recibido por parametro para ser comparado al recorrer el array
 * \return 0 ok o -1 error
 *
 */
int llamada_buscarLlamadasPendientes (sPersona* arrayPersona, sLlamada* arrayLlamada, int lontidudPersona, int lontigudLlamada, int id)
{
    int retorno = 0;
    int i;

    for(i=0; i<lontidudPersona; i++)
    {
        if(id == arrayPersona[i].id)
        {
            for(i=0; i<lontigudLlamada; i++)
            {
                if(arrayLlamada[i].estadoLlamada == ESTADO_PENDIENTE && arrayLlamada[i].idAsociado == id)
                {
                    retorno = -1;
                    break;
                }
            }
        }
    }
    return retorno;
}


/****************************************************************************************************/


/** \brief recorre el array buscando el proximo espacio libre para cargar una nueva llamada
 *
 * \param array estructura recibida por referencia
 * \param longitud tamaño del array
 * \param id recibido por parametro para ser comparado al recorrer el array
 * \param mensaje para el usuario
 * \param mensaje de error para el usuario
 * \return 0 ok o -1 error
 *
 */
int llamada_nuevaLlamada (sLlamada* arrayLlamada,sPersona* arrayPersona,int longitudPersona, int longitudLlamada, char* mensajeError, char* mensajeError2)
{
    int retorno = -1;
    int idAux, indice;
    int flagMotivo = 0;
    char buffer[10];
    int indicePersona;
    int contadorIntentos = 0;
    int i;

    if((arrayLlamada != NULL && arrayPersona != NULL) && (longitudLlamada >= 0 && longitudPersona  >= 0))
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
        indicePersona = persona_buscarIndicePorId(arrayPersona,longitudPersona,idAux, "\nNo se encontro el id");

        if(indicePersona != -1)
        {
            if(llamada_buscarLlamadasPendientes(arrayPersona, arrayLlamada,longitudPersona,longitudLlamada,idAux)== -1)
            {
                printf("%s", mensajeError2);
            }
            else
            {
                for(i=0; i<longitudLlamada; i++)
                {
                    do
                    {
                        val_getUnsignedInt(buffer,"\n1-Infarto.\n2- ACV.\n3- Gripe.\n\nIngrese un motivo: ","\nError, ingrese un numero",3,10);
                        switch(atoi(buffer))
                        {
                        case 1:
                            arrayLlamada[indice].motivo = MOTIVO_INFARTO;
                            flagMotivo = 1;
                            break;
                        case 2:
                            arrayLlamada[indice].motivo = MOTIVO_ACV;
                            flagMotivo = 1;
                            break;
                        case 3:
                            arrayLlamada[indice].motivo = MOTIVO_GRIPE;
                            flagMotivo = 1;
                            break;
                        }
                        contadorIntentos ++;
                    }
                    while (flagMotivo == 0 && contadorIntentos < 3);

                    if(flagMotivo == 1)
                    {
                        arrayLlamada[indice].idAsociado = arrayPersona[indicePersona].id;
                        arrayLlamada[indice].estadoLlamada = ESTADO_PENDIENTE;
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

/****************************************************************************************************/


/** \brief recorre el array buscando el id de la llamada para finalizarla
 *
 * \param array estructura recibida por referencia
 * \param longitud tamaño del array
 * \param mensaje para el usuario
 * \return 0 ok o -1 error
 *
 */
int llamada_finLlamada (sPersona* arrayPersona,sLlamada* arrayLlamada,int longitudPersona, int longitudLlamada, char* mensaje)
{
    int retorno = -1;
    char idAux[10];
    char tiempo[100];
    int idAmbulancia;
    int id, i;
    int indice;

    val_getUnsignedInt(idAux,"Ingrese su id: ","Ingrese un id valido",2,10);
    id = atoi(idAux);

    indice = persona_buscarIndicePorId(arrayPersona,longitudPersona,id,"El id no existe");

    if(indice != -1 )
    {
        if(llamada_buscarLlamadasPendientes(arrayPersona, arrayLlamada,longitudPersona,longitudLlamada,id)== 0)
        {
            printf("%s", mensaje);
        }
        else
        {
            for(i=0; i<longitudLlamada; i++)
            {
                if(arrayLlamada[i].estadoLlamada == ESTADO_PENDIENTE && arrayLlamada[i].idAsociado == id)
                {
                    val_getUnsignedInt(idAux, "Ingrese el Id de la ambulancia que lo atendio: ","Error, solo puede ingresar numeros: ",3,10);
                    idAmbulancia = atoi(idAux);

                    if(val_getUnsignedInt(tiempo, "Ingrese el tiempo que llevo la consulta (en minutos): ", "Error, solo se permiten numeros: ",3,10)== 0)
                    {
                        arrayLlamada[i].idAmbulancia = idAmbulancia;
                        arrayLlamada[i].tiempo = atoi(tiempo);
                        arrayLlamada[i].estadoLlamada = ESTADO_CUMPLIDO;
                        retorno = 0;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}


/****************************************************************************************************/


/** \brief recorre el array buscando un indice utilizando un id
 *
 * \param array estructura recibida por referencia
 * \param longitud tamaño del array
 * \param id recibido por parametro para ser comparado al recorrer el array
 * \param mensaje para el usuario
 * \return 0 ok o -1 error
 *
 */
int llamada_buscarIndicePorId (sLlamada* arrayLlamada, int longitud, int id, char* mensaje)
{
    int retorno = -1;
    int i;

    if(arrayLlamada != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayLlamada[i].idAsociado == id)
            {
                retorno = i;
                break;
            }
        }
        if(retorno == -1)
        {
            printf("%s", mensaje);
        }
    }
    return retorno;
}


/****************************************************************************************************/


/** \brief
 *
 * \param array estructura recibida por referencia
 * \param longitud tamaño del array
 * \param
 * \param
 * \return 0 ok o -1 error
 *
 */
int llamada_buscarIdConMasCantLlamadas (sLlamada* arrayLlamada, sPersona* arrayPersona,
                                        int longitudPersona, int longitudLlamada, char* mensajeError)
{
    int retorno = -1;
    int llamadasArray[longitudLlamada];
    int idLlamada[longitudLlamada];
    int posicionPersona, posicionLlamada;
    int i, id, max = 0;

    for(i= 0; i<longitudLlamada; i++)
    {
        llamadasArray[i] = 0;
        idLlamada[i] = -1;
    }

    if((arrayLlamada != NULL && arrayPersona != NULL) && (longitudLlamada > 0 && longitudPersona > 0))
    {
        for(posicionPersona=0; posicionPersona<longitudPersona; posicionPersona++)
        {
            if(arrayPersona[posicionPersona].estado == PERSONA_OCUPADO)
            {
                for(i=0; i<longitudLlamada; i++)
                {
                    if(idLlamada[i] == -1)
                    {
                        idLlamada[i] = arrayPersona[posicionPersona].id;
                        for(posicionLlamada=0; posicionLlamada<longitudLlamada; posicionLlamada++)
                        {
                            if(arrayLlamada[posicionLlamada].idAsociado == arrayPersona[posicionPersona].id && arrayLlamada[posicionLlamada].estadoLlamada == ESTADO_CUMPLIDO)
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



/****************************************************************************************************/


/** \brief recorre el array buscando el id de la llamada para finalizarla
 *
 * \param array estructura recibida por referencia
 * \param longitud tamaño del array
 * \param id recibido por parametro para ser comparado al recorrer el array
 * \param mensaje para el usuario
 * \return 0 ok o -1 error
 *
 */
int llamada_buscarCantidadLlamadasPorId (sLlamada* arrayLlamadas,int longitudLlamada,int id,char* mensaje)
{
    int retorno =-1;
    int i;
    int contLlamada = 0;

    if((arrayLlamadas != NULL ) && (longitudLlamada > 0 ))
    {
        for(i=0; i<longitudLlamada; i++)
        {
            if(arrayLlamadas[i].estadoLlamada == ESTADO_CUMPLIDO)
            {
                if(arrayLlamadas[i].idAsociado == id);
                {
                    contLlamada++;
                }
            }
        }
        if(contLlamada > 0)
        {
            retorno = contLlamada;
        }
        else
        {
            printf("%s",mensaje);
        }

    }
    return retorno;
}



/****************************************************************************************************/


/** \brief
 *
 * \param
 * \param
 * \param
 * \param
 * \return
 *
 */
int llamada_buscarMayorMotivo (sLlamada* arrayLlamada, int longitud, char* mensajeError)
{
    int retorno = -1;
    int i, maximoMotivo;
    int arrayMotivos[3];

    for(i= 0; i<3; i++)
    {
        arrayMotivos[i] = 0;
    }

    for(i= 0; i<longitud; i++)
    {
        if(arrayLlamada[i].estadoLlamada == ESTADO_CUMPLIDO)
        {
            if(arrayLlamada[i].motivo == MOTIVO_INFARTO)
            {
                arrayMotivos[MOTIVO_INFARTO]++;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_ACV)
            {
                arrayMotivos[MOTIVO_ACV]++;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_GRIPE)
            {
                arrayMotivos[MOTIVO_GRIPE]++;
            }
        }
    }
    maximoMotivo = arrayMotivos[0];

    for(i= 0; i<3; i++)
    {
        if(arrayMotivos[i] > maximoMotivo)
        {
            maximoMotivo = arrayMotivos[i];

        }
    }

    if(retorno == -1)
    {
        printf("%s", mensajeError);
    }
    return retorno;
}

/****************************************************************************************************/

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int llamada_obtenerCantidadMotivosYllamadas (sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i, cantidadMotivo = 0;
    int arrayMotivos[3];

    for(i= 0; i<3; i++)
    {
        arrayMotivos[i] = 0;
    }

    for(i= 0; i<longitud; i++)
    {
        if(arrayLlamada[i].estadoLlamada == ESTADO_CUMPLIDO)
        {
            if(arrayLlamada[i].motivo == MOTIVO_INFARTO )
            {
                arrayMotivos[MOTIVO_INFARTO]++;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_ACV  )
            {
                arrayMotivos[MOTIVO_ACV]++;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_GRIPE )
            {
                arrayMotivos[MOTIVO_GRIPE]++;
            }
        }
    }

    for(i= 0; i<3; i++)
    {
        if(arrayMotivos[i] > cantidadMotivo)
        {
            cantidadMotivo = arrayMotivos[i];
        }
    }

    for(i= 0; i<3; i++)
    {
        if(arrayMotivos[i] == cantidadMotivo)
        {
            printf("\nMotivos con mas llamadas %d: con: %d llamadas", i,cantidadMotivo);
            retorno = 0;
        }
    }


    return retorno;
}


/****************************************************************************************************/


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int llamada_printPersona (sPersona* arrayPersona, sLlamada* arrayLlamada,
                          int longitudPersona, int longitudLlamada, char* mensajeError,char* mensajeError2)
{
    int retorno = -1;
    int idAux,i,posicion;
    int motivoMasDemora;
    int cantLlamadas;

    if((arrayLlamada != NULL && arrayPersona != NULL) && (longitudLlamada > 0 &&
            longitudPersona > 0))
    {
        for(posicion=0; posicion<longitudPersona; posicion++)
        {
            if(arrayPersona[posicion].estado == PERSONA_OCUPADO)
            {
                for(i=0; i<longitudLlamada; i++)
                {
                    if(arrayPersona[posicion].id == arrayLlamada[i].idAsociado &&
                            arrayLlamada[i].estadoLlamada == ESTADO_CUMPLIDO)
                    {
                        idAux = llamada_buscarIdConMasCantLlamadas(arrayLlamada,arrayPersona,
                                longitudPersona,longitudLlamada,"Sin llamadas");

                        cantLlamadas = llamada_buscarCantidadLlamadasPorId(arrayLlamada,
                                       longitudLlamada,idAux,
                                       "El id no realizo ninguna llamada");

                        motivoMasDemora = llamada_calcularPromediodeMotivos(arrayLlamada,longitudLlamada);
                        llamada_obtenerCantidadMotivosYllamadas(arrayLlamada,longitudLlamada);

//                        printf("\n\nPosicion: %d", posicion);
//                        printf("\nId: %d", arrayPersona[posicion].id);
//                        printf("\nNombre: %s", arrayPersona[posicion].nombre);
//                        printf("\nApellido: %s", arrayPersona[posicion].apellido);
//                        printf("\nPosicion llamada: %d", arrayLlamada[i].idLlamada);
//                        printf("\nEstado de llamada: %d", arrayLlamada[i].estadoLlamada);
//                        printf("\nMotivo: %d", arrayLlamada[i].motivo);
                        printf("\n\nEl id con mas cantidad de llamadas es: %d con %d", idAux, cantLlamadas);
                        printf("\nEl asociado con mas llamados es: %s %s", arrayPersona[idAux].nombre, arrayPersona[idAux].apellido);
                        printf("\nEl motivo que en promedio demora mas en atender es: %d", motivoMasDemora);

                    }
                    else
                    {
                        printf("%s",mensajeError);
                    }
                    break;
                }
            }
            else
                printf("\n%s", mensajeError2);
            break;
        }
    }

    return retorno;
}


/****************************************************************************************************/

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int llamada_calcularPromediodeMotivos (sLlamada* arrayLlamada, int longitudLlamada)
{
    int retorno = 0;
    int i;
    int arrayMotivos[3];
    float arrayTiempoMotivos[3];
    float promedioMotivos[3];
    float maxPromedio = 0;


    for(i= 0; i<3; i++)
    {
        arrayMotivos[i] = 0;
        arrayTiempoMotivos[i] = 0;
    }

    for(i= 0; i<longitudLlamada; i++)
    {
        if(arrayLlamada[i].estadoLlamada == ESTADO_CUMPLIDO)
        {
            if(arrayLlamada[i].motivo == MOTIVO_INFARTO )
            {
                arrayMotivos[MOTIVO_INFARTO]++;
                arrayTiempoMotivos[MOTIVO_INFARTO] = arrayTiempoMotivos[MOTIVO_INFARTO] + arrayLlamada[i].tiempo;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_ACV  )
            {
                arrayMotivos[MOTIVO_ACV]++;
                arrayTiempoMotivos[MOTIVO_ACV] = arrayTiempoMotivos[MOTIVO_INFARTO] + arrayLlamada[i].tiempo;
            }
            else if(arrayLlamada[i].motivo == MOTIVO_GRIPE )
            {
                arrayMotivos[MOTIVO_GRIPE]++;
                arrayTiempoMotivos[MOTIVO_GRIPE] = arrayTiempoMotivos[MOTIVO_INFARTO] + arrayLlamada[i].tiempo;
            }
        }
    }
    for(i= 0; i<3; i++)
    {
        promedioMotivos[i] = arrayTiempoMotivos[i] / arrayMotivos[i];
    }

    for(i= 0; i<3; i++)
    {
        if(promedioMotivos[i] > maxPromedio)
        {
            maxPromedio = promedioMotivos[i];
            retorno = i;
        }
    }

    return retorno;
}














