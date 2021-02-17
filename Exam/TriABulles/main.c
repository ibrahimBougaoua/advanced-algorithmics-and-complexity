#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplirTable_decroisant(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
    {
	  t[i]=n-i;
    }
}

  void remplirTable_croisant(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
  {
	  t[i]=i;
  }
}

void remplirTable_rand(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
  {
	  t[i]=rand();
  }
}


void triBulle(int *t,int n){
    int i =0;int tmp =0;int changement=1;
    while(changement){
        changement = 0;
        for(i =0; i < n-1; i++){
            if(t[i] > t[i+1]){
                    tmp = t[i+1];
                    t[i+1] = t[i];
					t[i] = tmp;
                    changement = 1;
            }
        }
    }
}

void triBulleOpt(int *t,int n){
	int i =0;int tmp =0;int m;
	m=n-1;
	int changement=1;
	while(changement){
		changement = 0;
        for(i =0; i < m; i++){
            if(t[i] > t[i+1]){
                    tmp = t[i+1];
                    t[i+1] = t[i];
					t[i] = tmp;
                    changement = 1;
            }
        }
	}
}

int main(int argc, char *argv[])
{
    int n,i;
    int *t;
    clock_t Debut,Fin,Debut1,Fin1;
    float Temp;

  printf("donner la taille N= ");
  scanf("%d",&n);
  t=(int *)malloc(n*sizeof(int));


  remplirTable_rand(n,t);// remplir la table


  Debut=clock();
  triBulle(t,n);
  //triBulleOpt(t,n);
  Fin=clock();
  Temp=(float)(Fin-Debut)/CLOCKS_PER_SEC;
  printf("Le temps d'execution du tri par bull est %f\n",Temp);


  return 0;
}