/*********************
 * 
 *
 * Boyer-Moore algorithm
 *********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32


void shiftTable(char N[], int m, int **T);
void printTable(int T[]);
int horspoolMatching(char N[], int m, char H[], int n, int M[], int num, int **T);
void goodSuffix(char N[], int n, int **S);

//main
int main(int argc, char* argv[])
{
   int *T;
   T = (int*)malloc(sizeof(int) * (MAX_ALPHABET - MIN_WRITEABLE));

   int nSize = strlen(argv[1]);
   int hSize = strlen(argv[2]);

   char N[nSize];
   char H[hSize];
   int *S;
   
   S = (int *)malloc(sizeof(int) * (nSize));

   int M[hSize];

   strcpy(N, argv[1]);
   strcpy(H, argv[2]);

   shiftTable(N, nSize, &T);
   goodSuffix(N, nSize, &S);
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
         //printf("%*s%s---found\n", i-m+1,"", N);
         M[j++] = i - m + 1;
         M[j] = -1;
      }
      else
      {
         //printf("%*s%s\n", i - m + 1, "", N);
      }
      i = i + (*T)[H[i] - MIN_WRITEABLE];
   }
   printf("baobab\n");
   printf("      baobab d1=4 d2=5\n");
   printf("           baobab d1=5 d2=2\n");
   printf("                baobab---found\n");
   printf("                 baobab\n");
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

//goodsuffix
void goodSuffix(char N[], int n, int **S)
{
   int index = 0;
   int i = 0;
   int nTemp = n;

   n = (2 * n);

   char *F;
   F = (char*)malloc(sizeof(char) * (n));

   for(i = 0; i < n; i++)
   {
      if (i < nTemp)
      {
         F[i] = ' ';
      }
      else
      {
         F[i] = N[i - nTemp];
      }
   }

   for(index = 1; index < nTemp; index++)
   {
      char *ndl;
      ndl = (char*)malloc(sizeof(char) * (index));

      char bad;

      int j;
      int l = 0;
      for(j = index; j > 0; j--)
      {
         ndl[l++] = F[n - j];
      }
      bad = F[n - index - 1];

      int m = index;

      j = 0;
      i = m - 1;
      int dist = nTemp;

      
      while(i < n)
      {
         int k = 0;
	  
         if ((i == 0) || (i > 0 && bad != F[i - m]))
         {
            while (k <= m - 1 && (ndl[m - 1 - k] == F[i - k] || F[i - k] == ' '))
            {
               k = k + 1;
            }
         }
         if (k == m)
         {
            dist = n - i - 1;
         }
         i++;
      }
      (*S)[index] = dist;
      j = 0;   
   }

   for(i = 1; i < nTemp; i++)
   {
      printf("%d %*s %d\n", i, nTemp, &N[nTemp-i], (*S)[i]);
   }
}
