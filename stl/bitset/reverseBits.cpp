#include<iostream>
#include<bitset>
#include<stdlib.h>

using namespace std;
int reverseBits( int number ) {
    int origNum = number;
    int newNum = 0;
    int numBits = sizeof(number)* 8;

    //cout << "The size of number is " << sizeof(number) << endl;
    //cout << "The number of bits in the number is " << numBits << endl;

    int i=0;
    while ( i<= numBits - 1 ) {
        //cout << "Orig Number is " << origNum << endl;
        if ( 1 & origNum ) {
            cout << i<<"th bit is set" << endl;
            int j = 1 << ( numBits -i - 1);
            newNum |= j;
        }
        origNum = origNum>>1 ;
        ++i;
    }
    
    return newNum;
}

int main( int argc, const char *argv[] ) {
    if( argc != 2 ) {
        cerr << "pls specify a number to reverse the bits\n";
        exit(1);
    } 

    int N=atoi(argv[1] );

    int N1 = reverseBits( N );
    cout << "The reverse bits for number " << N << " is " << N1 << endl;
    bitset<32> bN(N);
    bitset<32> bnewN(N1);
    cout << N << "\t\tin bits is " << " is " << bN << endl;
    cout << N1 << "\t\tin bits is " << " is " << bnewN << endl;

    // Using the bitset features..
    string bstr = bN.to_string();
    reverse( begin(bstr), end(bstr) );
    bitset<32> xyz(bstr);

    cout << xyz << endl;

}
