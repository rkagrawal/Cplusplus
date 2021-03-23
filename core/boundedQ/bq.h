#include<iostream>
#include<queue>
#include<mutex>
#include<thread>
#include<condition_variable>
#include<atomic>
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
            ++_size;
            //std::this_thread::sleep_for (std::chrono::milliseconds(10));
            //std::cout << "thread:" << this_id << " Inserted " << x << std::endl;
            lk.unlock();
            _cv.notify_all();
        }

        T pop() {
            std::thread::id this_id = std::this_thread::get_id();
            std::unique_lock<std::mutex> lk( _mut );
            _cv.wait( lk, [ p=this] () { return p->_size > 0 ; } );
            T x = _q.front();
            _q.pop();
            --_size;
            //std::cout << "thread:" << this_id << " popped " << x << std::endl;

            lk.unlock();
            _cv.notify_all();
            return x;
        }

        int size() const { return _size; }

    private:
        std::queue<T> _q;
        int _max = {N};
        //std::atomic<int> _size;
        int _size;
        std::condition_variable _cv;
        std::mutex _mut;

};
