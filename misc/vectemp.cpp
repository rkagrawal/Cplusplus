#include<iostream>
#include<vector>

template<typename T>
void func( T& myt ) {
	std::cerr << __PRETTY_FUNCTION__ << std::endl;	
}

template<typename T>
void func( std::vector<T>& myt ) {
	std::cerr << __PRETTY_FUNCTION__ << std::endl;	
}

int main() 
{
	int x=0;
	func(x);

	std::vector<double> dv { 2.3, 4.5 };
	func(dv);
}

