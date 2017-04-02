int validacionFactorial (float numero)
{
    if(numero<0)
    {
        return 0;
    }
    else
    {
        int ent=(int)numero;
        if( (numero-ent) ==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int validarOperaciones (int flagA, int flagB)
{
    int resultado;
    if (flagA == 0 && flagB == 0)
    {
        resultado = 1;
        return resultado;
    }
    else if (flagA == 0 && flagB == 1)
    {
        resultado = 2;
        return resultado;
    }
    else if (flagA == 1 && flagB == 0)
    {
        resultado = 3;
        return resultado;
    }
    else
    {
        resultado = 4;
        return resultado;
    }

}

