#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


int main(){

    //initialisation des matrices 
    int i, j, k,ii,jj,kk,B,l, N = 1000;
    double *x, *y,*z;
    double begin, end, rate ;

    x = malloc(sizeof(double) * N);
    y = malloc(sizeof(double) * N);
    z = malloc(sizeof(double) * N);

    int block_table[] = {2,50,100,200,250,500};

    for(i = 0; i < N ; i++){
        for(j=0; j < N; j++){
            x[i,j] = 1.0;
            y[i,j] = 1.0;
            z[i,j] = 0.0;
        }
    }

    //multiplication par block


    for(l=0; l < sizeof(block_table)/sizeof(int); l++){

        B = block_table[l];

        

        begin = (double)clock() / (double) CLOCKS_PER_SEC;
    
        for (ii = 0; ii < N; ii+=B) {
            for (jj = 0; jj < N; jj+=B) {
                for (kk = 0; kk < N; kk+=B) {

                    for (i = ii; i < ii+B; i++) {
                        for (j = jj; j < jj+B; j++) {
                            for (k = kk; k < kk+B; k++) {
                                z[i,j] = z[i,j] + (x[i,k]*y[k,j]); //3 read + 1 write
                            }
                        }
                    }

                }
            }
        }

        end = (double)clock() / (double) CLOCKS_PER_SEC;

        double millis = (end -  begin) * 1000.0 ;

        // les 4 operations se font B^3 * (N/B) ^ 3 fois

        rate = ( sizeof(double)*  pow((N/B),3) * pow(B,3)  * 4 /(1024*1024) ) / (millis/1000.0) ;

        printf("%d,%f, %f \n",B,millis,rate);
    
    }
}
