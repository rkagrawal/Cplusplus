#include<iostream>
#include<array>
#include<stdlib.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 100> seen; seen.fill(-1);
        if ( s.length() == 0 ) return 0; 
        int len = 0;
        int longest = 1;
        int stidx = 0;
        for( int i=0; i< s.length(); i++ ) {
           int c = s[i] - ' ' ;
           //cout << " char is " << s[i] << " and int val is " << c << " and seen is " << seen[c] << endl;

           if( seen[c] == -1 ) { 
                len++;
                seen[c] = i;
                //cout << "seen is -1" << " len is " << len << " longest is " << longest << endl;
           } else {
                //cout << "**seen is true "<< seen[c] << " len is " << len<< endl;
                stidx = seen[c] + 1;
                if( longest < len ) longest = len;
                len = i - seen[c];
                //cout << "restting seen from 0 to " << seen[c] << endl;
                // make charcters seen earlier to be -1
                int seenidx = seen[c];
                //cout << "resetting to -1 for seen from 0 to " << seen[c] << endl;
                seen.fill(-1);
                for ( int j=seenidx; j<=i;  j++) {
                    int k = s[j] - ' '; seen[k] = j;
                }
                //cout << "**len " << len << " longest " << longest << endl; 
                seen[c] = i;
           }
        }
        if( len > longest ) longest = len;
        //cout << " The longest substr of non repeating characters is " << s.substr(stidx, stidx+longest) << " of length " << longest << endl;;
        return longest;
    }
};


int main(int argc, char* argv[] ) {
    Solution mysol;
    if ( argc != 2 ) {
        cerr << "wrong number of arguments\n" ;
        exit(1);
    }
    string t = argv[1];
    cout << "The longest substring is " << mysol.lengthOfLongestSubstring( t ) << endl;
}
