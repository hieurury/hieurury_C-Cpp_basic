#include <stdio.h>
#include <math.h>

int main () {
//KHOANG CACH GIUA HAI DIEM TRONG HE TOA DO OXY
		int a, b, c, d;
		float khoangCach;
		printf("nhap toa do diem dau: ");
		scanf("%d%d", &a, &b);
		printf("nhap toa do diem sau: ");
		scanf("%d%d", &c, &d);
		khoangCach = sqrt(pow(a-c, 2) + pow(b-d, 2));
		printf("khoang cach giua (%d; %d) va (%d; %d) la: %.2f", a, b, c, d, khoangCach);
		return 1;
}
