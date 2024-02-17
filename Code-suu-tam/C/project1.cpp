#include <iostream>
#include <string>
void input_number(int &number);
void write(int &number);
void option(int number);
int main() {
	int number;
	input_number(number);
	option(number);
}

void input_number(int &number) {
	std::cout << "enter your number: ";
	std::cin >> number;
}
void write(int &number) {
	std::string text;
	std::cout << "enter your text: ";
	std::cin.ignore();
	getline(std::cin, text);
	std::cout << "your text is: ";
	std::cout << text << std::endl;
	input_number(number);
	option(number);
}
void option(int number) {
	if(number == 0) {
		write(number);
	}
}
