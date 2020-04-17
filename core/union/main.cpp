#include<iostream>
#include<limits>


class A {
    public:
    A() {
        std::cout << "Inside A ctor" << std::endl;
        _ll = std::numeric_limits<long long>::max();
    }
    ~A() { std::cout << "Inside A dtor" << std::endl; }

    long long get() { return _ll; }

    private:
       long long _ll;
};

class B {
    public:
    B( int x ) : _x(x){
        std::cout << "Inside B ctor" << std::endl;
    }
    ~B() { std::cout << "Inside B dtor" << std::endl; }

    int get() { return _x; }

    private:

      int _x;
};


union M {
    A _mya;
    M() {};
    ~M(){}
};

struct S {
    A _mya;
    S() {};
    ~S() {}
};


int main() {
    M m;

    std::cout << "------------------------------" << std::endl;

    new( &m._mya ) A{};

    std::cout << m._mya.get() << std::endl;

    alignas( B ) char buf[ sizeof(B) ];

    B * myb = new( buf)  B {45};

    std::cout << myb->get() << std::endl;
    std::cout << "------------------------------" << std::endl;

    S s;

    std::cout << "Constructed s " << std::endl;

}
