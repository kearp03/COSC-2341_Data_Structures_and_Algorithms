#include <stdio.h>
#define N 5

int A[N][N] = { {10, 2, 3, 4, -5},
				{2, 10, 20, 30, 40},
				{3, 20, 50, 60, 70},
				{4, 30, 60, 80, 90},
				{5, 40, 70, -10, 95} };

int minMat(int mat[N][N], int rows, int cols){
	int min = mat[0][0];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(mat[i][j] < min) min = mat[i][j];
		}
	}
	return min;
}

int main(){
	//call the function!
	int min = minMat(A, N, N);
	//display the result!
	printf("The minimum of the matrix is : %d\n", min);
}
