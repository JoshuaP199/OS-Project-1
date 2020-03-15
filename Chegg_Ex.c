#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /* this data is shared by the thread(s) */

void *runner(void *param); /* the thread */

int main(int argc, char *argv[])
{
pthread_t tid; /* the thread identifier */
pthread_attr_t attr; /* set of attributes for the thread */


if (argc != 3) {
   fprintf(stderr,"usage: a.out <integer value, N> <integer value , M> \n Note : M < N \n");
   /*exit(1);*/
   return -1;
}

if (atoi(argv[1]) <= 0 ) {
   fprintf(stderr,"Argument %d must be Non-zero and non-negative\n",atoi(argv[1]));
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
/* get the default attributes */
pthread_attr_init(&attr);

/* create the thread */
int quotient , remainder , N , M ;
   N = atoi(argv[1]);
   M = atoi(argv[2]);
  
/* Create an array M x 3 array to store sum , start , end
    the pointer to pary[i][0] is passed to thread so that sum is stored in 1st element and lower & upper limits
   are retrieved from pary[i][1] & pary[i][2]
   */
  
   int pary[M+2][3];

   quotient = N/M ;
   remainder = N % M ;

  
   for( int i = 1 ; i<= M ; i++ ) {
       //pary[i][0] = M;
       pary[i][1] = 1 + (i - 1) * quotient ;
       pary[i][2] = i * quotient ;
       if (i == M ) {
           pary[i][2] = N ;
       } else {
           pary[i][2] = i * quotient ;
       }
      
       pthread_create(&tid,&attr,runner,&pary[i][0]);
       }
/* now wait for the thread to exit */
   pthread_join(tid,NULL);

   for (int i = 1 ; i <= M ; i ++ ) {
       sum = sum + pary[i][0];
   }
   printf("sum = %d\n",sum);
}

/**
* The thread will begin control in this function
*/
void *runner(void *param)
{
   int i;
   int* sum_n_len = (int* ) (param);
   int* lower = (int *) (param+ sizeof(int)*1);
   int* upper = (int*) ((param+ sizeof(int)*2));
   int sum1 = 0;
  
   if (upper > 0 && lower > 0 ) {
       for (i = *lower ; i <= *upper; i++)
           sum1 += i;
   }

   *sum_n_len = sum1 ;
   printf("Sum of %d to %d = %d \n" , *lower , *upper , sum1 );

   pthread_exit(0);
}
