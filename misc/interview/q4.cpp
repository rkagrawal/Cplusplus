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

struct alignas(32) F32 {
	std::uint64_t z;
	std::uint32_t x;
	char c;
	std::uint32_t y;
};

struct alignas(16) F16 {
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
	std::cout <<"The size of F16 is " << sizeof(F16) << std::endl;
	std::cout <<"The size of F32 is " << sizeof(F32) << std::endl;

}
