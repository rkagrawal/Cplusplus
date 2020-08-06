#include<iostream>
#include<vector>
#include<stdlib.h>
#include<assert.h>
#include<fstream>



std::string str = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
const int LEN = 1000;
const int INCR = 13;

/*
std::string str = "123560";
const int LEN = 6;
const int INCR = 3;
*/



unsigned long getNonZeroProduct( int sidx, int& eidx ) {
    unsigned long prd = 1;
    int len=0;
    int s = sidx;
    while ( prd > 0 && len < INCR && s+1 < LEN ) {
        if ( str[s] == '0' ) { // it is zero
            s += 1;
            prd = 1;
            len = 0;
            continue;
        }
        prd *= ( str[s] - '0' );
        ++len;
        ++s;
    }
    eidx  = s;;
    return prd;
}


int main() {

    std::fstream f ("/tmp/e8", std::ios::out) ;
    for (int i=0; i< str.size(); i++ ) f << str[i] << std::endl;
    f.close();

    int sidx =0;
    int eidx = 0;
    unsigned long prd = getNonZeroProduct( sidx, eidx );  // sidx points to the end of the prod chars
    unsigned long maxprod = prd;

    std::cout << "The first nonzero product starting from " << sidx << " and ending at " << eidx << " is " << prd << std::endl;

    int i = eidx;
    while( i<LEN ) {

        if( 0 == (str[i] - '0' )) {
            std::cout << "str["<<i<<"]=0"<<std::endl;
            i+=1;
            int e=0;
            unsigned long nprd = getNonZeroProduct(i, e);
            if( nprd > maxprod ) {
                maxprod = nprd;
            }
            prd = nprd;
            i = e;
        } else {
            int s = i-INCR;
            prd *= (str[i] - '0' ) ;
            prd /= ( str[s] - '0' );
            if ( prd > maxprod ) maxprod = prd;
            ++i;
        }
    }
    std::cout << "The max product of " << INCR << " digits is:" << maxprod << std::endl;
}

