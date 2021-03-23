#include<iostream>


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

//template<typename T, bool isConflatedType=std::is_same<decltype(std::declval<T&>().print()), void>::value>

//template<typename T>
void func( A myt) {
	myt.print();
}



template<typename T, class Enable=typename std::enable_if<std::is_same<decltype(std::declval<T&>().printB()), void>::value>::type>
void func( T myt )
{
	myt.printB();
}


int main() {
	
	//decltype(declval(T&).print())* x;
	A a(9);
	
	//func(a,  std::is_same<decltype(std::declval<A&>().print()), void>{} );
	func(a);

	B b(9);
	//func(b, std::is_same<decltype(std::declval<B&>().print()), void>{} );
	func(b);
}
