#include <iostream>
using namespace std;

template<typename ...Args>
void FoldPrint(Args&&... args)
{
  (cout << ... << forward<Args>(args)) << '\n';
}

int main()
{ 
  cout << "Your Arguments = ";
  FoldPrint("hello", 10, 20, 30);
}
