#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Random(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
    {
	   t[i]=rand();
    }
}

void Asc(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
    {
	   t[i] = i;
    }
}

void Desc(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
    {
	   t[i] = n-i;
    }
}

void triRapide(int* tab, long debut, long fin)
{   int temp;
    long gauche = debut-1;
    long droite = fin+1;
    int pivot = tab[fin-1];
    //int pivot = tab[(debut+fin)/2];
    //int pivot = tab[debut];
    if(debut >= fin)
        return;
    while(1)
    {
        do droite--; while(tab[droite] > pivot);
        do gauche++; while(tab[gauche] < pivot);
        if(gauche < droite)
        {
            temp = tab[gauche];
            tab[gauche] = tab[droite];
            tab[droite] = temp;
        }
        else break;
    }

    triRapide(tab, debut, droite);
    triRapide(tab, droite+1, fin);
}

int main()
{
  int i,n;
  int *t;

  printf("Donner la taille N = ");
  scanf("%d",&n);
  t=(int *)malloc(n*sizeof(int));

  //Random(n,t);
  Desc(n,t);
  //Asc(n,t);
  
  for(i=0;i<n;i++)
  {
    printf("%d \n",t[i]);
  }
  
  // Calculate the time spent by primeNumber(n) 
  clock_t begin = clock();
  
  triRapide(t,0,n);
  
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
