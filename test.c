#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0;
int finalSUM = 0;
int lb = 1, ub = 0; 
int q, rem;

void *runner(void *param);

int main(int argc, char *argv[]){
   pthread_t tid;
   pthread_attr_t attr;

   if (argc != 3) {
      fprintf(stderr,"usage: a.out <integer value>\n");
      /*exit(1);*/
      return -1;
   }

   if (atoi(argv[1]) < 0) {
      fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
      /*exit(1);*/
      return -1;
   }
   
   if (atoi(argv[2]) <= 0 ) {
      fprintf(stderr,"Argument %d must be Non-zero and non-negative\n",atoi(argv[1]));
      /*exit(1);*/
      return -1;
   }

   if ( atoi(argv[2]) > atoi(argv[1]) ) {
      fprintf(stderr,"Argument %d must be non-negative and N > M \n",atoi(argv[1]));
      /*exit(1);*/
      return -1;
   }

   pthread_attr_init(&attr);

   //create the thread
   int quotient , remainder , N , M ;
   N = atoi(argv[1]);
   M = atoi(argv[2]);

   int a[M];

   //the working code 
   q = (N/M)-1;      
   rem = N%M;       
   for(int i = 1; i < M+1; i++){   
      pthread_create(&tid,&attr,runner,&a[i]);  //SHOW THIS DOES WORK BUT IT DOES NOTHING AS OF RIGHT NOW
      ub = lb +q;           
      int cur = lb; 
      sum=0;

      for(int p = 0; p <= q; p++){   
         sum = sum + (lb+p);
      }
      printf("sum of %d to %d = %d\n", cur, ub, sum);
      finalSUM += sum;
      lb = ub +1;
         
   }

   /* now wait for the thread to exit */
   pthread_join(tid,NULL);

   printf("sum of 1 to %d = %d\n", ub, finalSUM);
}

void *runner(void *param){       //NEED TO CHANGE THE INPUT VARIABLES FOR THIS TO RUN CORRECTLY
   int i, upper = atoi(param);
	
   if (upper > 0) {
		for (i = 1; i <= upper; i++){
			sum += i;
         printf("sum in runner = %d", sum);
      }
   }
   
   else{
      printf("runner skipped\n");
   }
   
	pthread_exit(0);
}

//NEED TO FIX RUNNER SO IT ACTUALLY WORKS HOW IT IS SUPPOSED TO