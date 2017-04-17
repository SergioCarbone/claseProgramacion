#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***************
*\brief Le solicita un al usuario
*\param
*\return Devuelve el numero ingresado
*
*/

float numero()
{
    float num;

    printf("Ingrese un numero: ");
    scanf("%f", &num);

    return num;
}

/***************
*\brief Recibe un numero y tomandolo como radio calcula el area de un circulo
*\param float a es el numero que va a recibir
*\return Devuelve el area del circulo
*
*/

float AreaCirculo (float a)
{
    float area = 3.14 * a * a;

    return area;
}

/***************
*
*
*
*/

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

/***************
*
*
*
*/

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}

/***************
*
*
*
*/
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
int getEdad(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);

    while(auxiliar < 0 || auxiliar > 100)
    {
        printf("Error, ingrese una edad entre 0 y 100: ");
        scanf("%d", &auxiliar);
    }
    return auxiliar;
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
void getString(char mensaje[], char auxiliar[])
{
    printf(mensaje);
    scanf("%s", auxiliar);
}
/***************
*
*
*
*/
int getStringLetras(char mensaje[], char auxiliar[])
{
    char aux[200];
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




