#include <iostream>


int main(int argc, const char* argv[] ) {

	std::integral_constant<bool, false> ft;
	std::cout << ft << std::endl;

	template<bool B>
	using bool_constant = std::integral_constant<bool, B>;
	auto false_type = bool_constant<true>;
}
