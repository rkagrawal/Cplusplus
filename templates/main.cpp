#include <iostream>

using namespace std;
template< typename T, int N=3 > 
class Foo {
    private:
        const static int sz=N;
        T arr[N];
    public:
        Foo(T x) {
            for (int i=0; i< sz; i++ ) {
                arr[i] = x++;
            }
        }

        void print() {
            for (int i=0;i<sz; i++ ) { 
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        
};

int main( int argc, const char* argv[] ) {
    
    float y=2.1;
    Foo<float> myfoo(2.1);
    myfoo.print();

    Foo<float,5> myfoo2(3.9);
    myfoo2.print();

    Foo<float> myfoo3(5);
    myfoo3.print();
}
