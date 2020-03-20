#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum, finalSUM = 0;
int lb = 1, ub = 0, c = 1; 
int q, rem, p, M, N, holder;

void *runner(int, /*int,*/ int, int, int, int);

void main(int argc, char *argv[]){
   pthread_t tid;
   pthread_attr_t attr; 

   //pthread_attr_init(&attr);  #HONESTLY DONT THINK WE NEED THIS

   int N , M;
   N = atoi(argv[1]);
   M = atoi(argv[2]);

   int a[M];

   int q = (N/M);      
   rem = N%M;       

//PLACE 1
   //("M = %d\n", M);
   //printf("N = %d\n", N);
   //printf("q = %d\n", q);
   for(int i = 0; i < M; i++){ 
      //printf("i1 = %d\n\n", i);
      if(i == 0){
         //printf("1-lb = %d\tub = %d\n", lb, ub);
         lb = 1;
         ub = lb + (q-1);
         //printf("1q = %d\n", q);
         //printf("1-lb = %d\tub = %d\n", lb, ub);
      }
      else if(i == M-1){
         //printf("2-lb = %d\tub = %d\n", lb, ub);
         ub = N;
         lb = (ub - (q+rem)+1);
         //printf("2-lb = %d\tub = %d\n", lb, ub);
      }
      else{
         //printf("3-lb = %d\tub = %d\n", lb, ub);
         lb = 1 + (q*i);
         ub = lb + (q-1);
         //printf("3-lb = %d\tub = %d\n", lb, ub);
      }
      //printf("\n");
      pthread_create(&tid,&attr,runner(lb/*, ub*/, i, q, M, N),&a[i]);
      //printf("4\n");
      //lb = ub +1;
      pthread_join(tid,NULL);
      //printf("ENDi = %d", i);
   }
   printf("\nFINALsum of 1 to %d = %d\n", N, holder); //NOT DISPLAYING
   pthread_exit(0);
}

void *runner(int lb,/* int ub,*/ int i, int q, int M, int N){
   //printf("2q = %d\n", q);
   //printf("i2 = %d\n", i);
   //printf("M2 = %d\n", M);
   //printf("4-lb = %d\tub = %d\n", lb, ub);
   //printf("\n");
   if(i == M-1){
      //printf("5\n");
      sum = 0;
      for (int p = 0; p < ((N-lb)+1); p++){
         sum += (lb+p);
      }
      printf("R1sum of %d to %d = %d\n", lb, ub, sum);
      holder += sum;
   }
   else{
      //printf("3q = %d\n", q);
      //printf("6\n\n");
      sum = 0;
      for (int p = 0; p < q ; p++){
         sum += (lb + p);
         //printf("8\n");
      }
      printf("R2sum of %d to %d = %d\n", lb, ub, sum);
      holder += sum;
      //printf("\nsum = %d", sum);
      //printf("\nh = %d\n", holder);
      //printf("i4 = %d\n", i);
   }
// PLACE 2
	//pthread_exit(0); #HAVE A EXIT IN MAIN THAT WORKS
}

/*       PLACE 1
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
/*       PLACE 2
	ub = lb +q;             
   int cur = lb; 
   sum=0;

   for(int p = 0; p <= q; p++){   
      sum = sum + (lb+p);
   }
   printf("sum of %d to %d = %d\n", cur, ub, sum); 
   finalSUM += sum; 
*/