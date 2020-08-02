#include<iostream>
#include<string>
#include<numeric>
#include<cmath>


int main() {

  bool found = false;
  for(int i=999; i>=100 ; --i) {

	std::string stri = std::to_string(i);
	std::string revstri = stri;
	std::reverse( revstri.begin(),revstri.end() );
	std::string palin = stri + revstri;

	for (int j=999; j>=100; --j ) {
		int ival = std::stoi(palin);
		int q = ival / j;
		int r = ival % j;
		if ( r  == 0 &&  q >=100 && q < 1000) {
		   std::cout <<"i:"<<q<<" j:" <<j<< " palin:" << ival<< std::endl;
		   found = true;
		   break;
		}
		
	}
    if( found) break;
  }

}
