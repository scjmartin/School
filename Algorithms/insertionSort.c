/*****************************
 *
 *
 * Insertion Sort Algorithm
 *****************************/

#include "stdlib.h"
#include "stdio.h"

void insertionSort(int A[], int n);
void printArray(int A[], int n);

int count = 1;

int main(int argc, char *argv[])
{
   int i = 0;
   int A[argc-1];
   for(i = 1; i < argc; i++)
   {
      A[i-1] = atoi(argv[i]);
   }

   insertionSort(A, argc-1);

   return 0;
}

void printArray(int A[], int n)
{
   int i =0;
   for(i = 0; i < count; i++)
   {
      printf("%d ", A[i]);
   }
   printf("| ");
   for(i = i; i < n; i++)
   {
      printf("%d ", A[i]);
   }
   printf("\n");
}

void insertionSort(int A[], int n)
{
   printArray(A, n);

   int i;
   int j;
   int v;

   for(i = 1; i < n; i++)
   {
      v = A[i];
      j = i - 1;
      while(j >= 0 && A[j] > v)
      {
         A[j+1] = A[j];
         j = j - 1;
      }
      A[j+1] = v;
      count++;
      printArray(A, n);
   }
}
