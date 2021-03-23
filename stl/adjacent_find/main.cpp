#include<iostream>
#include<algorithm>
#include<vector>

int main() {
	
	std::vector<int> V = { 1,8,4,5,5,5};

	std::vector<int>::iterator it = std::adjacent_find(begin(V), end(V) );
	if( it != V.end() )
		std::cout << *it << " at pos " << it - V.begin() << std::endl;
	else
		std::cout << "No adjacent values are equal" << std::endl;

	
}
