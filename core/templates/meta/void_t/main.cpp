#include <iostream>

using namespace std;

template< class...>
using void_t = void;

template<class T, class = void>
struct has_type_as_member: false_type{};

template<class T>
struct has_type_as_member<T, void_t<typename T::type> > : true_type{};

class C {
};

class A {
	public:
		typedef C type;
};


class B {
	public:
};

int main(int argc, const char* argv[] ) {

		if( has_type_as_member<A>::value ) {
			std::cout << "Class A DOES  have type as member\n";
		} else {
			std::cout << "Class A does NOT have type as member\n";
		}

		if( has_type_as_member<B>::value ) {
			std::cout << "Class B DOES  have type as member\n";
		} else {
			std::cout << "Class B does NOT have type as member\n";
		}
}
