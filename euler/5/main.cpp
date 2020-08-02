#include<iostream>
#include<map>
#include<algorithm>
#include<iterator>
#include<math.h>

void updateWithPrimeFactors( int num_, std::map<int,int>& m_ ) {
	
	/* get the prime numbers */
	int orignum = num_;
	bool anyfactor=false;
	for( int i = 2; i <= num_; ++i ) {
		int powers = 0;
		while( num_ % i == 0) {
			++powers;
			num_ /= i;
			anyfactor = true;
		} 

		if( m_.find(i) == m_.end() || m_[i] <= powers ) m_[i] = powers;
	}

	if( !anyfactor ) m_[orignum] = 1;
	
}

int main(int argc, const char* argv[] ) {

	if ( argc != 2 ) {
		std::cerr << "Wrong num of args "<< std::endl;
		return 0;
	}

	int n = std::atoi(argv[1] );
	std::map<int,int> m;

#if 0
		updateWithPrimeFactors( n, m );

		std::cout << "The prime factors of number " << n << " are below" << std::endl;
		std::for_each( m.begin(), m.end(), []( const std::pair<int,int>& p ) { 
											if( p.second ) std::cout << "(" << p.first << "," << p.second << ")" << std::endl;
 											} );
#endif

	// euler problem..
	for (int i=2; i<=n; i++ ) {
		updateWithPrimeFactors(i, m );	
	}

	int result = 1;
	for( auto e: m ) {
		result *= std::pow( e.first, e.second );	
	}

	std::cout << "Result is " << result <<std::endl;
}
