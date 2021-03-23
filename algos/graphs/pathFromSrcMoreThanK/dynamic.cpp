#include<iterator>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

bool pathExists( const vector<vector<int>>& e, const vector<vector<int>>& weights , vector<bool>& visited,  int src, int wt ) {
	if ( wt < 0 ) return true;
	if( e[src].size() == 0 )  return false;

	visited[src] = true;
	//for(  const auto& s : e[src] ) {
	for(  int i =0; i < e[src].size(); i++ ) {
	 	int s = e[src][i];
		if ( visited[ s ] ) true;
		std::cout << "Checking path from " << src << " to " << s << " with weight " << weights[src][s] << std::endl;
		int nw = wt - weights[src][s];
		if ( pathExists( e, weights, visited, s,  nw ) )  
			return true;
		else visited[s] = false;
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

    for( int i=0; i< edges.size(); i++ ) {
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

    int srcNode;
    int weight;
    cout << "Enter the source node " << endl;
    cin >> srcNode;
    cout << "Pls enter the min weight " << endl;
    cin>> weight;

    vector<bool> visited( numnodes, false );
    int cumWeight = 0;
    bool pathPresent = pathExists( edges, weights, visited, srcNode, weight );
    cout << boolalpha << pathPresent << endl;
}

