#include <stdio.h>
#include <time.h>

// f(n) = 1 + 3 + 1 + 1 + 1 + n - 1 + 2*(n-2) + 1 + n - 2 + 1 + 1 + 1
// f(n) = 4n + 4

// f(n) = 1 + 3 + 1 + 1 + 1 + n - 1 + 2 + 1 + n - 2 + 1 + 1 + 1
// f(n) = 2n + 10

void primeNumber(int n)
{
	int i = 2; // 1
	
	if( (n == 0) || (n == 1) ) // 3 
	   printf("This isn't a prime number"); // 1
	    
	if( n == 2 ) // 1
	   printf("This is a prime number"); // 1
	
	while( i < n ) // n-1
	{
		if((n % i) == 0) // 2*(n-2) or 2
			break; // 1
		i++; // n-2
	}
	
	if( i == n ) // 1
	  printf("This is a prime number"); // 1
	else
	  printf("This isn't a prime number"); // 1
}

int main()
{
	int n;
	
	printf("Enter you'r number : ");
	scanf("%d",&n);
	
    // Calculate the time spent by primeNumber(n) 
    clock_t begin = clock();
    
	primeNumber(n);
	    
	clock_t end = clock();
    
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    puts(" ");
  
    printf("primeNumber(n) took %f seconds to execute \n", time_spent); 
	
	return 0;
}
