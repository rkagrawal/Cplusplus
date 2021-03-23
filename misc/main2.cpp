#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main() {

	std::list<char> l = { 'a', 'b', 'C', 'd', 'a', 'z','A' };

	std::vector<int> v(200,0);

	for( char e : l ) { 
		++v[ std::toupper( e ) - 'A' ]; 
		std::cout << e << " index is " << std::toupper(e) - 'A' << " " <<  v[ std::toupper( e ) - 'A' ] << std::endl;
	}

	//std::sort( v.begin(), v.end(), std::greater<int>{} );
	for( int i=0; i < 100; i++ ) {
		if( v[i] == 0 ) continue;
		std::cout <<  static_cast<char>(i + 'A') << " i:" << i << " occurances:" << v[i] << std::endl;
	}

	std::sort( v.begin(), v.end() );
	//std::copy( v.begin(), v.end(), std::ostream_iterator<int>( std::cout, " " ) ); 
	//std::cout << std::endl;
}
