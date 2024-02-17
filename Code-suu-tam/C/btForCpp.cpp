#include <iostream>

int main() {
	std::string input;
	std::cout << "nhap chuoi: ";
	getline(std::cin, input);
	again_1:
		//xoa khoang tran dau cuoi
		bool value = 1;
		while(value) {
			if(input[0] == ' ') {
				input.erase(0, 1);
				goto again_1;
			} else if(input[input.length() - 1] == ' ') {
				input.erase(input.length() - 1, 1);
				goto again_1;
			} else {
				value = 0;
			}
		}
		std::cout << "sau khi xoa khoang trang dau va cuoi: " << input << std::endl;
		//xoa khoang trang thua 
		again_2:
		while(1) {
			for(int i = 0; i < input.length() - 1; i++) {
				if(input[i] == ' ' && input[i + 1] == ' ') {
					input.erase(i + 1, 1);
					goto again_2;
				}
			}
			break;
		}
		std::cout << "sau khi xoa khoang trang thua: " << input << std::endl;
		//chuan hoa chu hoa <-> chu thuong
		for(int i = 0; i < input.length(); i++) {
			if(i == 0) {
				if(input[i] > 90) {
					input[i] -= 32;
				}
			} else if(input[i] == ' ' && input[i + 1] > 90) {
				input[i + 1] -= 32;
			} else if(input[i] < 97 && input[i] != ' ' && input[i - 1] != ' ') {
				input[i] += 32;
			}
		}
	std::cout << "ket qua cuoi cung: " << input;
}
