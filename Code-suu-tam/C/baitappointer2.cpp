#include <iostream>
#include <string>
void input_number(std::string label, int &n);
void input_arr(int arr[], int length);
void print_arr(int arr[], int length);
void push_index(int* &arr, int &length, int index, int new_number);
int main() {
	int n, x, z;
	input_number("n = ", n);
	int *my_arr = new int[n];
	std::cout << &my_arr[2] << std::endl;
	std::cout << "nhap mang: ";
	input_arr(my_arr, n);
	print_arr(my_arr, n);
	std::cout << std::endl;
	input_number("x = ", x);
	input_number("z =", z);
	push_index(my_arr, n, x, z);
	std::cout << &my_arr[2] << std::endl;
	print_arr(my_arr, n);
}
void input_number(std::string label, int &n) {
	std::cout << label;
	std::cin >> n;
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
void push_index(int* &arr, int &length, int index, int new_number) {
	int *new_arr = new int[length + 1];
	for(int i = 0; i < length; i++) {
		new_arr[i] = arr[i];
	}
	for(int i = index + 1; i < length + 1; i++) {
		new_arr[i] = arr[i - 1];
	}
	new_arr[index] = new_number;
	delete[] arr;
	arr = new_arr;
	length++;
}
