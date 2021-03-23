#include <iostream>

template<typename T>
class Example {
    public:
        Example( const T& t_ ) : t(t_) {}
        void print() {
            std::cout << t << std::endl;
        }
    private:
        T t;
};

// The partial specialiations may involve more template parameters..
// however the number of parameters in the specialiation must match primary..
// So Example<T[N]> works, but Example<T, N> does not work.

template<typename T, int N>
class Example<T[N]>{

    public:
        void print() {
            std::cout << "with int" << std::endl;
        }

    private:
        T t[N];
};


int main() {
    Example<int> intEx(5);
    intEx.print();
    Example<int[3]> intarrEx;
    intarrEx.print();


}

