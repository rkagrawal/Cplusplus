#include <iostream>
#include <string>
#include <map>
int main() {
  std::map<std::string, std::string> m;
  m["Hello"] = "World";
  std::string s = "C++";
  m.emplace(std::make_pair("Hello", std::move(s)));
  // what happens with the string 's'?
  std::cout << s << '\n';
  std::cout << m["Hello"] << '\n';
  s = "C++";

  // try_emplace will not move s into the map if Hello is already there
  // emplace will.

  //m.try_emplace("Hello", std::move(s));
  m.emplace("Hello", std::move(s));
  std::cout << s << '\n';
  std::cout << m["Hello"] << '\n';
}
