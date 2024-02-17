#include<stdio.h>
#include<math.h>

int check_length(int number) {
	int value = 0;
	int result = 0;
	
	while(1) {
		result += pow(2, value);
		
		if(result >= number) {
			return value;
		}
		
		value++;
	}
}

void change_type(int number, int array[], int length) {
	while(number > 0) {
		for(int i = length; i >= 0; i--) {
			if(pow(2, i) <= number) {
				array[i] = 1;
				number -= pow(2, i);
			} else {
				array[i] = 0;
			}
		}
	}
}

int main() {
	
	
	int number;
	while(1) {
		
		scanf("%d", &number);
		if(number >= 0) {
			break;
		}
		printf("input ko hop le!\n");
	}
	int length;
	length = check_length(number);
	printf("length: %d\n", length);
	int array[length];
	
	change_type(number, array, length);
	
	for(int i = length; i >= 0; i--) {
		printf("%d", array[i]);
	}
	
}