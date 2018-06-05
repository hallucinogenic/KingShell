#include "shell.h"

/*

   calc.c – calcula uma operação entre dois números

*/

void calc(char *value1, char *op, char *value2)
{
  float v1 = atof(value1);
  float v2 = atof(value2);
  float resultado;
  /*
    O Operador pode ser:
      - Soma;
      - Subtração;
      - Multiplicação;
      - Divisão;
      - Exponencial;
  */

  if(0 == strcmp(op, "+"))
  {
    resultado = v1 + v2;
  }
  else if(0 == strcmp(op, "-"))
  {
    resultado = v1 - v2;
  }
  else if(0 == strcmp(op, "*"))
  {
    resultado = v1 * v2;
  }
  else if(0 == strcmp(op, "/"))
  {
    if(v2 == 0.0)
    {
      printf("%s Lamento, mas não é possível dividir por zero!\n", ERROR_PREFIX);
      return;
    }
    resultado = v1 / v2;
  }
  else if(0 == strcmp(op, "^"))
  {
    resultado = powf(v1, v2);
  }
  else
  {
    printf("%s Este operador não existe ou não é suportado por esta operação!\n", ERROR_PREFIX);
    return;
  }

  printf("%s %0.2f %s %0.2f = %0.2f\n", INFO_PREFIX, v1, op, v2, resultado);
}

void bits(char *op1, char *op, char *op2)
{
  int v1 = atoi(op1);
  int v2 = atoi(op2);
  int resultado;

  if(0 == strcmp(op, "&"))
  {
    resultado = v1 & v2;
  }
  else if(0 == strcmp(op, "^"))
  {
    resultado = v1 ^ v2;
  }
  else if(0 == strcmp(op, "|"))
  {
    resultado = v1 | v2;
  }
  else
  {
    printf("%s Este operador não existe ou não é suportado por esta operação!\n", ERROR_PREFIX);
    return;
  }

  printf("%s %d %s %d = %d\n", INFO_PREFIX, v1, op, v2, resultado);
}
