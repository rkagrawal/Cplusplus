#include<limits>
#include<iostream>

int main() {
	double lastVal = std::numeric_limits<double>::quiet_NaN();
	double newVal = std::numeric_limits<double>::quiet_NaN();
	double val = 4.7;

	std::cerr << "The value of double - quite nan is " << val - lastVal << std::endl;
	std::cerr << "The value of quite nan - double is " << lastVal - val << std::endl;
	std::cerr << "The value of quite nan + double is " << lastVal + val << std::endl;

	double synPchange = val - lastVal;

    if( synPchange > .04 ) { 
		std::cout << "Change is > than 0.04" << std::endl;
    } else {
		std::cout << "Change is <= than 0.04" << std::endl;
	}

	std::cout << "min of val and lastVal="<<std::min( val, lastVal ) << std::endl; 
	std::cout << "max of val and lastVal="<<std::max( val, lastVal ) << std::endl; 
	std::cout << "min of newVal and lastVal="<<std::min( newVal, lastVal ) << std::endl; 
	std::cout << "max of newVal and lastVal="<<std::max( newVal, lastVal ) << std::endl; 
}
