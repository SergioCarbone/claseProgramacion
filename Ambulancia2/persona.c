#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "llamada.h"
#include "validar.h"


/** \brief cargaPersona realiza la carga de datos
 * \param arrayPersona array recibido por parametro
 * \param longitud del array
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo
 *
 */
int persona_cargarPersona (sPersona* arrayPersona,int longitud)
{
    int retorno = -1;
    int i, indice;
    char bNombre[51];
    char bApellido[51];
    char bDni[10];
    char edad[4];

    if(arrayPersona != NULL && longitud >= 0)
    {
        for(i=0; i<longitud; i++)
        {
            if(arrayPersona[i].estado == PERSONA_LIBRE)
            {
                indice = i;
                break;
            }
        }

        if(val_getString(bNombre,"\nIngrese el nombre: ","\nError, solo puede ingresar letras: ",3,51)==0)
        {
            if(val_getString(bApellido, "\nIngrese el apellido: ", "\nError, solo puede ingresar letras: ",3,51)== 0)
            {
                if(val_getDNI(bDni,"\nIngrese el DNI: ","\nError, tiene que ser con este formato XX.XXX.XXX: ",2,10)== 0)
                {
                    if(persona_buscarDniRepetido(arrayPersona,bDni,"Error, el DNI ya existe", longitud)==0)
                    {
                        if(val_getUnsignedEdad(edad,"\nIngrese la edad: ","\nError, edad fuera de rango o no ingreso un numero: ",2,4)== 0)
                        {
                            strncpy(arrayPersona[indice].nombre,bNombre,51);
                            strncpy(arrayPersona[indice].apellido,bApellido,51);
                            strncpy(arrayPersona[indice].DNI,bDni,10);
                            arrayPersona[indice].edad = atoi(edad);
                            arrayPersona[indice].id = persona_generarProximoId();
                            arrayPersona[indice].estado = PERSONA_OCUPADO;
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/***************************************************************************************************/


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int persona_buscarDniRepetido (sPersona* arrayPersona, char* dniAux,char* mensaje, int longitudPersona)
{
    int retorno = 0;
    int i;

    for(i=0; i<longitudPersona; i++)
    {
        if(arrayPersona[i].estado == PERSONA_OCUPADO)
        {
            if(strncmp(arrayPersona[i].DNI,dniAux,10)==0)
            {
                retorno =-1;
                break;
            }
        }
    }
    if(retorno == -1)
    {
        printf("%s", mensaje);
    }
    return retorno;
}

/***************************************************************************************************/

/** \brief Inicializa los campos del array
 *
 * \param array estructura recibida por referencia
 * \param longitud tamaño del array
 * \return 0 ok -1 error
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

/***************************************************************************************************/

/** \brief Genera un id autoincrementable
 *
 * \return id a utilizar
 *
 */
static int idAutoincrementable = -1;

int persona_generarProximoId (void)
{
    idAutoincrementable++;
    return idAutoincrementable;
}


/***************************************************************************************************/


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
    int idMax = idAutoincrementable;

    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPersona[i].estado == PERSONA_OCUPADO)
            {
                if(idMax < arrayPersona[i].id)
                {
                    //idMax = generarProximoId();
                }
            }
        }
        retorno = idMax;
    }
    return retorno;
}

/***************************************************************************************************/


/** \brief recorre el array buscando un indice utilizando un id
 *
 * \param array estructura recibida por referencia
 * \param longitud tamaño del array
 * \param id recibido por parametro para ser comparado al recorrer el array
 * \param mensaje para el usuario
 * \return 0 ok o -1 error
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

/***************************************************************************************************/


/** \brief recorre el array para modificar campos de la estructura
 *
 * \param array recibido por referencia
 * \param longitud del array
 * \return 0 ko o -1 error
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


/***************************************************************************************************/


/** \brief recorre el array para hacer una baja logica
 *
 * \param array recibido por referencia
 * \param longitud del array
 * \return 0 ko o -1 error
 *
 */
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

/***************************************************************************************************/

/**
 * Ordena el array por nombre
 * \param array pasado por parametro
 * @param longitud es la cantidad de posiciones que tiene el array
 */
void persona_ordenarPorNombre(sPersona* arrayPersona,int longitud)
{
    int i,j;
    sPersona aux;

    for(i=1; i< longitud; i++)
    {
        aux = arrayPersona[i];
        j= i;

        while(j>0 && (strcmp(aux.nombre,arrayPersona[j-1].nombre)< 0))
        {
            arrayPersona[j] = arrayPersona[j-1];
            j--;
        }
        arrayPersona[j] = aux;
    }
    printf("\n\nNombre\tdni\tEdad\n");
    for(i=0; i<longitud; i++)
    {
        if(arrayPersona[i].estado == ESTADO_CUMPLIDO)
        {
            printf("%s   %s   %d\n",arrayPersona[i].nombre,arrayPersona[i].DNI,arrayPersona[i].edad);
        }
    }
}

/***************************************************************************************************/


/**
 * Ordena el array por edad
 * \param array pasado por parametro
 * @param longitud es la cantidad de posiciones que tiene el array
 */
void persona_ordenarPorEdad(sPersona* arrayPersona,int longitud)
{
    int i,j;
    sPersona aux;

    for(i=1; i< longitud; i++)
    {
        aux = arrayPersona[i];
        j= i;

        while(j>0 && aux.edad > arrayPersona[j-1].edad)
        {
            arrayPersona[j] = arrayPersona[j-1];
            j--;
        }
        arrayPersona[j] = aux;
    }
    printf("\n\nNombre\tdni\tEdad\n");
    for(i=0; i<longitud; i++)
    {
        if(arrayPersona[i].estado == ESTADO_CUMPLIDO)
        {
            printf("%s   %s   %d\n",arrayPersona[i].nombre,arrayPersona[i].DNI,arrayPersona[i].edad);
        }
    }
}

/***************************************************************************************************/


/**
 * Ordena el array por edad y por nombre
 * \param array pasado por parametro
 * @param longitud es la cantidad de posiciones que tiene el array
 */
void persona_ordenarPorDosString(sPersona* arrayPersona,int longitud)
{
    int i,j;
    sPersona aux;

    for(i=1; i< longitud; i++)
    {
        aux = arrayPersona[i];
        j= i;

        while(j>0 )
        {
            if(aux.edad > arrayPersona[j-1].edad)
            {
                arrayPersona[j] = arrayPersona[j-1];
            }
            else if(aux.edad == arrayPersona[j-1].edad)
            {
                if(strcmp(aux.nombre,arrayPersona[j-1].nombre)>0)
                {
                    arrayPersona[j] = arrayPersona[j-1];
                }
            }
            j--;
        }
        arrayPersona[j] = aux;
    }


    printf("\n\nNombre\tdni\tEdad\n");
    for(i=0; i<longitud; i++)
    {
        if(arrayPersona[i].estado == ESTADO_CUMPLIDO)
        {
            printf("%s   %s   %d\n",arrayPersona[i].nombre,arrayPersona[i].DNI,arrayPersona[i].edad);
        }
    }
}


/**
 * Ordena el array por dos char
 * \param array pasado por parametro
 * @param longitud es la cantidad de posiciones que tiene el array
 */
void persona_ordenarPorEdadYNombre(sPersona* arrayPersona,int longitud)
{
    int i,j;
    sPersona aux;

    for(i=1; i< longitud; i++)
    {
        aux = arrayPersona[i];
        j= i;

        while(j>0 )
        {
            if(strcmp(aux.nombre,arrayPersona[j-1].nombre) < 0)
            {
                arrayPersona[j] = arrayPersona[j-1];
            }
            else if(strcmp(aux.nombre,arrayPersona[j-1].nombre) == 0)
            {
                if(strcmp(aux.apellido,arrayPersona[j-1].apellido) < 0)
                {
                    arrayPersona[j] = arrayPersona[j-1];
                }
            }
            j--;
        }
        arrayPersona[j] = aux;
    }


    printf("\n\nNombre\tdni\tEdad\n");
    for(i=0; i<longitud; i++)
    {
        if(arrayPersona[i].estado == ESTADO_CUMPLIDO)
        {
            printf("%s   %s   %d\n",arrayPersona[i].nombre,arrayPersona[i].DNI,arrayPersona[i].edad);
        }
    }
}
