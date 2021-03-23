#include <iostream>
#include <string>
#include <boost/intrusive/list.hpp>

using namespace boost::intrusive;

struct mytag1;
struct mytag2;

using basehook1 = list_base_hook< tag<mytag1 >>;
using basehook2 = list_base_hook< tag<mytag2 >>;

class Employee : public basehook1, public basehook2 {

	public:
		Employee( std::string n, int a ) : _name( std::move(n) ), _age(a) {}

		const std::string& getName() { return _name; }
		int getAge() { return _age; }

		~Employee() { 
			std::cout << "Destroying obj\n"; 
		}
	private:
		std::string _name;
		int _age;
};

int main() {

	/* NOTE... The Employee objects have to be created before  the list as 
     * the objects have to outlive the list themselves 
     */


	Employee e( "Rajesh", 55 );
	Employee e2( "Manisha", 52 );


 	list<Employee, base_hook<basehook1>> list1;
 	list<Employee, base_hook<basehook2>> list2;

	list1.push_back( e );	
	list1.push_back( e2 );	
	list2.push_back( e );	
	list2.push_back( e2 );	

	std::cout << "I am here \n";
	return 0;
}
