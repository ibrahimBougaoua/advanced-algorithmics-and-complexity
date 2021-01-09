#include <stdio.h>
#include <math.h>
#include <time.h>

int primeNumber(int n)
{
	int max,i = 2;
	
	if( (n == 0) || (n == 1) || (n == 4) )
	   return -1;
	    
	if( n == 2 || n == 3 )
	   return 1;
	
	max = sqrt(n);
	
	printf("%d",max);
	
	while( (i <= max ) && (n % i) != 0 )
	{
		i++;
	}
	
	if( i > max )
	  return 1;
	  
	return -1;
}

int main()
{
	int n;
	
	printf("Enter you'r number : ");
	scanf("%d",&n);
	
    // Calculate the time spent by primeNumber(n) 
    clock_t begin = clock();
    
	if( primeNumber(n) == 1 )
	    printf("This is a prime number");
	else
	    printf("This isn't a prime number");
	
	clock_t end = clock();
    
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    puts(" ");
  
    printf("primeNumber(n) took %f seconds to execute \n", time_spent); 
	
	return 0;
}
