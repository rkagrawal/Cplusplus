#include<iostream>
#include<iterator>
#include<ostream>
#include<vector>

using namespace std;

template<typename T, typename ...Args> 
void push_vector( vector<T>& v, Args&& ...args) {

	//( ... , v.push_back( std::forward<Args>(args) ) );
	( v.push_back( std::forward<Args>(args)), ... );
}

int main() {

	vector<int> v;
	push_vector( v, 1,2,3,4,5 );
	copy( v.begin(), v.end(), ostream_iterator<int>( cout, ", " ) ); 
	cout << "\n";

	vector<string> s;
	push_vector(s, "a", "b", "c" );
	copy( s.begin(), s.end(), ostream_iterator<string>( cout, ", " ) ); 
	cout << "\n";

}
