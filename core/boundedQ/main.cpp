#include<iostream>
#include<queue>
#include<mutex>
#include<thread>
#include<condition_variable>

#include <chrono>
#include <random>
#include <future>
#include <algorithm>


template< typename T, int N >
class BoundedQ {

   public:

        BoundedQ() : _max(N) {}

        void push( const T& x ) {
            std::thread::id this_id = std::this_thread::get_id();
            std::unique_lock<std::mutex> lk( _mut );
            _cv.wait( lk, [ p = this ]() { return p->_size < p->_max ; } );
            _q.push( x );
            _size++;
            std::cout << "thread:" << this_id << " Inserted " << x << std::endl;
            lk.unlock();
            _cv.notify_all();
        }

        T pop() {
            std::thread::id this_id = std::this_thread::get_id();
            std::unique_lock<std::mutex> lk( _mut );
            _cv.wait( lk, [ p=this] () { return p->_size > 0 ; } );
            T x = _q.front();
            _q.pop();
            _size--;
            std::cout << "thread:" << this_id << " popped " << x << std::endl;

            lk.unlock();
            _cv.notify_all();
            return x;
        }


    private:
        std::queue<T> _q;
        int _max = {N};
        int _size;
        std::condition_variable _cv;
        std::mutex _mut;

};


BoundedQ< int, 10> _MyQ;
std::uniform_int_distribution<> d(1, 1000);
std::mt19937 gen;

void produce( int initVal, int howmany ) {
    std::thread::id this_id = std::this_thread::get_id();
    for( int i=0; i< howmany; i++ ) {
        _MyQ.push( initVal + i );
        //std::cout << "Thread: " << this_id << " pushed:" << initVal + i  << std::endl;
        //std::this_thread::sleep_for( std::chrono::milliseconds(d(gen)));
    }
}

void consume( ) {
    std::thread::id this_id = std::this_thread::get_id();
    while( true )  {
        int val = _MyQ.pop();
        //std::cout << "Thread: " << this_id << " popped:" << val << std::endl;
        //std::this_thread::sleep_for( std::chrono::milliseconds( d(gen) ));
    }
}


int main( int argc, const char* argv[] ) {

    if ( argc != 3 ) {
        std::cerr << "usage : main.out <qsize> <# produce threads> <# consumer threads> " << std::endl;
        std::exit(1);
    }

    int nump = std::stoi( argv[1] );
    int numc = std::stoi( argv[2] );

    std::vector< std::future<void> > futVec;


    for(int i=0; i < numc;  i++ ) {
        futVec.push_back( std::async( std::launch::async, consume ));
    }

    for(int i=0; i < nump;  i++ ) {
        futVec.push_back( std::async( std::launch::async, produce, 1000*i, 50 ) );
    }

    //std::for_each( futVec.begin(), futVec.end(), std::mem_fn(&std::future::wait) );
    //for( auto& f: futVec ) {
    //    f.wait();
    //}
}
