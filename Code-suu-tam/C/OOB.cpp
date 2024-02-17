#include <iostream>
#include <string>

class Student {
	public:
		std::string name;
		int age;
		std::string mssv;
		Student() {
		}
		
		Student(std::string _name, int _age, std::string _mssv) {
			name = _name;
			age = _age;
			mssv = _mssv;
		}
		
		print() {
			std::cout << "Ten: " << name << std::endl;
			std::cout << "Tuoi: " << age << std::endl;
			std::cout << "MSSV: " << mssv << std::endl;
		}
		friend std::istream& operator>>(std::istream &is, Student &student) {
			std::cout << "Ten: ";
			getline(is, student.name);
			std::cout << "Tuoi: ";
			is >> student.age;
			is.ignore();
			std::cout << "MSSV: ";
			getline(is, student.mssv);			
		}
	private:
		
};

int main() {
	Student student1;
	std::cin >> student1;
	student1.print();
}
