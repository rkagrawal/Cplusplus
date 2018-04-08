#include<memory>
#include "emp.h"
#include "empinfo.h"

using namespace std;
class empholder {
    private:
        long long genid;
        empinfo ei;
        vector< shared_ptr<emp> > empVecPtr;
    public:
       empholder( long long id ) { genid = id ;}
       empholder( empholder&& eh  ) { 
          cout << "Calling empholder move ctr " << endl;
	  genid = eh.genid;
          ei = move( eh.ei );
          empVecPtr = move( eh.empVecPtr );
       }

       long long getId() const { return genid ; }
       void updateEmpInfo( empinfo x ) { ei = move(x); }
       void updateEmp( shared_ptr<emp> empptr ) {  empVecPtr.push_back( empptr ); }
       void print() const {
           for ( const auto& e : empVecPtr ) {
               e->print(cout);
           }
       }
};
