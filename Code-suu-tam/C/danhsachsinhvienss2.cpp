#include <iostream>
#include <string>
#include <fstream>

//KHOI TAO STRUCT VE STUDENT
struct Student {
	std::string name;
	int old;
	std::string job;
	//NAP TRONG TOAN TU NHAP
	friend std::istream& operator>>(std::istream &is, Student &student) {
		is.ignore();
		std::cout << "nhap ten: ";
		getline(is, student.name);
		std::cout << "nhap tuoi: ";
		is >> student.old;
		is.ignore();
		std::cout << "nhap nghanh hoc: ";
		getline(is, student.job);
		
		return is;
	}
	//NAP TRONG TOAN TU XUAT
	friend std::ostream& operator<<(std::ostream &os, Student student) {
		os << "Ten: " << student.name;
		os << ", Tuoi: " << student.old;
		os << ", Nghanh: " << student.job << std::endl;
		
		return os;
	}
};


//KHOI TAO FUNCTION;
int show_menu();
void print_students(Student students[], int length);
void add_student(Student* &students, int &length);
void delete_student(Student* &students, int &length);
void change_job(Student* &students, int length);
void add_to_text(Student* &students, int length);


int main() {
	int length = 0;
	Student *students = new Student[length];
	bool is_start = true;
	while(is_start) {
		int choose = show_menu();
		switch(choose) {
			case 1:
				std::cout << "DANH SACH SINH VIEN: " << std::endl;
				print_students(students, length);
				break;
			case 2:
				add_student(students, length);
				break;
			case 3:
				delete_student(students, length);
				break;
			case 4:
				change_job(students, length);
				break;
			case 5:
				add_to_text(students, length);
				break;
			case 0:
				std::cout << "ket thuc chuong trinh!" << std::endl;
				is_start = false;
				break;
			default:
				std::cout << "lua chon khong hop le!" << std::endl;
		}
	}
}
//FUNCTION HIEN THI MENU LUA CHON;
int show_menu() {
	int your_choose;
	std::cout << "------MENU------" << std::endl;
	std::cout << "1. xem danh sach." << std::endl;
	std::cout << "2. them sinh vien." << std::endl;
	std::cout << "3. xoa sinh vien." << std::endl;
	std::cout << "4. thay doi nghanh." << std::endl;
	std::cout << "5. chuyen du lieu cho file text." << std::endl;
	std::cout << "0. ket thuc chuong trinh." << std::endl;
	std::cout << "nhap lua chon cua ban: ";
	std::cin >> your_choose;
	std::cout << "-----------------------" << std::endl;
	return your_choose;
}


//IN RA DANH SACH SINH VIEN;
void print_students(Student students[], int length) {
	if(!length) {
		std::cout << "danh sach trong!" << std::endl;
		return;
	} else {
		for(int i = 0; i < length; i++) {
			std::cout << students[i];
		}
	}
}


//THEM SINH VIEN;
void add_student(Student* &students, int &length) {
	std::cout << "nhap thong tin sinh vien can them: " << std::endl;
	Student new_student;
	std::cin >> new_student;
	Student *tmp_student = new Student[length + 1];
	for(int i = 0; i < length; i++) {
		tmp_student[i] = students[i];
	}
	tmp_student[length] = new_student;
	delete[] students;
	students = tmp_student;
	length++;
	std::cout << "da them thanh cong!" <<std::endl;
	
}


//XOA SINH VIEN THEO TEN;
void delete_student(Student* &students, int &length) {
	std::cout << "nhap ten sinh vien: " << std::endl;
	std::string name_student;
	std::cin.ignore();
	getline(std::cin, name_student);
	int delete_index = -1;
	for(int i = 0; i < length; i++) {
		if(!name_student.compare(students[i].name)) {
			delete_index = i;
			break;
		}
	}
	std::cout << "dia chi vua tim thay: " << delete_index << std::endl;
	if(delete_index == -1) {
		std::cout << "khong tim thay sinh vien!" << std::endl;
		return;
	}
	Student *tmp_students = new Student[length];
	for(int i = 0; i < length; i++) {
		tmp_students[i] = students[i];
	}
	for(int i = delete_index; i < length - 1; i++) {
		tmp_students[i] = tmp_students[i + 1];
	}
	delete[] students;
	students = tmp_students;
	length--;
	std::cout << "da xoa thanh cong!" << std::endl;
}


//THAY DOI NGHANH;
void change_job(Student* &students, int length) {
	std::cout << "nhap ten sinh vien: ";
	std::string name_student;
	std::cin.ignore();
	getline(std::cin, name_student);
	int index_change = -1;
	for(int i = 0; i < length; i++) {
		if(!name_student.compare(students[i].name)) {
			index_change = i;
			break;
		}
	}
	if(index_change == -1) {
		std::cout << "sinh vien khong ton tai!" << std::endl;
		return;
	}
	std::cout << "nhap nghanh can thay doi: ";
	std::string new_job;
	getline(std::cin, new_job);
	students[index_change].job = new_job;
	std::cout << "da thay doi thanh cong!" << std::endl;
}

//CHUYEN DU LIEU QUA FILE TEXT
void add_to_text(Student* &students, int length) {
	std::fstream list_student;
	list_student.open("danhsachsinhvien.txt", std::ios::out);
	
	if(!list_student.is_open()) {
		std::cout << "mo file that bai!" << std::endl;
		return;
	}
	for(int i = 0; i < length; i++) {
		list_student << "Ten: " << students[i].name << " | ";
		list_student << "Tuoi : " << students[i].old << " | ";
		list_student << "Nghanh: " << students[i].job << std::endl;
	}
	
	
	std::cout << "da chuyen thanh cong!" << std::endl;
	list_student.close();
}
