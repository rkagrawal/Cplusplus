#include<iostream>
#include<cstdlib>

unsigned int f( unsigned int v ) {

	unsigned int c {0};
	
	while(v) {
		v &= v -1;
		c++;
	}
	
	return c;
}


int main(int argc, char* argv[] ) {

	if ( argc != 2 ) 
		return -1;

	unsigned int v = std::stoul( argv[1] );

	std::cout << f( v ) << std::endl;
}
