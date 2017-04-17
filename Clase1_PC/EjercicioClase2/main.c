#include <stdio.h>
#include <stdlib.h>

int main()
{
   float a,promedio, maximo,minimo,suma = 0;
   int flagA = 0, flagB = 0,i;

   for(i=0;i<5;i++)
   {
       printf("Ingrese el %d\247 de los 5 numeros: ", i+1);
       scanf("%f", &a);

       if(a > maximo || flagA == 0)
       {
           maximo = a;
           flagA = 1;
       }

       if (a < minimo || flagB == 0)
       {
           minimo = a;
           flagB = 1;
       }

       suma = suma + a;
   }

    promedio = suma/5;

    printf("\nEl numero maximo es: %.2f\n\nEl numero minimo es: %.2f\n\nEl promedio es: %.2f\n\n", maximo,minimo,promedio);
    return 0;
}
