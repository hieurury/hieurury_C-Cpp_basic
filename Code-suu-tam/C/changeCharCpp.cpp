#include <iostream>

int main() {
	char input, output;
	std::cout << "input: ";
	std::cin >> input;
	if(((int)input >= 65 && (int)input <= 90) || ((int)input >= 97 && (int)input <= 122)) {
		if((int)input >= 65 && (int)input <= 90) {
			output = (int)input + 32;
			std::cout << "output: " << (char)output;
		} else if((int)input >= 97 && (int)input <= 122) {
			output = (int)input - 32;
			std::cout << "output: " << (char)output;
		}
	} else {
		std::cout << "input khong hop le!";
	}
}
