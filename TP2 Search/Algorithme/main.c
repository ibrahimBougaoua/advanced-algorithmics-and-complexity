#include <stdio.h>
#include <time.h>

// f(n) = 1 + n + 1 + n + 1 + 2*n + 1 + 1

void rechEletsTabNonTries(int *tab,int n,int value)
{
	int i = 1; // 1
	while( i <= n ) // n + 1
	{
		if( tab[i] == value ) // n
		    break; // 1
		i++; // 2*n
	}
	
	if( i > n ) // 1
	    printf("This value doesn't exists : value =  %d",value); // 1
	else
	    printf("This value exists : value =  %d",value); // 1
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
	
	rechEletsTabNonTries(tab,n,101);
	 
	return 0;
}
