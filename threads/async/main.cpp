#include<vector>
#include<iostream>
#include<future>

using namespace std;

struct A  {
	const int& x;
	mutable int y;
	A( const int& xx ) : x(xx) {};
};

ostream& operator<< ( ostream& o, const A& mya ) {
	o << "-->mya.x:"<< mya.x << " mya.y:" << mya.y << endl;
	return o;
}

class Compute {
	public:
	void operator() ( const vector<A>& vec, int pos ) {
		cout << "The address of vec is " << &vec << endl;
		vec[pos].y = pos*7;
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
	
	auto f0 = async( mycompute, std::ref(Avec) , 0 );
	auto f1 = async( mycompute, std::ref(Avec) , 1 );
	auto f2 = async( mycompute, std::ref(Avec) , 2 );
	auto f3 = async( mycompute, std::ref(Avec) , 3 );

	f0.wait();
	f2.wait();
	f1.wait();
	f3.wait();

	cout << " Printing using cout address: "<< &Avec  << endl;
	for( const auto& a : Avec ) cout << a ;

	return 0;
}
