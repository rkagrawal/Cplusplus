#include<iostream>
#include<limits>

int main() {
	std::cout << "max long is " << std::numeric_limits<long>::max() << std::endl;
	long l = 1;
	l = (l <<  (sizeof(long)*8 - 1)) - 1 ;
	std::cout << l << std::endl;
	std::cout << "The size of long is " << sizeof( long ) << std::endl;
}
