#include<iostream>
#include<limits>
#include<bitset>

struct A {
};


struct B {
	std::uint32_t x;
	std::uint16_t y;
	std::uint64_t z;
};


struct C {
	std::uint32_t x;
	std::uint64_t z;
	std::uint16_t y;
};

struct D {
	std::uint64_t z;
	std::uint32_t x;
	std::uint16_t y;
};

struct E {
	std::uint64_t z;
	std::uint32_t x;
	char c;
	std::uint16_t y;
};

struct F {
	std::uint64_t z;
	std::uint32_t x;
	char c;
	std::uint32_t y;
};

int main() {

	std::cout <<"The size of A is " << sizeof(A) << std::endl;
	std::cout <<"The size of B is " << sizeof(B) << std::endl;
	std::cout <<"The size of C is " << sizeof(C) << std::endl;
	std::cout <<"The size of D is " << sizeof(D) << std::endl;
	std::cout <<"The size of E is " << sizeof(E) << std::endl;
	std::cout <<"The size of F is " << sizeof(F) << std::endl;

	std::cout << "The size of std::utint32_t is " << sizeof(std::uint32_t) << std::endl;
	std::cout << "The size of std::utint16_t is " << sizeof(std::uint16_t) << std::endl;
	std::cout << "The size of std::utint64_t is " << sizeof(std::uint64_t) << std::endl;

	std::cout << "max of uint8_t is " << std::numeric_limits<std::uint8_t>::max() << std::endl;
	std::cout << "min of uint8_t is " << std::numeric_limits<std::uint8_t>::min() << std::endl;
	std::cout << "max of int8_t is " << std::numeric_limits<std::int8_t>::max() << std::endl;
	std::cout << "min of int8_t is " << std::numeric_limits<std::int8_t>::min() << std::endl;




	std::cout << "max of unsigned short is " << std::numeric_limits<unsigned short>::max() << std::endl;
	std::cout << "min of unsigned short  " << std::numeric_limits<unsigned short>::min() << std::endl;
	std::cout << "max of short is " << std::numeric_limits<short>::max() << std::endl;
	std::cout << "min of short  is " << std::numeric_limits<short>::min() << std::endl;


	std::bitset<sizeof(short)*8> smax{ std::numeric_limits<short>::max()};
	signed short t = std::numeric_limits<signed short>::min();
	std::bitset<32> smin=t;

	std::bitset<sizeof(unsigned short)*8> usmax{ std::numeric_limits<unsigned short>::max()};
	std::bitset<sizeof(unsigned short)*8> usmin{ std::numeric_limits<unsigned short>::min()};

	std::cout << " max of signed short is " << smax <<  " int value : " << std::numeric_limits<short>::max() << std::endl;
	std::cout << " min of signed short is " << smin <<  " int value : " << std::numeric_limits<short>::min() << std::endl;

	std::cout << " max of unsigned short is " << usmax <<  " int value : " << std::numeric_limits<unsigned short>::max() << std::endl;
	std::cout << " min of unsigned short is " << usmin <<  " int value : " << std::numeric_limits<unsigned short>::min() << std::endl;
}
