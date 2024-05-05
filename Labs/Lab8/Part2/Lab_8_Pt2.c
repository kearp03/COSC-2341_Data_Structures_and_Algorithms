#include <stdio.h>
#include <stdlib.h>
#define N 7

int main(){
	int amat[N+1][N+1] = {	{0, 0, 0, 0, 0, 0, 0, 0},  //0
							{0, 0, 1, 0, 1, 0, 0, 0},  //1
							{0, 0, 0, 0, 0, 0, 0, 0},  //2
							{0, 0, 1, 0, 0, 1, 0, 1},  //3
							{0, 0, 1, 0, 0, 1, 1, 1},  //4
							{0, 0, 1, 1, 0, 0, 1, 0},  //5
							{0, 0, 0, 0, 0, 0, 0, 1},  //6
							{0, 0, 0, 0, 0, 0, 0, 0}}; //7

	int max = -1, maxI = -1;

	for(int i = 1; i < N+1; i++){
		for(int j = 1; j < N+1; j++){
			amat[i][0] += amat[i][j];
		}

		printf("Vertex %i is connected to %i other vertices\n", i, amat[i][0]);

		if(amat[i][0] > max){
			max = amat[i][0];
			maxI = i;
		}
	}
	printf("\nVertex %i is connected to the most vertices: %i other vertices\n", maxI, max);
}
