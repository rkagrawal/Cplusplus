#include<iostream>

const int ONE = 0x0000001;

int solution(int n) {

	int max=0;
	bool startflag = false;
	int curcount = 0;
	for(int i=0; i< 8*sizeof(int); i++ ) {
	
		if ( n & ONE ) {
			if( !startflag ) {
				startflag = true;
				curcount=0;
			} else {
				if( curcount > max ) max = curcount;
				curcount = 0;

			}

		}  else {
			if( startflag ) ++curcount;
		}

		n >>= 1 ;
	}

   return max;
}

int main( int argc, const char* argv[] ) {

	if (argc != 2 ) return -1;

	int n = std::atoi( argv[1] );

	std::cout << "The biggest binary gap for " << n << " is " << solution(n) << std::endl;
}
