#include<iostream>
#include<type_traits>


class  A {

    public:
	    A(int i_):i(i_){}

		A& operator=(const A&) = delete;
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
struct is_cp_assignable {
	private:
		template<typename U, class = decltype(std::declval<U&>() = std::declval<const U&>())>
		static std::true_type try_cp( U&& );
		static std::false_type try_cp(...);
	public:
		using type = decltype( try_cp(std::declval<T&>() ) ) ; 
};



template<typename T>
struct is_conflatable {
	private:
		template< class U, class = typename std::is_same<decltype(std::declval<U&>().print()), void>::type>
		static std::true_type try_conflation( U&& );
		static std::false_type try_conflation(...);
	public:
		using type = decltype( try_conflation(std::declval<T&>() ) ) ; 
};

template<typename T>
void func(T& myt, std::true_type ) 
{
	myt.print();	
}

template<typename T>
void func(T& myt, std::false_type ) 
{
	myt.printB();	
}

template<typename T>
void func(T& myt ) 
{
	func(myt, typename is_conflatable<T>::type{});
	using t = typename is_conflatable<T>::type;
	//func(myt, t{} );
}

int main() {

		
	
	//decltype(declval(T&).print())* x;
	A a(9);
	
	func(a);

	B b(9);
	//func(b, typename std::is_same<decltype(std::declval<B&>().print()), void>::type );
	func(b);

	std::cout << "is conflatable " << std::is_same<is_conflatable<B>::type, std::true_type>::value << std::endl;
	std::cout << "is cpassign " << std::is_same<is_cp_assignable<A>::type, std::true_type>::value << std::endl;
}

