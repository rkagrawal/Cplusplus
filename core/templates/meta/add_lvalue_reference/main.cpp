// from anthony dwyer's talk
#include <iostream>
#include <type_traits>

using namespace std;

template< class T, class>
struct ALR_impl { using type = T; };

template< class T >
struct ALR_impl< T, remove_reference<T&> > { using type = T&; };

template< class T >
struct add_lvalue_reference_t : ALR_impl< T, remove_reference<T> > {};

int main() {

    static_assert( std::is_same< add_lvalue_reference<void>::type, void>::value, "" );
    static_assert( std::is_same< add_lvalue_reference<int>::type, int&>::value, "" );
    static_assert( std::is_same< add_lvalue_reference<int&&>::type, int&>::value, "" );
}


