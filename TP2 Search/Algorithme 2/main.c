#include <stdio.h>
#include <time.h>

// Au pire cas :
// f(n) = 3 + n + 1 + n + n + n + n + 2*n + 1
// f(n) = 7n + 5

// T(n) = (7n + 5)*Dt
// Dt = T(n)/(7n + 5)

// Au meilleur cas :
// f(n) = 3 + 2 + 1 + 1 + 1 + 1 + 2 + 1
// f(n) = 12

// T(n) = 12*Dt
// Dt = T(n)/12

void maxEtMinA(int *tab,int n)
{
	int i = 0,cpt = 0,max = tab[1],min = tab[1]; // 3
	
	while( i < n ) // n + 1 or 2
	{
		if( tab[i] >= max ) // n or 1
		{
			cpt++;
			max = tab[i]; // n or 1
		}
		
		if( tab[i] <= min ) // n or 1
		{
			cpt++;
			min = tab[i]; //n or 1
		}

		i++; // 2*n or 2
	}
	
	printf("Max = %d et Min = %d / Counting = %d \n",max,min,cpt); // 1
}

void maxEtMinB(int *tab,int n)
{
	int i = 0,cpt = 0,x = 0,max,min; // 3
	
	while( i < n-1 ) // n
	{
		if( tab[i] > tab[i+1] ) // n or 1
		{
			cpt++; 
		    x = tab[i];
		    tab[i] = tab[i+1];
		    tab[i+1] = x;
		}
		
		i = i + 2; // 2*n or 2
	}
	
	min = tab[0];
	i = 2;
	
	while( i < n ) // n/2-1
	{
		if( min > tab[i] ) // n or 1
		{
			cpt++;
		    min = tab[i];
		}
		
		i = i + 2; // 2*n or 2
	}
	
	min = tab[1];
	i = 3;
	
	while( i < n ) // n/2-1
	{
		if( max < tab[i] ) // n or 1
		{
			cpt++;
		    max = tab[i];
		}
		
		i = i + 2; // 2*n or 2
	}
	
	if(n%2 == 1)
	{
		if( max < tab[n-1] ) // n or 1
		{
		    cpt++;
		    max = tab[n-1];
		}
	}
	
	printf("Max = %d et Min = %d / Counting = %d \n",max,min,cpt); // 1
}

int main()
{
	int i = 0,n = 1600000;
	long int *tab;
	tab = (long int *)malloc(n*sizeof(long int *));
	
	while( i < n )
	{
		tab[i] = i;
		i++;
	}
	
	// Calculate the time spent by function. 
    clock_t begin = clock();
    
	//maxEtMinA(tab,n);
	maxEtMinB(tab,n);
	
	clock_t end = clock();
    
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    puts(" ");
  
    printf("Le temps d'execution est temps = %f seconds \n", time_spent); 
	 
	return 0;
}
