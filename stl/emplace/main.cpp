#include <iostream>
#include <memory>
#include <unordered_map>
#include <map>
#include <vector>

struct Info {
    int _a;
    int _b;
    int _c;
    int _d;
    int _e;
    int _f;
    Info() : _a(0), _b(0), _c(0), _d(0), _e(0), _f(0)  {}
    Info( int a_, int b_, int c_, int d_, int e_, int f_ ) : _a(a_), _b(b_), _c(c_), _d(d_), _e(e_), _f(f_)  {}
    void print() const {
        std::cout << "_a:"<<_a << " _b:" << _b << " _c:" << _c << " _d:" << _d << " _e:" << _e << " _f:" << _f << std::endl;
    }
};

int main() {
    int x = 5;
    std::unordered_map< int, Info> _myMap;
    //std::unordered_map< int, std::shared_ptr<Info>> _myMap2;
    std::unordered_map< int, Info> _myMap2;

    /* vector stuff below works fine

    std::vector<Info> _myVec;
    _myVec.emplace_back( 3,7,1,2,4,8 );
    _myVec.emplace_back( 8,4,2,1,7,3 );

    for ( const auto& e : _myVec ) {
        e.print();
    }
    */

    /* Below does not work - because std::pair does not have variadic parameter in support of its second argument
    _myMap.emplace( 1, 3, 7, 1,2,4,8 );
    _myMap.emplace( 2, 8,4,2,1,7,3 );

    for( const auto& p : _myMap ) {
        p.second.print();
    }
    */

    // The below does not work.
    // std::pair< const int, Info> p = std::make_pair(  2, 8,4,2,1,7,3 );


    // below works if default constructor of Info is there.. other it will give compiler error.
    std::pair< const int, Info> p = std::make_pair(  2, Info(8,4,2,1,7,3 ));

    _myMap.emplace ( 1, Info( 3,7,1,2,4,8 ));
    _myMap[1].print();
    _myMap[1]._a += 4;

    _myMap[1].print();


    std::cout << std::is_default_constructible<Info>::value << std::endl;
    //std::cout << std::is_default_constructible_v<Info> << std::endl;


   _myMap.emplace( std::piecewise_construct,
                    std::forward_as_tuple( 2 ),
                    std::forward_as_tuple( 13,17,11,12,14, 18 ) );


    _myMap[2].print();


    _myMap2.emplace( std::piecewise_construct,
                    std::forward_as_tuple( 2 ),
                    std::forward_as_tuple( 13,17,11,12,14, 18 ) );


	// what happends if we two emplace on the same key
    std::map<std::string, std::string> newMap;
	newMap.emplace( "Rajesh", "Kumar" );
	newMap.emplace( "Rajesh", "Agrawal" );

	std::cout << "The newMap at Rajesh has " << newMap.at("Rajesh" ) << std::endl;
}
