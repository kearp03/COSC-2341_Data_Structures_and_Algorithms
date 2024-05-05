#include <stdio.h>
#define N 10

int A[N] = {-4, -1, 2, 5, 11, 10, 20, 30, 40, 50};

int binarySearch(int n, int k){
	int l = 0, r = n-1;
	int count = 0;
	while(l <= r){
		int m = (l+r)/2;
		count++;
		if(k == A[m]) return count;
		else if(k < A[m]) r = m - 1;
		else l = m + 1;
	}
	return count;
}

int main(){
	int comp;
	int keys[] = {50, 2, 42, -10}; //change to try other keys
	for(int j = 0; j < sizeof(keys)/sizeof(keys[0]); j++){
		//call the function
		comp = binarySearch(N, keys[j]);
		//print the result
		printf("Key %3d took %d comparisons\n", keys[j], comp);
	}
}
