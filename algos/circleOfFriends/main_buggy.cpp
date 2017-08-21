#include<set>
#include<vector>
#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

void print_circles( const vector<set<int>> & circles ) {
    for( int i=0; i < circles.size(); i++ ) {
        cout << "members of circle " << i << endl;
        for( const auto& e : circles[i] ) {
            cout << e << "," ;
        }
        cout << endl;
    }
}


int main( int argc, const char* argv[] ) {
    if( argc != 2 ) {
        cerr << "Wrong # of args: please input file name \n"; 
        exit(1); 
    } 
    fstream inp ( argv[1], ios::in ); 
    int n ;
    inp >> n;
    vector<string> farray(n);
    int i=0;
    while( i < n )  { inp >> farray[i]; ++i; }

    for( const auto& s : farray ) cout << s << endl;

    vector<set<int> > circles(n);
    
    for ( int i=0; i < n; i++ ) {
        for( int j=0; j<n; j++ )  {
            if( farray[i][j] == 'Y' )  {
                circles[i].insert(j);
            }
        }
    }

    cout << "It is here \n";
    print_circles( circles );
    //path compression

    auto prt = [] ( const set<int>& s ) { 
        for ( int x : s ) cout << x << "," ;
        cout << endl;
    };

    bool changed = true;
    while ( changed ) {
        cout << "-----------\n";
        changed = false;
        for( int c =0 ; c < n; c++ ) {
            for( const auto& e : circles[c] ) {
                if ( c == e ) continue;
                 
                cout << "Checking member " << e << " of circle " << c << endl;
                if ( circles[e].size() > 0 ) { 
                   cout << c << " is a friend in " << e << endl;
                   circles[c].insert( begin( circles[e] ), end( circles[e] ) ); 
                   circles[e].clear();
                   changed = true;
                   cout << "members of circle " << c << "are "  << endl;
                   prt( circles[c] );
                   cout << "members of circle " << e << "are "  << endl;
                   prt( circles[e] );
                   
                }
            }    
        }
    }

    int count=0;
    for( auto& c : circles ) {
        if ( c.size() > 0) ++count;
    }
    cout << "The number of friend circles is " << count << endl;

    print_circles( circles );
}
        
