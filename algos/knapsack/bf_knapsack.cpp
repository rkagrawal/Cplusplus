#include <vector>
#include <iostream>

int bf_knapsack( const std::vector<int>& profit, const std::vector<int>& weight, int capacity, int index ) {
	
	if( capacity <= 0 || index >= profit.size() ) 
		return 0;

	int p1=0;
	if( weight[index] <= capacity ) {
	 	p1 = profit[index] + bf_knapsack( profit, weight, capacity-weight[index], index+1 );
		std::cout << "p1 is " << p1 << " for index " << index+1 << " capacity: " << capacity-weight[index] << std::endl;
	}
	int p2 = bf_knapsack( profit, weight, capacity, index+1 );
	std::cout << "p2 is " << p1 << " for index " << index+1 << " capacity: " << capacity << std::endl;
	return std::max( p1, p2 );;
}

int main( int argc, const char* argv[] ) {
	
	std::vector<int> weight= { 2,3,1,4 };
	std::vector<int> profit= { 4,5,3,7 };
	int capacity = 5;

	std::cout << "Max profit is " << bf_knapsack( profit, weight, capacity, 0 ) << std::endl;;

	return 0;
}

