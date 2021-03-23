#include <iostream>
#include <memory>
using namespace std;
 
template <typename Concrete, typename... Ts>
unique_ptr<Concrete> constructArgs(Ts&&... params)
{
  std::cout << is_constructible_v  <Concrete, Ts...> << "\n";
  std::cout << __func__ << ": ";
	((std::cout << params << ", "), ...);
	std::cout << "\n";
  if constexpr (is_constructible_v <Concrete, Ts...>) // fixed!
  {
    std::cout << __func__ << ": ";
	  ((std::cout << params << ", "), ...);
	  std::cout << "\n";
    return make_unique<Concrete>(forward<Ts>(params)...);  
  }
  else
  {
   return NULL;
  }
}

class Test
{
  public:
  Test(int, int, int) {}
};

int main()
{
  auto p = constructArgs<Test>(10, 10, 10); // 3 args!
}
