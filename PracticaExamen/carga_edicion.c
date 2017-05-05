#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "carga_edicion.h"
#include "validaciones.h"


/**
* Devuelve el valor ingresado
* @param mensaje que tiene que imprimir
* @return valor ingresado por el usuario
*/
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}


float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}


char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);
    return auxiliar;

}


/***************
*
*
*
*/
char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand(time(NULL));
    return desde +(rand()% (hasta + 1 - desde));
}

/***************
*
*
*
*/
void getString(char mensaje[], char auxiliar[])
{
    printf(mensaje);
    scanf("%s", auxiliar);
}




/**
* Controla que solo se hayan ingresado letras
* @param mensaje para imprimir
* @param auxiliar texto que debe validar
* @return retorna 1 si se cumple la condicion o 0 si no
*/
int getStringLetras(char mensaje[], char auxiliar[])
{
    char aux[20];
    getString(mensaje,aux);
    if(Letras(aux))
    {
        strcpy(auxiliar, aux);
        return 1;
    }
    return 0;
}

/***************
*
*
*
*/
int getStringNumeros(char mensaje[], char auxiliar[])
{
    char aux[200];
    getString(mensaje, aux);
    if(Numerico(aux))
    {
        strcpy(auxiliar, aux);
        return 1;
    }
    return 0;
}

/***************
*
*
*
*/
int buscarPosicion(EPersona listaUsuario[], int cantidad, int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if (listaUsuario[i].isEmpty == valor)
        {
            return i;
        }
    }
    return -1;
}

/***************
*
*
*
*/
int buscarPosicionDeComentario(EComentario listaComentarios[], int cantidad, int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if (listaComentarios[i].isEmpty == valor)
        {
            return i;
        }
    }
    return -1;
}


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorNick(EPersona listaUsuarios[], char valor[],int cantidad)
{
    int i, retorno = -1;
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(listaUsuarios[i].nick , valor)==0 && listaUsuarios[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

/***************
* Inicia el estado de cada una de las personas del array
* @param persona recibe el array de persona
* @param cantidad recibe la cantidad de posiciones
* @param valor indica que valor va a recibir cada estado
*/
void iniciarEstado(EPersona listaUsuarios[],int cantidad,int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        listaUsuarios[i].isEmpty=valor;
    }
}

/***************
* Inicia el estado de cada una de las personas del array
* @param persona recibe el array de persona
* @param cantidad recibe la cantidad de posiciones
* @param valor indica que valor va a recibir cada estado
*/
void iniciarComentario(EComentario listaComentarios[],int cantidad,int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        listaComentarios[i].isEmpty=valor;
    }
}

void iniciarMeGusta(EComentario listaComentarios[],int cantidad,int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        listaComentarios[i].meGusta=valor;
    }
}

void ordenarPorNombre(EPersona persona[],int cantidad)
{

    int i,j;
    EPersona nombre;


    for(i=0; i< cantidad; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(stricmp(persona[i].nombre,persona[j].nombre)>0)
            {
                nombre = persona[i];
                persona[i] = persona[j];
                persona[j] = nombre;

            }
        }
    }
}




/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorClave(EPersona listaUsuarios[], char valor[],int cantidad)
{
    int i, retorno = -1;
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(listaUsuarios[i].claveAcceso , valor)==0 && listaUsuarios[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorEmail(EPersona listaUsuarios[], char valor[],int cantidad)
{
    int i, retorno = -1;
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(listaUsuarios[i].email , valor)==0 && listaUsuarios[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
