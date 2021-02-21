#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// tri Bulle
void triBulle(int *t,int n){
    int i = 0,x = 0,permut =1;
    while(permut ){
        permut = 0;
        for(i =0; i < n-1; i++){
            if(t[i] > t[i+1]){
                    x = t[i+1];
                    t[i+1] = t[i];
					t[i] = x;
                    permut = 1;
            }
        }
    }
}

// tri Bulle Opt
void triBulleOpt(int *t,int n){
	int i = 0,x = 0,m;
	m=n-1;
	int permut =1;
	while(permut){
		permut = 0;
        for(i =0; i < m; i++){
            if(t[i] > t[i+1]){
                    x = t[i+1];
                    t[i+1] = t[i];
					t[i] = x;
                    permut = 1;
            }
        }
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

  FilUpRand(n,t); // fill up table

  // Calculate the time spent by primeNumber(n)
  clock_t begin = clock();
  
  triBulle(t,n);
  //triBulleOpt(t,n);
  
  clock_t end = clock();
  
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
  puts(" ");
  
  printf("Le temps d'execution est temps = %f seconds \n", time_spent); 

  for(i=0;i<n;i++)
  {
    printf("%d \n",t[i]);
  }

  return 0;
}
