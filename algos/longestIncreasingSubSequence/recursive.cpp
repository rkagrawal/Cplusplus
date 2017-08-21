#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
int longestIncreasingSubSeq( vector<int>& V, int idx ) {
    if ( idx == V.size()-1 ) {
        cout << "checking length from " << V[idx] << endl;
        return 1;
    } 
    cout << "Checking liss at index " << V[idx] << endl;
    int max = 1;
    for ( int i=idx+1; i<V.size(); i++ ) {
        if ( V[idx] < V[i] ) {
            int l = longestIncreasingSubSeq( V, i );
            cout << V[idx] << " length from " << V[i] << " is " << l << endl;
            if ( l +1 > max )  max = l+1; 
        } 
    }   
    return max;
}  

using namespace std;
int main( int argc, const char* argv[] ) {
    if ( argc < 2 ) {
        cerr << "Pls specify the number sequence \n";
        exit(1);
    }

    vector<int> A;
    for ( int i=1; i < argc; i++ )  A.push_back( atoi( argv[i] ) );
    copy( begin( A ),  end(A), ostream_iterator<int>( cout, ", " ) ); cout << endl;

    int max=0;
    for ( int i=0; i<A.size(); i++ ) {
        cout << "=====  Checking for start " << A[i] << " at index " << i << "========\n";
        int liss = longestIncreasingSubSeq( A, i );
        if ( max < liss ) max = liss;
    }

    cout << "The longest increasingsub seq is " << max  << endl;
}
