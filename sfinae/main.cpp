#include<iostream>

using namespace std;


class Y {
    public:
        Y(int i ): value(i) {}
        int value;
};

template < typename T >
T add( const T& a, const T& b ) {
    cout << "Templated add \n";
    return a.value + b.value;
}

int add( unsigned x, unsigned y ) { 
    cout << "add of unsigned \n";
    return x + y; 
}

int main( int argc, char* argv[] ) {
    
    const int i=50;
    const int j=60;

    Y y1(5);
    Y y2(6);
 
    /*
     *  The following line if uncommented will result in compilation error as 
     *  i and j are int and the non templated functin takes unsigned.. so compiler 
     *  uses the template class for int and the compilation fails as int is not a structure
     *  or union with a value as member 
    */
    //cout << "The addition is " << add(i,j) << endl; 

    cout << "The addition is " << add(y1,y2).value << endl; 
    
}
