#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./../include/funclib.h"
#include "./../include/optimizelib.h"
#include "./../include/comparelib.h"

int main(const int argc, const char** argv){
    const double alpha = (argc==3) ? atof(argv[2]) : 0.001;
    const int dim = f_dimension();
    double* var = malloc(dim * sizeof(double));
    for(int i=0 ; i<dim ; i++){
        var[i] = 0.01;
    }
    printf("alpha = %f\n", alpha);
    int size = 0;
    FILE* fp = fopen(argv[1], "r");
    if(fp==NULL){
        printf("cannot open file\n");
        return EXIT_FAILURE;
    }

    char c[100];
    double d1;
    double d2;
    while(1){
        int check = fscanf(fp, "%[^,]",c);
        fscanf(fp, "%*c");
        check += fscanf(fp, " %lf,",&d1);
        check += fscanf(fp, " %lf\n",&d2);
        if(check!=3){
            break;
        }
        size++;
    }
    rewind(fp);
    Sample* s = malloc(size * sizeof(Sample));
    size = 0;
    while(1){
        int check = fscanf(fp, "%[^,]",c);
        fscanf(fp, "%*c");
        check += fscanf(fp, " %lf,",&d1);
        check += fscanf(fp, " %lf\n",&d2);
        if(check!=3){
            break;
        }
        char* str = malloc(100 * sizeof(char));
        strcpy(str,c);
        Sample sn = {.loc = str, .alt = d1, .temp = d2};
        s[size] = sn;
        size++;
    }

    const int iter = optimize(alpha, dim, var, s, size, f_gradient, f_value);
    
    printf("number of iterations = %d\n", iter);


    qsort(s,size,sizeof(s[0]),comp_alt);
    for(int i=0 ; i<size ; i++){
        printf("%2d %20s, %7f, %7f\n",i+1, s[i].loc, s[i].alt, s[i].temp);
    }


    return 0;
}