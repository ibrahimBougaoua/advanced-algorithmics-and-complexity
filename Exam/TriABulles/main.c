#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/****** tri Bulle *******/
// les valeurs de test [pire cas]
// 1000   = 0,005000
// 2000   = 0,020000
// 4000   = 0,089000
// 6000   = 0,176000
// 8000   = 0,311000
// 10000  = 0,501000
// 20000  = 2,287000
// 40000  = 7,842000
   
// les valeurs de test [meilleur cas]
// 400000    = 0,002000
// 800000    = 0,003000
// 1000000   = 0,005000
// 2000000   = 0,007000
// 4000000   = 0,014000
// 8000000   = 0,035000
// 10000000  = 0,036000

/****** tri Bulle Opt *******/
// les valeurs de test [pire cas]
// 1000   = 0,003000
// 2000   = 0,012000
// 4000   = 0,081000
// 6000   = 0,113000
// 8000   = 0,200000
// 10000  = 0,314000
// 20000  = 1,425000
// 40000  = 5,281000

// les valeurs de test [meilleur cas]
// 400000    = 0,001000
// 800000    = 0,003000
// 1000000   = 0,005000
// 2000000   = 0,008000
// 4000000   = 0,017000
// 8000000   = 0,032000
// 10000000  = 0,040000

// Fil Up Random
void FilUpRand(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
    {
	  t[i] = rand();
    }
}

// Fil Up Desc
void FilUpDesc(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
    {
	  t[i] = n-i;
    }
}

// Fil Up Asc
void FilUpAsc(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
	{
		t[i] = i;
    }
}

// Complexité dans le meilleur des cas
// 3 + 2 + 1 + 3*(n-1) + (n-1)
// 6 + 3*n - 3 + n - 1
// 4*n + 2

// Complexité dans le pire des cas
// 3 + n + 1 + n + 3*n*(n - 1) + 1 + 2*n*(n - 1) + 2*n*(n - 1) + 2*n*(n - 1) + n*(n - 1) + n*(n - 1)
// 3 + n + 1 + n + 3*n*n - 3*n + 1 + 2*n*n - 2*n + 2*n*n - 2*n + 2*n*n - 2*n + n*n - n + n*n - n
// 11*n*n - 4

// tri Bulle
void triBulle(int *t,int n){
    int i = 0,x = 0,permut =1; // 3
    while(permut){ // n + 1 // 2
        permut = 0; // n // 1
        for(i =0; i < n-1; i++){ // 3*n*(n - 1) + 1 // 3*(n-1)
            if(t[i] > t[i+1]){ // 2*n*(n - 1)           // (n-1)
                    x = t[i+1]; // 2*n*(n - 1)   // 0
                    t[i+1] = t[i]; // 2*n*(n - 1) // 0
					t[i] = x; // n*(n - 1)  // 0
                    permut = 1; // n*(n - 1)  // 0
            }
        }
    }
}

// Complexité dans le meilleur des cas
// 3 + 2 + 1 + 2 + 1 + 3*(n+1) + 2*n
// 5*n + 11 

// Complexité dans le pire des cas
// 3 + 2 + 1 + n + 1 + n + 3*n(n+1)/2 + 2*n(n+1)/2 + 2*n(n+1)/2 + 2*n(n+1)/2 + n(n+1)/2 + n(n+1)/2 + n
// 11*n(n+1)/2 + 3*n + 7

// tri Bulle Opt
void triBulleOpt(int *t,int n){
	int i = 0,x = 0,m; // 3
	m=n-1; // 2 
	int permut =1; // 1
	while(permut){ // m + 1 // 2
		permut = 0; // m // 1
        for(i =0; i < m; i++){ // 3*m(m+1)/2     // 3*(m + 1)
            if(t[i] > t[i+1]){ // 2*m(m+1)/2     // 2*m
                    x = t[i+1]; // 2*m(m+1)/2    // 0
                    t[i+1] = t[i]; // 2*m(m+1)/2 // 0  
					t[i] = x;   // m(m+1)/2   // 0
                    permut = 1; // m(m+1)/2   // 0
            }
        }
		m = m - 1; // m  // 1
	}
}

// Main
int main(int argc, char *argv[])
{
  int n,i;
  int *t;

  printf("Donner la taille N = ");
  scanf("%d",&n);
  t = (int *)malloc(n*sizeof(int));

  FilUpAsc(n,t); // fill up table

  // Calculate the time spent by primeNumber(n)
  clock_t begin = clock();
  
  //triBulle(t,n);
  triBulleOpt(t,n);
  
  clock_t end = clock();
  
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
  puts(" ");
  
  printf("Le temps d'execution est temps = %f seconds \n", time_spent); 

  /*
  for(i=0;i<n;i++)
  {
    printf("%d \n",t[i]);
  }
  */

  return 0;
}
