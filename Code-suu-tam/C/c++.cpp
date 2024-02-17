#include <iostream>
#include <stdio.h>


int main() {
	int old;
//	std::cout << "enter your old: ";
//	std::cin >> old;
//	std::cout << "....processing \n";
//	std::cout << "successful! \n";
//	std::cout << "your old is: " << old;
	printf("enter your old: ");
	scanf("%d", &old);
	printf("....processing \n");
	printf("successful! \n");
	printf("your old is: %d", old);
}
