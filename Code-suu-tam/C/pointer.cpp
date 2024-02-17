#include <iostream>

int main() {
	int n;
	std::cout << "n = ";
	std::cin >> n;
	int *x = new int[n];
	for(int i = 0; i < n; i++) {
		std::cin >> x[i];	
	}
	std::cout << "mang truoc khi them phan tu" << std::endl;
	for(int i = 0; i < n; i++) {
		std::cout << x[i] << " ";	
	}
	std::cout << "\n";
	std::cout << x << std::endl;
	int *y = new int[n + 1];
	std::cout << y << std::endl;
	for(int i = 0; i < n; i++) {
		y[i] = x[i];
	}
	int m;
	std::cout << "m = ";
	std::cin >> m;
	y[n] = m;
	delete x;
	x = y;
	std::cout << "mang sau khi them phan tu" << std::endl;
	for(int i = 0; i < n + 1; i++) {
		std::cout << x[i] << " ";
	}
	std::cout << "\n";
	std::cout << x << std::endl;
	std::cout << y << std::endl;
}
