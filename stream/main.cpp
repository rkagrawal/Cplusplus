#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

int main()  {

	std::stringstream abc;
	double d = 45.9876512;

	abc <<  std::fixed << std::setprecision(2) << d;
	std::cout << abc.str() << std::endl;
}
