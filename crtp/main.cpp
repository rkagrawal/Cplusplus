#include <iostream>
#include <memory>

using namespace std;

template< typename T >
class Base {
    public:
        Base() {
            cout << "Base:ctor\n";
        }   
        Base( const Base& b ) {
            cout << "Base:cpy ctor\n";
        }

        void print() {
            T* tptr= static_cast<T*> (this);
            tptr->printImpl();
        }
};

class Derived: public Base<Derived> {
    public:
        Derived() {
            cout << "Derived:ctor\n";
        }

        Derived(const Derived& d ): Base(d) {
            cout << "Derived:copy ctor\n";
        }

        void printImpl() {
            cout << "Derived: printImpl() \n";
        }
};

class Derived2 : public Base<Derived2> {
    public:
        Derived2() {
            cout << "Derived2:ctor\n";
        }

        Derived2(const Derived2& d ): Base(d) {
            cout << "Derived2:copy ctor\n";
        }

        void printImpl() {
            cout << "Derived2: printImpl() \n";
        }
};

int main( int argc, const char* argv[] ) {
    Derived x;
    x.print();

    shared_ptr<Derived> dptr = make_shared<Derived>( x );
    dptr->print();

    Derived2 y;
    y.print();
}
