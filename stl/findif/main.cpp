//
//  main.cpp
//  FindIf
//
//  Created by Rajesh Agrawal on 5/22/16.
//  Copyright © 2016 Rajesh Agrawal. All rights reserved.
//
#include <iostream>
#include <deque>
#include <algorithm>

template< typename T>
class GreaterThanFive {
private:
    T i;
public:
    GreaterThanFive(T x) : i(x) {}
    bool operator() (T x ) { return x > i; };
};


#include <iostream>

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
    std::cout << *iter << std::endl;

    return 0;
}
