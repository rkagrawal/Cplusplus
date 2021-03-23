
#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> mapUsersAge { { "Alex", 45 }, { "John", 25 } };


  // class template deduction
  std::map mapCopy{mapUsersAge};

  // structured binding , if block changes and new method in map
  if (auto [iter, wasAdded] = mapCopy.insert_or_assign("John", 26); !wasAdded)
    std::cout << iter->first << " reassigned...\n";

  if (auto [iter, wasAdded] = mapCopy.insert_or_assign("John2", 62); !wasAdded)
    std::cout << iter->first << " reassigned...\n";


  for (const auto& [key, value] : mapCopy)
    std::cout << key << ", " << value << '\n';
}
