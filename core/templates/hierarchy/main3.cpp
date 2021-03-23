#include <iostream>
#include <string>


class IdStr {

	public:
		IdStr( std::string idstr_ ): _idstr( std::move( idstr_ ) ) {}
		const std::string& getIdStr() { return _idstr; }
		const std::string getIdStrA() { return _idstr + "A"; }
		const std::string getIdStrB() { return _idstr + "B"; }
	private:
		std::string  _idstr;
	
};

class IdInt {
	public:
		IdInt( int idInt_ ) : _idInt( idInt_ ) {}
		const int& getIdInt() { return _idInt; }
	private:
		int _idInt;
};


template< typename K >
class C {
	public:
		C( K k_=0 ) : _k(k_) {}
		const K& getK() { 
			return _k;
		}

	private:
		K _k;
};


template< typename OUTER, typename K >
class B{
	public:
		B( OUTER* o_ , K k_="" ) : _o(o_), _k(k_){}

		const K& getK() { return _k; }
		OUTER* getOuter() { return _o; }

	private:
		OUTER* _o;
		K _k;
};




typedef const std::string&(IdStr::*strFPtr)();
typedef const int&(IdInt::*intFPtr)();

template< typename T1 , typename T2  > 
void printKey(  T1* a, strFPtr s, T2* b, intFPtr i ) {
	std::cout << (a->*s)() << " " << (b->*i)() << std::endl;
}


typedef IdStr KeyGen1;
typedef const std::string(KeyGen1::*fptr)();

typedef IdInt KeyGen2;
typedef const std::string(KeyGen2::*fptr2)();


template < typename T, typename... Ts > 
T* buildKey() {
	return new T( buildKey<T,Ts...>() );
}


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

	printKey<IdStr, IdInt>( new IdStr( "R" ), &IdStr::getIdStr,  new IdInt(4), &IdInt::getIdInt );

	B<C<int>, double>* aB = buildKey<B,C>()

}
