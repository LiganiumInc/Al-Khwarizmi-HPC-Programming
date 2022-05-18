#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int MAX_STRIDE= 20;
    
    int N = 1000000;

    double *tab;

    tab = malloc(N*MAX_STRIDE*sizeof(double));
    int i, k, i_stride;
    
    double mean, begin, end,rate;


    for(k=0;k< N*MAX_STRIDE;k++){
        tab[k] =0;
    }

    

    for(i_stride = 1; i_stride <= MAX_STRIDE; i_stride++){
        mean = 0.0;

        begin = (double)clock() / (double) CLOCKS_PER_SEC;

        for(i =0 ; i < N*i_stride; i = i +i_stride){
           
            mean = mean + tab[i];

        }
        

        end = (double)clock() / (double) CLOCKS_PER_SEC;
        mean = mean / N;
 
         double millis = (end -  begin) * 1000.0 ;

         rate = (sizeof(double)* N * (1000.0 / millis) )/ (1024*1024);

         printf("%d , %f, %f, %f \n",i_stride,mean,millis,rate);
    }
}