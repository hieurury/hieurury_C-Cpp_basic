#include <stdio.h>
#include <math.h>

int main () {
//KIEM TRA XE CO PHAI NAM NHUAN HAY KHONG
	int input;
	printf("nhap nam can kiem tra: ");
	scanf("%d", &input);
	if(input % 400 == 0 || (input % 4 == 0 && input % 100 != 0)) {
		printf("nam %d la nam nhuan", input);
		
	} else {
		printf("nam %d khong phai la nam nhuan", input);
	}
	return 1;
}
