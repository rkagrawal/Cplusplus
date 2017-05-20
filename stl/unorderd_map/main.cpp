#include <iostream>

#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <memory>

struct S {
    std::string first_name;
    std::string last_name;
};
bool operator==(const S& lhs, const S& rhs) {
    std::cout << "== here" << std::endl;
    return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}

// custom hash can be a standalone function object:
template <class T> struct MyHash;
template<> struct MyHash<S>
{
    std::size_t operator()(S const& s) const
    {
        std::size_t h1 = std::hash<std::string>()(s.first_name);
        std::size_t h2 = std::hash<std::string>()(s.last_name);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};

// custom specialization of std::hash can be injected in namespace std
namespace std
{
    template<> struct hash<S>
    {
        typedef S argument_type;
        typedef std::size_t result_type;
        result_type operator()(argument_type const& s) const
        {
            std::cout << "Here" << std::endl;
            result_type const h1 ( std::hash<std::string>()(s.first_name) );
            result_type const h2 ( std::hash<std::string>()(s.last_name) );
            return h1 ^ (h2 << 1); // or use boost::hash_combine
        }
    };
}

int main()
{
    
    std::string str = "Meet the new boss...";
    std::size_t str_hash = std::hash<std::string>{}(str);
    std::cout << "hash(" << str << ") = " << str_hash << '\n';
    
    S obj = { "Hubert", "Farnsworth"};
    
    // using the standalone function object
    std::cout << "hash(" << obj.first_name << ','
    << obj.last_name << ") = "
    << MyHash<S>()(obj) << " (using MyHash)\n                           or "
    << std::hash<S>()(obj) << " (using std::hash) " << '\n';
    
    std::cout << "-----------------" << std::endl;
    // custom hash makes it possible to use custom types in unordered containers
    std::unordered_set<S> names = {obj, {"Bender", "Rodriguez"}, {"Leela", "Turanga"} };
    for(auto& s: names)
        std::cout << s.first_name << ' ' << s.last_name << '\n';
    
    
    std::unordered_map<std::string, std::unique_ptr<S>> uomcache;
    uomcache[ "H" ] =  std::make_unique<S>( obj );
    std::unique_ptr<S>& myshp = uomcache[ "K" ];
    if( myshp ) {
        std::cout<< "K" << "found in the map" << std::endl;
    } else {
       std::cout<< "K" << "is NOT found in the map" << std::endl;
    }
    
    
    std::unique_ptr<S> myuptr = std::make_unique<S>() ; // calls new T inside make_unique
    std::unique_ptr<S>& myuptrref = myuptr;
    
}
