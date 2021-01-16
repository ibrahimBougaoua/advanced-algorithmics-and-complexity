#include <stdio.h>
#include <time.h>

// Au pire cas :
// f(n) = 1 + 1 + 1 + 2 + [n^(1/2) + 1]/2 + 2*(n^(1/2)) + 2*(n^(1/2)) + n^(1/2)
// f(n) = 11*n^(1/2) + 13/2

// T(n) = (11*n^(1/2) + 13/2)*Dt
// Dt = T(n)/(11*n^(1/2) + 13/2)

// Au meilleur cas :
// f(n) = 1 + 1 + 1 + 2
// f(n) = 5

// T(n) = 5*Dt
// Dt = T(n)/5

int main()
{
	int n,i,nbr,pr; 
	
	printf("Enter you'r number : ");
	scanf("%d",&n);
	
    // Calculate the time spent by primeNumber(n) 
    clock_t begin = clock();
    
	i = 1; // 1
	nbr = 0; // 1
	pr = 1; // 1
	
	if((n % 2) != 0) // 2
	{
		while( i <= sqrt(n) ) // [n^(1/2) + 1]/2
		{
			if((n % i) == 0) // 2*(n^(1/2))
				nbr++; // 2*(n^(1/2)) or 2*2
				
			i = i + 2; // n^(1/2)
		}
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



