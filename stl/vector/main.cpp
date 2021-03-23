
//
// https://oopscenities.net/2012/02/24/c11-stdfunction-and-stdbind/
//

#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

std::ostream& operator << ( std::ostream& o , const std::list<int>& l) {
    std::list<int>::const_iterator i = l.begin();
    for( i=l.begin(); i != l.end(); i++) {
        std::cout << *i << std::endl;
    }
    return o;
}

std::ostream& operator << ( std::ostream& o , const std::deque<double>& l) {
    std::deque<double>::const_iterator i = l.begin();
    for( i=l.begin(); i != l.end(); i++) {
        std::cout << *i << std::endl;
    }
    return o;
}

class MyFunctor {
private:
    int multiplier;

public:
    MyFunctor( int x ) : multiplier(x) {}
    
    int operator() (int x ) { return x*multiplier; }
};

void myexecute( const std::vector< std::function< int (int) > >& v ) {
    for( auto& a : v ) {
        std::cout << "The value is " << a(3) << std::endl;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    using namespace std;
    
    list<int> *l = new list< int >();
    l->push_back( -1 ); l->push_back(0);
    l->push_back(1); l->push_back(2);
    
    std::cout << *l <<  std::endl;

//  sort takes a randon access iterator.. so sort for list does not compile.
//  sort( l->begin(), l->end(), std::greater<int>() );
    std::cout << *l <<  std::endl;
    
    
    std::deque<double> d;
    d.push_back(8.80);
    d.push_front(9.837);
    d.push_back(-837);
    d.push_front(0 );
    
    std::cout << "Deque Orignal " << d << std::endl;
    
    sort( d.begin(), d.end(), greater<double>() );
    std::cout << "Deque Sorted " << d << std::endl;
    
    
    d.erase( d.begin() );
    std::cout << "Deque Sorted " << d << std::endl;
    
    //-------
    
   std::vector< std::function< int (int ) > > funcvector;
    MyFunctor myfunc(5);
    funcvector.push_back( myfunc );
    myexecute( funcvector );
    
    
    vector<int> v = { 14,52,65,98,53,01,23,6 };
    std::nth_element(v.begin(), v.begin() + v.size()/2, v.end() );
    std::cout << "the element at " << v.size()/2 << " is " << v[ v.size() / 2 ] << endl;
    std::copy( v.begin(),v.end(), ostream_iterator<int>( cout , " ") ); cout << endl;
    std::random_shuffle(v.begin(), v.end() );
    std::copy( v.begin(),v.end(), ostream_iterator<int>( cout , " ") ); cout << endl;
    std::nth_element(v.begin(), v.begin() + 2 , v.end() );
    std::copy( v.begin(),v.end(), ostream_iterator<int>( cout , " ") ); cout << endl;
    std::random_shuffle(v.begin(), v.end() );
    std::copy( v.begin(),v.end(), ostream_iterator<int>( cout , " ") ); cout << endl;
    std::partial_sort( v.begin(), v.begin() + 3, v.end() );
    std::copy( v.begin(),v.end(), ostream_iterator<int>( cout , " ") ); cout << endl;
    
    
    std::vector<int> v1 = {1,2,3,4,5 };
    std::vector<int> v2(5);
    std::vector<int> v3(10);
    
    class addOne {
    public:
        int operator() (int i ) { return ++i; }
    };
    
    class isEven {
    public:
        bool operator() (int i) { return ( i%2 == 0) ; }
    };
   
    addOne a;
    std::transform( v1.begin(), v1.end(), v2.begin(), a );
    std::cout << "After addOne tranformation\n";
    std::copy( v2.begin(),v2.end(), ostream_iterator<int>( cout , " ") ); cout << endl;

    std::remove_copy_if( v1.begin(), v1.end(), v3.begin(), isEven() );
    cout << "v1 after isEven remove \n";
    std::copy( v1.begin(),v1.end(), ostream_iterator<int>( cout , " ") ); cout << endl;
    cout << "v2 after isEven remove copied \n";
    std::copy( v3.begin(),v3.end(), ostream_iterator<int>( cout , " ") ); cout << endl;

    cout << "Vector of Vectors " << endl;
    vector< vector<int> > adjlist( 5, vector<int>());
    adjlist[2].push_back(4);
    for( auto& v : adjlist ) {
        cout << "checking the vector in the adjlist " << endl;
        for( auto e : v )
            cout << "The node is " << e << endl;
    }
    
}
