#include <iostream>

class B  {
    private:
        int _i;
    public:
    B(int i_) : _i(i_) {};

    static void print () {
        std::cout << "This is static B::print \n";
    }

    void func() {
        std::cout << "This is B::func \n";
    }
};

class D: public B {

    public:
        D() : B(-5) {}

    static void print( int i ) {
        std::cout << "This is static D::print -- overloaded with int \n";
    }

    void func(int x ) {
        std::cout << "This is D::func -- overloaded with int\n";
    }
};


int main( int argc, const char* argv[] ) {

    B::print();
    D::print(5);
    // Below will not compile as B::print is overloaded in D
    //D::print();
    //

    D myd;
    myd.func(2);

    //Below will not compile as func is overloaded wtih int and B::func is not visible
    //myd.func();

    B myb(3);
    myb.func();
}
