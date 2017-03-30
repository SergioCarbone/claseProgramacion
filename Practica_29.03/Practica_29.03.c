float prom ( int array[], int cantidad)
{

    int suma = 0, i;
    float promedio;

    for ( i = 0; i < cantidad; i ++)
    {
        suma = suma + array[i];
    }

    promedio = (float) suma / cantidad;

    return promedio;
}

int maximo (int array [], int cantidad)
{
    int max, cont = 0, i;
    for ( i = 0; i < cantidad; i ++)
    {
        if ( max < array[i] || cont == 0)
        {
            max = array[i];
              cont++;
        }

    }

        return max;
}

int minimo ( int array [], int cantidad)
{
    int min, cont = 0, i;
    for( i = 0; i < cantidad; i ++)
    {
        if (min > array[i] || cont == 0)
        {
            min = array[i];
            cont++;
        }

    }

      return min;
}

int comparacion(int array [], int cantidad)
{
    int maxProm[CANTIDAD], edad, minProm[CANTIDAD], flagA, flagB, i;

    for( i = 0; i < cantidad; i ++)
    {

    if (array[i] > prom() || flagA == 0)
    {
        maxProm[i] = edad;
        flagA = 1;
    }
    if (edad < prom() || flagB == 0)
    {
        minProm[i] = edad;
        flagB = 1;
    }
  }
}
