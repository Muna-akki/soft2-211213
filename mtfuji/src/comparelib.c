#include <stdio.h>
#include <stdlib.h>
#include "./../include/funclib.h"

int comp_alt(const void* x0, const void *x1)
{
    const Sample *p0 = (Sample*)x0;
    const Sample *p1 = (Sample*)x1;
    double val = p0->alt - p1->alt;
    if(val==0){
        return 0;
    }else if(val>0){
        return 1;
    }else{
        return -1;
    }
}