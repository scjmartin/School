/**************************
 * 
 *
 * Selection sort algorithm
 **************************/

#include "stdio.h"
#include "stdlib.h"

void selectionSort(int A[], int n);
void printArray(int A[], int n);
void swap(int *xp, int *yp);

//Main function
int main(int argc, char *argv[])
{
   int i = 0;
   int A[argc-1];
   for(i = 1; i < argc; i++)
   {
      A[i-1] = atoi(argv[i]);
   }
   printArray(A, argc);
   selectionSort(A, argc);

   return 0;
}

//Function prints array contents
void printArray(int A[], int n)
{
   int i = 0;
   for(i = 0; i < n-1; i++)
   {
      printf("%d ", A[i]);
   }
   printf("\n");
}

//Function swaps values in array
void swap(int *xp, int *yp)
{
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

//Function uses selection sort algorithm to sort array
void selectionSort(int A[], int n)
{
   int i = 0;
   int j = 0;
   int min = 0;
   for(i = 0; i < n-2; i++)
   {
      min = i;
      for(j = i+1; j < n-1; j++)
      {
         if(A[j] < A[min])
         {
            min = j;
         }
      }
      swap(&A[min], &A[i]);
      printArray(A, n);
   }
}
	 
