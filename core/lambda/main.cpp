#include <iostream>

int main() {

    int x = 8;
    // The below will not compile unless made mutable
    //auto f = [=x]( int i )  { return x += i; };

    // This compiles
    auto f = [&]( int i )  { return x += i; };
    auto f2 = [&x]( int i )  { return x += i; };

    std::cout << f(2) << std::endl;
    std::cout << f2(4) << std::endl;


    int v=9;
    int w=10;
    // this compiles
    auto f3 = [&lv=v, &lw=w]( int i )  { return lv+lw+i; lv++; };
    std::cout << f3(2) << std::endl;

    // the below does not compile unless it is made mutable as lv is capture by value
    auto f4 = [lv=v, &lw=w]( int i ) mutable  { return lv+lw+i; lv++; };

    // below will not compile as x is not captures.
    //auto f5 = []( int i ) { return x+i; };
    //std::cout << f5(3) << std::endl;

    // lambda to func pointer if it is capture less
    auto f6 = []( int i ) { return i; };
    std::cout << f6(4) << std::endl;


    int (*fptr)( int ) = f6;

}
