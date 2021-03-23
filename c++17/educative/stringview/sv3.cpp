#include <iostream>
#include <string_view>
using namespace std;
using namespace std::literals;

int main() {
  constexpr auto strv = "Hello Programming World"sv;
  constexpr auto strvCut = strv.substr("Hello "sv.size());
  
  static_assert(strvCut == "Programming World"sv);
  cout << strvCut.size(); 
}
