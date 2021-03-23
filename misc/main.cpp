#include <iostream>
#include <vector>
#include <iterator>

class A {
	public:
		A( int i_ ) : _i(i_) {}

		void misc( const std::string& str_ ) {
			std::cout << " const misc method called " << str_ << std::endl;
		}

		void misc(  std::string& str_ ) {
			std::cout << "  misc method called " << str_ << std::endl;
		}
	
	private:
		int _i;
};


int main() {
	A mya(4);	
	std::string x = "rajesh";
	mya.misc( x );

	const std::string y{ "kumar" };
	mya.misc( y );

	int number=1;

	switch( number )
	{
		case 1:
			std::cout << "number is " << number << std::endl;
			break;
		case 2:
			std::cout << "number is " << number << std::endl;
			break;

		default:
			;
	}

	std::vector<int> V = { 1,2,3,4  };
	
	std::vector<int>::const_iterator ci = V.begin();
	std::vector<int>::iterator i = V.begin();

	if( i == ci ) {
		std::cout << "iterators are equal" << std::endl;

		*i = 2;
	}

	std::remove(ci);
}
