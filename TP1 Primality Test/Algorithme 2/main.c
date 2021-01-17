#include <stdio.h>
#include <time.h>

// Au pire cas :
// f(n) = 1 + 1 + n / 2 + 1 + 2*(n / 2) + 2*(n/2+1) + 2*(n / 2)
// f(n) = n*(7/2) + 5

// T(n) = (n*(7/2) + 5)*Dt
// Dt = T(n)/(n*(7/2) + 5)

// Au meilleur cas :
// f(n) = 1 + 1 + n / 2 + 1 + 2*(n / 2) + 2*2 + 2*(n / 2)
// f(n) = n*(5/2) + 7

// T(n) = (n*(5/2) + 7)*Dt
// Dt = T(n)/(n*(5/2) + 7)

int main()
{
	int n,i,nbr; 
	
	printf("Enter you'r number : ");
	scanf("%d",&n);
	
    // Calculate the time spent by primeNumber(n) 
    clock_t begin = clock();
    
	i = 1; // 1
	nbr = 0; // 1
	
	while( i <= n/2 ) // (n / 2) + 1
	{
		if((n % i) == 0) // 2*(n / 2)
			nbr++; // 2*(n/2+1) or 2*2
			
		i++; // 2*(n / 2)
	}
	
	clock_t end = clock();
    
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
	if( nbr == 1 )
	  printf("This is a prime number");
	else
	  printf("This isn't a prime number");
	  
    puts(" ");
  
    printf("Le temps d'execution est temps = %f seconds \n", time_spent); 
	
	return 0;
}

