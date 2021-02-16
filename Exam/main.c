#include <stdio.h>
#include <time.h>

// Au pire cas :
// f(n) = 1 + 1 + n + 1 + 2*n + 2*(n/2+1) + 2*n
// f(n) = 6n + 5

// T(n) = (6n + 5)*Dt
// Dt = T(n)/(6n + 5)

// Au meilleur cas :
// f(n) = 1 + 1 + n + 1 + 2*n + 2*2 + 2*n
// f(n) = 5n + 7

// T(n) = (5n + 7)*Dt
// Dt = T(n)/(5n + 7)

int main()
{
	int n,i,nbr; 
	
	printf("Enter you'r number : ");
	scanf("%d",&n);
	
    // Calculate the time spent by primeNumber(n) 
    clock_t begin = clock();
	    
	clock_t end = clock();
    
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	  
    puts(" ");
  
    printf("Le temps d'execution est temps = %f seconds \n", time_spent); 
	
	return 0;
}
