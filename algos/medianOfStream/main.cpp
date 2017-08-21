#include<queue>
#include<iostream>

using namespace std;
int main(int argc, char* argv[] ) {

    auto mincmp = []( int i1, int i2  ) { return i1< i2; };
    auto maxcmp = []( int i1, int i2  ) { return i1 >= i2; };
    
    /* auto prtq = [] ( priority_queue<int>& p ) {
        while( !p.empty() ) { cout << p.top() << "'" ; p.pop(); };
        cout << endl;
    };
    */

    priority_queue<int, vector<int>, decltype(mincmp) > maxpq( mincmp );
    priority_queue<int, vector<int>, decltype(maxcmp) > minpq( maxcmp );  
    
    int i;
    while( cin>>i)  { 
            if (minpq.size() == 0 && maxpq.size() ==  0 )  {
                cout << "Initial push " << endl;
                minpq.push(i); 
            } else {
                if( i > minpq.top() )  {
                    cout << i << " is greater than mintop " << minpq.top() << endl;             
                    minpq.push(i);
                } else {
                    cout << i << " is less than or requal than maxtop" << maxpq.top()<< endl;             
                    maxpq.push(i);
                }
            } 

            cout << "The size of minpq is " << minpq.size() << " and  maxpq is " << maxpq.size() << endl;
            cout << "diff is " << minpq.size() - maxpq.size() << endl;            
            if ( minpq.size() > 0 )
                cout << "Min top before rebalance " << minpq.top() << endl;
            if ( maxpq.size() > 0 )
                cout << "Max top before rebalance " << maxpq.top() << endl;
 
            if( int ( minpq.size() - maxpq.size() ) >= 2 )  {
                cout << "It is here " << endl;
                cout << "The size of maxpq is " << maxpq.size() << endl;
                cout << "The size of minpq is " << minpq.size() << endl;
                maxpq.push( minpq.top() ); 
                minpq.pop();
            } else if ( int ( maxpq.size() - minpq.size() ) >= 2 ) {
                cout << "it is here 2 " << endl;
                cout << "The size of maxpq is " << maxpq.size() << endl;
                cout << "The size of minpq is " << minpq.size() << endl;
                minpq.push( maxpq.top() ); 
                maxpq.pop();
            }

            cout << "rebalance done " << endl;
            if ( minpq.size() > 0 )
                cout << "Min top After rebalance " << minpq.top() << endl;
            if ( maxpq.size() > 0 )
                cout << "Max top After rebalance " << maxpq.top() << endl;

            if( minpq.size() > maxpq.size() ) 
                cout << "median is " << minpq.top() << endl;    
            else if ( maxpq.size() > minpq.size() ) 
                cout << "median is " << maxpq.top() << endl;    
            else 
                cout << "the median is average of " <<  minpq.top() << " and " << maxpq.top() << endl;


    }
}
