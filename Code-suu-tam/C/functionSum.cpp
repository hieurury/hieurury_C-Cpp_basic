#include <stdio.h>
#include <math.h>

int check(int n) {
	int a = n, b = n, x = 0, y;
	while(a != 0) {
		x += a % 10;
		a /= 10;
	}
	if(x % 8 == 0) {
		while(b != 0) {
			y = b % 10;
			b /= 10;
			if(y == 6) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	printf("cac so co tong chia het cho 8 va chua so 6 trong pham vi 1 -> 1000:\n");
	printf("--------------------------\n");
	for (int i = 1; i <= 1000; i++) {
		if(check(i) == 1) {
			printf("%d ", i);
		}
	}
}
