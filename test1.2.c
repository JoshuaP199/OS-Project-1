#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum, finalSUM = 0;
int lb = 1, ub = 0; 
int q, rem;
int c = 1;
int holder;
int p;

void *runner(int, int, int, int, int);

void main(int argc, char *argv[]){
   pthread_t tid;
   pthread_attr_t attr;

   pthread_attr_init(&attr);

   int quotient , remainder , N , M ;
   N = atoi(argv[1]);
   M = atoi(argv[2]);

   int a[M];

   int q = (N/M);      
   rem = N%M;       

/*
   for(int i = 0; i < M; i++){
      if (i == 0){
         lb = 1;
         ub = lb + (q-1);
      }
      elif (i == M-1){
         ub = N
         lb = (ub - (q+rem)+1)
      }
      else{
         lb = 1 + (q*i)
         ub = lb + (q-1)
      }
   }
*/
   for(int i = 1; i < M+1; i++){  
      if(i == 0){
         lb = 1;
         ub = lb + (q-1);
      }
      else if(i == M-1){
         ub = N;
         lb = (ub - (q+rem)+1);
      }
      else{
         lb = 1 + (q*i);
         ub = lb + (q-1);
      }
      pthread_create(&tid,&attr,runner(lb, ub, i, M, N),&a[i]);
      //lb = ub +1;
      pthread_join(tid,NULL);
   }
   printf("\nsum of 1 to %d = %d\n", N, holder);
}

void *runner(int lb, int ub, int i, int M, int N){
   if(i == M-1){
      sum = 0;
      for (int p = 0; p < ((N-lb)+1); p++){
         sum += (lb+p);
      }
      printf("sum of %d to %d = %d", lb, ub, sum);
      holder += sum;
   }
   else{
      sum = 0;
      for (int p = 0; p < q; p++){
         sum += (lb + p);
      }
      printf("sum of %d to %d = %d", lb, ub, sum);
      holder += sum;
   }
/*
	ub = lb +q;             
   int cur = lb; 
   sum=0;

   for(int p = 0; p <= q; p++){   
      sum = sum + (lb+p);
   }
   printf("sum of %d to %d = %d\n", cur, ub, sum); 
   finalSUM += sum; 
*/
	pthread_exit(0);
}