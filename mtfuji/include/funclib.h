#pragma once

typedef struct {
    char *loc;   // location name
    double alt;  // altitude (km)
    double temp; // temperature (centigrade)
} Sample;

int f_dimension();
double f_value(const Sample s[], const int size, const double var[]);
void f_gradient(const Sample s[], double g[], const int size, const double var[]);
