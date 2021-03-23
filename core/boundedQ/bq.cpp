
#include "bq.h"

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
        std::cerr << "usage : main.out <# produce threads> <# consumer threads> " << std::endl;
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
