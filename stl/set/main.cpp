#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <memory>

using IntPtr = std::shared_ptr<int>;
inline bool operator<( const IntPtr& lhs , const IntPtr& rhs ) {
    return *lhs < *rhs ;
}

class Ex {
    public:
    Ex( int x_ ) : _e(x_) {}

    int getInt() { return _e; }
    private:
    int _e;
};

using ExPtr = std::shared_ptr<Ex> ;

namespace std {
inline bool operator<( const ExPtr& lhs , const ExPtr& rhs ) {
    std::cout << "In exptr operator < " << std::endl;
    return lhs->getInt() < rhs->getInt();
}
}

struct excmp {
    bool operator()( const ExPtr& lhs , const ExPtr& rhs ) const {
        return lhs < rhs;
    }
};



using namespace std;
int main( int argc, char* argv[] ) {

   // the below will create a vector of 5 elements all pointing to the same set

   auto prtsetaddr = [] ( set<int>* p ) { cout << hex << p << dec << endl; };
   auto prtset = [] ( set<int>* p ) { for( const auto& n: *p ) { cout << n << " " ; }  cout << "\n"; };

   vector<set<int>* > x(5, new set<int>() ); 
   cout << "vector X \n";
   for_each( begin(x), end(x), prtsetaddr );
  
   vector<set<int>*>  y(5, nullptr );

   // see the reference to a pointer as assignment is done in lambda
   for_each( begin(y), end(y), []( set<int>* &p ) { p = new set<int>(); });
   cout << "vector Y \n";
   std::for_each( begin(y), end(y), prtsetaddr );

   // Insert some things in 1 element of X and 2 element of Y

   x[0]->insert(5); 
   x[0]->insert(3); 
   cout << "Elements of X are as below \n";
   for_each( begin(x), end(x), prtset );

   y[1]->insert(5*10);
   y[1]->insert(3*10);
   cout << "Elements of Y are as below \n";
   for_each( begin(y), end(y), prtset );

   cout << "copy all elements of y to x " << endl;
   //copy( cbegin(y), cend(y), back_inserter(x)); 
   copy( begin(y), end(y), back_inserter(x)); 
   for_each( begin(x), end(x), prtset );

   std::set<IntPtr> abc;

   IntPtr a( new int(5) );

   abc.insert(a);
   std::cout << "The size of intptr set is " << abc.size() << std::endl;

   IntPtr b = a;
   abc.insert(b);
   std::cout << "The size of intptr set is " << abc.size() << std::endl;


   IntPtr c (new int(5) );
   abc.insert(c);
   std::cout << "The size of intptr set is " << abc.size() << std::endl;

   std::set<ExPtr, std::less<ExPtr> > exset;
   //std::set<ExPtr, excmp > exset;


   ExPtr e1 (new Ex( 14 ) );
   ExPtr e2 (new Ex( 14 ) );

   exset.insert( e1 );
   exset.insert( e2 );

   std::cout << "The size of exset set is " << exset.size() << std::endl;

}
