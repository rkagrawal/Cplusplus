#include "A.h"

template<>
void rka::A::print<std::string>(std::string& s ) {
     std::cout << "string specific:" << s << std::endl;
}
