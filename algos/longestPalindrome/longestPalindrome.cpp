#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

extern bool isPalindrome( const string& , int, int );

int longestPalindrome( const string& str ) {
    int s=0;
    int e = str.size() - 1;

    int max=0;

    for (int i=s; i<= e ; i++ ) {
        for( int j=e; j>=0 && j>=i; j-- ) {
            if( max >= j-i+1 ) {
                //cout << "breaking substr from " << i << " and " << j << " as max is " << max << endl;
                break;
            }
            if( isPalindrome( str, i,j ) ) {
                max = j - i + 1;
            } 
        }
    }

    return max;
}

#if 0
int main( int argc, char* argv[] ) {
    if ( argc != 2 ) {
        cerr << "Wrong arguments " <<endl;
        exit(1);
    }

    cout << "The string is " << argv[1] << endl;
    cout << "logest palindrome is " << longestPalindrome( argv[1] ) << endl;;
}

#endif // test is in palindrometest.cpp
