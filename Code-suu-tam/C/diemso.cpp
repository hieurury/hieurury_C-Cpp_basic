#include <stdio.h>
#include <math.h>
//DIEM SO LUONG SO CHAN VA SO LE
int main() {
	int x, y, soChan = 0, soLe = 0;
	printf("DAY LA CHUONG TRINH DIEM SO LUONG SO CHAN VA LE TRONG DOAN [x; y]\n");
	printf("-------------------------------------------------\n");
	printf("nhap x: ");
	scanf("%d", &x);
	printf("nhap y: ");
	scanf("%d", &y);
	printf("--------------------------------------------------\n");
	if(x > y) {
		printf("gia tri dau vao cua ban khong hop le!");
	} else {
		printf("phan loai so chan le trong doan [%d; %d]\n", x, y);
		for(int i = x; i <= y; i++) {
			if(i % 2 == 0) {
				soChan += 1;
			} else {
				soLe += 1;
			}
			
		}
		printf("- so luong so chan la: %d\n", soChan);
		printf("- so luong so le la: %d\n", soLe);	
	}
	
	
}
	
