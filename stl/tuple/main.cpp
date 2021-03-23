#include <iostream>
#include <string>
#include <tuple>

/* from steven lavavej talk on tuple cppcon 2016 */

std::tuple<std::string, int, std::string> starship() {
	return std::make_tuple( "NCC", 1701, "D" );
}

int main() {
	
	std::string s;	
	int i=0;
	std::tie(s, i, std::ignore) = starship();

	std::cout << s << "-" << i << std::endl;
	
}
