#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<numeric>

const int NUMBER=2000000;
//const int NUMBER=200;

void removeMultipleOfPrimes( std::set<int>& twoMillion, int p, bool keep ) {
	int mult=1;
	if( keep ) mult=2;
	int num;
	while( (num = mult*p) <= NUMBER ) { 
		twoMillion.erase( num ); 
		++mult;
	}
}

bool isPrime(int num ) {

	for( int i=2; i*i < num; i++ ) {
		if ( (num % i) == 0 )
			return false;
	}

	return true;
}

int main() {
	std::set<int> twoMillion;
	for(int i=2;i<NUMBER; i++) twoMillion.insert(i);

	int start = 2;
	std::set<int>::iterator iter = twoMillion.find(start);
	int num=*iter;
	while ( iter != twoMillion.end() ) {
		//std::cout << "Removing multiples of number " << num << std::endl;
		removeMultipleOfPrimes( twoMillion, num, true );	
	 	iter = twoMillion.find(num);
		if (++iter == twoMillion.end() ) break;	
		num = *iter;
	}

	std::cout << "The size of twoMillion is " << twoMillion.size() << std::endl;
	unsigned long sum = std::accumulate( twoMillion.begin(), twoMillion.end(), 0 );
	std::cout << "The sum of all prime numbers less than " << NUMBER << " is " << sum << std::endl;
}

