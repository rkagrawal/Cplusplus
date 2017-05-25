#include<iostream>
#include<string>
using namespace std;

class emp {
    private:
        string lname;
        string fname;
        int age;	

    public:
        emp( string l, string f, int a ) : lname (std::move(l)), fname( std::move(f)), 
                                           age ( a ) {
            cout << "called ctr for " << fname << " at address " << this << endl;
        }

        emp(const emp& e ): lname(e.lname), fname( e.fname), age(e.age)  {
            cout << "called copy ctr for " << fname << " at address " << this << endl;
        }

        emp(emp&& e ): lname(move(e.lname)), fname( move(e.fname)), age(e.age)  {
            cout << "called move ctr for " << fname << " at address " << this << endl;
        }

        emp( const emp* const e  ): lname(e->lname), fname(e->fname), age(e->age) {
            cout << "calling ctr with ptr " << fname << " at address " << this << endl;
        }

        const string& getFirstName() const ;
        const string& getLastName() const ;
        int getAge() const { return age; }
        ostream& print(ostream&);
        ~emp() {
            cout << "Calling dtor for " << fname << " at address " << this << endl;
        }
};
