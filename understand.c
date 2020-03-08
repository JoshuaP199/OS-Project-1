#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; //Global

void *runner(void *param); //want to understand the reason for pointers here

void *runner(void *param) {
    printf("param %s = upper\n", param); //param is argv[]
    int i, upper = atoi(param); //atoi sets the string of param into an int (atoi sets strings to ints)
    sum = 0;
    if(upper > 0) {
        for(i = 1; i <= upper; i++){
            sum += i;
        }
    }
}

int main(int argc, char *argv[]) {
    pthread_t tid;
    pthread_attr_t attr;
    printf("argc %d\n", argc);      // argc reads the positions this helps with the error loop from the main program so it functions correctly
    printf("argv[1] %s\n", argv[1]);   //reads the actual input from the user depending on the position starting at [int]
                                       //argv[2] = M & argv[1] = N

    pthread_attr_init(&attr);    //defaults

    pthread_create(&tid, &attr, runner, argv[1]);   //thread creation runner uses argv[1] as its param

    pthread_join(tid, NULL);    //waits for thread to exit

    printf("sum = %d\n", sum);
}
