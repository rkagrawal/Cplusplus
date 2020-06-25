#include <iostream>

template< unsigned long v>
struct factorial {
    static const unsigned long value = v * factorial<v-1>::value;
};

template<>
struct factorial<0> {
    static const unsigned long  value = 1;
};

int main( int argc, const char* argv[] ) {
    constexpr unsigned long N = 9;
    std::cout << "The value of N is " << N << std::endl;
    std::cout << factorial<N>::value << std::endl;
}
