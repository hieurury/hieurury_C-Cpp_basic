#include <stdio.h>
#include <math.h>

int main() {
	int input, bienDiem;
	printf("nhap so: ");
	scanf("%d", &input);
	
	while(input != 0) {
		bienDiem = input % 10;
		printf("%d\n", bienDiem);
		input /= 10;
	}
	
}
