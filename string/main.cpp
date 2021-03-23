#include<iostream>
#include<string>


int main() {
	
	std::string abc = "abc";

	std::string newstr = abc.substr(0,4);

	std::cout << abc << " " << newstr << std::endl;

	std::string j = "j";
	std::string t = "ra";

	if (  t == j.substr(t.size() ))
		std::cout << "here\n";
	else 
		std::cout << "there\n";
}
