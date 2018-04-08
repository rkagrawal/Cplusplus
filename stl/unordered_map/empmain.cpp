#include <unordered_map>
#include <iostream>
#include "empholder.h"

using namespace std;

int main(int argc, const char *argv[] ) {

    unordered_map<long long, empholder > empmap;

    empholder eh(123456789);
    empinfo ei; 
    ei.addId(1); ei.addId(4); ei.addId(2); ei.addId(13);
    eh.updateEmpInfo( ei );

    shared_ptr<emp> emp1ptr( new emp( "R", "A", 52 ) );
    shared_ptr<emp> emp2ptr( new emp( "S", "A", 50 ) );
    shared_ptr<emp> emp3ptr( new emp( "D", "A", 48 ) );

    eh.updateEmp( emp1ptr );
    eh.updateEmp( emp2ptr );
    eh.updateEmp( emp3ptr );

    cout << "----\n";    
    empmap.emplace( make_pair( eh.getId(),  move(eh)  ) );
    cout << "----\n";    

    empholder eh2(987654321);
    empinfo ei2; 
    ei2.addId(1); ei2.addId(4); ei2.addId(2); ei2.addId(13); ei2.addId(4);
    eh2.updateEmpInfo( ei2 );

    shared_ptr<emp> emp1ptr2( new emp( "R", "A", 52 ) );
    shared_ptr<emp> emp2ptr2( new emp( "S", "A", 50 ) );
    shared_ptr<emp> emp3ptr2( new emp( "M", "A", 49 ) );
    shared_ptr<emp> emp4ptr2( new emp( "D", "A", 48 ) );

    eh2.updateEmp( emp1ptr2 );
    eh2.updateEmp( emp2ptr2 );
    eh2.updateEmp( emp3ptr2 );
    eh2.updateEmp( emp4ptr2 );

    cout << "----\n";    
    empmap.emplace( make_pair( eh2.getId(),  move(eh2)  ) );
    cout << "----\n";    

    for( const auto& entry: empmap ) {
        cout << "key is " << entry.first << " genid is " << entry.second.getId() << endl;
        entry.second.print();
	cout << "---------------\n";
    }

    empmap.erase( 123456789 );

    cout << "Printing  after erase " << endl; 

    for( const auto& entry: empmap ) {
        cout << "key is " << entry.first << " genid is " << entry.second.getId() << endl;
        entry.second.print();
	cout << "---------------\n";
    }
}


