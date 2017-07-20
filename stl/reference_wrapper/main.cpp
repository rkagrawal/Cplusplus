#include<functional>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<string>
#include<iterator>
//#include<type_traits>

using namespace std;
int main( int argc, const char* argv[] ) {
    
    cout << "Names is as below \n";
    set<string> names = { "xyz", "xyz", "abc", "def", "ghi" };
    for_each( cbegin(names), cend(names), []( auto& n){ cout << n << endl; } ); 

    cout << "\nNames2 is as below \n";
    unordered_set<string> names2 = { "xyz", "xyz", "abc", "def", "ghi" };
    std::function<void(const string&)> prt2 = []( const string& n) { cout << n << endl; };
    for_each( cbegin(names2), cend(names2), prt2 );

    vector<reference_wrapper<const string>> v;
    //vector<const string& > v2;
    vector<reference_wrapper<const string> > v2;

    for( auto i = begin(names); i != end(names) ; i++ ) { 
        std::reference_wrapper<const string> s = *i;
        v.push_back(s);
//        v2.push_back( static_cast<string&>(*i));
        v2.push_back( std::ref( *i) );
    }
                

    reverse( v.begin(), v.end() );
    cout << "\n vector is as below \n";
    for_each( begin(v), end(v), prt2 );

    if( is_same< const string&, decltype( v[0].get() )>::value ) {
        cout << "vector v is holding references to const string\n";
    } else {
        cout << "vector v is NOT holding reference to const string\n";
    }


    if ( is_same< decltype( v2[0].get() ), const string& >::value ) {
        cout << "It is true\n";
    } else {
        cout << "It is false\n";
    }

}
