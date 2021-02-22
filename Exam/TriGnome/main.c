#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/****** tri Gnome *******/
// les valeurs de test [pire cas]
// 1000   = 0.646000
// 2000   = 5.359000
// 4000   = 42.938000
// 6000   = 148.898000
// 8000   = 
// 10000  = 
// 20000  = 
// 40000  = 
   
// les valeurs de test [meilleur cas]
// 1000   = 0.004000
// 2000   = 0.015000
// 4000   = 0.060000
// 6000   = 0.136000
// 8000   = 
// 10000  = 
// 20000  = 
// 40000  = 

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
// 2 + 1 + n + 1 + 2*n + 2*n
// 5*n + 4 

// Complexité dans le pire des cas
// 3 + 2 + 1 + n + 1 + n + 3*n(n+1)/2 + 2*n(n+1)/2 + 2*n(n+1)/2 + 2*n(n+1)/2 + n(n+1)/2 + n(n+1)/2 + n
// 11*n(n+1)/2 + 3*n + 7

void tri_gnome(int* T,int n) {
 int i, x; // 2
   i=0; // 1
   while(i<n) // n + 1
   {
       if(T[i]<=T[i+1]){ // 2*n
        i++; // 2*n
       } else {
           x=T[i]; // n
           T[i]=T[i+1]; // 2*n
           T[i+1]=x; // 2*n
           
		   if(i=0){ // n*n
            i++;
           } else {
               i--; // n(n+1) 
           }
       }
   }
} 

int main()
{
    int n,i;
    int *t;
    clock_t Debut,Fin,Temp;
    
  printf("Donner la taille N =");
  scanf("%d",&n);
  t=(int *)malloc(n*sizeof(int));

  FilUpAsc(n,t);

  // Calculate the time spent by primeNumber(n)
  clock_t begin = clock();
  
  tri_gnome(t,n);
  
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
