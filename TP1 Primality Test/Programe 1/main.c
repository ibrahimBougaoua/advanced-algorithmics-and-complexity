#include <stdio.h>
#include <time.h>

int primeNumber(int n)
{
	int i = 2;
	
	if( (n == 0) || (n == 1) )
	   return -1;
	    
	if( n == 2 )
	   return 1;
	
	while( (i < n) && (n % i) != 0 )
	{
		i++;
	}
	
	if( i == n )
	  return 1;
	  
	return -1;
}

int main()
{
	int n;
	
	printf("Enter you'r number : ");
	scanf("%d",&n);
	
	if( primeNumber(n) == 1 )
	    printf("This is a prime number");
	else
	    printf("This isn't a prime number");
	
	puts("");
	
    // Calculate the time spent by primeNumber(n) 
    clock_t begin = clock();
    
    primeNumber(n);
	
	clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  
    printf("primeNumber(n) took %f seconds to execute \n", time_spent); 
	
	return 0;
}
