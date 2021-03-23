#include<iterator>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

struct A {
	std::string id;
	int val;

	A( std::string i, int v ): id(i), val(v) {}
};

std::ostream& operator<<( std::ostream& o, const A& a_ ) {
	o << '(' << a_.id << "," << a_.val << ")" << " ";
	return o;
}

int main() {

	std::vector<A> aVec = { { "rajesh", 3 },
							{ "Shivam", 5},
							{ "Shreya", 7},
							{ "Manisha", 11}
						  };


	std::copy( aVec.begin(), aVec.end(), std::ostream_iterator<A>( std::cout, " " ) );
	std::cout << std::endl;

	std::unordered_map<std::string, int> mymap;

	for( int i=0; i< aVec.size(); i++ ) {
		mymap.insert( std::make_pair( aVec[i].id, i ));
	}
					

	for( auto& e : mymap ) {
		std::cout << e.first <<  " " << e.second << std::endl;
	}
}
