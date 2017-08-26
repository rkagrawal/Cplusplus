#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
string getLongestCommonSubSeq( const string s1, const string s2, int n1, int n2 ) {

    if ( n1 == 0 || n2 == 0 ) return "";

    if ( s1[n1-1] == s2[n2-1] ) {
           cout << "1 coming here \n";
           string t =  getLongestCommonSubSeq( s1, s2, n1-1, n2-1 ) + s1[n1-1];
           cout << "t is " << t << endl;
           return t;
    } else {
        cout << "2 coming here \n";
        string a = getLongestCommonSubSeq( s1,s2,n1-1, n2) ;
        string b = getLongestCommonSubSeq( s1,s2,n1, n2-1) ;
        if ( a.length() > b.length() )  {
            cout << "- " << a << endl;
            return a;
        } else {
            cout << "- " << b << endl;
            return b;
        } 
    }
}



int main( int argc, const char* argv[] ) {
    if ( argc != 3 ) {
        cerr << "please specify 2 strings\n";
        exit(1);
    }

    string s1 = argv[1];
    string s2 = argv[2];

    string lcs = getLongestCommonSubSeq( s1, s2, s1.length(), s2.length() );
    cout << "The longest common subseq between " << s1 << " and " << s2 << " is " << lcs << endl;
}

