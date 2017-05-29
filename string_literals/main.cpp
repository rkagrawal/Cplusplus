#include <iostream>
#include "emp.h"

int main( int argc, const char* argv[] ) {

// Below will not work as Age constructor is defined explicit.. 
//    Age a = 52ull;

// Below is direct ctor call.. so works.
//    Age a { 52ull };
// Below is a user defined literal and works 
   Age a = 52_years;
    emp x { "Rajesh", "Agrawal", a };
    x.print(std::cout);
}
