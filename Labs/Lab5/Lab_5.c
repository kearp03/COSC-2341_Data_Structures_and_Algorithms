#include <stdio.h>
#include <stdbool.h>
#define N 5

int A[N][N] = {{1,  2,  3,  4,  5},
               {2, 10, 20, 30, 40},
               {3, 20, 50, 60, 70},
               {4, 30, 60, 80, 90},
               {5, 40, 70, 90, 95} };

int B[N][N] = {{1,  2,  3,  4,  5},
               {2, 10, 10, 30, 40},
               {3, 20, 50, 60, 70},
               {4, 30, 60, 80, 90},
               {5, 40, 70, 90, 95} };

bool enigma(int a[N][N], int rows, int cols){
    for(int i = 0; i < rows-1; i++)
        for(int j = i+1; j < cols; j++)
        	if(a[i][j] != a[j][i])
        		return false;
    return true;
}

int main(){
	printf("A: %d", enigma(A, N, N));
	printf("\n");
	printf("B: %d\n", enigma(B, N, N));
}




int euclid(int m, int n){
	int r;
	while(n!=0){
		r = m%n;
		m = n;
		n = r;
	}
	return m;
}

int euclid_count(int m, int n){
	int count = 0, r;
	while(n!=0){
		r = m%n;
		m = n;
		n = r;
		count++;
	}

	return count;
}

int main1(){
	const int xMax = 200, yMax = 200;
	int max = 0;
	double sum = 0.0;

	for(int x = 1; x <= xMax; x++){
		for(int y = 1; y <= yMax; y++){
			int count = euclid_count(x, y);
			sum += count;
			if(count > max) max = count;
		}
	}

	printf("Worst case  : %d operations\n", max);
	printf("Average case: %.3lf operations\n", sum/xMax/yMax);
	return 0;
}

