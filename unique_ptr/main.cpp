#include <iostream>
#include <map>
#include <memory>
#include "emp.h"

using namespace std;

int main(int argc, char* argv[] ) {
    
    //calls template<T, Args&& .. args> unique_ptr<T> make_unique( Args&&.. args )
    unique_ptr<emp> up1 = make_unique<emp>(  "Agrawal", "Rajesh", 52  ); 
    
    // which one does the below call...
    // make_unique calls the copy ctor when it does a new obj and the rval obj in the parameter
    // goes out of scope and destroyed.
    // If move ctor is defined, then instead of the copy ctor , move ctro is called. Check emp.h
    unique_ptr<emp> up2 = make_unique<emp>(  emp("Agrawal", "Suresh", 50 ) ); 
    up1->print(cout);
    up2->print(cout);
    
    //The same logic should apply to shared_ptr as well.
    // create a shared ptr from unique_ptr ( move it )..
    shared_ptr<emp> sp1 = move(up1);

    // below line will cause segmentationf fault
    //up1->print(cout); 

    
    cout << "print from the shared ptr " << endl;
    // both pointer and * work
    sp1->print(cout);
    (*sp1).print( cout );

    /*
     *  If you pass make_unique a ptr, that will call a constructor that requires a ptr
     *  it will create a new copy  of the object, but the passed in pointer will not be deleted 
     *  and cause a memory leak. as seen in the example of up3
     *  If emp ( const emp* const ) ctor is not there, it will cause a compilation error
     *  as make_unique will try to create a new object with ctrol block from emp*
     *  same logic goes for make_shared as well as can be seem from sp3 below
     */
    unique_ptr<emp> up3 = make_unique<emp>(  new emp("Agrawal", "Mahesh", 50 ) ); 
    up3->print(cout);

    shared_ptr<emp> sp3 = make_shared<emp>( new emp( "xyz", "abc", 99 ) );
    sp3->print(cout);

}
