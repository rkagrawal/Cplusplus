#include<iostream>


class C {
    public:
        C(int x_) : x(x_) {}

        int getInt() { return x; }
    private:
        int x=5;

};
class B {

    public:
        B() {
            myc = new C(-40);
        }

        C* getC() { return myc; }

    private:
        C* myc;
};


class A {
    public:
        A( B& b ) : myb(b) {
        }

        B& getB() { return myb; }

    private:
        B& myb;
};

