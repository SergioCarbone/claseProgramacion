#include <stdio.h>
#include <stdlib.h>



int main()
{
    int numero;
    char respuesta;
    int contaPar = 0;
    int contaImpar = 0;

    do{
        printf("ingrese numero: ");
        scanf("%d", &numero);

        while ( numero < 0)
        {
            printf("error, reigrese: ");
            scanf("%d", &numero);
        }
        if (numero %2 == 0)
        {
            contaPar++;
        }
        else
        {
            contaImpar++;
        }

        printf("continual: ");
        scanf(" %c", &respuesta);

        }while(respuesta == 's');

        printf("contador par: %d", contaPar);
        printf("contador impar %d", contaImpar);
}


