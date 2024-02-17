#include <stdio.h>
#include <math.h>

void timSo(int a[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int x;
		if(a[i] > a[i + 1]) {
			x = a[i];
			a[i] = a[i + 1];
			a[i + 1] = x;		
		}
	}
}


int main() {
	int start, diem = 0;
	printf("gioi han phan tu trong mang la: ");
	scanf("%d", &start);
	int array[start];
	for(int i = 0; i < start; i++) {
		printf("phan tu thu %d la: ", i + 1);
		scanf("%d", &array[i]);
	}
	timSo(array, start);
	for(int i = 0; i < start; i++) {
		printf("%d ", array[i]);
	}
	return 1;
	
	 
}
