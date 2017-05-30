#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class sibling {
    private:
        string lname={}, fname={};
        unsigned short age;

    public:
        sibling( string l, string f, unsigned short z ) : lname( std::move(l)), fname( std::move(f)), age(z) { cout << "copyctr\n"; }
        sibling& operator=( const sibling& s ) {
            cout << "= operator\n"; 
            this->lname = s.lname; this->fname = s.fname; this->age = s.age;
            return *this;
        }

        bool operator<( const sibling& s ) const { 
            return age < s.age;
        }
        const string& getLname() const { return lname; }
        const string& getFname() const { return fname; }
        int getAge() const { return age; }
};

ostream& operator<<( ostream& o, const sibling& s ) {
    o << s.getFname() << " " << s.getLname() << ":" << s.getAge() << endl;
    return o;
}

const auto& getCRef( const sibling& s ) { return s; }

int main( int argc, char* argv[] ) {

    vector<sibling> s;
    s.emplace_back( "Agrawal", "Suresh", 49 );
    s.emplace_back( "Agrawal", "Rajesh", 51 );
    s.emplace_back( "Agrawal", "Dinesh", 46 );
    s.emplace_back( "Agrawal", "Mahesh", 48 );

    cout<<"1-----\n";
    auto first = cbegin(s);
    cout << "The address of first is " << &(*first)  << endl;
    cout << "The address of &*cbegin(s) is " << &(*cbegin(s))  << endl;
    cout<<"2-----\n";
    const auto& i = *first;
    cout << i << endl;
    cout<<"2-----\n";

    const auto& youngest = [] ( const sibling& a, const sibling& b ) -> const sibling& { 
                cout << "Inside Lambda " << " address of a is " << &a << endl;
                cout << "Inside Lambda " << " address of b is " << &b << endl;
                if ( a < b )  {
                    cout << "returning a\n"; 
                    return a;
                } else {
                    cout << "returning b\n"; 
                    return b;
                };
   //             return  ( a<b ? a: b ); 
    };


    class youngestfunctor {
        public:
            youngestfunctor() {} 
            const sibling& operator()( const sibling& a, const sibling& b ) {
                cout << "Inside functor " << " address of a is " << &a << endl;
                cout << "Inside functior " << " address of b is " << &b << endl;
                if ( a < b )  {
                    cout << "returning a\n"; 
                    return a;
                } else {
                    cout << "returning b\n"; 
                    return b;
                };
   //             return  ( a<b ? a: b ); 
            }
    };

    /*
        Accumulate takes the init as a copy ( T )
        The return value is also a T.. so the address of the object is different
    */

    cout<<"3-----\n";
    auto y = accumulate( ++first, cend(s), i , youngest );
    cout<<"4-----\n";
    cout << y << " address is " << &y << endl;

    // z is an iterator
    auto z = min_element( cbegin(s), cend(s) );
    cout << *z << endl;

    cout<<"*****\n";
    const auto& another = getCRef( *z );
    cout << another<< endl;

    
    cout << "-------\n";
    const auto& i2 = *first;
    auto y2 = accumulate( ++first, cend(s), i2 , youngestfunctor() );
    cout << y2 << " address is " << &y2 << endl;


    for( const auto& e : s ) {
        cout << e << " address is " << &e << endl;
    }

}



