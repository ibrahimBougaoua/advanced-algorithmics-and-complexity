#include <stdio.h>
#include <time.h>

// Au pire cas :
// f(n) = 1 + 3 + n + 1 + n + 1 + 2*n + 1 + 1
// f(n) = 4n + 8

// T(n) = (4n + 5)*Dt
// Dt = T(n)/(4n + 5)

// Au meilleur cas :
// f(n) = 1 + 1 + 1 + 1 + 1
// f(n) = 5

// T(n) = 5*Dt
// Dt = T(n)/5

void maxEtMinA(int *tab,int n)
{
	int i = 1,max = tab[1],min = tab[1]; // 1
	
	while( i <= n ) // n + 1 or 1
	{
		if( tab[i] >= max ) // n or 1
		    max = tab[i];
		
		if( tab[i] <= min ) // n or 1
		    min = tab[i];
		
		i++; // 2*n or 0
	}
	
	printf("Max = %d et Min = %d \n",max,min); // 1
}

int main()
{
	int i = 1,n = 100;
	long int *tab;
	tab = (long int *)malloc(n*sizeof(long int *));
	
	while( i <= n )
	{
		tab[i] = i;
		i++;
	}
	
	maxEtMinA(tab,n);
	 
	return 0;
}
