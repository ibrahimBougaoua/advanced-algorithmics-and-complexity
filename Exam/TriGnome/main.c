#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void tri_gnome(int* T,int n) {
 int i, x; // 2
   i=0; // 1
   while(i<n)
   {
       if(T[i]<=T[i+1]){
        i++;
       } else {
           x=T[i];
           T[i]=T[i+1];
           T[i+1]=x;
           
		   if(i=0){
            i++;
           } else {
               i--;
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

  for(i=0;i<n;i++)
  {
    printf("%d \n",t[i]);
  }

  return 0;
  
}
