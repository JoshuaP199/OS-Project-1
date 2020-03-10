#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0;
int finalSUM = 0;
int lb = 1, ub = 0; 
int q, rem;

void *runner(void *param); /* the thread */

int main(int argc, char *argv[])
{

pthread_t tid; /* the thread identifier */
pthread_attr_t attr; /* set of attributes for the thread */

if (argc != 3) {		//ERROR LOOP
	fprintf(stderr,"usage: a.out <integer value>\n");
	/*exit(1);*/
	return -1;
  }

if (atoi(argv[1]) < 0) {	//ERROR LOOP
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

/* create the thread */
int quotient , remainder , N , M ;
   N = atoi(argv[1]);
   M = atoi(argv[2]);

int a[M];

//the working code 
    q = (N/M)-1;      
    rem = N%M;       
    for(int i = 1; i < M+1; i++){   //this only works for if N/M is even, need to modify if its not
        pthread_create(&tid,&attr,runner,&a[i]);
        ub = lb +q;           
        int cur = lb; 
        sum=0;

        for(int p = 0; p <= q; p++){    //This works how it should in terms of the math
            sum = sum + (lb+p); //IMPORTANT
            //printf("sum = %d\n", sum);
        }
        printf("sum of %d to %d = %d\n", cur, ub, sum);
        finalSUM += sum;
        //printf("FS = %d\n", finalSUM);
        //a[0] = 0;
        //a[ i ] = sum;
        lb = ub +1;
       
    }
    /*
    for(int g=1; g<M+1; g++){
        int point = a[g];
        finalSUM = finalSUM + point;
    }
    */


/* now wait for the thread to exit */
pthread_join(tid,NULL);

//printf("sum = %d\n",sum);
printf("sum of 1 to %d = %d\n", ub, finalSUM);
}

/*
  The thread will begin control in this function
*/
void *runner(void *param) //NEED TO MODIFY THIS ??? (NOT SURE)
{
int i, upper = atoi(param);
//sum = 0;
	if (upper > 0) {
		for (i = 1; i <= upper; i++)
			sum += i;
            printf("sum in runner = %d", sum);
	}
    /*
    else{
        printf("runner skipped\n");
    }
    */

	pthread_exit(0);
}

//ALL WE NEED TO DO NOW IS MAKE A LOOP THAT CREATES THE ACUTAL THREADS WITH THE MATH INSIDE OF IT
