#include<fstream>
#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

using AdjList = vector<vector<int>>;
using ConnectedNodes = vector< vector<int> >;

AdjList get_adj_list( fstream& inp ) {
    int n ;
    inp >> n;
    vector< vector<int> > adjlist(n);
    int n1, n2;
    while( inp >> n1 >> n2 ) {
            adjlist[n1].push_back(n2);
            adjlist[n2].push_back(n1);
    }    

    return adjlist;
}

void pre_dfs( const AdjList& adjList, int node , vector<bool>& traversed, vector<int>& seq ) {
    traversed[node] = true;
    for( auto& e : adjList[node] ) {
        if( !traversed[e] ) {
            cout << "   going down " << e <<endl;
            seq.push_back(e);
            pre_dfs( adjList, e, traversed, seq );
        }
    }
}
                                                
void post_dfs( const AdjList& adjList, int node, vector<bool>& traversed, vector<int>& seq ) {
    traversed[node] = true;
    for( auto& e : adjList[node] ) {
        if( !traversed[e] ) {
            cout << "   going down " << e <<endl;
            post_dfs( adjList, e, traversed, seq );
            seq.push_back(e);
        }
    }
}


void get_connected_components( const AdjList& adjList, int node, vector<bool>& traversed, 
                                                            ConnectedNodes& connected, int& count ) {
    traversed[node] = true;
    for( auto e : adjList[node] ) {
        if( ! traversed[e] ) {
            cout << " .. ..  going down " << e << endl;
            connected[count].push_back( e );
            get_connected_components( adjList, e, traversed, connected, count );
        }
    }     
}


int main( int argc, const char* argv[] ) {
    if( argc != 2 ) {
        cerr << "Wrong # of args - please specify input file data\n";
        exit(1);
    }

    fstream inp( argv[1], ios::in );
    AdjList   adjlist = get_adj_list( inp );

    cout << endl;
    vector<int> pre_seq; 
    vector<bool> pre_traversed( adjlist.size(), false ); 
    
    cout << "Enter the start node " << endl;
    int start_node;
    cin >> start_node;
    pre_seq.push_back( start_node );
    pre_dfs( adjlist, start_node, pre_traversed, pre_seq ) ;

    cout << "Done the pre_dfs\n";
    
    cout << "The PRE traversal route is " << endl;
    copy( begin(pre_seq), end(pre_seq), ostream_iterator<int>( cout, "," ));
    cout << endl;

    vector<int> post_seq;
    vector<bool> post_traversed( adjlist.size(), false ); 
    post_dfs(adjlist, start_node, post_traversed, post_seq );
    post_seq.push_back(start_node);

    cout << "The POST traversal route is " << endl;
    copy( begin(post_seq), end(post_seq), ostream_iterator<int>( cout, "," ));
    cout << endl;

    cout << "\n checking for connected components \n";
    ConnectedNodes cn( adjlist.size() ); 
    int k = -1;;
    vector<bool> cn_traversed( adjlist.size(), false );
    for( int i =0; i< adjlist.size() ; i++ ) {
        cout << ".. node " << i << endl;
        if( !cn_traversed[i] ) {
           k++;
           cn[k].push_back( i );
           get_connected_components(adjlist, i, cn_traversed, cn, k );
        } 
    }

    cout << "\nThere are " << k+1 << " connected components\n";
    for( const auto& c : cn ) {
        copy( begin(c), end(c), ostream_iterator<int>( cout, "," ));
        cout <<"\n------\n";
    }
}

    
