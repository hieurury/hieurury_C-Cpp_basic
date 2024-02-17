#include <stdio.h>
#include <math.h>
void time(int value) {
	int days, hours, minutes;
	days = value / 86400;
	value -= days * 86400;
	hours = value / 3600;
	value -= hours * 3600;
	minutes = value / 60;
	printf("thoi gian duoc quy doi la: \n");
	printf("%d ngay, %d gio, %d phut \n", days, hours, minutes);
}
int main() {
	int setTime;
	printf("nhap thoi gian can quy doi: ");
	scanf("%d", &setTime);
	time(setTime);
	return 1;
}
