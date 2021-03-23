#include<iostream>

int main() {
	
	char c = 007;
	char d = 011;
	char e = 012;

	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	std::cout << std::hex << (int)c <<  std::endl;
	std::cout << std::hex << (int)d <<  std::endl;
	std::cout << std::hex << (int)(e&0xFF) <<  std::endl;
}
