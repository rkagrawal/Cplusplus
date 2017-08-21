#include<iostream>
#include<string>
#include<map>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

struct info {
    int count;
    vector<int> occurIndex;
    info() { count = 0 ; }
};

vector<info> countChar( const string&str, int s, int e ) {
    vector<info> v(26);
    for( int i=s; i< e; i++  )  {
        v[ str[i] - 'a' ].count += 1;
        v[ str[i] - 'a' ].occurIndex.push_back ( i );
    }

    return v;
}


void print( const vector<info>& v ) {
    cout << " Start Info \n";
    for ( int i =0; i < v.size(); i++ ) { 
       const info& inf = v[i];
       if( inf.count > 0 ) {
            cout << char( 'a' + i)  <<  " count : " << inf.count << endl;
            cout << " Occurs at "; 
            for ( int pos  : inf.occurIndex ) 
                cout << pos << "," ;
            cout << endl;
        }
    }
    cout << " End Info \n\n";
}

vector<int> posOfCharsThatShouldNotbeThere( const vector<info>& v, int s, int e, int k ) {
    vector<int> unWanted;
    for( auto& i : v ) {
        if ( i.count < k ) unWanted.insert( end(unWanted), begin(i.occurIndex), end(i.occurIndex) );
    }
    sort( begin(unWanted), end(unWanted) );
    return unWanted;
}

// There is a bug that needs to be fixed
int longSubStrWithKrepeatedChar( const string& str, int s, int e, int k ) {
    
    cout << "Calling for " << str << " start:" << s << " end:" << e << endl;
 
    vector<info> cchars = countChar( str, s, e );
    print( cchars );

    vector<int> posUnwanted = posOfCharsThatShouldNotbeThere( cchars, s, e, k );
    cout << endl;
    copy( begin(posUnwanted), end(posUnwanted ), ostream_iterator<int>( cout, "," ));
    cout << endl;
     
    
    if( posUnwanted.size() == 0 ) { 
        cout << " all chars satisfy the min k returning: " << e - s << endl;
        return e - s;
    } else {
        cout  << "Not good yet\n" << endl;
    }

    int l1=0, l2=0, l3=0;
    cout << "Calling begin string\n";
    if ( posUnwanted[0] > 0 )  l1 = posUnwanted[0] - s;
     
    
    int longest = 0;
    cout << "Calling middle portion\n";
    for( int i=0; i< posUnwanted.size() - 1; i++ ) {
        int st = posUnwanted[i]+1; int en = posUnwanted[i+1];
        l2 = max( l1, longSubStrWithKrepeatedChar( str, st, en, k ) );
        longest = max( longest, l2 );
    }

    cout << "Calling end portion\n";
    if( posUnwanted[ posUnwanted.size() - 1 ] < e )  l3 = e - posUnwanted[ posUnwanted.size() - 1 ] - 1;;
    
    longest = max( longest, max( l1, l3 ) );

    return longest;
}

int main( int argc, char* argv[] ) {

    string x = argv[1];
    int count = atoi( argv[2] );
    int l = longSubStrWithKrepeatedChar( x, 0, x.length(), count );
    cout << "Length is " << l << endl;
};
