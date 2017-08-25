#include<string>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<unordered_map>


using namespace std;

namespace std {
    template<>
        struct hash<string> {
            using argument_type = string;;
            using result_type = size_t ;

            result_type operator() ( argument_type x ) const {
                sort(begin(x), end(x));
                //cout << "Sorted string is " << x << endl;
                x.erase( unique( begin(x), end(x) ), end(x) );
                //cout << "uniq string is " << x << endl;
                int h=7;
                for(int i=0; i<x.length(); i++ ) {
                    h = ( ( h<<5 ) + h ) + x[i]; 
                }
                //cout << "returning hash value of " << x << ":" << h << endl;
                return h;
            }
        };

        template<>
        struct equal_to<string> {
            bool operator() (  string s1, string s2 ) const {
                sort( begin(s1), end(s1) ); s1.erase( unique( begin(s1), end(s1) ), s1.end() );
                sort( begin(s2), end(s2) ); s2.erase( unique( begin(s2), end(s2) ), s2.end() );
                return s1==s2;
            }
        };

};

class string_equal {
    public:
        bool operator() ( const string& x1, const string& x2 ) const {
            string arg1=x1;
            string arg2=x2;
            sort( begin(arg1), end(arg1) ); arg1.erase( unique( begin(arg1), end(arg1) ), arg1.end() );
            sort( begin(arg2), end(arg2) ); arg2.erase( unique( begin(arg2), end(arg2) ), arg2.end() );
            return arg1==arg2;
        }
};

class string_hash {
    public:
        size_t operator() (const string& x) const {
            string s = x; 
            sort(begin(s), end(s));
            s.erase( unique( begin(s),end(s) ), end(s) );
            int h=7;
            for( int i=0;i<s.length(); i++) {
                h = ( (h<<5) + h ) + s[i];
            }
            return h;
        }
};


int main( int argc, const char *argv[] ) {
    if ( argc < 2 ) {
        cerr << "Please specify at least 2 strings\n";  
        exit(1);
    } 

    vector<string> V;
    for (int i=1; i< argc; i++) V.push_back( argv[i] );
    
    copy( begin(V), end(V), ostream_iterator<string>(cout, "\n")); cout << endl;
    
    unordered_map<string, int > M;
    for ( auto s: V ) {
        if ( M.find( s ) == M.end() ) M.insert( make_pair(s, 1) );
        else {
            ++M[s];
        }
    }

    for_each( begin(M), end(M), []( const pair<string,int>& p ) { 
                        cout<< p.first <<"->"<<p.second <<endl; } );


    /* example of hash and equal functor */
    unordered_map<string, int, string_hash, string_equal  > M2;

    for ( auto s: V ) {
        if ( M2.find( s ) == M2.end() ) M2.insert( make_pair(s, 1) );
        else {
            ++M2[s];
        }
    }

    for_each( begin(M2), end(M2), []( const pair<string,int>& p ) { 
                        cout<< p.first <<"->"<<p.second <<endl; } );


    /* keep track of the orignal string */
    unordered_map<string, string, string_hash, string_equal> M3;

    for ( auto s: V ) {
        if ( M3.find( s ) == M3.end() ) M3.insert( make_pair(s, s) );
    }

    for_each( begin(M3), end(M3), []( const pair<string,string>& p ) { 
                        cout<< p.first <<"->"<<p.second <<endl; } );
}
