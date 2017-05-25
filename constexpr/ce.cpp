#include <iostream>
using namespace std;

class P  {
  private:
   int x, y;
  public:
    //P( int a, int b): x(a), y(b) {}
    constexpr P( int a, int b): x(a), y(b) {}

    constexpr int getX() const { return x ; }
    void setX(int a) {  x=a;  }
    constexpr int getY() const { return y ; }
    void setY(int a) {  y=a; }
};

int main( int argc, const char* argv[] ) {

  constexpr int x = 24;
  cout << x << endl;
  //x = 56;  //  will throw compile time error

  constexpr P p(2,3);  
  static_assert( p.getX() == 2, "Yikes" );
  static_assert( p.getY() == 3 , "Yikes");
  return 0;
}

