#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10
#define DNI 8

        //printf("Ingrese el DNI: ");
        //scanf("%s", buffer);
        //if(isnumber(buffer))
        //{
        //    printf("Es un numero");
        //    dni[i] = atoi(buffer); //convierte la cadena de carater en un numero
        //}

        //    strcpy(apellido[0], "hola");




  crear una estructura

  struct
  {
    int legajo;
    char nombre[50];
    char apellido[50];
    char isEmpty; //sirve para decir si un lugar esta vacio o lleno

    //type.h
    //define.h



  }typedef Empleado; //define el nombre de la estructura y ya lo la tengo que llamar literalmente


int main()
{
     char buffer[4084];
     Empleado arrayEmpleados[MAX];

  //   aux.legajo = 99;


    int isnumber(char* aux)
    {
        int i=0;
        int retorno =0;

        if (aux[i]== '-')//controlo si ingresa un numero negativo
        {
            i++;
        }
        while(aux[i]!= '\0')
        {
            if(isdigit(aux[i])== 0)// controlo que no se ingrese una cadena vacia
            {
                retorno = 0;
                break;
            }
            retorno = 1
            i++;
        }
    }


    for(i=0; i< 5; i++){
        printf("Ingrese el nombre: ");
        scanf("%s", buffer);
        if(strlen(buffer) < 50)
        {
            strcpy(arrayEmpleados[i].legajo = atoi(buffer));
        }


        printf("Ingrese el apellido: ");
        scanf("%s", buffer);
        if(strlen(buffer) < 50)
        {
            strcpy(arrayEmpleados[i].legajo = atoi(buffer));
        }


        printf("Ingrese el DNI: ");
        scanf("%s", buffer);
        if(isnumber(buffer))
        {
            dni[i] = atoi(buffer); //convierte la cadena de carater en un numero
        }
        strcpy(apellido[0], "hola");

    }


    }
