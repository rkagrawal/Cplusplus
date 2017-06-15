#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
 
using namespace std;

thread_local unsigned int rage = 1; 
mutex cout_mutex;

void update() {
    rage=10;
}

void increase_rage( const int& thread_name)
{
    ++rage; // modifying outside a lock is okay; this is a thread-local variable
    lock_guard<mutex> lock(cout_mutex);
    cout << "Rage counter for " << thread_name << ": " << rage << '\n';
}

 
int main()
{
    vector<thread> mythreads;
        
    for( int i=0; i<10; i++ ) {
        mythreads.push_back( thread( increase_rage, i ) );
    }

    for_each( begin( mythreads), end(mythreads), std::mem_fn( &thread::join ) );
    cout << "Rage counter for main: " << rage << '\n';

    /*
     * changing rage to 10 does not cause the next set of threads to see the value of 10 from 
     * They are see the value of 1... makes sense as the main thread is also a thread..
     */


    cout << "Changing rage to 10 in main thread " << endl; 
    update();

    vector<thread> mythreads2;
        
    for( int i=0; i<10; i++ ) {
        mythreads2.push_back( thread( increase_rage, i ) );
    }

    for_each( begin( mythreads2), end(mythreads2), std::mem_fn( &thread::join ) );
    cout << "Rage counter for main: " << rage << '\n';
}
