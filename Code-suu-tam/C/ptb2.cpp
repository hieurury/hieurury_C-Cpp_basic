#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	float delta, x1, x2;
	printf("nhap a: ");
	scanf("%d", &a);
	printf("nhap b: ");
	scanf("%d", &b);
	printf("nhap c: ");
	scanf("%d", &c);
	delta = (float)(pow(b, 2) - (4 * a * c));
	printf("phuong trinh %dx² + (%dx) + (%d)\n", a, b, c);
	printf("co delta: %.2f\n", delta);
	printf("------------------------\n");
	if(delta > 0) {
		printf("phuong trinh co 2 nghiem phan biet\n");
		x1 = ((-b + sqrt(delta)) / (2 * a));
		x2 = ((-b - sqrt(delta)) / (2 * a));
		printf("x1: %.2f\n", x1);
		printf("x2: %.2f\n", x2);
	} else if(delta == 0) {
		printf("phuong trinh co nghiem kep\n");
		x1 = (-b / (2 * a));
		x2 = x1;
		printf("x: %.2f\n", x2);
	} else {
		printf("phuong trinh vo nghiem\n");
	}
	
}
