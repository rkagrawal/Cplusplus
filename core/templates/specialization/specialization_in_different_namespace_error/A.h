#include<iostream>


namespace rka {

    class A {
        public:
            A(int i_) : i(i_) {}

            template<typename T>
            inline void print(T& t ) {
				std::cout << "generic print:" << t << std::endl;
			}
        private:
            int i;
    };
}
