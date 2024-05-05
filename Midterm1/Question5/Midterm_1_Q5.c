#include <stdio.h>

int sequentialSearch(int A[], int k, int n){
	int i = 0;
	while(i < n && A[i] != k){
		i++;
	}
	if(i < n) return i;
	else return -1;
}

int main(){
	int arr[] = {90, -10, 30, 70, 20, 30, 10};
	int size = sizeof(arr)/sizeof(int);

	int key = -30;
	int keyIndex = sequentialSearch(arr, key, size);
	if(keyIndex != -1) printf("Key %d is found at index %d\n", key, keyIndex);
	else printf("Key %d is not found\n", key);

	key = 30;
	keyIndex = sequentialSearch(arr, key, size);
	if(keyIndex != -1) printf("Key  %d is found at index %d\n", key, keyIndex);
	else printf("Key  %d is not found\n", key);

	key = 35;
	keyIndex = sequentialSearch(arr, key, size);
	if(keyIndex != -1) printf("Key  %d is found at index %d\n", key, keyIndex);
	else printf("Key  %d is not found\n", key);

}
