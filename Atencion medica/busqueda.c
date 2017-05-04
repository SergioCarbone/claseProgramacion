#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define CANTPERS 20
#include "validaciones.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"
#include "busqueda.h"

/**
 * \brief Obtiene el indice del ID
 * \param listaPersonas recibe array de personas
 * \param cantidad,cantidad de subindices
 * \param mensaje, texto para solicitar el ID
 * \param mensajeError, texto si el dato es invalido
 * \param mensajeNoEncontrado, texto si no se encontro el ID
 * \return indice del ID encontrado
 *
 */

int obtenerIndicePorId(EPersona listaPersonas[],int cantidad,char mensaje[], char mensajeError[],char mensajeNoEncontrado[])
{
    int indiceId=-1;
    char id[5];
    char continuar;
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999))
        {
            indiceId = buscarPorIdUsuario(listaPersonas,cantidad,atoi(id));
            if(indiceId==-1)
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(indiceId==-1 && continuar=='s');
    return indiceId;
}

/**
 * \brief Obtiene el indice del ID
 * \param recibe array de llamadas
 * \param cantidad,cantidad de subindices
 * \param mensaje, texto para solicitar el ID
 * \param mensajeError, texto si el dato es invalido
 * \param mensajeNoEncontrado, texto si no se encontro el ID
 * \return indice del ID encontrado
 *
 */

int obtenerIndiceLlamadaPorId(ELlamadas listaLlamadas[],int cantidad,char mensaje[], char mensajeError[],char mensajeNoEncontrado[])
{
    int indiceId=-1;
    char id[5];
    char continuar;
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999))
        {
            indiceId = buscarPorIdLlamadas(listaLlamadas,cantidad,atoi(id));
            if(indiceId==-1)
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(indiceId==-1 && continuar=='s');
    return indiceId;
}

/**
 * \brief busca el DNI
 * \param recibe array de personas
 * \param cantidad,cantidad de subindices
 * \param dni, dato a buscar
 * \return -1 si no se encontro el dato o indice del dato encontrado
 *
 */

int buscarPorDni(EPersona lista[], int cantidad,char dni[])
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(lista[i].dni,dni)==0)
            retorno=i;
    }
    return retorno;
}


/**
 * \brief busca el primer espacio libre
 * \param recibe array de llamadas
 * \param cantidad,cantidad de subindices
 * \param si se encuentra ocupado o no
 * \return -1 si no hay espacio libre o indice libre
 *
 */

int obtenerEspacioLibreLlamadas(ELlamadas lista[], int cantidad_elementos, int estado)
{
    int i;
    int retorno=-1;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(lista[i].isEmpty==estado)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param si se encuentra ocupado o no
 * \return -1 si no hay espacio libre o indice libre
 *
 */

int obtenerEspacioLibre(EPersona lista[], int cantidad_elementos, int estado)
{
    int i;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(lista[i].isEmpty==estado)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Obtiene el usuario con mayor cantidad de llamadas realizadas
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param indice de usuarios con mayor cantidad de llamadas
 * \return 0 si hubo error 1 si esta todo ok
 *
 */

int usuarioConMayorCantidadDeLlamadas (ELlamadas listaLlamadas[],int cantComent,EPersona listaUsuar[],int cantUsuar,int usuarConMasMensajes[])
{
    int retorno=0;
    int maximo=0;
    int contador;
    int i;
    int j;
    int k=0;
    inicializarArrayDeIndices(usuarConMasMensajes,cantUsuar,-1);
    for(i=0; i<cantUsuar; i++)
    {
        if(listaUsuar[i].isEmpty==1)
        {
            continue;
        }
        contador=0;
        for(j=0; j<cantComent; j++)
        {
            if(listaLlamadas[j].isEmpty==0 && listaLlamadas[j].idUsuario==listaUsuar[i].id)
            {
                contador++;

            }
        }
        if(contador>maximo)
        {
            k=0;
            inicializarArrayDeIndices(usuarConMasMensajes,cantUsuar,-1);
            usuarConMasMensajes[k]=i;
            maximo=contador;
            retorno = 1;

        }
        else if(contador==maximo)
        {
            k++;
            usuarConMasMensajes[k]=i;
        }

    }
    return retorno;
}
/**
 * \brief Obtiene id
 * \param recibe array de llamadas
 * \param cantidad,cantidad de subindices
 * \param dato a comparar
 * \return indice o -1 si no se encontro el id
 *
 */

int buscarPorIdLlamadas(ELlamadas lista[], int cantidad,int idComentario)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((idComentario==lista[i].id) && lista[i].isEmpty==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Obtiene el motivo más elegido
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param lista el array se pasa como parametro.
 * \param indice de motivos más elegidos
 * \return
 *
 */

void motivoMasRepetido (ELlamadas lista[],int cantidad,EMotivo motivo[],int motivosMasRepetidos[])
{
    int contador[3]= {0,0,0};
    int maximo=0;
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].isEmpty==0)
        {
            if(strcmp(lista[i].motivo,motivo[0].tipo)==0)
            {
                contador[0]++;
            }
            else if(strcmp(lista[i].motivo,motivo[1].tipo)==0)
            {
                contador[1]++;
            }
            else
            {
                contador[2]++;
            }
        }
    }

    for(i=0; i<3; i++)
    {
        if(contador[i]>maximo)
        {
            inicializarArrayDeIndices(motivosMasRepetidos,3,0);
            motivosMasRepetidos[i]=1;
            maximo=contador[i];
        }
        else if(contador[i]==maximo)
        {
            motivosMasRepetidos[i]=1;
        }
    }
}

