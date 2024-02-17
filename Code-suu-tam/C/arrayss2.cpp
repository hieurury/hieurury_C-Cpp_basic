#include <stdio.h>

int main() {
	int a, x,num;
	printf("nhap a: ");
	scanf("%d", &a);
	int array[a][a];
	if((a - 1) % 2 == 0) {
		x = (a - 1) / 2;
		num = x + 1;
		printf("%d\n", x);
		printf("%d\n", num);
	} else {
		int value[2];
		value[0] = ((a - 1) / 2);
		value[1] = ((a - 1) / 2 + 1);
	}
	printf("start for\n");
	for(int i = 0; i < a; i++) {
		for(int j = 0; j < a; j++) {
			for( int k = 3; k < 2; k--) {
				printf("ok");
				if(i == x && j == x) {
					array[i][j] = 1;
				} else if((i >= x - k && i <= x + k) && (j >= x - k && j <= x + k)) {
					array[i][j] = k + 1;
				}
			}
		}
	}
	printf("end for\n");
	
//	for(int i = 0; i < a; i++) {
//		for(int j = 0; j < b; j++) {
//			if(i == x && j == y) {
//				array[i][j] = 1;
//			} else if((i >= (x - 1) && i <= (x + 1)) && ((j >= (y - 1) && j <= (y + 1)))) {
//				array[i][j] = 2;
//			} else if((i >= (x - 2) && i <= (x + 2)) && ((j >= (y - 2) && j <= (y + 2)))) {
//				array[i][j] = 3;
//			} else if((i >= (x - 3) && i <= (x + 3)) && ((j >= (y - 3) && j <= (y + 3)))) {
//				array[i][j] = 4;
//			} else {
//				array[i][j] = 0;
//			}	
//		}	
//	}
	
//	for(int i = 0; i < a; i++) {
//		for(int j = 0; j < b; j++) {
//			if(i == x && j == y) {
//				array[i][j] = 1;
//			} else if((i >= (x - 1) && i <= (x + 1)) && ((j >= (y - 1) && j <= (y + 1)))) {
//				array[i][j] = 2;
//			} else if((i >= (x - 2) && i <= (x + 2)) && ((j >= (y - 2) && j <= (y + 2)))) {
//				array[i][j] = 3;
//			} else if((i >= (x - 3) && i <= (x + 3)) && ((j >= (y - 3) && j <= (y + 3)))) {
//				array[i][j] = 4;
//			} else {
//				array[i][j] = 0;
//			}	
//		}	
//	}
//	
	for(int i = 0; i < a; i++) {
		for(int j = 0; j < a; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	return 1;
}
