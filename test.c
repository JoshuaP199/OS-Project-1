#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum, finalSUM = 0;
int lb = 1, ub = 0; 
int q, rem;
int c = 1;

void *runner();

int main(int argc, char *argv[]){
   pthread_t tid;
   pthread_attr_t attr;

   pthread_attr_init(&attr);

   //create the thread
   int quotient , remainder , N , M ;
   N = atoi(argv[1]);
   M = atoi(argv[2]);

   int a[M];
 //
 //
 //
 //
 //

   q = (N/M)-1;      
   rem = N%M;       

   for(int i = 1; i < M+1; i++){  
      printf("\n"); 
      pthread_create(&tid,&attr,runner,&a[i]);  //SOMEHOW THIS DOES WORK BUT IT DOES NOTHING AS OF RIGHT NOW
      //finalSUM += sum;
      lb = ub +1;
   }

   pthread_join(tid,NULL);

//
//
//
//
//

   printf("\nsum of 1 to %d = %d\n", ub, finalSUM);
}

void *runner(){    //NEED TO CHANGE THE INPUT VARIABLES FOR THIS TO RUN CORRECTLY
	ub = lb +q;             
   int cur = lb; 
   sum=0;

   for(int p = 0; p <= q; p++){   
      sum = sum + (lb+p);
   }
   //printf("cur %d ---- ub %d\n", cur, ub);
   printf("c = %d --- sum of %d to %d = %d\n", c, cur, ub, sum);
   c++;
   finalSUM += sum;

	pthread_exit(0);
}

//NEED TO FIX RUNNER SO IT ACTUALLY WORKS HOW IT IS SUPPOSED TO