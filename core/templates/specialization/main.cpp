#include <iostream> 

template< typename A, typename B, typename C>
class MyClass {
	public:
		MyClass( A a_, B b_, C c_) : _a(a_), _b(b_), _c(c_) {}

		void print() {
			std::cout << "A:" << _a <<  " B:" << _b << " C:" << _c << std::endl;
		}
	private:
		A _a;
		B _b;
		C _c;
};

template< typename A, typename C> 
class MyClass< A, std::string, C > {
	public:
		MyClass(A a_, C c_) : _a(a_), _c(c_) {
			_b = "Rajesh";
		}

		void print() {
			std::cout << "A:" << _a <<  " B:" << _b << " C:" << _c << std::endl;
		}
	private:
		A _a;
		std::string _b;
		C _c;
};

int main() {

	MyClass<int, float, double> x( 2,2.3,5.6);
	x.print();

	MyClass<int, std::string, double> s( 2,5.6);
	s.print();
}
