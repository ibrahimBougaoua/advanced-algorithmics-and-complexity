#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void remplirTable_rand(int n, int *t)
{
    int i;
    for(i=0;i<n;i++)
  {
 	  //n valeurs généré aléatoirement
	  t[i]=rand();
  }
}


void tri_gnome (int* T, int n) {
   int i, x;
   i=0;
   while(i<n)
   {
       if(T[i]<=T[i+1]){
        i++;
       }
       else
       {
           x=T[i];
           T[i]=T[i+1];
           T[i+1]=x;
           if(i=1){
            i++;
           }else
           {
               i--;
           }
       }

   }
}


int main()
{
    int n,i;
    int *t;
    clock_t Debut,Fin;
    float Temp;

  printf("donner la taille N= ");
  scanf("%d",&n);
  t=(int *)malloc(n*sizeof(int));

  remplirTable_rand(n,t);// remplir la table


  Debut=clock();
  tri_gnome(t,n);
  Fin=clock();
  Temp=(float)(Fin-Debut)/CLOCKS_PER_SEC;
  printf("Le temps d'execution du tri gnome est %f\n",Temp);

  /*for(i=0;i<n;i++)
  {
 	  //n valeurs généré aléatoirement
 	  printf("\t Tab[%d]= %d \n",i,t[i]);
  }*/

    return 0;
}