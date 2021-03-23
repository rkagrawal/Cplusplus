
/* Read Richard Chen's blogs at 
 * https://devblogs.microsoft.com/oldnewthing/20200624-00/?p=103886 
 * before you proceed
 */

#include<iostream>
#include<tuple>


void print(int i, int j, int k ) {
	std::cout << i << " " << j << " " << k << std::endl;
}

template< typename... Args >
void func( Args... myargs ) {
	print( myargs... );
}

template <class F, class... Arg>
void for_each_argument(F f, Arg&&... arg)
{
   f(std::forward<Arg>(arg)...);
}
int main()
{
	func( 2,3,4);

    for_each_argument(
     [](const auto& a){std::cout<< a;}, "Aa", 3, 4);

    return 0;
}
