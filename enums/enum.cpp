#include<iostream>

using namespace std;
int main( int argc, const char* argv[] ) {
    enum class Color { red, green = 20, orange=5, blue=4, pink=-2 };
    Color r = Color::blue;
    switch(r)
    {
        case Color::red  : std::cout << "red\n";   break;
        case Color::green: std::cout << "green\n"; break;
        case Color::blue : std::cout << "blue\n";  break;
        case Color::orange : std::cout << "orange\n";  break;
        case Color::pink : std::cout << "pink\n";  break;
    }
    // int n = r; // error: no scoped enum to int conversion
    cout << "The enum value of blue is " << static_cast<int>(Color::blue) << endl; 
    cout << "The enum value of red is " << static_cast<int>(Color::red) << endl; 
    cout << "The enum value of green is " << static_cast<int>(Color::green) << endl; 
    cout << "The enum value of orange is " << static_cast<int>(Color::orange) << endl; 
    cout << "The enum value of pink is " << static_cast<int>(Color::pink) << endl; 

    // cast the enum to underlying type..
    cout << "The underlying type value of the Color::red is " << static_cast< underlying_type_t<Color>>(Color::red) << endl;

    cout << "The underlying type of Color is " << std::underlying_type<Color>::type(Color::red) << endl;

    /* cannot print the type so the below throws error  -- to print the actual type, you have to use boost typeindex class
        cout << "The underlying type of Color is " << decltype( Color::blue ) << endl;
    */

  
}
