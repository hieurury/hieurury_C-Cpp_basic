#include <stdio.h>


int main() {
	int length;
	printf("Nhap do dai cua mang: ");
	scanf("%d", &length);
	int array[length];
	
	for(int i = 0; i < length; i++) {
		printf("Phan tu thu %d: ", i);
		scanf("%d", &array[i]);
	}
	
	printf("DANG SAP XEP....\n");
	
	for(int i = length - 1; i > 0; i--) {
		for(int j = 0; j < i; j++) {
			if(array[j] > array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
	printf("Result: ");
	for(int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
}