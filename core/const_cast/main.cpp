#include <iostream>
#include <memory>
#include <string>


int main() {

	std::shared_ptr<std::string> sptr = std::make_shared<std::string>("Rajesh" );

	std::shared_ptr<const std::string> csptr = std::const_pointer_cast<const std::string>( sptr );
	const std::shared_ptr<const std::string> ccsptr = std::const_pointer_cast<const std::string>( sptr );

	std::cout << *sptr << std::endl;
	std::cout << *csptr << std::endl;
	std::cout << *ccsptr << std::endl;
}
