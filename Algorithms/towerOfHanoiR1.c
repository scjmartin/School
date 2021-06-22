/********************
 *
 *
 * Tower of Hanoi 
 * Restriction: All movement must involve pin B
 *******************/

#include "stdio.h"
#include "stdlib.h"

void towerOfHanoi(int n, char A, char B, char C);

//Tower of Hanoi, main function
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   towerOfHanoi(n, 'A', 'B', 'C');
   return 0;
}

//Recursive algoritm for sorting the tower
void towerOfHanoi(int n, char A, char B, char C)
{
   if(n == 1)
   {
      printf("Move %c TO %c\n", A, B);
      printf("Move %c TO %c\n", B, C);
      return;
   }

   towerOfHanoi(n-1, A, B, C);
   printf("Move %c TO %c\n", A, B);
   towerOfHanoi(n-1, C, B, A);
   printf("Move %c TO %c\n", B, C);
   towerOfHanoi(n-1, A, B, C);
}
