#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define MAX 100


int main()
{
    int i;
    int num[MAX]= {60,55,3,94,16,47};
    int cantidad = 6;


    ordenarVector (num, cantidad);


    for (i = 0; i < cantidad; i++)
    {
        printf("\n %d", num[i]);
    }


    return 0;
}

