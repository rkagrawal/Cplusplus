#include<iostream>
#include<string>
#include<utility>
#include<boost/intrusive/set.hpp>

using namespace boost::intrusive;

class Employee  
{
    public:
        Employee( std::string n, int a ) : _name( std::move(n) ), _age(a) {}

        const std::string& getName() { return _name; }
        int getAge() { return _age; }

        ~Employee() {
            std::cout << "Destroying obj\n";
        }

		set_member_hook<> hook_;

		friend bool operator< (const Employee &a, const Employee &b)
      	{  return a._age < b._age;  }

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


	using  member_hook1 = member_hook<Employee, set_member_hook<> , &Employee::hook_> ;

    set<Employee, member_hook1> set1;

    set1.insert( e );
    set1.insert( e2 );
}
