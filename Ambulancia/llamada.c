#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "llamada.h"
#include "validar.h"


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
            arrayLlamada[i].contACV = 0;
            arrayLlamada[i].contGripe = 0;
            arrayLlamada[i].contInfarto = 0;
            arrayLlamada[i].contMax = 0;
            arrayLlamada[i].contLlamadas = 0;
        }
        retorno = 0;
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
int llamada_nuevaLlamada (sLlamada* arrayLlamada,sPersona* arrayPersona,int longitudPersona, int longitudLamada, char* mensajeError, char* mensajeError2)
{
    int retorno = -1;
    int idAux;
    int flagMotivo = 0;
    char buffer[10];
    int indice;
    int contadorIntentos = 0;

    if((arrayLlamada && arrayPersona != NULL) && (longitudLamada && longitudPersona  >= 0))
    {
        val_getUnsignedInt(buffer,"\nIngrese su Id: ", "\nIngrese solo numeros",3,10);

        idAux = atoi(buffer);

        indice = persona_buscarIndicePorId(arrayPersona,longitudPersona,idAux, "\nNo se encontro el id");

        if(indice != -1 && arrayLlamada[indice].estadoLlamada != ESTADO_PENDIENTE)
        {
            do
            {
                val_getUnsignedInt(buffer,"\n1-Infarto.\n2- ACV.\n3- Gripe.\n\nIngrese un motivo: ","\nError, ingrese un numero",3,10);
                switch(atoi(buffer))
                {
                case 1:
                    arrayLlamada[indice].motivo = MOTIVO_INFARTO;
                    arrayLlamada[indice].contInfarto ++;
                    flagMotivo = 1;
                    break;
                case 2:
                    arrayLlamada[indice].motivo = MOTIVO_ACV;
                    arrayLlamada[indice].contACV ++;
                    flagMotivo = 1;
                    break;
                case 3:
                    arrayLlamada[indice].motivo = MOTIVO_GRIPE;
                    arrayLlamada[indice].contGripe ++;
                    flagMotivo = 1;
                    break;
                }
                contadorIntentos ++;
            }
            while (flagMotivo == 0 && contadorIntentos < 3);

            if(flagMotivo == 1)
            {
                arrayLlamada[indice].idAsociado = arrayPersona[indice].id;
                arrayLlamada[indice].estadoLlamada = ESTADO_PENDIENTE;
                arrayLlamada[indice].contLlamadas++;
                retorno = 0;
            }
        }
        else
        {
            printf("%s", mensajeError2);
        }

    }
    return retorno;
}


int llamada_finLlamada (sLlamada* arrayLlamada, int longitudLamada, char* mensaje)
{
    int retorno = -1;
    char idAux[10];
    char tiempo[100];
    int idAmbulancia;
    int id;
    int indice;

    val_getUnsignedInt(idAux,"Ingrese su id: ","Ingrese un id valido",2,10);
    id = atoi(idAux);

    indice = llamada_buscarIndicePorId(arrayLlamada,longitudLamada,id,"El id no existe");

    if(indice != -1 && arrayLlamada[indice].estadoLlamada == ESTADO_PENDIENTE)
    {
        val_getUnsignedInt(idAux, "Ingrese el Id de la ambulancia que lo atendio: ","Error, solo puede ingresar numeros: ",3,10);
        idAmbulancia = atoi(idAux);

        if(val_getUnsignedInt(tiempo, "Ingrese el tiempo que llevo la consulta (en minutos): ", "Error, solo se permiten numeros: ",3,10)== 0)
        {
            arrayLlamada[indice].idAmbulancia = idAmbulancia;
            arrayLlamada[indice].tiempo = atoi(tiempo);
            arrayLlamada[indice].estadoLlamada = ESTADO_CUMPLIDO;
            retorno = 0;
        }
    }
    else if (arrayLlamada[indice].idAsociado == ESTADO_CUMPLIDO || arrayLlamada[indice].estadoLlamada == ESTADO_SIN_USO)
    {
        printf("%s", mensaje);
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


int llamada_buscarMayorCantLlamadas (sLlamada* arrayLlamada, int longitud, char* mensajeError)
{
    int retorno = -1;
    int i;
    int maximo;

    maximo = 0;

    for(i= 0; i<longitud; i++)
    {
        if(arrayLlamada[i].contLlamadas > maximo)
        {
            maximo = arrayLlamada[i].contLlamadas;
            retorno = arrayLlamada[i].idAsociado;
        }
    }
    if(retorno == -1)
    {
        printf("%s", mensajeError);
    }
    return retorno;
}


int llamada_buscarMayorMotivo (sLlamada* arrayLlamada, int longitud, char* mensajeError)
{
    int retorno = -1;
    int i;

    for(i= 0; i<longitud; i++)
    {
        if(arrayLlamada[i].contGripe > arrayLlamada[i].contACV && arrayLlamada[i].contGripe > arrayLlamada[i].contInfarto)
        {
            retorno = 3;
            arrayLlamada[i].contMax = arrayLlamada[i].contGripe;
        }
        else if (arrayLlamada[i].contInfarto > arrayLlamada[i].contGripe && arrayLlamada[i].contInfarto > arrayLlamada[i].contACV)
        {
            retorno = 1;
            arrayLlamada[i].contMax = arrayLlamada[i].contInfarto;
        }
        else
        {
            retorno = 2;
            arrayLlamada[i].contMax = arrayLlamada[i].contACV;
        }
    }
    if(retorno == -1)
    {
        printf("%s", mensajeError);
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
int llamada_printPersona (sPersona* arrayPersona, sLlamada* arrayLlamada, int longitudPersona, int longitudLlamada)
{
    int retorno = -1;
    int id;
    int indice;
    int motivo;

    if(arrayPersona != NULL && longitudPersona > 0)
    {
        id = llamada_buscarMayorCantLlamadas(arrayLlamada,longitudLlamada,"Sin llamadas");
        indice = persona_buscarIndicePorId(arrayPersona,longitudPersona,id,"\nError");

        motivo = llamada_buscarMayorMotivo(arrayLlamada,longitudLlamada,"No se registraron llamadas");

        printf("\nel retorno es %d", motivo);
        printf("\ngripe %d", arrayLlamada[indice].contGripe);
        printf("\nacv %d", arrayLlamada[indice].contACV);
        printf("\ninfarto %d", arrayLlamada[indice].contInfarto);


        if(indice != -1)
        {
            printf("\nID: %d\nNombre: %s\nApellido: %s\nCantidad de llamadas: %d", arrayPersona[indice].id, arrayPersona[indice].nombre, arrayPersona[indice].apellido, arrayLlamada[indice].contLlamadas);
        }

        printf("\n\nEl motivo mas solicitado es: %d con %d llamados", motivo, arrayLlamada[indice].contMax);
    }
    return retorno;
}
