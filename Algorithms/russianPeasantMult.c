/**************************************
 * 
 *
 * Russian Peasant Multiplication
 *************************************/
#include "stdio.h"
#include "stdlib.h"

void print(int x, int y, int sum);
void russianPeasant(int x, int y, int sum);

int main(int argc, char *argv[])
{
   if(argc > 3)
   {
      printf("To many inputs (Aborted)\n");
      return 0;
   }
   int x = atoi(argv[1]);
   int y = atoi(argv[2]);
   russianPeasant(x, y, 0);
   return 0;
}

void print(int x, int y, int sum)
{
   printf("%6d %6d", x, y);
   if((x%2) != 0)
   {
      printf(" %6d", y);
   }
   if(x == 1)
   {
      printf("\n");
      printf("%20s\n", "------");
      printf("%20d\n", sum);
   }
   else
   {
      printf("\n");
   }
}

void russianPeasant(int x, int y, int sum)
{
  if((x%2) != 0)
   {
      sum = sum + y;
   }
   print(x, y, sum);
   if(x != 1)
   {
      x = x/2;
      y = y*2;
      russianPeasant(x, y, sum);
   }
}
