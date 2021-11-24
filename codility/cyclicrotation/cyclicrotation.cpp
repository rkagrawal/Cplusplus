#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

vector<int> solution( vector<int>& A, int K ) {

	vector<int> result( A.size() );
	if (A.size() == 0 ) return result;

	if( K > A.size() ) K = K % A.size();

	int idx=0;
	for(unsigned int i = A.size() - K;  i<A.size(); i++ ) {
			result[idx] = A[i]; 
			idx++;
	}

	for(unsigned int i=0; i< A.size() - K; i++ ) {
			result[idx] = A[i]; 
			idx++;
	}

	return result;
}


int main(int argc, const char* argv[] ) {
	
	if( argc != 2 ) return -1;

	int K = atoi( argv[1] );

	//vector<int> inp = { 1,2,3,4,5,6,7,8,9 };
	vector<int> inp = {};

	vector<int> out = solution( inp,K );


	std::copy( begin(inp),end(inp), ostream_iterator<int>( cout, " " ) );
	std::cout << "\n";
	std::copy( begin(out),end(out), ostream_iterator<int>( cout, " " ) );
}
