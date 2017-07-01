#include <thread>
#include <iostream>
#include <condition_variable>

using namespace std;
class printseq {
    private:
    int i{0};
    condition_variable c;
    mutex m;
    public:

        printseq() {}
        void start_thread( function<bool(int) > f ) {
            thread::id this_id = this_thread::get_id() ;
            while( true ) { 
                unique_lock<mutex> ul( m );
                if( i>100 ) { cout << "returned from thread is " << this_id << endl; return; }
                c.wait( ul , [&f=f, this](){ return f(this->i); } ) ;
                cout << i << " by thread id " << this_id << endl;;
                i++;
                ul.unlock();
                c.notify_all();
            }
        }
};

int main ( int argc, char* argv[] ) {
    printseq ps;
    auto even = [](const int i) { return  i%2==0; }; 
    auto odd = [](const int i) { return  i%2!=0; }; 
    std::thread t1 ( [&p=ps, f1=std::ref(even)]() { p.start_thread(f1);} );
    std::thread t2 ( [&p=ps, f2=std::ref(odd) ]() { p.start_thread(f2);} );
    std::thread t3 ( [&p=ps, f2=std::ref(even) ]() { p.start_thread(f2);} );

    t1.join();
    t2.join();
    t3.join();
}

