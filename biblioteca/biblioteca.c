int obtenerInt(char mensaje [], char mensajeError [], int maximo, int minimo)
{
    int buffer;
    printf(mensaje);
    scanf("%d", &buffer);

    while ( buffer > 100 || buffer < 0)
    {
        printf(mensajeError);
        scanf("%d", &buffer);
    }

}
