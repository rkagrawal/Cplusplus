#include<iostream>
#include<deque>
#include<vector>
#include<map>
#include<string>
#include<list>

using namespace std;

map<char, list<string>> num2chars;

list<string> l0 = {"0"}; 
list<string> l1 = {"1"}; 
list<string> l2 = { "a","b","c" }; 
list<string> l3 = { "d","e","f" }; 
list<string> l4 = { "g","h","i" }; 
list<string> l5 = { "j","k","l" }; 
list<string> l6 = { "m","n","o" }; 
list<string> l7 = { "p","q","r","s" }; 
list<string> l8 = { "t","u","v" }; 
list<string> l9 = { "w","x","y","z" }; 


deque<string> getLetterCombination( const string& N, int idx ) {
    cout << "Str:idx->"<<N<<":" <<idx<<endl;
    if ( idx == N.length()-1 ) {
        deque<string> nlc;
        list<string>& l = num2chars[ N[idx] ];
        for ( auto c : l ) {
            cout << "inserting " << c << endl;
            nlc.push_front(c);
        }
        return nlc;
    } 

    deque<string> lc = getLetterCombination( N, idx+1 );
    list<string>& l = num2chars[ N[ idx ] ]; 

    if ( l.size() == 0 ) return lc; // for 0 and 1 keys that do not have any letter associated

    deque<string> nlc;
    if ( lc.size() != 0 ) {
        for( auto c : l ) {
            for( auto s : lc ) {
                    cout << "prepending " << c << " to "  << s << endl;
                    nlc.push_front( c+s );;
            }
        }
    } else {
        for (auto c: l ) nlc.push_front(c);
    }

    return nlc;
}

int main( int argc, const char* argv[] ) {

    if ( argc != 2 ) {
        cerr << "please specify tel number\n";
        exit(1);
    }

    num2chars.insert( pair<char,list<string>>( '0', l0 ) );
    num2chars.insert( pair<char,list<string>>( '1', l1 ) );
    num2chars.insert( pair<char,list<string>>( '2', l2 ) );
    num2chars.insert( pair<char,list<string>>( '3', l3 ) );
    num2chars.insert( pair<char,list<string>>( '4', l4 ) );
    num2chars.insert( pair<char,list<string>>( '5', l5 ) );
    num2chars.insert( pair<char,list<string>>( '6', l6 ) );
    num2chars.insert( pair<char,list<string>>( '7', l7 ) );
    num2chars.insert( pair<char,list<string>>( '8', l8 ) );
    num2chars.insert( pair<char,list<string>>( '9', l9 ) );

    auto prt = [] ( const list<string>& l ) { for( auto c : l ) cout << c << "," ; cout << endl; }; 
    //prt( l9 );

    string N=argv[1];

    cout << "The tel number is " << N << endl;
    deque<string> letterComb =  getLetterCombination( N, 0 );

    for ( auto& s : letterComb ) 
        cout<< s << endl;

    cout << "there are " << letterComb.size() << " combinations" << endl; 
}



