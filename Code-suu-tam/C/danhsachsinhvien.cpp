#include <iostream>
#include <string>
struct Student {
	std::string name;
	int age;
	//
	Student() {
	}
	Student(std::string _name, int _age) {
		name = _name;
		age = _age;
	}
	print() {
		std::cout << "ten: " << name << " | tuoi: " << age << std::endl;
	}
};
// khoi tao ham
void input_interger(std::string label, int &n);
void input_number(int &number);
void input_arr(Student arr[], int length);
void push_student(Student* &arr, int &length);
void setup_student(Student &new_student);
void print_student(Student arr[], int length);
void get_index(int &index);
void delete_student(Student* &arr, int &length);
// 
int main() {
	std::cout << "DAY LA CHUONG TRINH KHOI TAO DANH SACH SINH VIEN!" << std::endl;
	std::cout << "Cac lenh duoc thuc thi theo cac so nhu ben duoi: " << std::endl;
	std::cout << "1: them sinh vien." << std::endl;
	std::cout << "0: in ra danh sach hien tai." << std::endl;
	std::cout << "-1: ket thuc chuong trinh." << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	int length;
	int number;
	input_interger("so luong sinh vien: ", length);
	Student *students = new Student[length];
	input_arr(students, length);
	choose:
		input_number(number);
		if(number == 1) {
			std::cout << "ban da chon them sinh vien!" << std::endl;
			push_student(students, length);
			goto choose;
		} else if(number == 0) {
			std::cout << "ban da chon xem danh sach!" << std::endl;
			print_student(students, length);
			goto choose;
		} else if(number == 2) {
			std::cout << "ban da chon xoa sinh vien!" << std::endl;
			delete_student(students, length);
			goto choose;
		} else if(number == -1) {
			std::cout << "---------------------------" << std::endl;
			std::cout << "ban da chon ket thuc chuong trinh!" << std::endl;
			std::cout << "danh sach cuoi cung la: " << std::endl;
			print_student(students, length);
		}
	
	
}
//
void setup_student(Student &new_student) {
	std::cin.ignore();
	std::cout << "nhap ten: ";
	getline(std::cin, new_student.name);
	std::cout << "nhap tuoi: ";
	std::cin >> new_student.age;
}
void input_interger(std::string label, int &n) {
	std::cout << label;
	std::cin >> n;
}
void input_number(int &number) {
	std::cout << "-------------------" << std::endl;
	std::cout << "hay nhap lua chon: ";
	std::cin >> number;
}
void input_arr(Student arr[], int length) {
	for(int i = 0; i < length; i++) {
		std::cout << "nhap ten sinh vien " << i + 1 << ": ";
		std::cin.ignore();
		getline(std::cin, arr[i].name);
		std::cout << "nhap tuoi sinh vien " << i + 1 << ": ";
		std::cin >> arr[i].age;
	}
}

void push_student(Student* &arr, int &length) {
	Student new_student;
	setup_student(new_student);
	Student *new_arr = new Student[length + 1];
	for(int i = 0; i < length; i++) {
		new_arr[i] = arr[i];
	}
	new_arr[length] = new_student;
	delete[] arr;
	arr = new_arr;
	length++;
}
void print_student(Student arr[], int length) {
	std::cout << std::endl;
	for(int i = 0; i < length; i++) {
		arr[i].print();
	}
}
void get_index(int &index) {
	std::cout << "nhap vi tri trong mang: ";
	std::cin >> index;
}
void delete_student(Student* &arr, int &length) {
	int index;
	get_index(index);
	Student *new_arr = new Student[length - 1];
	for(int i = 0; i < length; i++) {
		new_arr[i] = arr[i];
	}
	for(int i = index; i < length - 1; i++) {
		new_arr[i] = arr[i + 1];
	}
	delete[] arr;
	arr = new_arr;
	length--;
}
