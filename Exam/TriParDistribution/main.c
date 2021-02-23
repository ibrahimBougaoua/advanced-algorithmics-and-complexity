#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/****** tri par distribution *******/
// les valeurs de test [pire cas]
// 1000   = 0.001000
// 2000   = 0.002000
// 4000   = 0.003000
// 6000   = 0.004000
// 8000   = 0.006000
// 10000  = 0.008000
// 20000  = 0.014000
// 40000  = 0.027000
   
// les valeurs de test [meilleur cas] c'est la meme avec pire des cds !!!!
// 1000   = 0.001000
// 2000   = 0.002000
// 4000   = 0.003000
// 6000   = 0.004000
// 8000   = 0.006000
// 10000  = 0.008000
// 20000  = 0.014000
// 40000  = 0.027000


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

int cle(int x,int i)
{
    int r,j; // 2
    for(j =0;j<i;j++) // 3*9 + 1
    {
    	r = x%10; // 2*9
    	x = x/10; // 2*9
	}
	return r; // 1
}

// [7 + 3*n + n + 9*3 + 9*3*3*n + 1 + 9*3*n + 9*3*n + 9*3*2*n + 3*n + 1 + n ]
// (9*3)*f(n)

void TriAux(int *tab,int n,int i)
{
    int *t1=(int *)malloc(n*sizeof(int)); // 1
    int *t2=(int *)malloc(n*sizeof(int)); // 1
    
    int j,m,ind,longeur; // 3

    ind = 0; // 1
    for(j=0; j<n; j++)  // 3*n + 1
    {           
        t1[j] = cle(tab[j], i); // n
    }

    for(j=0; j<=9; j++)   // 9*3
    {
        for(m=0; m<n; m++) // 9*3*3*(n) + 1
        {
            if(t1[m] == j ) // 9*3*n
            {
                t2[ind] = tab[m]; // 9*3*n
                ind++; // 9*3*2*n
            }
        }
    }
    for(m=0 ; m<n; m++) // 3*n + 1
    {
        tab[m] = t2[m]; // n
    }
}

void TriBase(int *t, int n, int k)
{
    int i; // 1
    for(i=1; i<=k; i++) // 9*3 + 1
    {
        TriAux(t,n,i); // (9*3)*f(n)
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

  FilUpAsc(n,t);

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
