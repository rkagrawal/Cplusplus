#include <iostream>
#include <map>
#include <memory>
#include <tuple>
#include <utility>
#include "emp.h"

using namespace std;

int main(int argc, char* argv[] ) {
    map<string, unique_ptr<emp> > empMap;
    
    unique_ptr<emp> up1 = make_unique<emp>(  "Agrawal", "Rajesh", 52  ); 
    unique_ptr<emp> up2 = make_unique<emp>(  emp("Agrawal", "Suresh", 50 ) ); 
    up1->print(cout);
    up2->print(cout);
    
    using mapiter = map<string, unique_ptr<emp>>::iterator;
    using mappair = pair<string, unique_ptr<emp>>;

    // map emplace takes a pair
    // move ctors are called..
    pair<mapiter, bool> p = empMap.emplace( make_pair( "Dinesh",
                                            make_unique<emp>( "Agrawal", "Dinesh", 46 )));


    p = empMap.emplace( make_pair( "Rajesh", make_unique<emp>( "Agrawal", "Rajesh", 52 )));
    p = empMap.emplace( make_pair( "Suresh", make_unique<emp>( "Agrawal", "Suresh", 50 )));

    // emplace in map can also take the variadic args like below
    // for it does not work as there is some problem with my understanding... 
    // 
    /*
    pair<mapiter, bool> p = empMap.emplace( piecewise_construct,
                                            forward_as_tuple( "Dinesh" ),
                                            forward_as_tuple( "Agrawal", "Dinesh", 46 ));
    */

    cout << "Printing Map\n";
    for( auto& p : empMap ) 
        p.second->print(cout);
         
    auto iter = empMap.find( "Rajesh" ) ;
    iter = empMap.erase( iter );    

    cout << "\nPrinting after removing Rajesh\n";
    for( auto& p : empMap ) 
        p.second->print(cout);
         
    empMap.insert( iter, make_pair( "Rajesh", make_unique<emp>( "Agrawal", "Mahesh", 48 ) ) );

    cout << "\nPrinting after inserting Mahesh\n";
    for( auto& p : empMap ) 
        p.second->print(cout);
         
    
}
