#include<vector>
#include<iostream>
#include<future>

using namespace std;

struct A  {
	const int& x;
	mutable int y;
	A( const int& xx ) : x(xx) { y=0;};
};

ostream& operator<< ( ostream& o, const A& mya ) {
	o << "-->mya.x:"<< mya.x << " mya.y:" << mya.y << endl;
	return o;
}

class Compute {
	public:
	void operator() ( const vector<A>& vec, int pos ) {
		//cout << "The address of vec is " << &vec << endl;
		vec[pos].y += pos*7;
	}
};


int main(int argc, const char* argv[] ) {
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;

	A a1(one);
	A a2(two);
	A a3(three);
	A a4(four);
	
	vector<A> Avec;
	Avec.push_back( move(a1) );
	Avec.push_back( move(a2) );
	Avec.push_back( move(a3) );
	Avec.push_back( move(a4) );

	cout << " Printing using copy address: " << &Avec << endl;
	copy( begin(Avec), end(Avec),  ostream_iterator<A>(cout , " " ) ); 

	cout << endl;
	Compute mycompute;

	vector<future<void>> futvec;

	for ( int i=0; i<1000; i++ ) {
		futvec.push_back( async( mycompute, std::ref(Avec), (i%4) ) );
	}

	for( int i=0; i<1000; i++ ) futvec[i].wait() ;

	cout << " Printing using cout address: "<< &Avec  << endl;
	for( const auto& a : Avec ) cout << a ;

	return 0;
}
