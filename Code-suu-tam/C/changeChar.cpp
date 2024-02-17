#include <stdio.h>
#include <math.h>

	int main() {
		//CHUYEN DOI GIU CHU HOA VA CHU THUONG
	char input;
	printf("nhap ki tu can chuyen doi: ");
	scanf("%c", &input);
	if((input >= 97) && (input <= 122)) {
		printf("ki tu '%c' la chu thuong ",input);
		input = ((input - 'a') + 'A');
		printf("da duoc chuyen doi sang chu hoa la '%c'", input);
		
	} else if((input >= 65) && (input <= 90)){
		printf("ki tu '%c' la chu hoa ", input);
		input = ((input - 'A') + 'a');
		printf("da duoc chuyen sang chu thuong la '%c'", input);
	} else {
		printf("nhap cai dell gi co biet cai gi dau ma !");
	}
	return 1;
}
