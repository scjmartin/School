/******************************
 *
 *
 * Permutations Algorithm
 *****************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y);
void permute(char *A, int left, int right, int length);

//main
int main(int argc, char* argv[])
{
   int p = atoi(argv[1]);
   char *pList = (char*)malloc(sizeof(char)*p);
   int i = 0;

   for (i = 1; i < p + 1; i++)
   {
      pList[i] = i + '0';
   }

   permute(pList, 0, p, p);
   return 0;
}

//swap
void swap(char *x, char *y)
{
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

//permute
void permute(char *A, int left, int right, int length)
{
   int i;
   if (left == right && strlen(A) == length)
   {
      printf("%s\n", A);
   }
   else
   {
      for (i = left; i <= right; i++)
      {
         swap((A+left), (A+i));
         permute(A, left+1, right, length);
         swap((A+left), (A+i));
      }
   }
}
