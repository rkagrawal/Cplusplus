#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>


using namespace std;

struct info {
    info( char c, int count ) : c(c), count(count), ignore(false) {}
    char c;
    int count;
    vector<int> idx;
    bool ignore;
};

int main(int argc, char* argv[] ) {
    
    if ( argc != 3 ) {
        cerr << "Wrong args, pls enter string and k ( distance apart )\n";
        exit(1);
    } 
    string x = argv[1];    
    int k = atoi(argv[2]);

    map<char, int> m;
    for (int i=0; i< x.length(); i++ ){
       m[x[i]]++; 
    }

    
    vector<info> vec;
    for (auto& p : m ) {
        vec.emplace_back( p.first, p.second );
    }

    auto cmp=[]( const info& i1, const info& i2 ) { return i1.count > i2.count ; };
    sort ( begin(vec), end(vec), cmp );

    for ( auto& v: vec ) {
        cout << v.c << "|" << v.count << endl;
    }

    string newstring ;
    int start=0;
    bool flag=true; 
    while( flag )  {
        flag = false;
        int i=start;
        cout << "Iteration start is :" << start << " i is " << i << " k is " << k << endl;
        while( i<=k && start <= vec.size()) {
            if( vec[i+start].count > 0 ) { 
                flag=true;
                cout << "appending " << vec[i+start].c << endl;
                newstring += vec[i+start].c; --vec[i+start].count; 
                cout << "New count is " << vec[i+start].count << endl;
            } else if ( ! vec[i+start].ignore  ) {
                    vec[i+start].ignore = true;
                    ++start;
                    cout << "Incrementing start value is " << start << endl;
            }
            i++;
        }
    }

    if( newstring.length() == x.length()) 
        cout << newstring << endl;
    else  {
        cout << "it is not possible -- new str is " << newstring << "\n";
    }
}


