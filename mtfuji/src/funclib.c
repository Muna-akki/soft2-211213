#include <stdio.h>
#include "./../include/funclib.h"
// 必要に応じてヘッダファイルを追加する


int f_dimension()
{
	return 2;
}

double f_value(const Sample s[], const int size, const double var[])
{
	double ret  = 0;
	for(int i=0 ; i<size ; i++){
		double f = (s[i].temp - var[0]*s[i].alt - var[1]);
		ret += f*f;
	}
	return ret;
}

void f_gradient(const Sample s[], double g[], const int size, const double var[])
{
    double g0 = 0;
	double g1 = 0;
	for(int i=0 ; i<size ; i++){
		double f = s[i].temp - var[0]*s[i].alt - var[1];
		g0 -= 2*f*s[i].alt;
		g1 -= 2*f;
	}
	g[0] = g0;
	g[1] = g1;
}

