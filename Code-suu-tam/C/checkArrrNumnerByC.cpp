#include <stdio.h>


int main() {
	int length;
	printf("enter length: ");
	scanf("%d", &length);
	int array[length];
	for(int i = 0; i < length; i++) {
		scanf("%d", &array[i]);
	}
	int flag = 1;
	for(int i = 0; i < length - 1; i++) {
		if(array[i] >= array[i + 1]) {
				flag = 0;
				break;
			}
	}
	
	if(flag == 1
	) {
		printf("day so tang dan.");
	} else {
		printf("day so khong dieu.");
	}
	return 1;
	
}
