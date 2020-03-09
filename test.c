#include <stdio.h>
#include <stdlib.h>

int sum = 0;
int finalSUM = 0;
int M = 8, N = 256, lb = 1, ub = 0;
char a[8];
 
int q, rem;

void main(){
    q = N/M;
    //printf("q = %d\n", q);        **
    rem = N%M;
    //printf("rem = %d\n", rem);            **
    for(int i = 1; i < M+1; i++){ //this only works for if N/M is even, need to modify if its not
        ub = lb +q;
        //printf("1st ub = %d\n", ub);          **
        int cur = lb;
        //printf("1st cur(lb) = %d\n", cur);        **

        //printf("ub = %d\n", ub);      **
        sum=0;
        //create array to hold sums
        for(int p = 0; p <= q; p++){
            sum = sum + (lb+p); //IMPORTANt
            //printf("sum = %d\n", sum);
            
        }
        printf("sum of %d to %d = %d\n", cur, ub, sum);
        a[0] = 0;
        a[ i ] = sum;
        lb = ub +1;
    }
    
        for(int g=1; g<M+1; g++){
            int point = a[g];
            printf("point = %d\n", point);
            finalSUM = finalSUM + point;
            printf("finalSUM = %d\n", finalSUM);
        }
        //printf("lb = %d\n", lb);      **
    
    
    //use the array stated earlier ^ and add those to get the total sum
    printf("sum of 1 to %d = %d", ub, finalSUM); //replace 1000 with total sum (create total sum variable)
}