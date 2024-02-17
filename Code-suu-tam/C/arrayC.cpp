#include <iostream>

int main() {
	int month;
	std::cout << "nhap thang can tinh: ";
	std::cin >> month;
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 9) {
		std::cout << "thang " << month << " co 30 ngay";
	} else if(month == 2) {
		std::cout << "thang 2 co 27 ngay";
	} else {
		std::cout << "thang " << month << " co 31 ngay";
	}
	return 1;
}
