#include <algorithm>
#include <iostream>
#include <memory>
#include <functional>

void print( const std::shared_ptr<const std::string> sptr_ ) {
	std::cout << *sptr_ << " use count " << sptr_.use_count() << std::endl;

}

void func() {

	const std::shared_ptr<const std::string> ptr = std::make_shared<std::string>( "Rajesh" );

	std::cout << "The use count of ptr before bind is " << ptr.use_count() << std::endl;
	auto f = std::bind( &print, std::ref(ptr) );
	std::cout << "The use count of ptr after bind is " << ptr.use_count() << std::endl;
	
	f();

}

int main() {
	func();
}

