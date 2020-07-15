#include <iostream>
#include <unordered_map>
#include <boost/functional/hash.hpp>

struct pair_hash_val {
	std::size_t operator()( const std::pair<int, int>& p )  const{
		std::size_t seed = 0;
		boost::hash_combine( seed, p.first );
		boost::hash_combine( seed, p.second );
		return seed;
	} 
};

namespace std {
	template<> struct hash< std::pair<int,int> > {
		std::size_t operator()( const std::pair<int, int>& p ) const {
			std::size_t seed = 0;
			boost::hash_combine( seed, p.first );
			boost::hash_combine( seed, p.second );
			return seed;
		} 
	};
}

int main() {

	pair_hash_val hash_val;
	std::hash<std::pair<int, int>> shash;
	std::cout << "The hash value of pair(1233456, 67 ) is " << hash_val( std::make_pair( 1233456, 67 ) ) << std::endl;	
	std::cout << "The hash value of pair(1233456, 67 ) is " << hash_val( std::make_pair( 1233457, 68 ) ) << std::endl;	
	std::cout << "The hash value of pair(1233456, 67 ) is " << hash_val( std::make_pair( 8233456, 68 ) ) << std::endl;	
	std::cout << "The hash value of pair(1233456, 67 ) is " << hash_val( std::make_pair( 1233456, 67 ) ) << std::endl;	

	std::cout << "std::hash " <<std::endl;	
	std::cout << "The hash value of pair(1233456, 67 ) is " << shash( std::make_pair( 1233456, 67 ) ) << std::endl;	
	std::cout << "The hash value of pair(1233456, 67 ) is " << shash( std::make_pair( 8233456, 68 ) ) << std::endl;	

	std::unordered_map< std::pair<int,int>, long > mymap;

	mymap.emplace( std::make_pair( 1233456, 67 ), 2 );
	mymap.emplace( std::make_pair( 8233456, 68 ), -22 );

	auto iter = mymap.find( std::make_pair(8233456, 68));
	std::cout << "The value at pair 8233456, 68 is " << iter->second << std::endl;

	(*iter).second = -87;

	iter = mymap.find( std::make_pair(8233456, 68));
	std::cout << "The value at pair 8233456, 68 is " << iter->second << std::endl;
	

}
