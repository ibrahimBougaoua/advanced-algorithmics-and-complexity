#include <stdio.h>

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
	
	return 0;
}
