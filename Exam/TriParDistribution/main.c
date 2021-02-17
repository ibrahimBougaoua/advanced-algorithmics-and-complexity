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

int Length(int x)
{
    int length;
    while (x != 0) {
        x /= 10;
        length++;
    }
    return length;
}

int Max(int *t,int n)
{
    int i,max=0;
    for(i=0;i<n; i++)
    {
        if(max < t[i])
        {
            max=t[i];
        }
    }
    return max;

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

void TriAux(int *tab,int n,int k)
{
    int *t1=(int *)malloc(n*sizeof(int));
    int *t2=(int *)malloc(n*sizeof(int));
    int i,m,indice=0;

    for(i=0; i<n;i++){
        t1[i]=cle(tab[i],k);
    }

    for(i=0; i<=9;i++)
    {
        for(m=0; m<n;m++){
                if(t1[m]==i)
                {
                   t2[indice]=tab[m];
                   indice++;
                }
        }
    }
    for(m=0; m<n;m++){
        tab[m]=t2[m];
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
    int n,i,k,max;
    int *t;
    clock_t Debut,Fin;
    float Temp;

  //printf(" cle=%d ",cle(45,2));

  printf("donner la taille N= ");
  scanf("%d",&n);
  t=(int *)malloc(n*sizeof(int));

  Random(n,t);

  for(i=0;i<n;i++)
  {
 	printf("\t Tab[%d]= %d \n",i,t[i]);
  }
  
  max = Max(t,n);
  k= Length(max);
  
  // Calculate the time spent by primeNumber(n) 
  clock_t begin = clock();
    
  TriBase(t,n,k);
  
  clock_t end = clock();
    
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
  puts(" ");
  
  printf("Le temps d'execution est temps = %f seconds \n", time_spent); 

  for(i=0;i<n;i++)
  {
 	  //n valeurs généré aléatoirement
 	  printf("\t Tab[%d]= %d \n",i,t[i]);
  }

    return 0;
}
