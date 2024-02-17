#include <iostream>
#include <string>

int main() {
	std::string name;
	std::cout << "nhap ten: ";
	getline(std::cin, name);
	
	std::cout << "name: " << name;
}