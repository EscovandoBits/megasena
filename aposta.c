#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mega.h"

#define HASH(NUMS) {\
  qtd = str2nums(&nums, NUMS);\
  hash = hash_aposta(nums, qtd);\
  printf("[%s]\n", NUMS);\
  printf("qtd = %2d, hash = %llu\n\n", qtd, hash);\
}

int main()
{
  int8 hash = 0;
  int8 nums[MAX_NUMEROS], qtd = 0;

/*
  qtd = str2nums(&nums, "1,2,3");
  printf("qtd = %2d\n", qtd);
  printf("nums[0] = %2d\n", nums[0]);
  printf("nums[1] = %2d\n", nums[1]);
  printf("nums[2] = %2d\n", nums[2]);
  printf("nums[3] = %2d\n", nums[3]);
  printf("nums[4] = %2d\n", nums[4]);
  hash = hash_aposta(nums, qtd);
  printf("qtd = %2d, hash = %llu\n", qtd, hash);
*/

  HASH("1");
  HASH("2");
  HASH("3");
  HASH("4");

  HASH("57");
  HASH("58");
  HASH("59");
  HASH("60");

  HASH("31,32");
  HASH("60,59");

  HASH("1,2,3,4,5,6");
  HASH("55,56,57,58,59,60");
  HASH("46,47,48,49,50,51,52,53,54,55,56,57,58,59,60");

  return 0;
}
