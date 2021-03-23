#include <iostream>
#include <variant>

void* operator new(std::size_t count) {
    std::cout << "allocating " << count << " bytes" << std::endl;
    return malloc(count);
}

struct SampleVisitor {
    void operator()(int i) const { std::cout << "int: " << i << '\n'; }
    void operator()(float f) const { std::cout << "float: " << f << '\n'; }
    void operator()(const std::string& s) const { std::cout << "string: " << s << '\n'; }
};

int main() {
    std::variant<int, float, std::string> intFloatString;
    static_assert(std::variant_size_v<decltype(intFloatString)> == 3);
    
    //default initialized to the first alternative, should be 0
    std::visit(SampleVisitor{}, intFloatString); 
    // visit(vis,vars)  - Applies the visitor vis to the variants vars 
    // where vis    -	a Callable that accepts every possible alternative from every variant
    // vars   -	list of variants to pass to the visitor
    
    std::cout << "index will show the currently used 'type'" << std::endl;
    std::cout << "- when intFloatString is default initialized to the first alterantive ie. int" << std::endl;
    std::cout << "index = " << intFloatString.index() << std::endl;

    std::cout << "- when intFloatString = 100.0f " << std::endl;
    intFloatString = 100.0f;
    std::cout << "index = " << intFloatString.index() << std::endl;

    std::cout << "- when intFloatString = hello super world " << std::endl;
    intFloatString = "hello super world";
    std::cout << "index = " << intFloatString.index() << std::endl;

    // check currently used type with holds_alternative
    if (std::holds_alternative<int>(intFloatString))
	    std::cout << "the variant holds an int!\n";
	else if (std::holds_alternative<float>(intFloatString))
	    std::cout << "the variant holds a float\n";
	else if (std::holds_alternative<std::string>(intFloatString))
	    std::cout << "the variant holds a string\n";  

    // try with get_if:
    // get_if: obtains a pointer to the value of a pointed-to variant given the index or the type (if unique)
    if (const auto intPtr (std::get_if<int>(&intFloatString)); intPtr) {
        std::cout << "int: " << *intPtr << '\n';}
    else if (const auto floatPtr (std::get_if<float>(&intFloatString)); floatPtr) {
        std::cout << "float: " << *floatPtr << '\n';}


    // try/catch and bad_variant_access
    try {
        auto f = std::get<float>(intFloatString); 
        std::cout << "float! " << f << '\n';
    }
    catch (std::bad_variant_access&) {
        std::cout << "our variant doesn't hold float at this moment...\n";
    }

    // visit:
    std::visit(SampleVisitor{}, intFloatString);
    intFloatString = 10;
    std::visit(SampleVisitor{}, intFloatString);
    intFloatString = 10.0f;
    std::visit(SampleVisitor{}, intFloatString);

	std::cout << "The index of infloatstring is " << intFloatString.index() << std::endl;

    return 0;
}
