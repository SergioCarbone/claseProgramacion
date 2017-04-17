float numeroEsInvalido(int flag, int n)
{
    if (flag==0)
    {
        printf("\nDebe ingresar el operando nro %d para realizar el calculo seleccionado: ",n);
        return 1;
    }
    else
        return 0;
}

float tomarValor()
{
    float num;
    scanf("%f",&num);
    return num;
}

int esEntero(float n)
{
    int entero;
    if(n<0)
    {
        return 0;
    }
    else
    {
        entero=(int)n;
        if(n-entero!=0)
        {
            return 0;
        }
        else
            return 1;
    }

}
