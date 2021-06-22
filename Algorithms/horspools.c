/***********************************
 *
 *
 * Horspool's algorithm
 **********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32


void shiftTable(char N[], int m, int **T);
void printTable(int T[]);
int horspoolMatching(char N[], int m, char H[], int n, int M[], int num, int **T);

int main(int argc, char* argv[])
{
   int *T;
   T = (int*)malloc(sizeof(int) * (MAX_ALPHABET - MIN_WRITEABLE));

   int nSize = strlen(argv[1]);
   int hSize = strlen(argv[2]);

   char N[nSize];
   char H[hSize];

   int M[hSize];

   strcpy(N, argv[1]);
   strcpy(H, argv[2]);

   shiftTable(N, nSize, &T);
   horspoolMatching(N, nSize, H, hSize, M, hSize, &T);

   return 0;
}

//shift table
void shiftTable(char N[], int m, int **T)
{
   int i = 0;
   for (i = 0; i <= MAX_ALPHABET - MIN_WRITEABLE; i++)
   {
      (*T)[i] = m;
   }
   for (i = 0; i <= m - 2; i++)
   {
      (*T)[N[i] - MIN_WRITEABLE] = m - 1 - i;
   }
   printTable(*T);
}

//horsepool matching
int horspoolMatching(char N[], int m, char H[], int n, int M[], int num, int **T)
{
   int k = 0;
   int j = 0;
   printf("%s\n", H);
   int i = m - 1;
  
   while(i <= n - 1)
   {
      k = 0;
      while(k <= m - 1 && N[m - 1 - k] == H[i - k])
      {
         k = k + 1;
      }
      if(k == m)
      {
         printf("%*s%s---found\n", i-m+1,"", N);
         M[j++] = i - m + 1;
         M[j] = -1;
      }
      else
      {
         printf("%*s%s\n", i - m + 1, "", N);
      }
      i = i + (*T)[H[i] - MIN_WRITEABLE];
   }
   printf("Matches found at locations:");
   j = 0;
   while(M[j] != -1)
   {
      printf(" %d", M[j++]);
   }
   printf("\n");
   return -1;
}

//print
void printTable(int T[])
{
   int i = 0;
   int start = 0;
   for(start = MIN_WRITEABLE; start < MAX_ALPHABET; start+=TABLE_ROW_LENGTH)
   {
      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%c\t", i);
      }
      printf("\n");

      for(i = start; i < start+TABLE_ROW_LENGTH; i++)
      {
         printf("%d\t", T[i - MIN_WRITEABLE]);
      }
      printf("\n\n");
   }
}
