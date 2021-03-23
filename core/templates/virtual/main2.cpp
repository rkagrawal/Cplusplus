#include <iostream>

template < typename T >
class A {
	public:
		A( T t_) : _t(t_) {
			std::cout << "A : ctor " << std::endl;
		}

		virtual void print() {
			std::cout << _t << std::endl;
		}

		virtual int level() = 0;


	/* The below will not compile as templates cannot be virtual 
	 *
		template< typename U >
		virtual void VF() {}
	 */

	private:
		T _t;
};

template< typename T >
class D1 : public A<T>  {
	public:
		D1( T t_ ) : A<T>( t_ ) {
			std::cout << "D1 ctro " << std::endl;
		}

		int level () { return 1; }	
};

class D2 : public A<std::string> {
	public: 
		D2(const std::string& s ) : A<std::string>(s) {} 

		int level() { return 2; }
};

template < typename T >
class D3 : public virtual A<T> {
	public:
		D3( T t_ ) : A<T>( t_ ) {
			std::cout << "D3 ctro " << std::endl;
		}

		int level () { return 3; }	
};



int main() {
	D1<int> myd{ 6 };
 	myd.print();
	std::cout << "The level of myd is " << myd.level() << std::endl;

	A<int> *dptr = new D1<int>{ 7 };
	dptr->print();
	std::cout << "The level of dptr is " << dptr->level() << std::endl;

	A<std::string> *d2ptr = new D2{ "ABC" };
	d2ptr->print();
	std::cout << "The level of d2ptr is " << d2ptr->level() << std::endl;

	A<int> *d3ptr = new D3<int>{ 9 };
	d3ptr->print();
	std::cout << "The level of d3ptr is " << d3ptr->level() << std::endl;
}

