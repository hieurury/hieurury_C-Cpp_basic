#include <stdio.h>

int main() {
	int array[5][5] = {{7, 3, 4, 2, 1}, {1, 1, 1, 5, 6}, {0, 6, 7, 8, 2}, {6, 9, 1, 2, 2}, {2, 5, 1, 8, 2}};
	int sum = 0;
	int n = 4;
	for(int i = 0; i < 5; i++) {
		sum += array[i][n];
		n--;
	}
	printf("sum: %d", sum);
}
