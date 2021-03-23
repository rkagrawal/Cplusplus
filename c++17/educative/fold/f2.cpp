
#include <iostream>
using namespace std;

template<typename F, typename ...Args>
void FoldPrintComma(F&& f, Args&&... args)
{
  cout << f;
  auto withComma = [](const auto& mya) { cout << "," << mya ; };

  ( ... , withComma(std::forward<Args>(args)));
  cout << "\n";
}

int main()
{ 
  cout << "Your Arguments = ";
  FoldPrintComma("hello", 10, 20, 30);
}
