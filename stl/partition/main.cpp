#include<vector>
#include<algorithm>
#include<iterator>
#include<iostream>


int main() {

	std::vector<int> v ={ 8,7,10,5,3};
	std::copy( v.begin(), v.end(), std::ostream_iterator<int>( std::cout, " " )); std::cout << "\n";

	

	std::partition( v.begin(), v.end(), [ p=10 ](int i) { return i < p; } );

	std::copy( v.begin(), v.end(), std::ostream_iterator<int>( std::cout, " " )); std::cout << "\n";

	auto first = std::find_if_not( v.begin(), v.end(),  [ p=7 ](int i) { return i > p; } );

	std::cout << *first << std::endl;

	std::copy( v.begin(), v.end(), std::ostream_iterator<int>( std::cout, " " )); std::cout << "\n" ;

	
	int pivot=7;
	auto it1 = std::partition( v.begin(), v.end(), [ p=pivot ](int i) { 
				return (i < p) ; } );

	std::cout << "Index at :" << (it1 - v.begin()) << std::endl;
	std::copy( v.begin(), v.end(), std::ostream_iterator<int>( std::cout, " " )); std::cout << "\n";

	
	it1 = std::partition( v.begin(), v.end(), [ p=pivot ](int i) { return i > p; } );
	std::cout << "Index at :" << (it1 - v.begin()) << std::endl;
	std::copy( v.begin(), v.end(), std::ostream_iterator<int>( std::cout, " " )); std::cout << "\n";
	

	//v.erase( it1, v.end() );
	v.erase( v.begin(), it1  );
	std::copy( v.begin(), v.end(), std::ostream_iterator<int>( std::cout, " " )); std::cout << "\n";



}
