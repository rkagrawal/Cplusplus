#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

class joinstr {

    public:
    joinstr() { }
        string operator()  ( string& a, const string& b ) {
        return std::move( a + "->" + b );
    }
};

int main( int argc, const char* argv[] ) {

    vector<string> myvec = { "Rajesh", "Manisha", "Shreya", "Shivam" };
    string blank = {""};

    std::copy( cbegin(myvec), cend(myvec), ostream_iterator<string>( cout, " " ));
    cout << endl;
    auto s = accumulate( cbegin( myvec ), cend(myvec), blank, joinstr() );
    cout << "the string s is " << s << endl;
    
    string a = "j" ; string b= "k";
    joinstr  x;
    cout << x( a, b ) << endl;

    auto cat = []( const string& a, const string& b ) { return (a + "->" + b ); };
    auto s2 = accumulate( cbegin( myvec ), cend(myvec), blank, cat );
    cout << "the string s2 is  " << s << endl;
}
