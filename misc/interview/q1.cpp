#include <iostream>

int f(int x) {
	return 5*x;
}

int main() {

	int x = 2;
	std::cout << f(x++) << std::endl
			  << f(++x) << std::endl;
}
