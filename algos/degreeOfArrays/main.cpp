#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

struct info {
    info() : count(0) {}
    int count;
    vector<int> posvec;
};

int degreeOfArray( vector<int>& v ) {
    map<int,info> m;
    for (int i=0; i<v.size(); i++ ) {
        m[v[i]].count += 1;
        m[v[i]].posvec.push_back(i);
    }; 
    
    for( const auto e : m ) {
        cout << e.first << "|" << e.second.count << endl;
        copy( begin( e.second.posvec), end( e.second.posvec) , ostream_iterator<int>( cout, "," ) );
        cout <<endl;
    }
    
    int max = 0;
    int smallestsubarray = 0;
    for( const auto& p : m ) {
        if ( p.second.count > 1 && p.second.count >= max ) {
            if( p.second.count != max ) {
                max = p.second.count;
                smallestsubarray = p.second.posvec[ p.second.posvec.size() -1 ] - p.second.posvec[0] + 1; 
            } else {
                int x = p.second.posvec[ p.second.posvec.size() -1 ] - p.second.posvec[0] + 1;
                if ( x < smallestsubarray ) smallestsubarray = x;
            }
        }
    }
    return smallestsubarray;
} 

int main( int argc, const char* argv[] ) {
    
    int n; // the size of the array
    cout << "Enter size of the array: ";
    cin >> n;
    cout << "Enter the array elements\n";

    vector<int> vec;
    int x;
    for ( int i=0; i<n; i++ ) {
        cin >> x; vec.push_back(x); 
    }

    copy( begin(vec), end(vec), ostream_iterator<int>( cout, ","));
    cout << endl;
    cout << "The smallest subarray is " << degreeOfArray(vec) << endl;
}
