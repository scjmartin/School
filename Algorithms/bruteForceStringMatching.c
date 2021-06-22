/******************************
 *
 *
 * Brute Force String Match
 *****************************/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void BruteForceStringMatch(char *P, char *T, int n, int m);

//main function
int main(int argc, char *argv[])
{
   int n = strlen(argv[1]);
   int m = strlen(argv[2]);
   char P[n];
   char T[m];
   strcpy(P, argv[1]);
   strcpy(T, argv[2]);

   BruteForceStringMatch(P, T, n, m);
  
   return 0;
}

//brute force string match function
void BruteForceStringMatch(char *P, char *T, int n, int m)
{
   int i = 0;
   int j = 0;
  
   printf("Matches found at locations:");

   for(i = 0; i <= m-n; i++)
   {
      for(j = 0; j < m; j++)
      {
         if(T[i+j] != P[j])
         {
            break;
         }
      }
      if(j == n)
      {
         printf(" %d", i);
      }
   }
   printf("\n");
}
  
