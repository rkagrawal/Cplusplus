#include <iostream>
#include <array>
using namespace std;

struct NonMoveable
{
  NonMoveable(int x) : v(x) { std::cout << "ctor \n"; }
  NonMoveable(const NonMoveable&) = delete;
  NonMoveable(NonMoveable&&) = delete;
  
  std::array<int, 1024> arr;
  int v;
};

NonMoveable make(int val)
{
 
  if (val > 0)
    return NonMoveable(val);
  return NonMoveable(-val);
 

/* below fails to compile 
 * because it uses named varaible /
 * c++17 make copy elison mandator for temporary as able
 */

/* 
  if( val > 0 ) {
	NonMoveable x{val};
 	return x;
  } else {
	NonMoveable x{-val};
 	return x;
  }
*/

}

int main()
{
  auto largeNonMoveableObj = make(90); // construct the object
  cout << "The v of largeNonMoveableObj is: " <<largeNonMoveableObj.v <<endl;
  return largeNonMoveableObj.v;
}
