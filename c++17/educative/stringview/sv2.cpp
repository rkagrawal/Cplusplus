#include <iostream>
#include <string>
#include <string_view>

using namespace std;

class UserName 
{ 
  std::string mName;
  public:
  UserName(std::string_view sv) : mName(sv) { }
  std::string_view getName(){return mName;}
};
std::string GetString() { return "some string..."; }

int main(){
  // creation from a string literal
  UserName u1{"John With Very Long Name"};
  cout << u1.getName() << endl;
  
  // creation from l-value:
  std::string s2 {"Marc With Very Long Name"};
  UserName u2 { s2 };
  cout << u2.getName() << endl;
  // use s2 later...
  
  // from r-value reference
  std::string s3 {"Marc With Very Long Name"};
  UserName u3 { std::move(s3) };
  cout << u3.getName() << endl;
  // third case is also similar to taking a return value: 
  
  UserName u4 { GetString() };
  cout << u4.getName() << endl;
}
