/* see for better solution: https://adamdrake.com/an-unreasonably-deep-dive-into-project-euler-problem-1.html */
#include <iostream>
#include <set>
#include <algorithm>

int main() {

  std::set<int> numset;
  
  int threem = 3;
  int fivem = 5;
  
  numset.insert(threem);
  numset.insert(fivem);
  while ( threem <1000 || fivem < 1000 ) {

    threem += 3;
    fivem +=5;
    if ( threem < 1000) numset.insert(threem);
    if ( fivem < 1000) numset.insert(fivem);
 

  }
  std::copy( numset.begin(),numset.end(), std::ostream_iterator<int>(std::cout, " " ) );

  int s=0;
  std::for_each( numset.begin(), numset.end(), [&s=s]( int x) { s+=x;});
  std::cout << "The sum is " << s << std::endl;

}
