#include <iostream>
int main() {
	int arr[4] = {4, 3, 2, 1};
	for(int i = 3; i > 0; i--) {
		for(int j = 0; j <= i; j++) {
			if(arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for(int i = 0; i < 4; i++) {
		std::cout << arr[i] << " ";
	}
}
