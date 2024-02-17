#include <iostream>
#include <string>

int main() {
	std::string arr[10][10];
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 6; j++) {
			if(j == 0 && i == 0) {
				arr[i][j] = "Ho va Ten ";
			} else if( i == 0 && j == 5) {
				arr[i][j] = "Xep loai ";
			} else if(j == 0 && i != 0) {
				std::cout << "ten hang " << i << " ";
				getline(std::cin, arr[i][j]);
			} else if(j == 5 && i != 0) {
				std::cout << "xep loai hang " << i << " ";
				getline(std::cin, arr[i][j]);
			} else {
				arr[i][j] = "  ";
			}					
		}
	}
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 6; j++) {
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}
}
