#include <stdio.h>
#include <time.h>

int Cle(int x,int i)
{
	int k = 0,chiffre;
	while( x != 0 && i >= k )
	{   
		chiffre = x%10;
	    x = x/10;
		k++;
	}
	return chiffre;
}

void TriAux(int *tab,int n,int i)
{
	int k[n],tt[n],j,m,indice;
	
	indice = 1;
	for(j=1;j<=n;j++)
	{
		k[j] = Cle(tab[j],i);
	}
	
	for(j=0;j<=9;j++)
	{
		for(m=1;m<=n;m++)
		{
			if(k[m]=j)
			{
				indice++;
			}
		}
	}
	
	for(m=1;m<=n;m++)
	{
		tab[m] = tt[m];
	}
}

int main()
{
	int n = 8,i = 0; 
	
	long int *tab;
	tab = (long int *)malloc(n*sizeof(long int *));
	
    tab[1] = 10;
    tab[2] = 143;
    tab[3] = 30;
    tab[4] = 43;
    tab[5] = 141;
    tab[6] = 232;
    tab[7] = 45;
    tab[8] = 112;
	
    TriAux(tab,n,0);
	
	i = 0; 
	while( i < n )
	{
		printf("%d \n", tab[i]);
		i++;
	}

    // Calculate the time spent by primeNumber(n) 
    clock_t begin = clock();
	    
	clock_t end = clock();
    
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	  
    puts(" ");
  
    printf("Le temps d'execution est temps = %f seconds \n", time_spent); 
	
	return 0;
}
