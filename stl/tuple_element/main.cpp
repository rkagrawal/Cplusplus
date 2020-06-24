/* there is std::tuple_element that gets the type of the 1th element of a tuple */
/* This exercise is to write one of my own to see if I understand */

#include<tuple>
#include<iostream>

namespace rka {
	
	template< std::size_t I, class T>
	struct tuple_element;

	template<std::size_t I, class Head, class... Tail > 
	struct tuple_element<I, std::tuple<Head, Tail...>> : tuple_element<I-1, std::tuple<Tail...>> {};

	template< class Head, class... Tail>
	struct tuple_element<0, std::tuple<Head, Tail...>> {
		typedef Head type;
	};
}

template <class... Args>
struct type_list
{
   template <std::size_t N>
   using type = typename rka::tuple_element<N, std::tuple<Args...>>::type;
};
 
int main()
{
   std::cout << std::boolalpha;
   type_list<int, char, bool>::type<2> x = true;
   type_list<int, char, bool>::type<0> y = 25;
   type_list<int, char, bool, std::string>::type<3> z = std::string("mine");
   std::cout << x << '\n';
   std::cout << y << '\n';
   std::cout << z << '\n';

   auto t = std::make_tuple( 1,2.3,'C');

   std::tuple_element<2, std::tuple<int, float, char>>::type t1 = 'x';
   std::cout << t1 <<  std::endl;
}
