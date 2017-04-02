#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    int i;
    for (i = 0; i < 6; i++)
    {
        printf("\n %d", i);
    }
   return 0;
}

/*
int main()
{

int edad[MAX], i;
   float sueldo [MAX], suma = 0, prom, aux;

   for(i = 0; i<MAX; i++)
   {
       printf("Ingrese la edad del legajo %d: ", i +1);
       scanf("%d", &edad[i]);
       printf("Ingrese el suledo del legajo %d: ", i + 1);
       scanf("%f", &aux);
       sueldo[i]= aux;
   }

   for (i = 0; i<MAX; i++)
   {
       suma = suma + sueldo[i];
   }

   prom = suma/MAX;
   printf("El sueldo promedio es %.2f", prom);
   return 0;
}

*/

/*
 char texto[MAX];
    int x;
    printf("\nIngrese su clave: ");
    gets(texto);  // Lee lo que se ingresa por teclado y lo guarda
    //scanf("%s", texto);

    x = strlen ( texto ); // strlen cuenta la cantidad de caracteres
    if (strcmp (texto, "1234")== 0) // strcmp compara cadena de caracteres distingue mayusculas
    {                               // stricmp compara cadena de caracteres NO distingue mayusculas
        printf("\nClave correcta");
        printf("\nLa clave tiene %d letras", x);
    }
    else
    {
        printf("\nClave incorrecta");
        printf("\nLa clave tiene %d letras", x);
    }
    main();
*/
