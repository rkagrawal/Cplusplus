#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>


int main() {
	int found = false;
	for( int i=1; i<=1000; i++ ) {
		for( int j=i+1; j<=1000; j++ ) {
			int k = 1000 - i - j;
			if ( k*k == i*i + j*j ) {
				std::cout << i << "*" << i << "+" << j << "*" << j << "=" << k << "*" << k << std::endl;	
				std::cout << i << "+" << j << "+" << k << "=1000" << std::endl;
				found = true;
				break;
			}
		}
		if( found) break;
	}	
}
