#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "Validaciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1=0;
    float num2=0;
    float resultado;
    int resultadoFactorial;
    int flagN1=0;
    int flagN2=0;

    printf("\n1- Ingresar 1er operando (A= x)\n");
    printf("2- Ingresar 2do operando (B= y)\n");
    printf("3- Calcular la suma (A + B)\n");
    printf("4- Calcular la resta (A - B)\n");
    printf("5- Calcular la division (A / B)\n");
    printf("6- Calcular la multiplicacion (A x B)\n");
    printf("7- Calcular el factorial (!A)\n");
    printf("8- Calcular todas las operaciones\n");
    printf("9- Salir\n");

    printf("\nIngrese una opcion: ");
    scanf("%d",&opcion);

    do
    {
        if(opcion==9)
            break;
        while(opcion<0 || opcion>9)
        {
            printf("Opcion invalida, elija una opcion entre el 1 y el 8, o 9 para salir: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
        case 1:
            printf("\nIngrese el 1er nro con el que desea operar: ");
            scanf("%f",&num1);
            flagN1=1;
            break;
        case 2:
            printf("\nIngrese el 2do nro con el que desea operar: ");
            scanf("%f",&num2);
            flagN2=1;
            break;
        case 3:
            if(numeroEsInvalido(flagN1,1))
            {
                num1=tomarValor();
                flagN1=1;
            }
            if(numeroEsInvalido(flagN2,2))
            {
                num2=tomarValor();
                flagN2=1;
            }
            resultado=suma(num1,num2);
            printf("\nEl resultado de la suma es: %.2f\n",resultado);
            break;
        case 4:
            if(numeroEsInvalido(flagN1,1))
            {
                num1=tomarValor();
                flagN1=1;
            }
            if(numeroEsInvalido(flagN2,2))
            {
                num2=tomarValor();
                flagN2=1;
            }
            resultado=resta(num1,num2);
            printf("\nEl resultado de la resta es: %.2f\n",resultado);
            break;
        case 5:
            if(numeroEsInvalido(flagN1,1))
            {
                num1=tomarValor();
                flagN1=1;
            }
            if(numeroEsInvalido(flagN2,2))
            {
                num2=tomarValor();
                flagN2=1;
            }
            while(num2==0)
            {
                printf("El divisor no puede ser 0, ingrese nuevamente: ");
                scanf("%f",&num2);
            }
            resultado=division(num1,num2);
            printf("El resultado de la division es: %.2f\n",resultado);
            break;
        case 6:
            if(numeroEsInvalido(flagN1,1))
            {
                num1=tomarValor();
                flagN1=1;
            }
            if(numeroEsInvalido(flagN2,2))
            {
                num2=tomarValor();
                flagN2=1;
            }
            resultado=multiplicacion(num1,num2);
            printf("El resultado de la multiplicacion es: %.2f\n",resultado);
            break;
        case 7:
            if(esEntero(num1)==1)
            {
                resultadoFactorial=factorial(num1);
                printf("El factorial del numero ingresado es: %d\n",resultadoFactorial);

            }
            else
            {
                printf("No se puede calcular factorial de un numero negativo o un numero con decimal\n");

            }
            break;
        case 8:
            if(numeroEsInvalido(flagN1,1))
            {
                num1=tomarValor();
                flagN1=1;
            }
            if(numeroEsInvalido(flagN2,2))
            {
                num2=tomarValor();
                flagN2=1;
            }
            while(num2==0)
            {
                printf("El divisor no puede ser 0, ingrese nuevamente: ");
                scanf("%f",&num2);
            }
            resultado=suma(num1,num2);
            printf("\nEl resultado de la suma es: %.2f",resultado);

            resultado=resta(num1,num2);
            printf("\nEl resultado de la resta es: %.2f\n",resultado);

            resultado=division(num1,num2);
            printf("El resultado de la division es: %.2f\n",resultado);

            resultado=multiplicacion(num1,num2);
            printf("El resultado de la multiplicacion es: %.2f\n",resultado);

            if(esEntero(num1)==1)
            {
                resultadoFactorial=factorial(num1);
                printf("El factorial del numero ingresado es: %d\n",resultadoFactorial);

            }
            else
            {
                printf("No se puede calcular factorial de un numero negativo o un nunmero con decimal\n");

            }
            break;
        case 9:
            seguir = 'n';
            break;
        }
        printf("\n1- Ingresar 1er operando (A= %.2f)\n",num1);
        printf("2- Ingresar 2do operando (B= %.2f)\n",num2);
        printf("3- Calcular la suma (%.2f + %.2f)\n",num1,num2);
        printf("4- Calcular la resta (%.2f - %.2f)\n",num1,num2);
        printf("5- Calcular la division (%.2f / %.2f)\n",num1,num2);
        printf("6- Calcular la multiplicacion (%.2f x %.2f)\n",num1,num2);
        printf("7- Calcular el factorial (!%d)\n",(int)num1);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        printf("\n \nIngrese la opcion deseada: ");
        scanf("%d",&opcion);

    }
    while(seguir=='s');
    return 0;
}
