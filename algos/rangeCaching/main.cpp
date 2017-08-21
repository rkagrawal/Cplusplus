#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> getModifiedArray( const vector<vector<int>>& Arr, int sz ) {
    vector<int> result( sz, 0 );
    int start, end, val;
    for( auto& t : Arr ) {
        start = t[0];
        end = t[1];
        val = t[2];

        result[start] += val;
        if( end < sz - 1 ) 
            result[end+1] -= val;
    }

    partial_sum( result.begin(), result.end(), result.begin() );
    return result;
}

int main( int argc, const char* argv[] ) {

    int sz;
    cout << "Enter the array size : " ;
    cin >> sz; 

    int updates;
    cout << "Enter the number of updates: ";
    cin >> updates;

    vector<vector<int>> updateTuples(updates);
    for ( int i = 0; i < updates; i++ ) {
       int x , y , z;
       cin>> x >> y>> z;
       updateTuples[i].push_back(x);
       updateTuples[i].push_back(y);
       updateTuples[i].push_back(z);
    } 

    vector<int> modArray = getModifiedArray( updateTuples, sz );
    copy( begin(modArray), end(modArray), ostream_iterator<int>( cout, "," ) );
    cout << endl;
}
