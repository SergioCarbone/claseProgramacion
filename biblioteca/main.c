#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
   int edad;
   edad = obtenerInt("Ingrese edad: ", "Error: Edad entre 0 y 100: ",100,0);

    return 0;
}
