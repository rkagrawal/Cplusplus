#include<iostream>
#include<vector>

struct E {
    std::string x;
    std::string y;
    int z;

    E(){
        std::cout << "def ctor" << std::endl;
    }
    E( std::string x_, std::string y_, int z_ ): x(x_), y(y_), z(z_) {
        std::cout << "non def ctor " << std::endl;
    }

/*
    E( const E& e ) {
        x = e.x; y=e.y; z=e.z;
        std::cout << "copy ctor " << std::endl;
    }
*/

/*
    E& operator=( const E& e ) {
        x = e.x; y=e.y; z=e.z;
        std::cout << "assignment ctor " << std::endl;
		return *this;
    }
*/

    void print() {
        std::cout << "x: " << x << " y:" << y << " z:" << z << std::endl;
    }
};
struct Q {
    std::vector<E> eVec;
    Q() {}

    void push( const E& e ) {
        eVec.push_back(e);
    }
};


int main() {
    Q myq ;

    E e1("a", "b", 1);
    E e2("a", "b", 2);
    E e3("a", "b", 3);

    myq.push(e1);
    myq.push(e2);
    myq.push(e3);

	for( auto& e : myq.eVec ) e.print();

    // With above there will be 6 calls to copy ctr of E due to vector reallocation


    std::cout << "============== Testing for vector assign ===============" << std::endl;

    Q myq2;
    myq2.eVec.assign( myq.eVec.begin(), myq.eVec.end() );
	for( auto& e2 : myq2.eVec ) e2.print();
}
