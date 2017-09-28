#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "llamada.h"
#include "validar.h"


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int persona_cargarPersona (sPersona* arrayPersona, int indice, int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];
    char bDni[10];
    int idAux;
    char edad[4];

    if(arrayPersona != NULL && indice >= 0)
    {
        idAux = persona_buscarProximoId(arrayPersona,longitud);

        if(val_getString(bNombre,"\nIngrese el nombre: ","\nError, solo puede ingresar letras: ",3,51)==0)
        {
            if(val_getString(bApellido, "\nIngrese el apellido: ", "\nError, solo puede ingresar letras: ",3,51)== 0)
            {
                if(val_getDNI(bDni,"\nIngrese el DNI: ","\nError, tiene que ser con este formato XX.XXX.XXX: ",2,10)== 0)
                {
                    if(val_getUnsignedEdad(edad,"\nIngrese la edad: ","\nError, edad fuera de rango o no ingreso un numero: ",2,4)== 0)
                    {
                        strncpy(arrayPersona[indice].nombre,bNombre,51);
                        strncpy(arrayPersona[indice].apellido,bApellido,51);
                        strncpy(arrayPersona[indice].DNI,bDni,10);
                        arrayPersona[indice].edad = atoi(edad);
                        arrayPersona[indice].id = idAux;
                        arrayPersona[indice].estado = PERSONA_OCUPADO;
                        retorno = 0;
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
int persona_initArray (sPersona* arrayPersona, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayPersona[i].estado = PERSONA_LIBRE;
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
int persona_buscarProximoId (sPersona* arrayPersona, int longitud)
{
    int retorno = -1;
    int i;
    int idMax = -1;

    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPersona[i].estado == PERSONA_OCUPADO)
            {
                if(idMax < arrayPersona[i].id)
                {
                    idMax = arrayPersona[i].id;
                }
            }
        }
        retorno = idMax +1;
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
int persona_buscarIndicePorId (sPersona* arrayPersona, int longitud, int id, char* mensaje)
{
    int retorno = -1;
    int i;

    if(arrayPersona != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPersona[i].estado == PERSONA_OCUPADO)
            {
                if(id == arrayPersona[i].id)
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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int persona_modificarPersona (sPersona* arrayPersona, int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];
    int idAux;
    char buffer[10];
    int indice;

    val_getUnsignedInt(buffer,"Ingrese el ID a modificar", "El ID no se encontro",3,10);
    idAux = atoi(buffer);

    indice = persona_buscarIndicePorId(arrayPersona,longitud,idAux, "No se encontro el id");

    if(indice != -1)
    {
        if(val_getString(bNombre,"\nIngrese el nombre: ","\nError\n",3,51)==0)
        {
            if(val_getString(bApellido, "\nIngrese el apellido: ", "\nError",3,51)== 0)
            {
                strncpy(arrayPersona[indice].nombre,bNombre,51);
                strncpy(arrayPersona[indice].apellido,bApellido,51);
            }
        }
    }
    return retorno;
}


int persona_darDeBajaPersona (sPersona* arrayPersona, int longitud)
{
    int retorno = -1;
    int idAux;
    char buffer[10];
    int indice;

    val_getUnsignedInt(buffer,"Ingrese el ID para dar de baja", "El ID no se encontro",3,10);
    idAux = atoi(buffer);

    indice = persona_buscarIndicePorId(arrayPersona,longitud,idAux, "No se encontro el id");

    if(indice != -1)
    {
        arrayPersona[indice].estado = PERSONA_LIBRE;
        retorno = 0;

    }
    return retorno;
}

