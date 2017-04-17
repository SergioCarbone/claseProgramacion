#include <stdio.h>
#include <stdlib.h>

/*Escribir  un programa que realice las siguientes acciones
1. Limpie la pantalla
2. Asigne a 2 variables numero1 y numero2 valores distintos de cero
3. Efectœe el producto de dichas variables
4. Muestre el resultado pos pantalla
Obtenga el cuadrado de numero1 y lo muestre par pantalla*/


int main(int argc, char *argv[]) {

	int a, b, cuadrado, producto, resta;

	system("cls");

	do{
	printf("\nIngrese el 1\247 numero: ");
	scanf("%d",&a);
	printf("_________________________\n");

	if(a==0)
    {
        printf("\nIngrese un valor mayor a 0\n");
        printf("______________________\n");
    }
	}while(a==0);

	do{
        printf("\nIngrese el 2\247 numero: ");
        scanf("%d", &b);
        printf("__________________________\n");

        if(b==0)
        {
            printf("\nIngrese un valor mayor a 0\n");
            printf("________________________\n");
        }

	}while(b==0);

	producto = a*b;
	cuadrado = a*a;
	resta = a-b;

	printf("\nEl 1\247 numero es: %d\n\nEl 2\247 numero es: %d\n\nEl producto de %d*%d es: %d\n\nEl cuadrado de %d es: %d\n\n", a,b,a,b,producto,a,cuadrado);
	if(resta < 0)
    {
        printf("La resta de %d-%d es: %d\n\nResultado negativo.\n\n",a,b,resta);
    }
    else
    {
        printf("La resta de %d-%d es: %d\n\nResultado positivo.\n\n",a,b,resta);
    }



	return 0;
}

/*
int a;
	int b;
	int producto;
	int cuadrado;

	system("?");

	do{
	printf("\nIngrese 1\247 numero: ");
	scanf("%d",&a);
	printf("______________________________________\n");
		if(a==0)
		{
            printf("\nIngrese numero mayor a 0\n");
            printf("______________________________________\n");
		}
    }while(a==0);

	do{
	printf("\nIngrese 2\247 numero: "); // \247 asigna el signo º al numero
	scanf("%d",&b);
	printf("______________________________________\n");
		if(b==0)
		{
		printf("\nIngrese numero mayor a 0\n");
		printf("______________________________________\n");
		}
    }while(b==0);

	producto=a*b;
	cuadrado=a*a;

	printf("\nEl valor 1\247: %d\nEl valor 2\247: %d\n\nEl producto es: %d\n\nEl cuadrado del 1\247 valor %d es: %d \n",a,b,producto,a,cuadrado);
	printf("______________________________________\n\n\n\n");


*/
