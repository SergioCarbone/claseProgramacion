#include <stdio.h>
#include <stdlib.h>

#define LEGAJO 4


int main()
{
    int sueldo [LEGAJO], sueldoMax;
    int horasTrab [LEGAJO], catA = 50, catB = 100, catC =150, i;
    char sexo[LEGAJO], categoria[LEGAJO], nombre[20], apellido[20];

    for (i = 0; i< LEGAJO; i ++)
    {

        printf("Ingrese el nombre del empleado %d ", i+1);
        scanf("%s", nombre);

        printf("ingrese el apellido: ");
        scanf("%s", apellido);

        printf("Ingrese las horas trabajadas ");
        scanf("%d", &horasTrab[i]);

        printf("Ingrese el sexo de la persona, f/m: ");
        fflush (stdin);
        scanf("%c", &sexo[i]);

        while (sexo[i] != 'f' && sexo[i] != 'm')
        {
            printf("Error, ingrese sexo valido: ");
            fflush(stdin);
            scanf("%c", &sexo[i]);
        }

        printf("Ingrese la categoria: A-B-C: ");
        fflush(stdin);
        scanf("%c", &categoria[i]);

        while (categoria[i] != 'a' && categoria[i] != 'b' && categoria[i] != 'c')
        {
            printf("Error, Ingrese entre las categorias: A-B-C: ");
            fflush(stdin);
            scanf("%c", &categoria[i]);
        }

    }

    for (i=0; i<LEGAJO; i++)
    {
        if (categoria[i] == 'a')
        {
            sueldo[i] = horasTrab[i] * catA;
        }
        else if (categoria[i] == 'b')
        {
            sueldo[i] = horasTrab[i] * catB;
        }
        else
        {
            sueldo[i] = horasTrab[i] * catC;
        }
    }


    for (i=0; i<LEGAJO; i++)
    {
        if ( i == 0)
        {
            sueldoMax = sueldo[i];
        }
        else if (sueldoMax < sueldo[i])
        {
            sueldoMax = sueldo[i];
        }


    }
    printf("Nombre\tApellido\tLegajo\tSexo\tCategoria\ths\tsueldo\n");
    for(i = 0; i<LEGAJO; i++)
    {
        printf("%s\t%s\t\t%d\t%c\t%c\t\t%d\t%d\n",nombre, apellido, i+1, sexo[i], categoria[i], horasTrab[i], sueldo[i]);

    }
        printf("El sueldo maximo es: %d ",sueldoMax);




    return 0;
}
