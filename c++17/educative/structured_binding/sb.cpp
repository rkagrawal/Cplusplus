#include <iostream>
#include <tuple>

class UserEntry {
public:
    UserEntry() { }
    
    void Load() { 
        // simulate loading from db...
        name="John"; 
        age=45;
        cacheEntry = 10;
    }
    
    std::string GetName() const { return name; }
    unsigned GetAge() const { return age; }
    
private:
    std::string name;
    unsigned age { 0 };
    size_t cacheEntry { 0 };
};

// read access:
template <size_t I> auto get(const UserEntry& u) {
    if constexpr (I == 0) return u.GetName();
    else if constexpr (I == 1) return u.GetAge();
}

namespace std {
    template <> struct tuple_size<UserEntry> : std::integral_constant<size_t, 2> { };

    template <> struct tuple_element<0,UserEntry> { using type = std::string; };
    template <> struct tuple_element<1,UserEntry> { using type = unsigned; };
}

int main () {
    UserEntry u;
    u.Load();
    auto [name, age] = u;
    std:: cout << name << ", " << age << '\n';
     std::tuple_element<0, UserEntry>::type name2 = get<0UL>(u); 
    std:: cout << name2 << ", " << age << '\n';
}

/* 
	The above translates to something like this..

  std::basic_string<char> name = get<0UL>(__u84);
  std::tuple_element<1, UserEntry>::type age = get<1UL>(__u84); 

*/
