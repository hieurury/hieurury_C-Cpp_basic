

#include <iostream>
#include <stdio.h>
#include <math.h>

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

void sang_so(int l, int r) {
	int length = r - l + 1;
	int array[length];

	for (int i = 0; i <= length; i++) {
		array[i] = 1;
	}

	for (int i = 2; i <= sqrt(r); i++) {
		for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) {
			array[j] = 0;
		}
	}

	for (int i = max(l, 2); i <= r; i++) {
		if (array[i - l]) {
			printf("%d ", i);
		}
	}
}
int main() {
	int l, r;
	scanf("%d%d", l, r);
	sang_so(l, r);
}