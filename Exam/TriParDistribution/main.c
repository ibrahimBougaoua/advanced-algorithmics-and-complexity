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

int cle(int x,int i)
{
    int r,j;
    for(j =0;j<i;j++)
    {
    	r = x%10;
    	x = x/10;
	}
	return r;

}

void TriAux(int *tab,int n,int i)
{
    int *t1=(int *)malloc(n*sizeof(int));
    int *t2=(int *)malloc(n*sizeof(int));
    
     int j,m,ind,longeur;

    ind = 0;
    for(j=0; j<n; j++)  
    {
        t1[j] = cle(tab[j], i);
    }

    for(j=0; j<=9; j++)  
    {
        for(m=0; m<n; m++)
        {
            if(t1[m] == j )
            {
                t2[ind] = tab[m];
                ind++;
            }
        }
    }
    for(m=0 ; m<n; m++)
    {
        tab[m] = t2[m];
    }
}

void TriBase(int *t, int n, int k)
{
    int i;
    for(i=1; i<=k; i++)
    {
        TriAux(t,n,i);
    }
}

int main()
{
    int n,i;
    int *t;
    clock_t Debut,Fin;
    float Temp;

  //printf(" cle=%d ",cle(45,2));

  printf("donner la taille N= ");
  scanf("%d",&n);
  t=(int *)malloc(n*sizeof(int));

  Random(n,t);

/*
  for(i=0;i<n;i++)
  {
 	printf("\t Tab[%d]= %d \n",i,t[i]);
  }
  */
  
  
  // Calculate the time spent by primeNumber(n) 
  clock_t begin = clock();
    
  TriBase(t,n,9);
  
  clock_t end = clock();
    
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
  puts(" ");
  
  printf("Le temps d'execution est temps = %f seconds \n", time_spent); 

/*
  for(i=0;i<n;i++)
  {
 	  //n valeurs généré aléatoirement
 	  printf("\t Tab[%d]= %d \n",i,t[i]);
  }
*/

    return 0;
}
