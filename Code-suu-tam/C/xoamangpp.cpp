#include <iostream>

int main() {
	int n, x;
	while(true) {
		std::cout << "nhap n: ";
		std::cin >> n;
		if(n >= 0 && n <= 10) {
			break;
		}
	}	
	int mang[n];
	std::cout << "nhap mang: ";
	for(int i = 0; i < n; i++) {
		std::cin >> mang[i];
	}
	
	while(true) {
		std::cout << "nhap x: ";
		std::cin >> x;
		if(x >= 0 && x <= 9) {
			break;
		}
	}
	for(int i = 0; i < n; i++) {
		if(i == x) {
			mang[i] = 0;
		}
	}
	std::cout << "mang da xoa: ";
	for(int i = 0; i < n; i++) {
		std::cout << mang[i] << " ";
	}
}
