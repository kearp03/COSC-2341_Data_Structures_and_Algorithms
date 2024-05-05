#include <stdio.h>
#include <math.h>

double t(double x){
	//return 5 * x * x * pow(x, 1.0/3.0);
	return 5 * x * x * cbrt(x);
}

double g(double x){
	return 10000 * x * sqrt(x) * log10(x);
}

int main(){
	int n = 59720;
	double tn, gn;
	while(1){
		tn = t((double)n), gn = g((double)n);
		printf("n = %2d: %lf %lf\n",n, tn, gn);
		if(tn > gn) break;
		n++;
	}
}
