#include<iostream>
#include<string>
#include "emp.h"

using namespace std;
const string& emp::getFirstName() const { return fname; }
const string& emp::getLastName() const  { return lname; }

ostream& emp::print( ostream& o) const {
    o << "First Name:" << fname << " Last Name:" << lname << " Age:" << age << endl;
    return o;
}
