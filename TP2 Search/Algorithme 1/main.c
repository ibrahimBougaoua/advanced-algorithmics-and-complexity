#include <stdio.h>
#include <time.h>

// Au pire cas :
// f(n) = 1 + n + 1 + n + 1 + 2*n + 1 + 1
// f(n) = 4n + 5

// T(n) = (4n + 5)*Dt
// Dt = T(n)/(4n + 5)

// Au meilleur cas :
// f(n) = 1 + 1 + 1 + 1 + 1
// f(n) = 5

// T(n) = 5*Dt
// Dt = T(n)/5

void rechEletsTabNonTries(int *tab,int n,int value)
{
	int i = 1; // 1
	while( i <= n ) // n + 1 or 1
	{
		if( tab[i] == value ) // n or 1
		    break; // 1
		i++; // 2*n or 0
	}
	
	if( i > n ) // 1
	    printf("This value doesn't exists : value =  %d \n",value); // 1
	else
	    printf("This value exists : value =  %d \n",value); // 1
}

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

void rechEletsTabTries(int *tab,int n,int value)
{
	int i = 1; // 1
	
	if( (tab[i] <= value) && (tab[n] >= value) ) // 3
	{
		while( i <= n ) // n + 1 or 1
		{
			if( tab[i] == value ) // n or 1
			    break; // 1
			i++; // 2*n or 0
		}
		if( i > n ) // 1
		    printf("This value doesn't exists : value =  %d \n",value); // 1
		else
		    printf("This value exists : value =  %d \n",value); // 1
	} else {
		printf("This value doesn't exists : value =  %d \n",value); // 1
	}
}

void rechEletsDicho(int *tab,int sup,int value)
{
	int inf = 1,mil; // 1
	
	if( (tab[inf] <= value) && (tab[sup] >= value) ) // 3
	{
		while( inf < sup )
		{
			mil = (inf + sup)/2;
			if(tab[mil] == value) {
				break;
			} else if( value > tab[mil] ) {
				inf = mil + 1;
			} else {
				sup = mil - 1;
			}
		}
		if( inf > sup ) // 1
		    printf("This value doesn't exists : value =  %d \n",value); // 1
		else
		    printf("This value exists : value =  %d \n",value); // 1
	} else {
		printf("This value doesn't exists : value =  %d \n",value); // 1
	}
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
	
	//rechEletsTabNonTries(tab,n,101);
	//rechEletsTabTries(tab,n,10);
	rechEletsDicho(tab,n,0);
	rechEletsDicho(tab,n,75);
	rechEletsDicho(tab,n,1);
	rechEletsDicho(tab,n,100);
	rechEletsDicho(tab,n,5);
	rechEletsDicho(tab,n,101);
	 
	return 0;
}
