#include <iostream>

using namespace std;

template<typename T>
T sum(T t) {
    return t;
}

/* this does not compile.. there is no partial spepcializtion of function templates
 *
 */ 

/*
template<string t, typename... Ts>
string sum( string t, typename... Ts ) {
    return t +"->" + sum(Ts...);
}

*/

template <typename T, typename... Ts> 
T
sum( T t, Ts... rest) {
    return t+sum(rest...);
}


int main(int argc, const char * argv[] ) {
    cout << "The sum is " << sum(1.0, 1.0, 3.0 ) << endl;
    cout << "The sum is " << sum( string("1.0"), string("1.0"), string("3.0") ) << endl;
}
