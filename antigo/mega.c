#include <stdio.h>
#include <string.h>

#define MAX_NUMEROS 15

int
exp2(const int n)
{
  return (n > 0 ? 2 * exp2(n - 1) : 1);
}

/**
 * Retorna o resultado da soma binária de cada número apostado.
 */
int
aposta(const int nums[], const int qtd)
{
  int i, res = 0;
  for (i = 0; i < qtd; i++)
    res += exp2(nums[i] - 1);
  return res;
}

int
apostar(int *nums[], const char *ns)
{
  char *tk, *ps;
  char cns[3 * MAX_NUMEROS];
  int pos = 0, qtd = 1;

  printf("{%s} ", ns);

  memset(nums, 0, MAX_NUMEROS);
  strcpy(cns, ns);

  if (!(tk = strtok(cns, ",")))
    return 0;

  nums[0] = atoi(tk);

  while ((tk = strtok(NULL, ",")))
  {
    nums[++pos] = atoi(tk);
    qtd++;
  }

  return qtd;
}

/**
 * Retorna a quantidade de acertos da aposta com relação ao número sorteado.
 */
int
acertos(const int sorteado, const int aposta)
{
  const int and = sorteado & aposta;
  int i, res = 0, bin = 1;
  for (i = 0; i < 60; i++, bin *= 2)
    if (bin & and)
      res++;
  return res;
}

#define APOSTA(NUMS) {\
  qtd = apostar(&nums, NUMS);\
  num = aposta(nums, qtd);\
  ace = acertos(nso, num);\
  printf("num = %d => %d\n", num, ace);\
}

int
main()
{
  int qtd, num, nso, ace;
  int sorteio[6], nums[MAX_NUMEROS];

  qtd = apostar(&sorteio, "1,2,3,4,5,6");
  nso = aposta(sorteio, qtd);
  printf("nso = %d\n\n", nso);

  // sena
  APOSTA("1,2,3,4,5,6");
  APOSTA("1,2,3,4,5,6,7");
  APOSTA("1,2,3,4,5,6,7,8");
  printf("\n");

  // quina
  APOSTA("2,3,4,5,6,7");
  APOSTA("2,3,4,5,6,7,8");
  APOSTA("2,3,4,5,6,7,8,9");
  APOSTA("1,3,4,5,6,7");
  APOSTA("1,3,4,5,6,7,8");
  APOSTA("1,3,4,5,6,7,8,9");
  APOSTA("1,2,4,5,6,7");
  APOSTA("1,2,3,5,6,7");
  APOSTA("1,2,3,4,6,7");
  APOSTA("1,2,3,4,6,8");
  APOSTA("1,2,3,4,5,7");
  APOSTA("1,2,3,4,5,8");
  printf("\n");

  // quadra
  APOSTA("3,4,5,6,7,8");
  APOSTA("3,4,5,6,7,8,9");
  APOSTA("3,4,5,6,7,8,10");
  APOSTA("2,3,4,5,7,8");
  APOSTA("2,3,4,5,7,8,9");
  APOSTA("2,3,4,5,7,8,9,10");
  APOSTA("1,3,4,5,7,8");
  APOSTA("1,3,4,5,7,8,10,11");
  APOSTA("1,3,4,5,7,8,10,11,12");
  printf("\n");

  // trinca
  APOSTA("1,2,3,13,25,46");
  APOSTA("1,2,3,24,33,48,55");
  APOSTA("1,2,3,17,22,36,49,59");
  APOSTA("3,4,5,16,22,31");
  APOSTA("3,4,5,28,39,51,60");
  APOSTA("3,4,5,18,29,32,44,56");
  printf("\n");

  return 0;
}
