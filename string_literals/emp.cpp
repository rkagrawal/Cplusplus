#include<iostream>
#include<string>
#include "emp.h"

using namespace std;
const string& emp::getFirstName() const { return fname; }
const string& emp::getLastName() const  { return lname; }

ostream& emp::print( ostream& o) {
    o << "First Name:" << fname << " Last Name:" << lname << " Age:" << age << endl;
    return o;
}

ostream& operator<<( ostream& o, const Age& a ) {
    o << a.age ;
    return o;
}
  
