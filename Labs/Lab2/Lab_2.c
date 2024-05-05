#include <stdio.h>
#include <stdlib.h>
#define N 20

void printArray(int a[], int length){
    for (int i=0; i<length; i++)
        printf("%2d ", a[i]);
    printf("\n");
}

int maxArray(int a[], int length){
	int max = a[0];
	for(int i = 1; i < length; i++){
		if(a[i] > max) max = a[i];
	}
	return max;
}

int main(void) {
    int arr[N];
    for (int i=0; i<N; i++){
        arr[i] = rand()%51;
    }
    printArray(arr, N);
    printf("Max element in array is: %d\n", maxArray(arr, N));
}

int euclid(int m, int n){
	int i = 1;
	int r;
	while(n != 0){
		r = m % n;
		printf("%d: m=%5d, n=%5d, r=%5d, q=%5d\n", i, m, n, r, m/n);
		m = n;
		n = r;
		i++;
	}

	return m;
}

int consecutive(int m, int n){
	int t = (m < n) ? m : n;
	while(1){
		if(m % t == 0) if(n % t == 0) return t;
		t--;
	}
}

//consecutive method main
//int main(){
//	int m = 60, n = 24;
//	printf("GCD(%d, %d) is %d\n", m, n, consecutive(m, n));
//	m = 31415, n = 14142;
//	printf("GCD(%d, %d) is %d\n", m, n, consecutive(m, n));
//	m = 1155, n = 12597;
//	printf("GCD(%d, %d) is %d\n", m, n, consecutive(m, n));
//}

//euclid method main
//int main(){
//	int m = 1155, n = 12597;
//	printf("\nGCD(%d, %d) is %d\n", m, n, euclid(m, n));
//}
