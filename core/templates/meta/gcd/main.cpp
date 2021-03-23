#include<iostream>

template< int M, int N>
struct gcd {
	static const int value = gcd<N, M%N>::value;
};

template <int M>
struct gcd<M,0> {
	static const int value = M;
};


int main() {
	std::cout << "The gcd of 16 and 12 is " << gcd<16,12>::value << std::endl;
}
