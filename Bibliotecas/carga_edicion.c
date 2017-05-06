#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "carga_edicion.h"
#include "validaciones.h"


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

//-------------------------------------------------------------------------------------------------------------------------------------------
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}
//-------------------------------------------------------------------------------------------------------------------------------------------

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin); // Win
    // fpurge(stdin); //Linux y OSx
    scanf("%c",&auxiliar);
    return auxiliar;
}

//-------------------------------------------------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param auxiliar donde se cargará el texto ingresado
 */
void getString(char mensaje[], char auxiliar[])
{
    printf(mensaje);
    scanf("%s", auxiliar);
}

//-------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param auxiliar donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getNumerosChar (char mensaje[],char auxiliar[])
{
    int retorno=0;
    getString(mensaje,auxiliar);
    if(Numerico(auxiliar))
    {
        retorno= 1;
    }
    return retorno;
}

/*************************************************************************************************************************************************

/**
* \brief Solicita un texto al usuario y lo devuelve
* \param mensaje Es el mensaje a ser mostrado
* \param auxiliar donde se cargará el texto ingresado
* \return 1 si el texto contiene solo letras
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

//-------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int ingresarSoloLetras (char auxiliar[], char mensajeParaPedirDato[],char mensajeError[])
{
    char seguir='s';
    int cargaExitosa;
    do
    {
        cargaExitosa=getStringLetras(mensajeParaPedirDato,auxiliar);
        if(!(cargaExitosa))
        {
            printf(mensajeError);// Ejemplo "Ha ingresado caracteres invalidos para un nombre.\n"
            seguir=getChar("Desea reintentar? s/n");
        }
    }
    while(cargaExitosa!=1 && seguir == 's');
    return cargaExitosa;
}



/*************************************************************************************************************************************************

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
/*************************************************************************************************************************************************


