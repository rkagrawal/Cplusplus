#include<iostream>
#include<vector>
#include<map>


//std::map<int, vector<int>> mapofvec;

bool targetSum( int target, const std::vector<int>& numbers, std::map<int, bool>& m ) {

	if ( m.find( target ) != m.end() ) return m[target];

	if( target == 0 ) return true;
	if (target < 0 ) return false;

	for( int i=0; i< numbers.size(); i++ ) {

		bool b = targetSum( target - numbers[i], numbers, m );
		if(b) {
			std::cout << "TargetSum can be achieved " <<  target - numbers[i] << " number: " << numbers[i] << "\n" ;
			m.insert( std::make_pair( target-numbers[i], b ) );
			return true;
		}
	}

	m.insert( std::make_pair( target, false ) );
	return false;
}


int main() {


	std::map<int, bool> m;
	std::vector<int> v={5,3,4,7};
	int target = 7;

	//std::vector<int>  v= {7,14};
	//int target = 300;

	targetSum(target, v, m );
	
}
