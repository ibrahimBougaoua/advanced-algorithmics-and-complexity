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

void Echanger(int *t, int i, int j)
{
    int tmp;
    tmp=t[i];
    t[i]=t[j];
    t[j]=tmp;
}

int Partition(int *t, int deb, int fin)
{
    int compt=deb;
    int pivot=t[deb];
    int i;
    for(i=deb+1;i<=fin;i++)
    {
        if(t[i]<pivot)
        {
            compt++;
            Echanger(t,compt,i);
        }
    }
    Echanger(t,compt,deb);
    return(compt);
}

void TriRapideBis(int *t, int debut,int fin)
{
    if(debut<fin)
    {
        int pivot = Partition(t,debut,fin);
        TriRapideBis(t,debut,pivot-1);
        TriRapideBis(t,pivot+1,fin);
    }
}

void TriRapide(int *t,int n)
{
    TriRapideBis(t,0,n-1);
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
  
  TriRapide(t,n);
  
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
