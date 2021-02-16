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

void TriAux(int *tab,int n,int k)
{
	int i = 1,x;
	while( i < n )
	{
		if( Cle(tab[i],k) <= Cle(tab[i+1],k) )
		{
			x = tab[i];
			tab[i] = tab[i+1];
			tab[i+1] = x;
		}
		i++;
	}
}

int main()
{
	int n = 5,i = 1; 
	
	long int *tab;
	tab = (long int *)malloc(n*sizeof(long int *));
	
	while( i <= n )
	{
		printf("%d \n", i+100); 
		tab[i] = i+100;
		i++;
	}
	
	puts("");
	TriAux(tab,n,2);
	
	i = 1; 
	while( i <= n )
	{
		printf("%d \n", tab[i]);
		i++;
	}
	
	printf("x = %d \n", Cle(143,1)); 

    // Calculate the time spent by primeNumber(n) 
    clock_t begin = clock();
	    
	clock_t end = clock();
    
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	  
    puts(" ");
  
    printf("Le temps d'execution est temps = %f seconds \n", time_spent); 
	
	return 0;
}
