#pragma once
#include "funclib.h"
int optimize(const double alpha,const int dim,double var[],
            const Sample s[], const int size,
            void (*calc_grad)(const Sample s[], double g[], const int size, const double var[]),
            double (*f_value)(const Sample s[], const int size, const double var[]));