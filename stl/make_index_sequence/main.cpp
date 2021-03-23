#include<iostream>
#include<tuple>


int main() {

	auto t = std::make_tuple ( 1,"Rajesh", 54);
	
	size_t sz = std::tuple_size<decltype(t)>::value;

	std::cout << "The size of tuple is " << sz << std::endl;
	auto i = std::make_index_sequence<3>();
}
