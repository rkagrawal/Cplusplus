#include<iostream>

template<auto ...vs> struct heterolist {};

int main() {
	using hl = heterolist<'A', 3, 4>;

	hl a;

	std::cout << "end" << std::endl;
}
