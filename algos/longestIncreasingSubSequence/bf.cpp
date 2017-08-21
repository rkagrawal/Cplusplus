#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
int longestIncreasingSubSeq( vector<int>& V ) {
    int maxcount = 0;
    int startidx = -1; // to keep track of where the longest increasing sub seq starts.
    for ( int i=0; i < V.size(); i++ ) {
        //cout << "FFFFFFFFFFFF -- for i " << i << "\n";
        int curidx = i;
        int curcount = 1;
        for ( int j = i+1; j < V.size(); j++ ) {
            //cout << "SSSSSSSSSSSS\n -- for j : " << j << "\n";
            for( int k=j; k< V.size(); k++ ) {
                //cout << "TTTTTTTTTTTT -- for k : " << k << "\n";
                if ( V[curidx] < V[k] ) { 
                    curidx = k; curcount++;
                } 
            }
            if ( maxcount < curcount ) {
                maxcount = curcount; 
                startidx = i;
            }
            curidx = i;
            curcount = 1;
        }
    }

    cout << "The start idx is " << startidx << endl;
    return maxcount;
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

    int liss = longestIncreasingSubSeq( A );
    cout << "The longest increasingsub seq is " << liss << endl;
}
