#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::string text = "hello world";
	std::ofstream ofs_text;
	ofs_text.open("test.bin", std::ios::binary);
	ofs_text.write((char*)&text, sizeof(std::string));
	ofs_text.close();
	
	std::ifstream ifs_text;
	ifs_text.open("test.bin", std::ios::binary);
	std::string read_text;
//	ifs_text.read((char*)&read_text, sizeof(std::string));
	ifs_text >> read_text;
	std::cout << read_text;
	return 1;
}
