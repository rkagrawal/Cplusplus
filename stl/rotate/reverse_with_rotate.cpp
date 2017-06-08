#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;
int main( int argc, const char* argv[] ) {

    if( argc != 2 ) {
        cerr << "Usage : reverse_with_rotate <string>\n";
        exit(1);
    }

    string x = argv[1];
    
    cout << "The original string is " << x << endl; 
    auto b = x.begin();
    auto e = x.end();
    while ( b < e ) {
        rotate( b, b+1,e); --e;
    }
    cout << "The reversed string using rotate left is " << x << endl; 

    auto rb = x.rbegin();
    auto re = x.rend();
    while( rb < re ) {
        //cout << "rb points to " << *rb << " and rb + 1 points to " << *(rb+1) <<endl;
        rotate( rb, rb+1, re ); --re;
        //cout << x << endl;
    }
    cout << "The reverse of reversed string using rotate right is " << x << endl; 
}
