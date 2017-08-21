#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using FriendsMatrix = vector<string>;


/* quick find takes quadratic  time */


int find( int i, const vector<int>& connected  ) {
    return connected[i];
}

void union_friends( int i, int j, vector<int>& connected, int& circle_count ) {
    int id1 = find(i,connected);
    int id2 = find(j,connected);
    
    if( id1 == id2 ) return;
    
    for(int idx = 0; idx< connected.size(); idx++) {
        if ( connected[idx] == id1 ) connected[idx] = id2 ;
    }

    --circle_count;
}

int main(int argc, const char * argv[] ) {

    fstream inp ( argv[1], ios::in ); 
    int n ;
    inp >> n;
    FriendsMatrix frndmat(n);
    vector<int> connected;
    int i=0;
    while( i < n )  { inp >> frndmat[i]; ++i; }
    
    for(int i=0;i< frndmat.size() ; i++) connected.push_back(i);

    int circle_count = n;
    for(int i=0; i< frndmat.size(); i++) {
        for( int j=i+1; j < frndmat.size(); j++ ) {
            cout << "checking i: " << i << " j: " << j << endl;
            if( frndmat[i][j] == 'Y' ) {
                cout << " i and j are already part of the same connection -- continuing\n";
                if( find(i,connected) == find(j,connected) ) continue;                
                else {
                    cout << "i and j need to be merged\n"; 
                    union_friends( i, j, connected, circle_count );
                }
            }
        }
    }
    
    cout << "The # of circle of friends is " << circle_count << endl;
}
