float multiplicar(float a, float b)
{
    float total;
    total = a * b;
    return total;
}

float resta( float a, float b)
{
    float total;
    total = a - b;
    return total;
}

float suma ( float a, float b)
{
    float total;
    total = a + b;
    return total;
}

float dividir ( float a, float b)
{
    float total;
    total = a / b;

    return total;
}

int factorial (enteroA)
{
    int i;
    int respuestaA = 1;

    if ( enteroA == 1)
    {
        return 1;
    }
    else
    {
        for ( i = enteroA ; i > 1; i--)
        {
            respuestaA = respuestaA * i;

        }
        return respuestaA;
    }

}

int compactar(int array[], int size, int indice)
{
    for ( ;indice < size-1; indice++)
        array[indice] = array[indice+1];
    return size - 1;
}

int calcularIndiceMinimo(int array[], int size)
{
    int indice=1;
    int minimo = array[0];
    int indiceMinimo = 0;
    for ( ;indice < size; indice++)
    {
       if(array[indice] < minimo)
       {
           minimo = array[indice];
           indiceMinimo = indice;
       }

    }
    return indiceMinimo;
}

float promedio(int edad[], int cantidad){

    float retornoPromedio;
    int i, suma=0;

    for(i=0;i<cantidad;i++){
        suma=suma+edad[i];
    }
    retornoPromedio=(float)suma/cantidad;

    return retornoPromedio;
}



