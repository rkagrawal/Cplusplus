#include<iostream>
#include<vector>
#include<map>
#include<optional>

std::optional<std::vector<int>>  targetSum( int target, const std::vector<int>& numbers, std::map<int, std::optional<std::vector<int>>>& m ) {

	if ( m.find( target ) != m.end() ) return m[target];

	if( target == 0 ) return std::optional<std::vector<int>>(std::vector<int>());
	if (target < 0 ) return std::optional<std::vector<int>>();

	for( int i=0; i< numbers.size(); i++ ) {

		std::optional<std::vector<int>> optVal = targetSum( target - numbers[i], numbers, m );

		if(optVal) {

			std::cout << "TargetSum can be achieved " <<  target - numbers[i] << " number: " << numbers[i] << "\n" ;

			(*optVal).push_back( numbers[i] );

			m.insert( std::make_pair( target-numbers[i], std::move(optVal) ) );

			return m[target-numbers[i]];
		}
	}

	m.insert( std::make_pair( target, std::optional<std::vector<int>>() ) );
	return m[target];
}


int main() {

	std::map<int, std::optional<std::vector<int>>> m;
	std::vector<int> v={5,3,4,7};
	int target = 7;

	//std::vector<int>  v= {7,14};
	//int target = 300;

	std::optional<std::vector<int>> o = targetSum(target, v, m );

	std::cout << "[";

	if( o ) { 
		for( auto e : *o ) 
			std::cout << e <<  ' ';
	} 
	
	std::cout << "]\n";
}
