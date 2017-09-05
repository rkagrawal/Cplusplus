#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

bool pathWithAtLeastKWeight( const vector<vector<int>>& allVec, const vector<vector<int>>& allWeight,
                              int src, vector<bool>& visited, int weight, int& cumWeight )  {
    visited[src] = true;
    const vector<int>&  Nodes = allVec[src];
    const vector<int>&  Weights = allWeight[src];
    for( int i = 0 ; i< Nodes.size(); i++ ) {
        if( !visited[ Nodes[i] ] ) {
            cout << "Adding " << Weights[i] << " from node " << Nodes[i] << endl;
            cumWeight += Weights[i];
            if ( cumWeight >= weight ) return true;
            if ( !pathWithAtLeastKWeight( allVec, allWeight, Nodes[i], visited, weight, cumWeight ) )  {
                cumWeight -= Weights[i];
                visited[ Nodes[i] ] = false;
                cout << "Backtracking  " << Weights[i] << " from node " << Nodes[i] << endl;
            } else return true; 
        }
    }
    return false;
}

int main( int argc, const char* argv[] ) {

    if ( argc != 2 ) {
        cerr << "Pls specify the data file\n";
        exit(1);
    }
    
    fstream inp( argv[1], ios::in );
    int numnodes ;
    int numedges; 
    inp >> numnodes;
    inp >> numedges;
    vector< vector<int>> edges( numnodes, vector<int>{} );
    vector< vector<int>> weights( numnodes, vector<int>{} );

    int e1, e2, w;
    for (int i=0; i< numedges; i++ ) {
        inp >> e1 >> e2 >> w;
        edges[e1].push_back(e2);
        edges[e2].push_back(e1);
        weights[e1].push_back( w );
        weights[e2].push_back( w );
    }

/*    for( int i=0; i< edges.size(); i++ ) {
        cout << "edges from node " << i << endl;
        auto& v = edges[i]; 
        copy( begin(v), end(v), ostream_iterator<int>(cout, "," ) );
        cout << endl;
    }

    for( int i=0; i< weights.size(); i++ ) {
        cout << "weights from node " << i << endl;
        auto& v = weights[i]; 
        copy( begin(v), end(v), ostream_iterator<int>(cout, "," ) );
        cout << endl;
    }
 */

    int srcNode;
    int weight;
    cout << "Enter the source node " << endl;
    cin >> srcNode;
    cout << "Pls enter the min weight " << endl;
    cin>> weight;

    vector<bool> visited( numnodes, false );
    int cumWeight = 0;
    bool pathExists = pathWithAtLeastKWeight( edges, weights, srcNode, visited, weight , cumWeight ) ;
    cout << boolalpha << pathExists << endl;
}

