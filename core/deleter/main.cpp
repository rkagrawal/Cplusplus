#include <iostream>
#include <string>
#include <memory>

class emp {
	private:
		std::string name;
		int age;
	public:
		emp( std::string n_, int a_ ) : name( n_ ), age(a_) {}

		~emp() {
			std::cout << "Emp destructor" << this << std::endl;
		}
};

class emp_deleter {
	public:
		void operator() ( emp* p ) { 
			std::cout << "emp_deleter .. about to delete " << p << std::endl;
			delete p;
		}
};


int main() {
	std::shared_ptr<emp> e1( new emp( "Rajesh", 55 ) ); 
	std::shared_ptr<emp> e2( new emp( "Rajesh", 55 ) , emp_deleter() ); 
	
}
