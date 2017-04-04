#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"

int main()
{
    float valorA = 0, valorB  = 0, resultadoDiv, resultadoSum, resultadoRes, resultadoMult;
    int opcion, respuestaA, flagA = 0, flagB = 0;
    char seguir='s';


        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");

        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);

        while (opcion < 0 || opcion > 8)
        {
            printf("\nError, elija entre las opiones del menu: ");
            scanf("%d", &opcion);
        }

        do
        {

            switch(opcion)
            {
            case 1:
                printf("Ingrese el primer operando: ");
                scanf("%f", &valorA);
                flagA = 1;
                break;
            case 2:
                printf("Ingrese el segundo operando: ");
                scanf("%f", &valorB);
                flagB = 1;
                break;
            case 3:
                if (flagA == 0 || flagB == 0)
                {
                    if (flagA == 0)
                    {
                        printf("Falta ingresar el primer operando, por favor reingrese: ");
                        scanf("%f", &valorA);
                        flagA = 1;
                    }
                    if ( flagB ==0)
                    {
                        printf("Falta ingresar el segundo operando, por favor reingrese: ");
                        scanf("%f", &valorB);
                        flagB = 1;
                    }
                }
                resultadoSum = suma(valorA, valorB);
                printf("El resultado de la suma entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoSum);
                break;
            case 4:
                if (flagA == 0 || flagB == 0)
                {
                    if (flagA == 0)
                    {
                        printf("Falta ingresar el primer operando, por favor reingrese: ");
                        scanf("%f", &valorA);
                        flagA = 1;
                    }
                    if ( flagB ==0)
                    {
                        printf("Falta ingresar el segundo operando, por favor reingrese: ");
                        scanf("%f", &valorB);
                        flagB = 1;
                    }
                }
                resultadoRes = resta(valorA, valorB);
                printf("El resultado de la resta entre %.2f y %.2f es: %.2f \n",valorA, valorB, resultadoRes);
                break;
            case 5:
                if (flagA == 0 || flagB == 0)
                {
                    if (flagA == 0)
                    {
                        printf("Falta ingresar el primer operando, por favor reingrese: ");
                        scanf("%f", &valorA);
                        flagA = 1;
                    }
                    if ( flagB ==0)
                    {
                        printf("Falta ingresar el segundo operando, por favor reingrese: ");
                        scanf("%f", &valorB);
                        flagB = 1;
                    }
                }
                if(valorB == 0)
                {
                    printf("No se puede dividir entre 0\n");
                    break;
                }
                resultadoDiv = dividir(valorA, valorB);
                printf("El resultado de la division entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoDiv);
                break;
            case 6:
                if (flagA == 0 || flagB == 0)
                {
                    if (flagA == 0)
                    {
                        printf("Falta ingresar el primer operando, por favor reingrese: ");
                        scanf("%f", &valorA);
                        flagA = 1;
                    }
                    if ( flagB ==0)
                    {
                        printf("Falta ingresar el segundo operando, por favor reingrese: ");
                        scanf("%f", &valorB);
                        flagB = 1;
                    }
                }
                resultadoMult = multiplicar(valorA, valorB);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoMult);
                break;
            case 7:
                if ( flagA == 0)
                {
                    printf("Falta ingresar el primer operando, por favor reingrese: ");
                    scanf("%f", &valorA);
                    flagA = 1;
                }
                if (validacionFactorial(valorA)==1)
                    {
                        respuestaA = factorial(valorA);
                        printf("El factorial de %.0f es: %d \n", valorA, respuestaA);
                        break;

                    }
                    else
                    {
                        printf("Error, introduzca un valor entero mayor o igual a 0 \n");
                        break;
                    }
            case 8:
                if (flagA == 0 || flagB == 0)
                {
                    if (flagA == 0)
                    {
                        printf("Falta ingresar el primer operando, por favor reingrese: ");
                        scanf("%f", &valorA);
                        flagA = 1;
                    }
                    if ( flagB == 0)
                    {
                        printf("Falta ingresar el segundo operando, por favor reingrese: ");
                        scanf("%f", &valorB);
                        flagB = 1;
                    }
                }
                if(valorB == 0)
                {
                    printf("No se puede dividir entre 0\n");
                }
                else
                {
                    resultadoDiv = dividir(valorA, valorB);
                    printf("El resultado de la division entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoDiv);
                }

                resultadoSum = suma(valorA, valorB);
                printf("El resultado de la suma entre %.2f y %.2f es : %.2f\n",valorA, valorB, resultadoSum);

                resultadoRes = resta(valorA, valorB);
                printf("El resultado de la resta entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoRes);

                resultadoMult = multiplicar(valorA, valorB);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoMult);

                if (validacionFactorial(valorA)==1)
                {
                    respuestaA = factorial(valorA);
                    printf("El factorial de %0.f es: %d \n", valorA, respuestaA);
                    break;

                }
                else
                {
                    printf("Error, introduzca un valor entero mayor o igual a 0 \n");
                    break;
                }
        case 9:
            seguir = 'n';
            break;
        }

            do
            {
                printf("\n1- Ingresar 1er operando (A= %.2f)\n", valorA);
                printf("2- Ingresar 2do operando (B= %.2f)\n", valorB);
                printf("3- Calcular la suma (%.2f + %.2f)\n",valorA, valorB);
                printf("4- Calcular la resta (%.2f - %.2f)\n",valorA, valorB);
                printf("5- Calcular la division (%.2f / %.2f)\n",valorA, valorB);
                printf("6- Calcular la multiplicacion (%.2f * %.2f)\n",valorA, valorB);
                printf("7- Calcular el factorial (!%d)\n", (int)valorA);
                printf("8- Calcular todas las operaciones\n");
                printf("9- Salir\n");

                printf("\nIngrese una opcion: ");
                scanf("%d",&opcion);

                switch (opcion)
                {
                case 1:
                    printf("Ingrese el nuevo valor para el primer operando: ");
                    scanf("%f", &valorA);
                    flagA = 1;
                    break;
                case 2:
                    printf("Ingrese el nuevo valor para el segundo operando: ");
                    scanf("%f", &valorB);
                    flagB = 1;
                    break;
                case 9:
                    seguir = 'n';
                    break;
                }

            }while (opcion == 1 || opcion == 2);



        }while(seguir=='s');


        return 0;
    }
