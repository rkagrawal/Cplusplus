#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<iterator>

template < typename R, typename A >
void foo( R(*fptr)(A) ) {
    puts( __PRETTY_FUNCTION__);
}

void callfoo() {
    // below will not compile without a +
    foo( +[]( double x) { return int(x); } );
}

int main(int argc, const char* argv[] ) {

    std::vector<int> v={2,3,6,1,3,8 };
    std::copy( std::begin(v), std::end(v), std::ostream_iterator<int>( std::cout, " " )) ; std::cout << std::endl;
    auto lt  = []( int a, int b ) { return a > b; };

    std::sort( std::begin(v), std::end(v), lt );
    std::copy( std::begin(v), std::end(v), std::ostream_iterator<int>( std::cout, " " )) ; std::cout << std::endl;

    // below will NOT compile without +
    foo( +[]( double x) { return int(x); } );

    auto l = []( double x) { return int(x); } ;

    // the below compiles.
    int (*fptr)( double) = l;
    foo(fptr);

    std::set< std::string> myset = { "OEX", "XEO", "OEF", "OEF2" };
    std::copy ( std::begin( myset ), std::end(myset ), std::ostream_iterator< std::string> (std::cout , " " ) ); std::cout << std::endl;

    std::set< std::string > myset_oex;
    std::for_each( std::begin( myset ), std::end( myset ), []( const std::string& p ) { std::cout << p << std::endl; } );

    std::cout << "Another list where OEX is not present " << std::endl;

    std::remove_copy_if( std::begin( myset ), std::end( myset ), std::inserter<std::set<std::string>>( myset_oex, end( myset_oex ) ),
                                        []( const std::string& p ) { return ( p != "OEX" ? false : true );  } );

    std::copy ( std::begin( myset_oex ), std::end(myset_oex ), std::ostream_iterator< std::string> (std::cout , " " ) ); std::cout << std::endl;
}
