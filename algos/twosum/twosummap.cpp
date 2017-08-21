#include<iostream>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
int main( int argc, char* argv[] ) {
    vector<int> v = { 3,2,4};
    int target = 6;
    map<int, int> mp;
    int idx=0;
    for( auto m: v) { 
        mp.insert( std::pair<int,int>( m, idx++ ) );
        if( ( mp.find(m) != mp.end() ) && ( mp.find( target - m ) != mp.end() )) {
            cout << " found  " << mp[m] << " and " << mp[target-m] << endl;
        }
    } 
}
