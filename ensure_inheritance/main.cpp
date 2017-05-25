#include<iostream>

using namespace std;

class A {
    public: 
        A() {
            cout << "A::ctor\n";
        }
};

class B {
    public:
        B() {
            cout << "B:ctor\n";
        } 
};


class C: A {
    public:
        C() {
            // This should not compile
            //B* bptr = this;

            // this will compile
            A* aptr = this;
        }
};


int main(int argc, const char* argv[] ) {
    C myc;
}
