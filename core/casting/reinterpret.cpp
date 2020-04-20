#include <iostream>

class A{
    private:
        int i;;
        int getInt() { return i ; }

    public:
        A(int x) : i(x) {}
        int publicgetInt() { return i; };
};

class B {
    public :
        int i;
		// you can have other members after i and reinterpret cast may still work
};

int main() {
   A mya(4);

   B* xyz = reinterpret_cast<B*>(&mya);
   xyz->i = 5;
   std::cout << "B i is " << xyz->i << std::endl;
   std::cout << "public A returns " << mya.publicgetInt() << std::endl;
}
