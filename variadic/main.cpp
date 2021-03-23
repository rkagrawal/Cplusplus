#include <iostream>

using namespace std;

template<typename T>
T sum(T t) {
    puts( __PRETTY_FUNCTION__ );
    return t;
}



template <typename T, typename... Ts>
T
sum( T t, Ts... rest) {
    puts( __PRETTY_FUNCTION__ );
    return t+sum(rest...);
}


/* this does not compile.. there is no partial spepcializtion of function templates
 *
 * typename... Ts means variadic template parameters. you have to refer as Ts... in function parameters and specialization
 * Look at main2.cpp if you need to see how to get around partial template specialization for functions.
 */


/*
template<typename... Ts>
string sum<string, Ts...>( string t, Ts... rest ) {
    return t +"->" + sum(rest);
}
*/



int main(int argc, const char * argv[] ) {
    cout << "The sum is " << sum(1.0, 1.0, 3.0, 6.3 ) << endl;
    //cout << "The sum is " << sum( string("1.0"), string("1.0"), string("3.0"), string( "6.3" ) ) << endl;
}
