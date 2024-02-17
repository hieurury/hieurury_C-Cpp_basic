#include <iostream>

int main() {
	char input[100];
	std::cout << "nhap ten: ";
	fgets(input, sizeof(input) + 1, stdin);
	int array[100];
	array[0] = input;
	std::cout << (char)array[0];
	
}
