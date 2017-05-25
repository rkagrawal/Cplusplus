
#include<iostream>

using namespace std;

class A {
    public: 
        A() {
            cout << "A::ctor\n";
        }

        void print() {
            cout << "A:print\n";
        }
};

class B {
    public:
        B() {
            cout << "B:ctor\n";
        } 
};


template <typename T >
class C: public T{
    public:
        C() {
            using ptr2mfns = void(T::*)();
            ptr2mfns fptr = &T::print;
        }
};


int main(int argc, const char* argv[] ) {
    C<A> myc;
    // this followng line will compile as B has no member function print
    C<B> myb;
}
