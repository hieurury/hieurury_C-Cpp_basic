#include <stdio.h>
#include <iostream>
#include <string>

 struct Student {
	int age;
	std::string name;
	
	//contructor
	Student() {
	}
	
	Student(int age, std::string name) {
		this->name = name;
		this->age = age;
	}
	
	
};

int main() {
	Student student1(19, "vo minh hieu");
	printf("tuoi: %d", student1.age);
	std::cout << "ten: " << student1.name;
}
