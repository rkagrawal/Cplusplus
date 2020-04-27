#include<iostream>
using namespace std;


class A {
    public:
        virtual void onUpdate() { cout << "A::onUpdate" << endl; }
};


//class B: private  A {    // this will not compile
//class B: protected  A {    // this will not compile
class B: public  A {   // this will compile
    public:
        void onUpdate() override { cout << "B:onUpdate" << endl; }
};


class C {
    private:
        A* _p;
    public:
        C() {}

        void reg( A* p ) { _p = p; }
        void call() { _p->onUpdate(); }
};


int main( int argc, const char* argb[] ) {
    B *myb = new B();
    C myc;
    myc.reg( myb );
    myc.call();
}

