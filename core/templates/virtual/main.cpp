#include <iostream>

class B {
	public:
		B() {}
		virtual void print() = 0;
};

template< typename T >
class D : public B {
	public:
		D( T t_) : B(), _t(t_) {}
		void print() {
			std::cout << _t << std::endl;
		}
	private:
		T _t;
};


int main() {
	D<int> myd(5);
	myd.print();
	D<std::string> mys("Rajesh");
	mys.print();
}

