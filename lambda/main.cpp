#include <memory>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main( int argc, const char* argv[] ) {
    
    auto greaterThan5 = [p=5] ( int i ) { return i>p; };
    vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> r;

    copy_if( cbegin(v), cend(v), back_inserter(r ), greaterThan5 );

    copy( cbegin(r), cend(r), ostream_iterator<int>( cout, " " ) ); cout << "\n";

    partition( begin(v), end(v), greaterThan5 );
    copy( cbegin(v), cend(v), ostream_iterator<int>( cout, " " ) ); cout << "\n";

}
