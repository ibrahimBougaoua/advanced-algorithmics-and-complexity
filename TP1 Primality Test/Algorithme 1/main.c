#include <stdio.h>
#include <time.h>

// Au paire cas :
// f(n) = n + 1 + 2*n + 2*(n/2+1) + 2*n + 1 + 1 + 1
// f(n) = 6n + 6

// Au meilleur cas :
// f(n) = n + 1 + 2*n + 2*2 + 2*n + 1 + 1 + 1
// f(n) = 5n + 8

// T(n) = (5n + 8)*Dt


int main()
{
	int n,nbr = 0,i = 1;
	
	printf("Enter you'r number : ");
	scanf("%d",&n);
	
    // Calculate the time spent by primeNumber(n) 
    clock_t begin = clock();
	
	while( i <= n ) // n+1
	{
		if((n % i) == 0) // 2*n
			nbr++; // 2*(n/2+1) or 2*2
		i++; // 2*n
	}
	
	if( nbr == 2 ) // 1
	  printf("This is a prime number"); // 1
	else
	  printf("This isn't a prime number"); // 1
	    
	clock_t end = clock();
    
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    puts(" ");
  
    printf("primeNumber(n) took %f seconds to execute \n", time_spent); 
	
	return 0;
}
