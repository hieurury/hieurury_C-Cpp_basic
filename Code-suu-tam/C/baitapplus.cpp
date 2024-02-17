#include <iostream>
#include <string>

void input_number(std::string label, int *n);
void input_arr(int arr[], int length);
void print_arr(int arr[], int length);
void push_arr(int* &arr, int length);
int main() {
	int n, x;
	input_number("n = ", &n);
	int *my_arr = new int[n];
	std::cout << "nhap mang: ";
	input_arr(my_arr, n);
	print_arr(my_arr, n);
	std::cout << std::endl;
	push_arr(my_arr, n);
	print_arr(my_arr, n);
}
void input_number(std::string label, int *n) {
	std::cout << label;
	std::cin >> *n;
}
void input_arr(int arr[], int length) {
	for(int i = 0; i < length; i++) {
		std::cin >> arr[i];
	}
}
void print_arr(int arr[], int length) {
	for(int i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
}
void push_arr(int* &arr, int length) {
	for(int i = length - 1; i > 0; i--) {
		for(int j = 0; j < i; j++) {
			if(arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	int *new_arr = new int[length];
	for(int i = 0; i < length; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
}
