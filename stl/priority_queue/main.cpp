//
//  main.cpp
//  priority_queue
//
//  Created by Rajesh Agrawal on 2/24/17.
//  Copyright © 2017 Rajesh Agrawal. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

int main(int argc, const char * argv[]) {
    
    std::priority_queue<int> pq ;
    
    for( auto i : { 3,84,1,94,82,521, 45, } ) pq.push( i );
    
    // container adapters do not have iterators defined..
    // hence you cannot do something like the below.
    // std::copy( pq.begin(), pq.end(), std::ostream_iterator<int>( std::cout, " " ) ; std::cout << "\n";
    
    while( !pq.empty() ) {
        std::cout << pq.top() << std::endl; pq.pop();
    }


    // USE OF LAMBDA .. see the type and variable declaration
    const auto& maxfunction = []( const int i, const int j ) { return i>j; };
    std::priority_queue<int, std::vector<int>, decltype(maxfunction) >  maxpq( maxfunction );
    for( auto i : { 3,84,1,94,82,521, 45, } ) maxpq.push( i );
    
    while( !maxpq.empty() ) {
        std::cout << maxpq.top() << std::endl; maxpq.pop();
    }

   return 0;
}
