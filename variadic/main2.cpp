#include <iostream>

/*
 * Does not compile... more understanding required
 */

using namespace std;


template <typename T, typename... Ts>
struct sum_impl{
    static T sum( T t, Ts... rest) {
        puts( __PRETTY_FUNCTION__ );
        return t+sum(rest...);
    }
};


template<typename T>
struct sum_impl<T> {
    static T sum(T t ) {
        puts( __PRETTY_FUNCTION__ );
        return t;
    }
};


template<typename T, typename... Ts>
T sum ( T t, Ts... rest ) {
    return sum_impl<T,Ts...>::sum(t, rest...);
}



int main(int argc, const char * argv[] ) {
    cout << "The sum is " << sum(1.0, 1.0, 3.0 ) << endl;
    //cout << "The sum is " << sum( string("1.0"), string("1.0"), string("3.0") ) << endl;
}

#if 0

+ g++ '-std=c++11' -o main2.out main2.cpp
main2.cpp: In instantiation of âstatic T sum_impl<T, Ts>::sum(T, Ts ...) [with T = double; Ts = {double, double}]â:
main2.cpp:29:45:   required from âT sum(T, Ts ...) [with T = double; Ts = {double, double}]â
main2.cpp:35:48:   required from here
main2.cpp:13:39: error: no matching function for call to âsum_impl<double, double, double>::sum(double&, double&)â
         return t+sum_impl::sum(rest...);
                                       ^
main2.cpp:13:39: note: candidate is:
main2.cpp:11:14: note: static T sum_impl<T, Ts>::sum(T, Ts ...) [with T = double; Ts = {double, double}]
     static T sum( T t, Ts... rest) {
              ^
main2.cpp:11:14: note:   candidate expects 3 arguments, 2 provided
#endif

