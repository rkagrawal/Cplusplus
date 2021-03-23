#include<list>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<chrono>

std::list<int> l={2};

int dblentry( std::list<int>::reverse_iterator li, int carry ) {
	int dbl = *li * 2 + carry;
	
	/* see below for more efficient */
	//int rem = dbl % 10;
	//int q = dbl/10;
	
	/* this is more efficient */
	int rem = dbl;
    int q=0;
	if ( dbl >= 10 ) {
		rem = dbl - 10;
		q = 1;
	}	
	*li = rem;
	return q;
}

void doubleListContent( std::list<int>& l ) {

	int carry = 0;
	for( auto li = l.rbegin(); li != l.rend(); ++li ) {
		carry = dblentry( li, carry );	
	}
	if ( carry ) l.push_front( carry );
}


int main() {
	
	std::chrono::system_clock::time_point tp1 = std::chrono::system_clock::now();
	for( int i=2; i<= 1000; i++ ) {
		doubleListContent( l );	

		//std::copy( l.begin(), l.end(), std::ostream_iterator<int>( std::cout, "" ));
		//std::cout << std::endl;
	}

	std::chrono::system_clock::time_point tp2 = std::chrono::system_clock::now();
	
	std::cout << "The sum of digits in 2 power 1000 is " << std::accumulate( l.begin(), l.end(), 0 ) << std::endl;
	std::cout << "It finished in " << std::chrono::duration_cast<std::chrono::microseconds>( tp2-tp1 ).count() << " microseconds" << std::endl;
}
