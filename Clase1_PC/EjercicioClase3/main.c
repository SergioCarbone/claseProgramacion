#include <stdio.h>
#include <stdlib.h>
float numero ();
float AreaCirculo (float a);

int main()
{
    float a, num;

    num = numero();
    a = AreaCirculo(num);

    printf("\nEl area del circulo es: %.2f", a);

    return 0;
}

float numero()
{
    float radio;

    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);

    return radio;
}

float AreaCirculo (float a)
{
    float area = 3.14 * a * a;

    return area;
}
