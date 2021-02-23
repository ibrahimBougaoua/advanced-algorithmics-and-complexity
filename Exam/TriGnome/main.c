#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/****** tri Gnome *******/
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
// 10000000  = 0,046000

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
// 2 + 1 + n*n + 1 + 2*n*n + 2*n + n*n + 2*n*n + 2*n*n + n*n + n*n + n*n
// 11n*n+2*n+4

void tri_gnome(int* T,int n) {
 int i, x; // 2
   i=0; // 1
   while(i<n) // n*n + 1
   {
       if(T[i]<=T[i+1]){ // 2*n*n
        i++; // 2*n
       } else {
           x=T[i]; // n*n
           T[i]=T[i+1]; // 2*n*n
           T[i+1]=x; // 2*n*n
           
		   if(i=0){ // n*n
            i++; // n*n
           } else {
               i--; // n*n
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

  FilUpDesc(n,t);

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
