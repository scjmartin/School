/***************************
 *
 * 
 * This program uses a recursive algorithm to compute
 * 2^n for any nonnegative integer n based on the 
 * formula 2^n = 2^(n-1) + 2^(n-1)
 **************************/

#include "stdio.h"
#include "stdlib.h"

int two2TheN(int n);

//Takes input and prints results
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);

   printf("%d\n", two2TheN(n));

   return 0;
}

//Function that recursively calculates 2^n
//using 2^n = 2^(n-1)+2^(n-1)
int two2TheN(int n)
{
   int result;

   if(n == 1) //Base case
   {
      result = 2;
   }
   else       //Recursive case
   {
      result = (two2TheN(n-1) + two2TheN(n-1));
   }

   return result;
}
