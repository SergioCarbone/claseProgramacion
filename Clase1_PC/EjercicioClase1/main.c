#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a,positivo = 0,negativo = 0,i;

  for(i=0;i<10;i++)
  {
      printf("Ingrese el %d\247 de los 10 numeros: ", i+1);
      scanf("%d", &a);

      if(a < 0)
      {
          negativo++;
      }
      else
      {
          positivo++;
      }
  }
  printf("\nSe ingresaron %d numeros negativos\n\nSe ingresaron %d numeros positivos\n\n", negativo, positivo);

    return 0;
}
