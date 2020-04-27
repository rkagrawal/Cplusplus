#include <stdexcept>
#include <iostream>


class B {
        int _f;
        long _l;
    public:
        B( int f_, long l_) : _f(f_), _l(l_) { std::cout << "B() called" << std::endl; }
        virtual ~B() {
            std::cout << "virtual ~B called" << std::endl;
        }


        void* operator new( size_t sz, bool f ) {
            std::cout << "B::new called sz:" << sz << std::endl;
            return ::operator new (sz);
        }

        void operator delete( void * p ) {
            std::cout << "B::delete (void*p) called" << std::endl;
            ::operator delete(p);
        }

        void operator delete( void * p, size_t sz ) {
            std::cout << "B::delete called sz:" << sz << std::endl;
            ::operator delete(p);
        }

};

class  D : public B {
    private:
        int _a;
    public:
        /* the throw in the constuctor will cause the delete with matching signature tobe called -- destructor of D is not called
         * as the D is not created . Howver destructor of B is called before the matching delete is called.
         */
        D( int f_, long l_, int a_) :  _a(a_ ) , B(f_,l_) {
            std::cout << "D ctr called\n";
            //std::cout << "Dctor throwing exception " << std::endl;
            //throw std::runtime_error(" "); std::cout << "D() called" << std::endl;
        }


        ~D() {
            std::cout << "~D called" << std::endl;
        }


        void* operator new( size_t sz, bool f ) {
            std::cout << "D::new called sz:" << sz << "bool : " << f << std::endl;
            return :: operator new (sz);
        }

        void* operator new( size_t sz, void *p ) {
            std::cout << "D::new(void*p) called sz:" << sz << std::endl;
            return p;
        }


        void operator delete( void *p ) {
            std::cout << "D::delete( void*p) called :" << std::endl;
            ::operator delete(p);
        }

        void operator delete( void *p , size_t sz ) {
            std::cout << "D::delete called sz:" << sz << std::endl;
            ::operator delete(p);
        }

        void operator delete( void *p , bool f ) {
            std::cout << "D::delete with bool :" << f << std::endl;
            ::operator delete(p);
        }


};


int main( int argc, const char* argv[] ) {

    try {

        std::cout << "Creating D" << std::endl;

        // Below calls the global new
        //D* pd1 = ::new D( 2,4,3 );
        // Below calls the D:: new
        B* pd1 = new(false) D( 2,4,3 );
        std::cout << "Deleting pd1.. " << std::endl;
        delete pd1;

        std::cout << std::endl;
        std::cout << "Creating B" << std::endl;

        B* pb1 = new(false) B( 2,4 );
        std::cout << "Deleting pb1.. " << std::endl;
        delete pb1;


        std::cout << "Creating D with in my own space" << std::endl;
        char *myp = new char[ sizeof(D) ];
        B* pd2 = new( myp ) D( 1,2,3 );
        delete pd2;

        // The below delete of myp will crash the system as memory is already deleted by operator delete of D
        //delete (char*)myp;

        } catch( ... ) {
            std::cerr << "Possible exception during construction of the object" << std::endl;
        }
}

