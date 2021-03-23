#include<bitset>
#include<iostream>


int main() {

	std::bitset<16> mybitset;
	std::bitset<16> mybs1( "0000000000000000" );
	std::bitset<16> mybs2( "0111010000001010" );

    std::cout << "mybitset:" << mybitset << std::endl;

	mybitset.set(11);

    std::cout << "mybitset: after setting 11th bit :" << mybitset << std::endl;

    std::cout << "0000000000000000 xor " << mybitset << ":"  << (mybitset ^ mybs1) << std::endl;
    std::cout << "0111010000001010 xor " << mybitset << ":"  << (mybitset ^ mybs2) << std::endl;

	std::bitset<16> mybs3( "0111010000001010" );

	mybs3 ^= mybitset;
    std::cout << "myb3 after xor is " << mybs3 << std::endl;
	if( mybs3.any() ) {
		std::cout << "Some bits of mybs3 are set " << std::endl;
	} else {
		std::cout << "None of the bits of mybs3 are set " << std::endl;
	}
	
	
}
