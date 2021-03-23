#include <iostream>
#include <variant>
template<class... Ts> struct overload : Ts... {
    using Ts::operator()...;
};
template<class... Ts> overload(Ts...) -> overload<Ts...>;
struct Pizza { };
struct Chocolate { };
struct Salami { };
struct IceCream { };

int main() {
    //std::variant<Pizza, Chocolate, Salami, IceCream> firstIngredient { IceCream() };
    //std::variant<Pizza, Chocolate, Salami, IceCream> secondIngredient { Chocolate()};
    std::variant<Pizza, Chocolate, Salami, IceCream> firstIngredient { Salami() };
    std::variant<Pizza, Chocolate, Salami, IceCream> secondIngredient { Salami()};
    std::visit(overload{
        [](const Pizza& p, const Salami& s) {
            std::cout << "here you have, Pizza with Salami!\n";
        },
        [](const Salami& s, const Pizza& p) {
            std::cout << "here you have, Pizza with Salami!\n";
        },
        [](const Chocolate& c, const IceCream& i) {
            std::cout << "Chocolate with IceCream!\n";
        },
        [](const IceCream& i, const Chocolate& c) {
            std::cout << "IceCream with a bit of Chocolate!\n";
        },

        [](auto a, auto b) {
            std::cout << "invalid composition...\n";
        },
    }, firstIngredient, secondIngredient);
    return 0;
}
