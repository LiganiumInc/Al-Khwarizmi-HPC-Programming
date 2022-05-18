#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


int main(){

    int i, j, k, N = 1000;
    double *x, *y,*z;
    double begin, end, rate ;

    x = malloc(sizeof(double) * N);
    y = malloc(sizeof(double) * N);
    z = malloc(sizeof(double) * N);

    for(i = 0; i < N ; i++){
        for(j=0; j < N; j++){
            x[i,j] = 1.0;
            y[i,j] = 1.0;
            z[i,j] = 0.0;
        }
    }


    begin = (double)clock() / (double) CLOCKS_PER_SEC;
    for(i = 0; i < N ; i++){
        for(j=0; j < N; j++){
            for(k=0; k < N; k++){
                z[i,j] = z[i,j] + (x[i,k] * y[i,k]); 
            }
        }
    }
    end = (double)clock() / (double) CLOCKS_PER_SEC;

    double millis = (end -  begin) * 1000.0 ;

    rate = ( sizeof(double)* pow(N,3) * 4 /(1024*1024) ) / (millis/1000.0) ;

    printf("%f, %f \n",millis,rate);
}