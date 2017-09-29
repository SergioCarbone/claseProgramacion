#include <stdio.h>
#include <stdlib.h>
#include "Entidad1.h"
#include "Entidad2.h"
#define LONGITUD_ENTIDAD1 50
#define LONGITUD_ENTIDAD2 50

int main()
{
    sEntidad1 arrayEntidades1[LONGITUD_ENTIDAD1];
    sEntidad2 arrayEntidades2[LONGITUD_ENTIDAD2];

    ent1_init(arrayEntidades1, LONGITUD_ENTIDAD1);
    ent2_init(arrayEntidades2, LONGITUD_ENTIDAD2);

    printf("Hello world!\n");
    return 0;
}
