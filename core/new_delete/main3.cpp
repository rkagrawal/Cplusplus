#include <iostream>

 class Allocator
    {
    public:
        virtual ~Allocator() { }
        virtual void *malloc(size_t bytes_) = 0;
        virtual void free(void *) = 0;
    };


 template<size_t POOL_SIZE>
    class StackAllocator : public Allocator
    {
    public:
        StackAllocator()
        : _maxSize(POOL_SIZE)
        , _currentOffset(0)
        { }
        void *malloc(size_t bytes_)
        {
            if (_currentOffset + bytes_ > _maxSize)
                return 0;

            void *ptr = &_pool[_currentOffset];
            _currentOffset += bytes_;
            return ptr;
        }

        void free(void *)
        { }

    private:
        char _pool[POOL_SIZE];
        size_t _maxSize;
        size_t _currentOffset;
    };


void* operator new( size_t sz, Allocator &a ) {
        std::cout << "It is coming here\n";
        return a.malloc( sz );

}

 struct A {
    int _a;
    long _b;
    A( int a_, long b_ ) : _a(a_), _b(b_) {}

    void print () { std::cout <<  "a:" << _a << "b:"  << _b << std::endl; }

 };


int main() {

    StackAllocator< sizeof(A) * 5 > myalloc;
    A* mya1 = new( myalloc ) A(1, 5671 );
    mya1->print();
    A* mya2 = new( myalloc ) A(2, 5672 );
    mya2->print();
    A* mya3 = new( myalloc ) A(3, 5673 );
    mya3->print();
    A* mya4 = new( myalloc ) A(4, 5674 );
    mya4->print();
    A* mya5 = new( myalloc ) A(5, 5675 );
    mya5->print();

    // There the allocator has space for five As, creating antoher one shoudl crash
    A* mya6 = new( myalloc ) A(6, 5676 );
    mya6->print();

    std::cout << "End \n";

}

