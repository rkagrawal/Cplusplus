#include<functional>
#include<algorithm>
#include<iostream>
#include<chrono>

using namespace std;

int sum( int x, int y ) {
    return (x+y);
}

int main(int argc,const char* argv[] ) {
    std::function<int(int,int)> myfunc = sum; 
    auto prt = [&f = myfunc]( auto& a1, auto& a2 ) {
        chrono::system_clock::time_point tp1= chrono::system_clock::now();
        auto x = f( a1, a2);
        chrono::system_clock::time_point tp2= chrono::system_clock::now();
        cout << "The the function (sum) took " << chrono::duration_cast<chrono::nanoseconds>(tp2-tp1).count() 
             << endl;
        return x;
    };   


    int i1 = 4; 
    int i2 = 5;
    cout << "The sum is " << prt( i1, i2 ) << endl;


    auto prt2 = [&f = myfunc]( auto&&... args ) {
        chrono::system_clock::time_point tp1= chrono::system_clock::now();

        /* See the sepcial syntax  below ( ... in the call to f 
         * read https://stackoverflow.com/questions/12515616/expression-contains-unexpanded-parameter-packs
        */
        auto x = f( forward<decltype(args)>(args)...);
        chrono::system_clock::time_point tp2= chrono::system_clock::now();
        cout << "The duratio of the call to sum took " << chrono::duration_cast<chrono::nanoseconds>(tp2-tp1).count() << endl;
        return x;
    };   
    
    cout << "the sum of 58 and 87 is " << prt2( 58, 87 ) << endl;


    auto prt3 = []( auto& f, auto&&... args ) {
        chrono::system_clock::time_point tp1= chrono::system_clock::now();
        /* See the sepcial syntax  below ( ... in the call to f 
         * read https://stackoverflow.com/questions/12515616/expression-contains-unexpanded-parameter-packs
        */
        auto x = f( forward<decltype(args)>(args)...);
        chrono::system_clock::time_point tp2= chrono::system_clock::now();
        cout << "The duratio of the call to sum took " << chrono::duration_cast<chrono::nanoseconds>(tp2-tp1).count() << endl;
        return x;
    };

    cout << "the sum of 158 and 187 is " << prt3( sum, 158, 187 ) << endl;

}

