#include <iostream>
#include <set>
#include <vector>

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
   for_each( begin(y), end(y), prtsetaddr );

   // Insert some things in 1 element of X and 2 element of Y

   x[0]->insert(5); 
   x[0]->insert(3); 
   cout << "Elements of X are as below \n";
   for_each( begin(x), end(x), prtset );

   y[1]->insert(5*10);
   y[1]->insert(3*10);
   cout << "Elements of Y are as below \n";
   for_each( begin(y), end(y), prtset );

   
}
