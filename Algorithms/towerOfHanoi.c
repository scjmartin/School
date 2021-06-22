/********************
 * 
 *
 * Tower of Hanoi
 *******************/

#include "stdio.h"
#include "stdlib.h"

void towerOfHanoi(int n, char A, char B, char C);
int count = 0;

//Tower of Hanoi, main function
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   towerOfHanoi(n, 'A', 'C', 'B');
   printf("%d\n", count);
   return 0;
}

//Recursive algoritm for sorting the tower
void towerOfHanoi(int n, char A, char B, char C)
{
   if(n > 0)
   {
      towerOfHanoi(n-1, A, C, B);
      printf("Move %c TO %c\n", A, B);
      count++;
      towerOfHanoi(n-1, C, B, A);
   }
}
