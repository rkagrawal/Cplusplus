#include<iostream>
#include<string>
#include "emp.h"

using namespace std;
const string& emp::getFirstName() const { return fname; }
const string& emp::getLastName() const  { return lname; }
