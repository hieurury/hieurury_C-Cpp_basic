#include <stdio.h>
#include <math.h>

int a(int callBack(int), int n) {
	callBack(n);
}

int b(int x) {
	int sum;
	for (int i = 1; i <= x; i++) {
		sum += i;
	}
	return sum;
}

int main () {
	int num;
	printf("nhap num: ");
	scanf("%d", &num);
	int result = a(b, num);
	printf("tong cac so tu 1 den %d la: %d", num, result);
	
}
