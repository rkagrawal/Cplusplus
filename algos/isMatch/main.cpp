#include<string>
#include<iostream>

using namespace std;
bool isMatch(string s, string p ) {
    
    int si=0;
    int pi=0;
    bool match=true;
    while ( si < s.length() && pi < p.length() ) {
       if ( p[pi] == '.' || p[pi] == s[si] ) { 
            cout << ".="<<p[pi]<<":"<<s[si]<<endl;
            pi++; si++;
            // if there is a mismatch in length .. it did not match..
            if ( ( si == s.length() && pi < p.length() ) || ( si < s.length() && pi == p.length() ) )
                return false;
       } else if ( p[pi] == '*'  ) { 
            if( pi>0 && p[pi-1] == '*' ) pi++;   // ignore consecutive stars.
            char mtill=s[si];
            if ( si>0) mtill = s[si-1];
            cout << "mtill is " << mtill  << endl;
            while( si < s.length() && s[si] == mtill ) {
                si++;
            } 
            cout << "s[si]:"<<s[si]<<"si:"<<si<<"mtill:" << mtill << endl;
            if ( pi == p.length() && si == s.length() ) {
                if ( p[pi-1] != s[si-1] ) return false;   // if the last char donot match return false
                else return true;            
            } else {
                ++pi;
            }
       } else {
            pi++;
            if ( pi == p.length() ) return false;
       }
    }
    return match;
}


int main( int argc, char* argv[] ) {
    if ( argc != 3 ) {
        cerr << "Usage : string patstring\n";
        exit(1);
    }

    string s= argv[1]; 
    string p= argv[2];

    bool m=isMatch(s,p);
    cout << m << endl;
}

