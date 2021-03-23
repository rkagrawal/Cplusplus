#include<iostream>
#include<vector>

class  A {

    public:
	    A(int i_):i(i_){}

	    void print() {
		std::cout << "A::i:"<< i<< std::endl;
	    }
	private:
  	    int i;
};

class  B {

    public:
	    B(int i_):i(i_){}

	    void printB() {
		    std::cout << "B::i:"<< i<< std::endl;
	    }
	private:
  	    int i;
};

template<typename T> 
void func(T& myt ) 
{
	myt.print();
}

template<typename T>
void func( std::vector<T>& myt ) {
	for( auto& e: myt ) 
		e.print();
}


int main() {
	A mya(9);

	func(mya);

	std::vector<A> avec { A{56}, A{76} };

	func(avec);
}
