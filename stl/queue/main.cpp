#include <iostream>
#include <queue>
#include <vector>

int main(int argc, const char * argv[]) {
    
    std::queue<int> pq ;
    
    for( auto i : { 3,84,1,94,82,521, 45, } ) pq.push( i );
    
    while( !pq.empty() ) {
        std::cout << pq.top() << std::endl; pq.pop();
    }


    // USE OF LAMBDA .. see the type and variable declaration
    const auto& maxfunction = []( const int i, const int j ) { return i>j; };
    std::queue<int, std::vector<int>, decltype(maxfunction) >  maxpq( maxfunction );
    for( auto i : { 3,84,1,94,82,521, 45, } ) maxpq.push( i );
    
    while( !maxpq.empty() ) {
        std::cout << maxpq.top() << std::endl; maxpq.pop();
    }

   return 0;
}
