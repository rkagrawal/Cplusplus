#include<iostream>
#include<stdlib.h>
#include<utility>
#include<algorithm>
#include<numeric>

using namespace std;

string longestPalindrome( const string& s, int l, int h  ) {
    if ( l == h ) {
        cout << "s len = 1 so returning " << s[l] << endl;
        return s.substr(l, l+1);
    }

    int m = (h-l)/2;
    
    string ls = longestPalindrome( s, l, l+m ); 
    string rs = s.substr( m+1, h); reverse(begin(rs), end(rs));
    cout << "rs  = " << rs << " ls = " << ls << " r subs = " << s.substr(m+1,h) << endl;
    return rs+ls+s.substr(m+1,h);
}

pair<int,int> checkPalindrome( const string& s, int m ) {
    
    cout << "mid is " << m << endl;
    int idx = std::min( int(s.length()) - m, m );
    int center=idx;
    cout << "center: "<< center << endl;
    int i=0;
    while( idx >= 0 ) {
        if ( s[center-i ] == s[center+i+1] ) {
            i++;
            idx--; 
        } else break;
    }
    int mlen = center - idx;

    cout << "mlen: " << mlen << endl;
    cout << "center: "<< center << endl;
    cout << "-----\n";
    
    idx = center;
    while( idx>= 0 ) {
        if( s[center-i-1] == s[center+i+1] ) {
            i++; idx--;
        } else break;
    }
    
    int mlen2 = center-idx;
    cout << "mlen2: "<<mlen2<<endl;
    cout << "center2:" <<  center << endl;
    if ( mlen2>mlen)  return pair<int,int>( mlen2, center+1 );
    else return pair<int,int>( mlen, center+1 );
}

string shortestPalindrome( const string& s, int l, int h ) {
    
    int mid = (h-l)/2;
    
    int idx= mid; 
    int p = 0;
    pair<int,int> maxp {0,-1};
    while ( idx >= 0 )  { 
            cout << "Checking palindrom from "  << mid << endl;
            pair<int,int> x = checkPalindrome(s,mid);
            if ( x.first >= maxp.first ) {   /* it is important for >= check and not > */
                maxp = x;
            } 
            --mid;
            --idx;
    }
    cout << "The max match is " << maxp.first << " from " << maxp.second << endl; 
    
    string prefix = s.substr( maxp.second+maxp.first,  s.length() - maxp.second-maxp.first );
    reverse(begin(prefix), end(prefix));
    cout << "The string to prefix is " << prefix<< endl;
    return prefix+s;
}

int main( int argc, const char* argv[] ) {

    if ( argc != 2 ) {
        cerr << "Please specify the string\n";
        exit(1);
    }

    string s = argv[1];
    //string ps = longestPalindrome( s, 0, s.length() - 1 );
    //cout << "The longestPalindrome is " << ps << endl;

    cout << "The shorted palindrom is " << shortestPalindrome( s, 0, s.length()-1) << endl;
}
