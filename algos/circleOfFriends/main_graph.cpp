#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

using FriendsMatrix = vector<string>;
using Circles = vector<vector<int>>;

void getCircleOfFriends( const FriendsMatrix& matrix, int sz, int person, vector<bool>& marked, 
                                                                    Circles& circles, int& count ) {

    marked[person] = true;
    const string& isfrnd  = matrix[ person ];
    for( int i =0; i< sz; i++ ) {
        if( !marked[ i ]  && isfrnd[i] == 'Y' ) {
            circles[count].push_back( i );
            getCircleOfFriends( matrix, sz, i, marked, circles, count );
        }     
    }
}


int main( int argc, const char* argv[] ) {
    
    if( argc != 2 ) {
        cerr << "Wrong # of args: please input file name \n"; 
        exit(1); 
    } 
    fstream inp ( argv[1], ios::in ); 
    int n ;
    inp >> n;
    FriendsMatrix frndmat(n);
    int i=0;
    while( i < n )  { inp >> frndmat[i]; ++i; }

    for( const auto& s : frndmat ) cout << s << endl;
   
    Circles circles(n);
    vector<bool> marked(n, false );
    int k = -1;
    for( int i=0; i< n; i++ ) {
        if( !marked[i] ) {
            k++;
            getCircleOfFriends( frndmat, n, i, marked, circles, k );
        }
    } 

    cout << "There are " << k + 1<< " cirles " << endl;
}
