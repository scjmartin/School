/********************
 *
 *
 * Tower of Hanoi
 * Restriction: A must only move to B
 *              B must only move to C
 *              C must only move to A
 *******************/
#include "stdio.h"
#include "stdlib.h"

void towerOfHanoi(int n, char A, char B, char C);
void swapA(int n, char A, char B, char C);

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
   swapA(n-1, C, B, A);
   printf("Move %c TO %c\n", B, C);
   towerOfHanoi(n-1, A, B, C);
}

//function that adds restriction
void swapA(int n, char C, char B, char A)
{
   if(n == 1)
   {
      printf("Move %c TO %c\n", C, A);
      return;
   }

   towerOfHanoi(n-1, C, A, B);
   printf("Move %c TO %c\n", C, A);
   towerOfHanoi(n-1, B, C, A);
   return;
}
