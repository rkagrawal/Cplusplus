//   https://www.hackerrank.com/contests/w26/challenges/twins
#include<iostream>
#include<set>
#include<map>
#include<math.h>

void prime_factors_slow( int n, std::set<int>& v ) {
	for ( int i = 2; i<= n; i++ ) 
		if ( i == n ) {
			v.insert(n);
		} else {
			if ( n%i == 0 ) {
				std::set<int> tset;
				prime_factors_slow( i, tset );	
				if ( tset.size() == 1 ) v.insert(i);
			}
		}	
	
}

void prime_factors_better( int n, std::map<int,int>& m ) {
	std::cout << "Sqrt of "<< n << " is " << sqrt( n ) << "\n";
	int till_here = floor(sqrt(n));
	for( int i=2; i<=till_here ; i++ ) {
		while ( n % i == 0 ) {
			m[i] += 1; 
			n = n/i;
		}
	}
}

int main( int argc, char* argv[] ) {
	if ( argc != 2 ) {
		std::cout << "Wrong args" << std::endl;
		exit(1);
	}

	int num1 = atoi( argv[1] );

	std::set<int> s;

	s.insert(1); 
	prime_factors_slow( num1, s );
	
	for( auto n:s) {
		std::cout << n << std::endl;
	}

	std::map<int,int> m;
	prime_factors_better( num1, m );

	for( auto e : m ) {
		std::cout << e.first <<"^"<< e.second << " * " ;
	}
	std::cout << "\n";
	
	
}
