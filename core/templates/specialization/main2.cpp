#include <iostream>

template<typename T, typename R>
void func( T& t) 
{
	std::cout << t <<  std::endl;
}

template<>
void func<std::string, int>( std::string & s, double& d ) 
{
	std::cout << s << " " << d <<  std::endl;
}

int main() 
{
	func( 3.5 );
}
