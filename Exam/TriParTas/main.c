#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/****** tri par distribution *******/
// les valeurs de test [pire cas]
// 1000   = 0.000000
// 2000   = 0.000000
// 4000   = 0.001000
// 6000   = 0.001000
// 8000   = 0.002000
// 10000  = 0.002000
// 20000  = 0.006000
// 40000  = 0.009000
   
// les valeurs de test [meilleur cas]
// 1000   = 0.000000
// 2000   = 0.001000
// 4000   = 0.001000
// 6000   = 0.002000
// 8000   = 0.002000
// 10000  = 0.002000
// 20000  = 0.004000
// 40000  = 0.010000

void Random(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
    {
	   t[i]=rand();
    }
}

void Asc(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
    {
	   t[i] = i;
    }
}

void Desc(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
    {
	   t[i] = n-i;
    }
}

void heapify(long *heap,long i,long size){
    long left_child = i*2-1, right_child = i*2, max = --i;
    if((left_child < size) &&(heap[left_child] > heap[i])){
        max = left_child;
    }
    if((right_child < size) && (heap[right_child] > heap[max])){
        max = right_child;
    }
    if(max != i){
        long temp;
        temp = heap[i];
        heap[i] = heap[max];
        heap[max] = temp;
        heapify(heap, max+1,size);
    }

}

void build_heap(long * heap,long size){
    long i;
    for(i=size/2;i>0;i--){
        heapify(heap, i,size);
    }
}

void tri_tas(long* heap, long size){
    long temp,i,j;
    build_heap(heap, size);
    for(i=size;i>1;i--){
        temp = heap[i-1];
        heap[i-1] = heap[0];
        heap[0] = temp;
        heapify(heap,1,i-1);
    }
}

int main()
{
  int i,n;
  int *t;

  printf("Donner la taille N = ");
  scanf("%d",&n);
  t=(int *)malloc(n*sizeof(int));

  //Random(n,t);
  Asc(n,t);
  //Asc(n,t);
  
  /*
  for(i=0;i<n;i++)
  {
    printf("%d \n",t[i]);
  }
  */
  
  // Calculate the time spent by primeNumber(n) 
  clock_t begin = clock();
  
  tri_tas(t,n);
  
  clock_t end = clock();
    
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
  puts(" ");
  
  printf("Le temps d'execution est temps = %f seconds \n", time_spent); 

  /*
  for(i=0;i<n;i++)
  {
    printf("%d \n",t[i]);
  }
  */
  
  return 0;
}
