#include<algorithm>
#include<iostream>
#include<iterator>
#include<map>
#include<string>
#include<set>

int main() {

	std::map<std::string, int> abc;

	std::set<int> s;

	abc.insert( std::make_pair( "Rajesh" , 1 ) );
	abc.insert( std::make_pair( "Manisha" , 2 ) );
	abc.insert( std::make_pair( "Shreya" , 3 ) );
	abc.insert( std::make_pair( "Shivam" , 4 ) );

	std::transform( abc.begin(), abc.end(), std::inserter( s, s.begin() ),
		[]( std::pair<std::string, int> p ) { return p.second; } );

	for ( int i: s ) std::cout << i << std::endl;
	
}
