/***************************
 * 
 *
 * 
 * 
 * 
 *
 * This program finds the minimum distance between
 * two numbers inside of an array.
 **************************/

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

int MinDistance(int A[], int n);

// Main function, finds the minimum distance between
// two numbers inside of an array.
int main(int argc, char *argv[])
{
   int arr[argc]; //Holds arr contents
   int i; 
   // Changes char values from command line to int 
   // values and stores in "arr".
   for(i = 1; i <= (argc - 1); i++)
   {
      arr[i-1] = atoi(argv[i]);
   }

   printf("%d\n", MinDistance(arr, argc));
   return 0;
}

// Function used to find minimum distance of an 
// array.
int MinDistance(int A[], int n)
{
   int dmin = INT_MAX;
   int i = 0;
   int j = 0;
   int count = 0;
   printf("%d\n", n);
   // Loops and statement used to find distance.
   for(i = 0; i < n; i++)
   {
      for(j = 1; j < n; j++)
      {
	 count++;
         if(i != j && (A[i] - A[j]) < dmin && (A[i] - A[j]) > 0)
         {      
            dmin = (A[i] - A[j]);
         }
      }
   }
  
   printf("%d\n", count);
   return dmin;
}
