#include <stdio.h>
#include <math.h>
int nT(int num) {
	for(int i = 2; i < sqrt(num); i++ ) {
		if(num % i == 0) {
			return 0;
		}
		return 1;
	}
}
int main() {
	int array[3][4] = {{4, 5, 2, 1}, {5, 8, 9, 3}, {5, 1, 1, 8}};
	int sum = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			if(nT(array[i][j]) == 1) {
				sum += 1;
			}
		}
	}
	printf("tong so luong so nguyen to: %d", sum);
}
