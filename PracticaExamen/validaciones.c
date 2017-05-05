#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "carga_edicion.h"



/***************
*
*
*
*/
int Letras(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/***************
*
*
*
*/
int Telefono(char str[])
{
    int i = 0,contadorGuiones = 0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') && (str[i] != '-'))
        {
            return 0;
        }
        if(str[i] == '-')
        {
            contadorGuiones++;
        }
        i++;
    }
    if(contadorGuiones == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

/***************
*
*
*
*/
int mail(char str[])
{
    int i = 0;
    int contador = 0;

    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] != '-') && (str[i] != '@') && (str[i] != '_') && (str[i] != '.'))
        {
            return 0;
        }
        if(str[i] == '@')
            {
                contador++;
            }
        i++;
    }
    if(contador == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/***************
*
*
*
*/
int Alfanumerico(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/***************
*
*
*
*/
int Numerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}


/**
 * \brief Solicita un texto numérico al usuario y valida si se encuentra dentro de un rango de edad lógico
 * \param input Array donde se cargará el texto ingresado
 * \return -
 */

void rangoEdad (char input[])
{
    int edad=atoi(input);
    if(edad<0 || edad>150)
    {
        printf("\nLA EDAD INGRESADA ES INVALIDA");
    }
}


/***************
* Controla que solo se hayan ingresado numeros
* @param mensaje para imprimir
* @param auxiliar texto que debe validar
* @return retorna 1 si se cumple la condicion o 0 si no
*/
int getStringClave(char mensaje[], char auxiliar[])
{
    char aux[10];
    getString(mensaje, aux);
    if(Alfanumerico(aux)&& strlen(aux)<= 8)
    {
        strcpy(auxiliar, aux);
        return 1;
    }
    return 0;
}


/***************
* Controla que solo se hayan ingresado numeros
* @param mensaje para imprimir
* @param auxiliar texto que debe validar
* @return retorna 1 si se cumple la condicion o 0 si no
*/
int getStringNick(char mensaje[], char auxiliar[])
{
    char aux[10];
    getString(mensaje, aux);
    if(Alfanumerico(aux)&& strlen(aux)<= 8)
    {
        strcpy(auxiliar, aux);
        return 1;
    }
    return 0;
}

/***************
* Controla que solo se hayan ingresado numeros
* @param mensaje para imprimir
* @param auxiliar texto que debe validar
* @return retorna 1 si se cumple la condicion o 0 si no
*/
int getStringMensaje(char mensaje[], char auxiliar[])
{
    char aux[150];
    getString(mensaje, aux);

    if(Alfanumerico(aux)&& strlen(aux)<= 150)
    {
        strcpy(auxiliar, aux);
        return 1;
    }
    return 0;
}

/***************
* Recibe un mensaje y un texto
* @param mensaje para imprimir
* @param auxiliar texto que debe validar
* @return retorna 1 si se cumple la condicion o 0 si no
*/
int getStringMail(char mensaje[], char auxiliar[])
{
    char aux[60];
    getString(mensaje, aux);
    if(mail(aux)&& strlen(aux)<= 30)
    {
        strcpy(auxiliar, aux);
        return 1;
    }
    return 0;
}
