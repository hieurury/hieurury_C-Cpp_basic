#include <stdio.h>
#include <math.h>

int main () {
	//CHU VI VA DIEN TICH HINH TRON
		int banKinh;
		float chuVi, dienTich;
		printf("nhap ban kinh: ");
		scanf("%d", &banKinh);
		dienTich = pow(banKinh, 2) * 3.14;
		chuVi = banKinh * 2 * 3.14;
		printf("dien tich hinh tron co ban kinh %d là: %.2f\n", banKinh, dienTich);
		printf("chu vi hinh tron co ban kinh %d la: %.2f\n", banKinh, chuVi);
		return 1;

}
