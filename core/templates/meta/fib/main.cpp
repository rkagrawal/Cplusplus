#include<iostream>

template< int N >
struct fib {
    //static const int n = fib<N-1>::n + fib<N-2>::n;
    enum { n = fib<N-1>::n + fib<N-2>::n };
};

template<>
struct fib<0> {
    //static const int n = 0;
    enum { n =  0 };
};

template<>
struct fib<1> {
    //static const int n = 1;
    enum {n =  1} ;
};


int main() {
    std::cout << "the fib of 5 is " << fib<6>::n << std::endl;
}

