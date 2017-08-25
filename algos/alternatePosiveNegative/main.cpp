#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

int main( int argc,  const char* argv[] ) {
    if ( argc <=2 ) {
        cerr << "pls specify more elements of the array\n";
        exit(1);
    }

    vector<int> V;
    for ( int i=1; i< argc; i++) V.push_back( atoi(argv[i] ));

    /* partition changes the array */
    
    //auto it = partition( begin(V), end(V), []( int x) { return x<0; } );
    //if ( it - begin(V)  != end(V) - it  ) {
    //    cerr << "There are unequal number of positive and negative elements\n" ;
    //    exit(1);
    //}
    

    /* use count_if */
    int count = count_if( begin(V), end(V), [](int x) { return x<0; } );
    if ( 2*count != V.size() ) {
        cerr << "There are unequal number of positive and negative elements\n" ;
        exit(1);
    }

    copy( begin(V), end(V), ostream_iterator<int>(cout, "," ) ); cout << endl;

    /* start with positive */
    int p = 0;
    int n = 1;
    while ( p < V.size() && n < V.size() ) {
        while( p < V.size() ) { if ( V[p] < 0 ) break; else p += 2; };
        // fix p 
        while( n < V.size() ) { if ( V[n] >= 0 ) break; else n += 2; };
        // fix n;
        cout << "fix p " << p << " fix n " << n << endl;
        if ( p < V.size() && n < V.size() ) { swap( V[p], V[n] ); p += 2; n += 2; }
    } 
    
    copy( begin(V), end(V), ostream_iterator<int>(cout, "," ) ); cout << endl;
}
