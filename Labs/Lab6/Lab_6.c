#include <stdio.h>
#include <math.h>

int fib1(int n){
	double phi = (1 + sqrt(5.0))/2;
	return round((pow(phi, n)/sqrt(5.0)));
}

int fib2(int n){
	if(n <= 1) return n;
	else return fib2(n-1) + fib2(n-2);
}

int fib3(int n){
	int f[100] = {0, 1}; // rest of values initialized to 0
	for(int i = 2; i <= n; i++)
		f[i] = f[i-1] + f[i-2];
	return f[n];
}

int fun1(int n){
	return pow(3, n-1)*(3 + 2*n);
}

int fun2(int n){
	if(n == 0) return 1;
	else if(n == 1) return 5;
	else return 6*fun2(n-1) - 9*fun2(n-2);
}

int fun3(int n){
	int f[20] = {1, 5}; // rest of values initialized to 0
	for(int i = 2; i < n+1; i++)
		f[i] = 6*f[i-1] - 9*f[i-2];
	return f[n];
}

int main(){
	printf("   fib1(n)\tfib2(n)\t\tfib3(n)\n");
	for(int n = 0; n < 41; n++)
		printf("%2d %9d\t%9d\t%9d\n", n, fib1(n), fib2(n), fib3(n));

	printf("\n\n");

	printf("   fun1(n)\tfun2(n)\t\tfun3(n)\n");
	for(int n = 0; n <= 15; n++)
		printf("%2d %9d\t%9d\t%9d\n", n, fun1(n), fun2(n), fun3(n));

}
