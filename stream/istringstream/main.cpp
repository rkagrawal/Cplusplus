#include<sstream>
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<strstream>
#include<vector>
#include<array>
#include<map>
#include<set>
#include<stdlib.h>


using namespace std;

map<string, long> posInfo;
struct TransInfo {
    string symbol;
    string buysell;
    long   pos;
    long  cash;
    TransInfo( string s, string b, long p, long c ): symbol(s), buysell(b),pos(p),cash(c) {}
};

list<TransInfo> transInfo;

vector<string> readFile( string filename ) {
    vector<string> vec;
    fstream inp( filename, ios::in );
    string tmp;
    while( getline( inp, tmp ) )  { 
        if( tmp.length() == 0 ) 
            continue;

        vec.push_back( tmp);
    }

    inp.close();
    return vec; 
}

void reconcile( vector<string>& contents ) {

    int i = 0;
    for( const string& v : contents ) {
        cout << v << endl;
    }

    bool d0flag = false;
    while ( i<contents.size() ) {
        if ( contents[i] != "D0 - POS"  || contents[i] == "" )  {
            i++;
            continue; 
        } else {
            d0flag = true;
            i++;
            break;
        }
    }    

    bool d1tranflag = false;
    while ( d0flag && i< contents.size() ) {
        if ( contents[i] == "" )  {
            i++;
            continue;
        } else if ( contents[i] == "D1 - TRAN" ) {
            i++;
            d1tranflag = true;
            break;
        } else {
            istringstream sinp ;
            sinp.str( contents[i] );
            string symbol; long pos;
            sinp >> symbol >> pos;
            posInfo.emplace( make_pair( symbol, pos ) ); 
            i++;
        }
    }

    bool d1posflag = false;
    while( d1tranflag && i < contents.size() ) {
        if( contents[i] == "" ) {
            i++;
            continue;
        } else if ( contents[i] == "D1 - POS" ) {
            i++;
            d1posflag=true;
            break;
        } else {
            istringstream sstr;
            sstr.str( contents[i] );
            i++;
            string symbol, bs;
            long pos, cash;
            sstr >> symbol >> bs >> pos >> cash;

            transInfo.emplace( transInfo.end(), symbol, bs, pos, cash );
            auto itp  = posInfo.find( symbol );
            auto itc  = posInfo.find( "CASH" );
            int pmult = bs == "BUY" ? 1 : -1; 
            int cmult = bs == "BUY" ? -1 : 1; 
            if ( itp != posInfo.end() ) {
                    itp->second += pmult * pos;
            } else {
                posInfo.emplace( make_pair( symbol, pmult*pos ) );
            }

            if ( itc != posInfo.end() ) {
                    itc->second += cmult * cash;
            } else {
                posInfo.emplace( make_pair( "CASH", cmult*cash ) );
            }
        }
    }

    set<string> d1PosKeys;
    while ( d1posflag && i< contents.size() ) {
        
        istringstream sstr;
        sstr.str( contents[i] );  
        i++;
        string symbol;
        long pos;
        sstr >> symbol >> pos;
        if( d1PosKeys.find( symbol ) == d1PosKeys.end() ) d1PosKeys.insert(symbol );
        auto it = posInfo.find( symbol );
        if ( it != posInfo.end() ) {
            if ( it->second != pos ) {
                cout << "\nMismatch in pos for "<< it->first << "->"<<it->second << " " << pos <<endl;
            } 
        } 
    }

    set<string> posKeys ;
    for( auto & p : posInfo ) posKeys.insert( p.first );
    set<string> d0p_d1pkeys, d1p_d0pkeys;

 
    set_difference( posKeys.begin(), posKeys.end(), d1PosKeys.begin(), d1PosKeys.end(),
                                                        inserter(d0p_d1pkeys, d0p_d1pkeys.begin() ) );

    set_difference( d1PosKeys.begin(), d1PosKeys.end(),posKeys.begin(), posKeys.end(), 
                                                        inserter(d1p_d0pkeys, d1p_d0pkeys.begin() ) );


    cout << "Found in D0 but missing in D1 " << endl;
    copy( begin(d0p_d1pkeys), end(d0p_d1pkeys), ostream_iterator<string>( cout , " " ) );
    cout << endl;

    cout << "Found in D1 but missing in D0 " << endl;
    copy( begin(d1p_d0pkeys), end(d1p_d0pkeys), ostream_iterator<string>( cout , " " ) );
    cout << endl;
}

int main(int argc, const char* argv[] ) {

    if ( argc != 2) {
        cerr << "Pls specify filename \n";
        exit(1);
    }

    vector<string> fileContents = readFile( argv[1] );
    reconcile( fileContents );
    
}
