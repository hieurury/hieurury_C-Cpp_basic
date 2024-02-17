#include <iostream>
#include <string>
#include <vector>
class Sever;
class User {
private:
	std::string name;
	int pass;
public:
	std::string get_name() {
		return this->name;
	}
	int get_pass() {
		return this->pass;
	}
	friend Sever;
};
class Sever {
	private:
		std::vector<User> accounts;
	public:
		void add_user(std::string name, int pass) {
			User new_user;
			new_user.name = name;
			new_user.pass = pass;
			
			this->accounts.push_back(new_user);
		}
		void get_account(std::string name) {
			for(int i = 0; i < accounts.size(); i++) {
				if(name == accounts[i].name) {
					std::cout << "name: " << accounts[i].name << " ";
					std::cout << "pass: " << accounts[i].pass << std::endl;
					return;
				}
				
			}
			std::cout << "not found!";
		} 
};

int main() {
	Sever sever1;
	sever1.add_user("hieu", 123); 
	sever1.add_user("linh", 321); 
	sever1.add_user("trang", 111); 
	sever1.get_account("linh"); 
	return 1;
}
