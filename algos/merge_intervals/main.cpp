#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;
using interval= pair<int,int>;


auto prt=[] (const interval&  p ) { cout << p.first << "|" << p.second <<endl; };
pair<bool,int> isOverlap( const interval& i1, const interval i2 ) {

    if ( i1.first >= i2.first && i1.second <=  i2.second ) { prt(i1); prt(i2); return pair<bool,int> (true, 0 ); }
    else if ( i2.first - i1.second < 2) { prt(i1); prt(i2); return pair<bool,int>(true, 1 ); }
    else return pair<bool,int>(false, -1); 
}

interval merge( const interval& i1, const interval i2 , int merge_type) {
    switch( merge_type ) {
        case 0: 
            return( interval( i2.first, i2.second ) );
        case 1:
            return ( interval( i1.first, i2.second ) );
        case 2:
        default:
            return ( interval( i2.first, i1.second ) );
    }
}

int main( int argc, char* argv[] ) {
    
    vector<interval>  intervals;
    
    int n;
    cout << "enter the # of intervals " << endl;
    cin >> n;
    if ( n != 0 ) {
	    int i=0;
	    int x, y;
	    while ( i < n ) {
	        cout << "Please enter the start and end \n";
	        cin >> x >> y;
	        if ( x > y ) {
	            cout << " lower should be less than upper"<< endl;  
	            continue;
	        }
	        i++;
	        intervals.emplace_back( x,y );
	    }
	
	    for_each( begin(intervals), end(intervals), prt );
	
	    sort( begin( intervals), end(intervals), 
	            [] (const interval& p1, const interval& p2 )  {
	                    if ( p1.second == p2.second ) 
                                return p1.first < p2.first ; 
	                    else  return( p1.second < p2.second  ); 
	                    } 
	            );
	
	    for_each( begin(intervals), end(intervals), prt );
	    
	    vector<interval> results;
	    interval m=intervals[0];
	    int count=0;
	    while ( count < intervals.size()-1 ) {
	        count++;
            pair<bool,int> p = isOverlap( m, intervals[count] );
            if ( p.first ) {
                cout << "Merging.. " << "type is " << p.second << endl;
	            m = merge(m, intervals[count], p.second ); 
                continue;
	        } else {
	           results.emplace_back( m.first, m.second ); 
               m = intervals[count];
	        } 
	    }
	    results.emplace_back( m.first, m.second );    
	    cout << "The merged intervals are \n";
	    for_each( begin(results), end(results), prt );
    }
}
