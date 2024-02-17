#include <iostream>
#include <string>
struct User {
	std::string email;
	std::string password;
	
	User() {
	}
	
	User(std::string _email, std::string _password) {
		email = _email;
		password = _password;
	}
	user_print() {
		std::cout << "email: " << email << " | " << "password: " << password << std::endl;
	}
};
void input_number(std::string label, int &number);
void input_arr(User arr[], int length);
void login(User arr[], int length);
int main() {
	int length;
	input_number("length = ", length);
	User *users = new User[length];
	input_arr(users, length);
	std::cout << std::endl;
	std::cout << "tai khoan da tao:" << std::endl;
	for(int i = 0; i < length; i++) {
		users[i].user_print();
	}
	std::cout << std::endl;
	int number;
	chosse:
		input_number("number = ", number);
		if(number == 0) {	
			std::cout << std::endl;	
			std::cout << "dang nhap tai khoan:" << std::endl;
			login(users, length);
			goto chosse;
		} else if(number == -1) {
			std::cout << std::endl;
			std::cout << "ket thuc chuong trinh!";
		} else {
			goto chosse;
		}
}
void input_number(std::string label, int &number) {
	std::cout << label;
	std::cin >> number;
}
void input_arr(User arr[], int length) {
	for(int i = 0; i < length; i++) {
		std::cout << "nhap email nguoi dung " << i + 1 << ": ";
		std::cin.ignore();
		getline(std::cin, arr[i].email);
		std::cout << "nhap password nguoi dung " << i + 1 << ": ";
		std::cin.ignore();
		getline(std::cin, arr[i].password);
	}
}
void login(User arr[], int length) {
	std::string login_email;
	std::string login_password;
	std::cout << "email: ";
	std::cin.ignore();
	getline(std::cin, login_email);
	std::cout << "password: ";
	std::cin.ignore();
	getline(std::cin, login_password);
	for(int i = 0; i < length; i++) {
		if(login_email == arr[i].email && login_password == arr[i].password) {
			std::cout << "login sussecfully" << std::endl;
			return;
		}
	}
	std::cout << "login fail!";
}
