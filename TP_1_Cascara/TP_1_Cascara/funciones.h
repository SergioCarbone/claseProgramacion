#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED
float dividir ( float a, float b);
    float suma ( float a, float b);
    float resta( float a, float b);
    float multiplicar(float a, float b);
    int factorial (int enteroA);


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

    if(b == 0)
    {
        return 0;
    }
    else
    {
        total = a / b;
    }
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
