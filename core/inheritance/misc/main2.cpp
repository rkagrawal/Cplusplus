#include <iostream>
#include <string>


class B {
    protected:
        int _i;
    public:
        B(int i_) : _i(i_) {}
        virtual void evaluate() { std::cout << "B:evaluate i:" << _i << std::endl; }
        virtual ~B() {}
};

class D1 : public B {

    private:
        std::string _s;
    public:
        D1(int i_, std::string x_) : B(i_), _s( std::move(x_)) {}
        void evaluate() { std::cout << "D1:evaluate i:" << _i << " _s:" << _s << std::endl; }
        virtual ~D1() {}

};

class D2 : public B {

    private:
        double _d;
    public:
        D2(int i_, double x_) : B(i_), _d(x_) {}
        void evaluate() override { std::cout << "D2:evaluate i:" << _i << " _s:" << _d << std::endl; }
        virtual ~D2() {}
};
