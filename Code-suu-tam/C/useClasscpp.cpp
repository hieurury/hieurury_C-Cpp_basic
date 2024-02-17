#include <iostream>
#include <string>
#include <vector>
class User;
class Account;

class User {
	private:
		std::string name;
		int age;
	public:
		std::string get_name() {
			return this->name;
		}
		
		int get_age() {
			return this->age;
		}
		
		friend std::istream& operator>>(std::istream &is, User &user) {
			std::cout << "nhap ten: ";
			getline(is, user.name);
			std::cout << "nhap tuoi: ";
			std::cin >> user.age;
		}
		friend std::ostream& operator<<(std::ostream &os, User &user) {
			os << "ten: " << user.name;
			os << " tuoi: " << user.age << std::endl;
		}
		
		friend Account;
};
class Account {
	private:
		User *accounts = new User[0];
	public:
		void add_user(User* &arr) {
			int length = arr.length(arr);
			User *new_accounts = new User[length + 1];
			for(int i = 0; i < length; i++) {
				new_accounts[i] = arr[i];
			}
			
			std::cin >> new_accounts[length];
			
			delete[] arr;
			arr = new_accounts;
		}
		
		void print_accounts(User* &arr) {
			if(arr.size() == 0) {
				std::cout << "danh sach trong" << std::endl;
			} else {
				for(int i = 0; i< length; i++) {
					std::cout << arr[i];
				}
			}
			
		}
		friend User;	
		
};



int main() {
	Account accounts1;
	accounts1.add_user(accounts1);
	
	return 1;
}
