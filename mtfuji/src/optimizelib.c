#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "./../include/optimizelib.h"
#include "./../include/funclib.h"
double calc_norm(const int dim, double v[]){
    double ret = 0;
    for(int i=0 ; i<dim ; i++){
        ret += v[i]*v[i];
    }
    ret = sqrt(ret);
    return ret;
}
int optimize(const double alpha,const int dim,double var[],
            const Sample s[], const int size,
            void (*calc_grad)(const Sample s[], double g[], const int size, const double var[]),
            double (*f_value)(const Sample s[], const int size, const double var[])){
    
    
    double *g = malloc(dim * sizeof(double));
    
    int iter = 0;
    while(++iter < 10000){
        (*calc_grad)(s,g,size,var);
        const double norm = calc_norm(dim,g);
        //printf("%3d norm = %7.4f", iter, norm);
        for(int i=0 ; i<dim ; i++){
            //printf(", var[%d] = %7.4f", i, var[i]);
        }
        //double e = (f_value)(s, size, var);
        //printf(", E = %7.4f", e);
        //printf("\n");

        if(norm<0.001){
            double answer = var[0]*3.776 + var[1];
            printf("The average temperature at the top of t Fuji in July is %7.4f degrees Celsius.\n",answer );
            break;
        }
        for(int i=0 ; i<dim ; i++){
            var[i] -= alpha * g[i];
        }
    }

    free(g);

    return iter;
}