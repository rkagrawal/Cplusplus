#include<string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;

bool isPalindrome( const string& s ) {
     size_t len = s.size();

    int start = 0;
    int reverse = len-1;
    bool strPalindrome = true;
    // below reverse can become negative is size_t is used.. so used an integer
    while( reverse>= start ) {
        //cout << "start is " << start << " and reverse is " << reverse << endl;
        //cout << "char at start is:"<<s[start]<< " "<<"char at rev is:" <<s[reverse] << endl;
        if( s[start] != s[reverse]) {
            strPalindrome = false;
            break;
        }
        start += 1; reverse -= 1;
    }

    return strPalindrome;
}


bool isPalindrome( const string& s, int start, int end ) {

    if( end-start > s.size() ) return false;

    int reverse = end;
    bool strPalindrome = true;
    // below reverse can become negative is size_t is used.. so used an integer
    while( reverse>= start ) {
        //cout << "start is " << start << " and reverse is " << reverse << endl;
        //cout << "char at start is:"<<s[start]<< " "<<"char at rev is:" <<s[reverse] << endl;
        if( s[start] != s[reverse]) {
            strPalindrome = false;
            break;
        }
        start += 1; reverse -= 1;
    }

    return strPalindrome;
}
