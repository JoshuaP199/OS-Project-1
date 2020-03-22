#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum, finalSUM = 0;
int lb = 1, ub = 0; 
int q, rem, p, M, N, holder;

void *runner(void *param);

void main(int argc, char *argv[]){
   pthread_attr_t attr;
   pthread_attr_init(&attr);
 
   N = atoi(argv[1]);
   M = atoi(argv[2]);
   pthread_t tid[M];
 
   q = (N/M);   
   rem = N%M;       

   for(int i = 0; i < M; i++){ 
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
      pthread_create(&tid[i],&attr,runner,&i);
      pthread_join(tid[i],NULL);
   }
   printf("\nFINALsum of 1 to %d = %d\n", N, holder);
   pthread_exit(0);
}

void *runner(void *param){
   int i=*(int *)param;
   if(i == M-1){
      sum = 0;
      for (int p = 0; p < ((N-lb)+1); p++){
         sum += (lb+p);
      }
      printf("R1sum of %d to %d = %d\n", lb, ub, sum);
      holder += sum;
   }
   else{
      sum = 0;
      for (int p = 0; p < q ; p++){
         sum += (lb + p);
      }
      printf("R2sum of %d to %d = %d\n", lb, ub, sum);
      holder += sum;
   }
}
