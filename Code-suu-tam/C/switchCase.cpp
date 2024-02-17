#include <stdio.h>
#include <math.h>

int main() {
	int input, coin = 0;
	printf("nhap du lieu: ");
	scanf("%d", &input);
	
	if((input >= 0) && (input <= 9)) {
		printf("so diem cua ban là %d \n", input);
		switch(input) {
			case 9:
				coin += 900;
			case 8:
				coin += 800;
			case 7:
				coin += 700;
			case 6:
				coin += 600;
			case 5:
				coin += 500;
			case 4:
				coin += 400;
			case 3:
				coin += 300;
			case 2:
				coin += 200;
			case 1:
				coin += 100;
			case 0:
				coin += 0;
				break;
			default:
				printf("so diem chua du tieu chuan \n");
		}
		printf("tong phan thuong da nhan duoc là: %d coin \n", coin);
	} else {
		printf("xin hay nhap so");
	}
	
}
