#include <iostream>
int main() {
	char str[100] = "hieu";
	str[10];
	int length = sizeof str / sizeof(char);
	std::cout << length;
//	for(int i = 0; i < length; i++) {
//		std::cout << str[i] << std::endl;	
//	}
		
}