/**
 * \brief Obtiene el motivo con más tiempo en linea
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param lista el array se pasa como parametro.
 * \param indice de motivos con más tiempo en linea
 * \return
 *
 */
void motivoMasDemoraEnPromedio (ELlamadas lista[],int cantidad,EMotivo motivo[],int motivosMasDemorados[])
{
    int contador[3]= {0,0,0};
    int acumulador[3]= {0,0,0};
    int promedio[3]= {0,0,0};
    int maximo=0;
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].isEmpty==0 && (stricmp(lista[i].estado,"CUMPLIDO")==0))
        {
            if(strcmp(lista[i].motivo,motivo[0].tipo)==0)
            {
                contador[0]++;
                acumulador[0]=acumulador[0]+lista[i].duracion;

            }
            else if(strcmp(lista[i].motivo,motivo[1].tipo)==0)
            {
                contador[1]++;
                acumulador[1]=acumulador[1]+lista[i].duracion;
            }
            else
            {
                contador[2]++;
                acumulador[2]=acumulador[2]+lista[i].duracion;
            }
        }
    }
    for(i=0; i<3; i++)
    {
        if(contador[i]>0)
        {
            promedio[i]=(acumulador[i]/contador[i]);
        }

    }


    for(i=0; i<3; i++)
    {
        if(promedio[i]>maximo)
        {
            inicializarArrayDeIndices(motivosMasDemorados,3,0);
        motivosMasDemorados[i]=1;
            maximo=promedio[i];

        }
        else if(promedio[i]==maximo)
        {
            motivosMasDemorados[i]=1;
        }
    }
}

/**
 * \brief Obtiene el indice del ID
 * \param listaPersonas recibe array de personas
 * \param cantidad,cantidad de subindices
 * \param id a comparar
 * \return indice del ID encontrado o -1 si no se encuentra
 *
 */

int buscarPorIdUsuario(EPersona lista[], int cantidad,int idUsuario)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((idUsuario==lista[i].id) && lista[i].isEmpty==0)
        {
            retorno=i;
            break;
        }

    }

    return retorno;
}

int usuarioMayorEdad (EPersona lista[],int cantidad,int listaUsuariosMayorEdad[])
{
    int retorno =0;
    int i,j;
    int maximo=0;
    int auxiliarEdad;
    for(i=0; i<cantidad; i++)
    {
        auxiliarEdad=(atoi(lista[i].edad));
        if(lista[i].isEmpty==0 && auxiliarEdad>maximo)
        {
            j=0;
            inicializarArrayDeIndices(listaUsuariosMayorEdad,cantidad,-1);
            listaUsuariosMayorEdad[j]=i;
            maximo=auxiliarEdad;
            retorno =1;
        }
        else if(lista[i].isEmpty==0 && auxiliarEdad==maximo)
        {
            j++;
            listaUsuariosMayorEdad[j]=i;
        }
    }
    return retorno;
}






