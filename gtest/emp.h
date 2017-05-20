#include<iostream>
#include<string>
using namespace std;

class emp {
    private:
        string lname;
        string fname;
        int age;	

    public:
        emp( string l, string f, int a ) : lname (std::move(l)), fname( std::move(f)), age ( a ) {}
        const string& getFirstName() const ;
        const string& getLastName() const ;
        int getAge() const { return age; }
};
