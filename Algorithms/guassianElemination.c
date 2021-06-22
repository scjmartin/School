/*********************************
 * 
 *
 * This program solves a system of linear equations
 * by using Guassian elimination
 *********************************/

#include "stdio.h"
#include "stdlib.h"

void printMatrix(int n, float A[n][n+1], int a);

//main function
int main(int argc, char *argv[])
{
   int n = atoi(argv[1]);
   int i = 0;
   int j = 0;
   int k = 0;
   int a = 0;
   int b = 0;
   int c = 0;
   int tempji = 0;
   float A[n][n+1];

   for(i = 0; i <= argc-3; i++)
   {
      if(j == n+1)
      {
         j = 0;
         k++;
         printf("\n");
      }
      A[j][k] = atoi(argv[i+2]);
      printf("%.2f ", A[j][k]);
      j++;
   }
   printf("\n\n");
   
   for(a = 0; a <= n-2; a++)
   {
      for(b = a+1; b <= n-1; b++)
      {
         tempji = A[b][a];
         for(c = a; c <= n; c++)
         {
            A[b][c] = A[b][c] - (A[a][c] * tempji / A[a][a]);
         }
      }
      printMatrix(n, A, argc-3);
   }
   return 0;
}

//Prints matrix
void printMatrix(int n, float A[n][n+1], int a)
{
   int i = 0;
   int j = 0;
   int k = 0;

   for(i = 0; i <= a; i++)
   {
      if(j == n+1)
      {
         j = 0;
         k++;
         printf("\n");
      }
      printf("%.2f ", A[j][k]);
      j++;
   }
   printf("\n\n");
}
