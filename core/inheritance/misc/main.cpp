#include<iostream>

struct A {

    A() {
        bar();
    }
    virtual ~A() {
        foo();
    }

    virtual void foo() {
        std::cout << "A::foo" << std::endl;
    }

    virtual void bar() {
        std::cout << "A::bar" << std::endl;
    }
};

struct B: A {

    B() {
        bar();
    }

    virtual ~B() {
        foo();
    }

    virtual void foo() {
        std::cout << "B::foo" << std::endl;
    }

    virtual void bar() {
        std::cout << "B::bar" << std::endl;
    }
};

int main() {
    std::cout << "Creating A " << std::endl;
    A a;

    std::cout << "Created A " << std::endl;
    std::cout << "Creating B " << std::endl;
    B b;
    std::cout << "Created B " << std::endl;


    A* aptr = &b;
    aptr->foo();
    std::cout << "Called foo from aptr " << std::endl;

}
