#include <iostream>

struct A {
};

void func(...) {
	std::cout << "In func " << std::endl;
}

int main() {

	using abc = int A::*;

	func( 3 );
    func( "Rajesh" );
}
