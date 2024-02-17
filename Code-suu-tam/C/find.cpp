#include <stdio.h>
void find(int r, int c, int x, int y, int array[]) {
	for(int i = 0; i < r + 1; i++) {
		for(int j = 0; j < c + 1; j++) {
			if(i == 0 && j > 0) {
				printf("%d ", j);
			} else if( i > 0 && j == 0) {
				printf("%d ", i);
			} else if(i == 0 && j == 0) {
				printf("  ");
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}
int main() {
	int c, r;
	printf("nhap so hang va so cot: ");
	scanf("%d%d", &r, &c);
	int array[r][c];
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			printf("nhap gia tri hang %d cot %d: ", i + 1, j + 1);
			scanf("%d", &array[i][j]);
		}
	}
	for(int i = 0; i < r + 1; i++) {
		for(int j = 0; j < c + 1; j++) {
			if(i == 0 && j > 0) {
				printf("%d ", j);
			} else if( i > 0 && j == 0) {
				printf("%d ", i);
			} else if(i == 0 && j == 0) {
				printf("  ");
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
	int x, y;
	printf("nhap vi tri can tra cuu: ");
	scanf("%d%d", &x, &y);
	printf("---------------\n");
	printf("gia tri tai x %d y %d la: %d\n", x, y, array[x-1][y-1]);
	printf("------------\n");
	find(r, c, x, y, array[r][c]);
	
}
