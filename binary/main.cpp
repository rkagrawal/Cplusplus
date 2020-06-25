#include<iostream>

int main() {

	char buf[256];

	*(int*)buf = 25087;

	std::cout << buf << std::endl;

	std::cout << "-------------" << std::endl;
	int x = *(int*)buf;	
	
	std::cout << x << std::endl;
	
}
