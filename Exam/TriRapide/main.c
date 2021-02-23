#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/****** tri rapide *******/
// les valeurs de test [pire cas]
// 1000   = 0.002000
// 2000   = 0.007000
// 4000   = 0.024000
// 6000   = 0.055000
// 8000   = 0.100000
// 10000  = 0.156000
// 20000  = 0.612000
// 40000  = 
   
// les valeurs de test [meilleur cas]
// 1000   = 
// 2000   = 
// 4000   = 
// 6000   = 
// 8000   = 
// 10000  = 
// 20000  = 
// 40000  = 

void Random(long n, long *t)
{
    long i;
    for(i=0;i<n;i++)
    {
	   t[i]=rand();
    }
}

void Asc(long n, long *t)
{
    long i;
    for(i=0;i<n;i++)
    {
	   t[i] = i;
    }
}

void Desc(long n, long *t)
{
    long i;
    for(i=0;i<n;i++)
    {
	   t[i] = n-i;
    }
}

void triRapide(long* tab, long debut, long fin)
{   int temp;
    long gauche = debut-1;
    long droite = fin+1;
    //int pivot = tab[fin-1];
    int pivot = tab[(debut+fin)/2];
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
  long i,n;
  long *t;

  printf("Donner la taille N = ");
  scanf("%d",&n);
  t=(long *)malloc(n*sizeof(long));

  //Random(n,t);
  Desc(n,t);
  //Asc(n,t);
  
  /*
  for(i=0;i<n;i++)
  {
    printf("%d \n",t[i]);
  }
  */
  
  // Calculate the time spent by primeNumber(n) 
  clock_t begin = clock();
  
  triRapide(t,0,n);
  
  clock_t end = clock();
    
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
  puts(" ");
  
  printf("Le temps d'execution est temps = %f seconds \n", time_spent); 

  /*
  for(i=1;i<=n;i++)
  {
    printf("%d \n",t[i]);
  }
  */
  
  return 0;
}
