#include<iostream>
#include<complex>

using namespace std;

class Base
{
	public:
		virtual void f(int);
		virtual void f(double);

		virtual void g(int i=10);
};


void Base::f(int i) {
	cout << "Base::f(int):" << i << endl;
}

void Base::f(double d) {
	cout << "Base::f(double):" << d << endl;
}

void Base::g(int i) {
	cout << "Base::g(int):" << i << endl;
}

class Derived: public Base
{
	public:
		//using Base::f;
		void f( complex<double> );
		void f( std::string );
		void g( int i=20);
};

void Derived::f( complex<double> ) {
	std::cout << "Derived:f(complex)" << std::endl;
}

void Derived::f( std::string ) {
	std::cout << "Derived:f(sttring)" << std::endl;
}

void Derived::g( int i) {
	std::cout << "Derived:g " << i << std::endl;
}

int main() {
	Base b;
	Derived d;
	Base *pb = new Derived();
	b.f(1.0);
	d.f(1);
	d.f(1.0);
	d.f("s");

	pb->f(1.0);
}
