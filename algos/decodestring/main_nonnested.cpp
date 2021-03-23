#include<cctype>
#include<string>
#include<iostream>


int main( int argc, const char* argv[] )  {

	if ( argc != 2 ) return 0;

	std::string s = argv[1];
	
	std::string fs;
	int i=0;
	int ss=0;
	int se=0;
	int n;
	bool repeatflag = false;
	while( i< s.size() ) {
		std::cout << i << " " << s[i] << std::endl;
		if( std::isdigit(s[i]) ) {
			n = s[i] - '0';
			ss = i+2;
			i += 2;
			repeatflag = true;	
		} else if ( s[i] == ']' ) {
			se = i;
			for (int k=0;k<n; ++k ) 
				for( int j=ss; j< se; j++ ) 
					fs += s[j];	

			i += 1;
			repeatflag = false;	
		} else {
			if( !repeatflag ) {
				fs += s[i];
			}
			++i;
		}

	}
	std::cout << "orig: " << s << " processed:" << fs << std::endl;
}

