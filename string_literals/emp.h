#include<iostream>
#include<string>
using namespace std;

class Age {
    private:
        //unsigned short age;
        unsigned long long age;
    public:
        //explicit Age( unsigned long long s ) : age(s) {}
        explicit constexpr Age( unsigned long long s ) : age(s) {}

    friend ostream& operator<< ( ostream&, const Age& );
};

class emp {
    private:
        string lname;
        string fname;
        Age age;	

    public:
        emp( string l, string f, Age a ) : lname (std::move(l)), fname( std::move(f)), 
                                           age ( a ) {
            cout << "called ctr for " << fname << " at address " << this << endl;
        }

        emp(const emp& e ): lname(e.lname), fname( e.fname), age(e.age)  {
            cout << "called copy ctr for " << fname << " at address " << this << endl;
        }

        emp(emp&& e ): lname(move(e.lname)), fname( move(e.fname)), age(e.age)  {
            cout << "called move ctr for " << fname << " at address " << this << endl;
        }


        const string& getFirstName() const ;
        const string& getLastName() const ;
        Age getAge() const { return age; }
        ostream& print(ostream&);
        ~emp() {
            cout << "Calling dtor for " << fname << " at address " << this << endl;
        }
};

constexpr Age operator ""_years( unsigned long long s ) {
    return Age( s );
};

