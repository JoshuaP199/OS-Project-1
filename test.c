#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum, finalSUM = 0;
int lb = 1, ub = 0; 
int q, rem;
int c = 1;

void *runner();

void main(int argc, char *argv[]){
   pthread_t tid;
   pthread_attr_t attr;

   pthread_attr_init(&attr);

   int quotient , remainder , N , M ;
   N = atoi(argv[1]);
   M = atoi(argv[2]);

   int a[M];

   q = (N/M)-1;      
   rem = N%M;       

   for(int i = 1; i < M+1; i++){  
      printf("\n"); 
      pthread_create(&tid,&attr,runner,&a[i]);
      lb = ub +1;
   }

   pthread_join(tid,NULL);

   printf("\nsum of 1 to %d = %d\n", ub, finalSUM);
}

void *runner(){
	ub = lb +q;             
   int cur = lb; 
   sum=0;

   for(int p = 0; p <= q; p++){   
      sum = sum + (lb+p);
   }
   printf("sum of %d to %d = %d\n", cur, ub, sum);
   finalSUM += sum; //MOST INCONSISTANT

	pthread_exit(0);
}
