#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"


int main()
{
   float valorA, valorB, resultado;
   int operaciones;

   printf("Ingrese el primer valor: ");
   scanf("%f", &valorA);

   printf("Ingrese el segundo valor: ");
   scanf("%f", &valorB);

   printf("Que operacion desea: 1 = divide, 2 = suma, 3 = resta, 4 = multiplica: ");
   scanf("%d", &operaciones);

   switch (operaciones)
   {
       case 1:
        resultado = dividir(valorA, valorB);
        printf("El resultado es: %f", resultado);
        break;

       case 2:
        resultado = suma(valorA, valorB);
        printf("El resultado es: %f", resultado);
        break;

       case 3:
        resultado = resta(valorA, valorB);
        printf("El resultado es: %f", resultado);
        break;

       case 4:
        resultado = multiplicar(valorA, valorB);
        printf("El resultado es: %f", resultado);
        break;
   }


    return 0;
}
