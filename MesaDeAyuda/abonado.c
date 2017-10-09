#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abonado.h"
#include "llamada.h"
#include "validar.h"
#include "informes.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int abonado_initArray (sAbonado* arrayAbonado, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAbonado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayAbonado[i].estado = ABONADO_LIBRE;
            retorno = 0;
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
static int idAutoincrementable = -1;

int abonado_generarProximoId (void)
{
    idAutoincrementable++;
    return idAutoincrementable;
}

/** \brief cargaAbonado realiza la carga de datos
 * \param arrayAbonado array recibido por parametro
 * \param longitud del array
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo
 *
 */
int abonado_cargarAbonado (sAbonado* arrayAbonado ,int longitud)
{
    int retorno = -1;
    int i, indice;
    char bNombre[51];
    char bApellido[51];

    if(arrayAbonado != NULL && longitud >= 0)
    {
        for(i=0; i<longitud; i++)
        {
            if(arrayAbonado[i].estado == ABONADO_LIBRE)
            {
                indice = i;
                break;
            }
        }

        if(val_getString(bNombre,"\nIngrese el nombre: ","\nError, solo puede ingresar letras: ",3,51)==0)
        {
            if(val_getString(bApellido, "\nIngrese el apellido: ", "\nError, solo puede ingresar letras: ",3,51)== 0)
            {
                strncpy(arrayAbonado[indice].nombre,bNombre,51);
                strncpy(arrayAbonado[indice].apellido,bApellido,51);
                arrayAbonado[indice].id = abonado_generarProximoId();
                arrayAbonado[indice].estado = ABONADO_OCUPADO;
                retorno = 0;
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
int abonado_modificarAbonado (sAbonado* arrayAbonado, int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];
    int idAux;
    char buffer[10];
    int indice;

    val_getUnsignedInt(buffer,"Ingrese el ID a modificar", "El ID no se encontro",3,10);
    idAux = atoi(buffer);

    indice = abonado_buscarIndicePorId(arrayAbonado,longitud,idAux, "No se encontro el id");

    if(indice != -1)
    {
        if(val_getString(bNombre,"\nIngrese el nombre: ","\nError\n",3,51)==0)
        {
            if(val_getString(bApellido, "\nIngrese el apellido: ", "\nError",3,51)== 0)
            {
                strncpy(arrayAbonado[indice].nombre,bNombre,51);
                strncpy(arrayAbonado[indice].apellido,bApellido,51);
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
int abonado_buscarIndicePorId (sAbonado* arrayAbonado, int longitud, int id, char* mensaje)
{
    int retorno = -1;
    int i;

    if(arrayAbonado != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAbonado[i].estado == ABONADO_OCUPADO)
            {
                if(id == arrayAbonado[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }
        if(retorno == -1)
        {
            printf("%s", mensaje);
        }
    }
    return retorno;
}

int abonado_darDeBajaAbonado (sAbonado* arrayAbonado, int longitud)

{
    int retorno = -1;
    int idAux;
    char buffer[10];
    int indice;

    val_getUnsignedInt(buffer,"Ingrese el ID para dar de baja", "El ID no se encontro",3,10);
    idAux = atoi(buffer);

    indice = abonado_buscarIndicePorId(arrayAbonado,longitud,idAux, "No se encontro el id");

    if(indice != -1)
    {
        arrayAbonado[indice].estado = ABONADO_LIBRE;
        retorno = 0;

    }
    return retorno;
}



