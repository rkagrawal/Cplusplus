#include <iostream>


class A {

    int _i;

    public:
        A( int i ) : _i(i) { std::cout << "A(int )" << std::endl; }
        virtual ~A() { std::cout << "~A()" << std::endl; }

        virtual void f() { std::cout << "A::f" << std::endl; }
};

class B : public A {
    public:
        B( int i ) : A(i) {
            std::cout << "B ctror" << std::endl;
        }

        void f() override { std::cout << "B::f" << std::endl; }
};

int main() {
    A* mya = new B(5);
    mya->f();


/*
    B bobj(2);
    B *bobjptr = new B(3);
    B bobj2 = bobj;

    // below does not compile
    //B bobj3 = *mya;

    // this compiles
    B bobj4 = *bobjptr;
 */
    // below causes slicing
    A aobj = *mya;
    aobj.f();

    // below X is A obj
    auto X = *mya;
    X.f();

    // Below Y is pointer to mya ( which is pointing to derived B
    auto Y = mya;
    Y->f();

    std::cout << std::is_same< decltype(X), A >::value << std::endl;
    std::cout << std::is_same< decltype(X), A& >::value << std::endl;
}
