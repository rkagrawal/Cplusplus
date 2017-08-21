#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int calcReverse( const vector<string>& v, int pos, int songidx ) {
    size_t b;
    if ( songidx > pos ) {
        auto it = upper_bound( v.begin()+songidx, v.end(), v[songidx] );
        if ( it == v.end() ) {
            b = v.size() - 1 - songidx + pos + 1;;
            cout << "S>P:R:E:b:" << b<<endl;
        } else {
            --it;
            int t = it - v.begin() ;
            //cout << "t is " << t << endl;
            b =   v.size() - 1 - t + pos + 1;;
            //cout << "it is not end b:" << b << "pos : " << pos << " v size is " << v.size()-1 << endl;
            cout << "S>P:R:NE:b:" <<b <<endl;
        }
    } else {
        auto it = lower_bound( v.begin(), v.begin()+pos, v[songidx] );
        //cout << *it << " pos :" << it - v.begin() << endl;
        b = it - v.begin() + v.size() - 1 - pos + 1;;
        cout << "S<=P:R::b:" << b << endl;
    }
    cout << "The reverse calc " << v[songidx] << " idx " << songidx << " b is " << b << endl; 
    return b;
}
int calcStraight( const vector<string>& v, int pos, int songidx ) {

    int f;
    if ( songidx > pos ) {
        f  =  songidx - pos;
        //cout << "forward is " << f << endl;
        cout << "S>P:F::f:" << f << endl; 
    } else {
        //cout << "***" << v[songidx] << endl;
        auto it = upper_bound( v.begin(), v.begin()+ pos, v[songidx] );
        --it;
        //cout << "pos : " << pos << " and it is " << it - v.begin() << endl;
        f = pos - (it - v.begin() );
        //f = distance( it, v.begin() + pos );
        //cout << "the song is " << *it << "index is " << f << endl;
        cout << "S<=P:F::f:" << f << endl; 
    }
    return ( f );
}

int minClick( const vector<string>& v, int pos, string song ) {
    auto it = find( begin( v), end(v), song );
    int songidx;
    if ( it != v.end() ) songidx = it - v.begin() ;
    if ( songidx == pos ) return 0;

    cout<< "calc Straight is " << calcStraight( v, pos, songidx ) << endl;
    cout<< "calc backWard is " << calcReverse( v, pos, songidx ) << endl;
    return min( calcStraight( v, pos, songidx), calcReverse( v, pos, songidx ) );
    return -1;
}

int main( int argc, char* argv[] ) {
    if ( argc < 3 ) {
        cerr << "wrong # of arguments : usage < main.out <init pos> <list of strings>\n";
        exit(1);
    }
    vector<string> v;
    for ( int i=1 ; i < argc; i++ ) {
        v.push_back( argv[i] );
    }

    sort( begin(v), end(v) );
    copy( begin(v), end(v), ostream_iterator<string>( cout , " " ) );
    cout << endl;

    int pos;
    string song;
    cout << "Enter position : " ;
    cin >> pos;
    cout << "Enter song\n";
    cin >> song;
    
    int l  =minClick(v,pos,song);
    cout << "\n\nthe min click required for switching to song " << song << " from the song " << v[pos] 
         << " is " << l << endl;
    
}
