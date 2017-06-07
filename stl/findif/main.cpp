//
//  main.cpp
//  FindIf
//
//  Created by Rajesh Agrawal on 5/22/16.
//  Copyright © 2016 Rajesh Agrawal. All rights reserved.
//
#include <iostream>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>
#include <assert.h>

template< typename T>
class GreaterThanFive {
private:
    T i;
public:
    GreaterThanFive(T x) : i(x) {}
    bool operator() (T x ) { return x > i; };
};


using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::deque<double> d;
    d.push_back(8.80);
    d.push_front(9.837);
    d.push_back(-837);
    d.push_front(0 );
    
   // std::cout << "Deque Orignal " << d << std::endl;
  //
  

    GreaterThanFive<double> x(5);
    std::deque<double>::iterator iter;
    iter = std::find_if( d.begin(), d.end(), GreaterThanFive<double>(5) );
    int v1 = *iter;
    cout << "The value of v1 is " << v1 << endl;
    
    //using lambda with init capture
    iter = std::find_if( d.begin(), d.end(), [v=5]( int val ) { return val > 5 ; } );
    int v2 = *iter;
    cout << "The value of v2 is " << v2 << endl;
    assert( v1 == v2 );


    vector<double> allMoreThan5;
    copy_if( d.begin(), d.end(), back_inserter(allMoreThan5), GreaterThanFive<double>(5) );  
    copy( allMoreThan5.begin(), allMoreThan5.end(), ostream_iterator<double>( cout, " " ) ); cout << "\n"; 
    return 0;
}
