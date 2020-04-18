#include <iostream>
#include <string>

template< typename K >
class C {
	public:
		C( K k_ ) : _k(k_) {}
		const K& getK() { 
			return _k;
		}

	private:
		K _k;
};


template< typename OUTER, typename K >
class B{
	public:
		B( OUTER* o_ , K k_ ) : _o(o_), _k(k_){}

		const K& getK() { return _k; }
		OUTER* getOuter() { return _o; }

	private:
		OUTER* _o;
		K _k;
};


int main() {
	C<int>* myC = new C<int>( 10 );

	B<
	   C<int>,
       int  
     > * myB = new B<C<int>,int>( myC, -10 );

	B< B< C<double>, std::string >,
       int > *tripleH = new B< B< C<double>, std::string>, int>( new B<C<double>,std::string> ( new C<double>( 89.98 ), "Rajesh" ),  16 );
	 

	std::cout << "Outer key: " << myB->getOuter()->getK() << std::endl;
	std::cout << "Inner key: " << myB->getK() << std::endl;

	std::cout << "Outer most key: " << tripleH->getOuter()->getOuter()->getK() << std::endl;
	std::cout << "Outer key: " << tripleH->getOuter()->getK() << std::endl;
	std::cout << "Inner key: " << tripleH->getK() << std::endl;
}
