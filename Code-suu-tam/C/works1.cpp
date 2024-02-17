#include <stdio.h>
#include <math.h>
void nT(int array[], int length, int soDiem) {
	for(int i = 0; i < length; i++) {
		array[i] = soDiem++;
	}
}

int main() {
	int soDau, soCuoi, length;
	printf("nhap pham vi cua mang: ");
	scanf("%d%d",&soDau, &soCuoi);
	printf("pham vi hien tai: [%d; %d]\n", soDau, soCuoi);
	length = soCuoi - soDau + 1;
	printf("do dai cua mang la: %d\n", length);
	int array[length];
	nT(array, length, soDau);
	for(int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	
	
	return 1;
}
