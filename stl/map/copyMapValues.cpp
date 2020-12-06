#include <algorithm>
#include <iterator>
#include <memory>
#include <iostream>
#include <map>
#include <vector>
#include <string>

int main() {

	std::map<int, std::shared_ptr<std::string>> m;
	m.insert( std::make_pair( 55, std::make_shared<std::string>( "Rajesh" )));
	m.insert( std::make_pair( 53, std::make_shared<std::string>( "Suresh" )));

	for( auto& e : m ) {
		std::cout << e.first << " " << *e.second << std::endl;
	}

	std::vector<std::shared_ptr<std::string>>  v;

	std::cout<< "The size of vector is " << v.size() << " capacity is " << v.capacity() << std::endl;

	std::transform( m.begin(), m.end(), std::inserter<std::vector<std::shared_ptr<std::string>>>(v, v.begin()), 
										[](const std::pair<int, std::shared_ptr<std::string>>& p ) { return p.second; } );

	for( auto& ev: v ) {
		std::cout << *ev << std::endl;
	}
}
