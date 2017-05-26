#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <thread>

using namespace std;

int main( int argc, const char* argv[] ) {

    chrono::seconds x = 75s;
    chrono::minutes y = 98min;;
    chrono::hours h = 14h;

    /* 
     *  Duration has a represenation and a ratio
     */

    chrono::duration<float, std::ratio<3600>> dh = h+y+x;
    cout << dh.count() << " hours" << endl;

    chrono::duration<uint64_t, std::ratio<1,1000000>> ms = h+y+x;
    cout << ms.count() <<  " microseconds " << endl;

    chrono::duration<float, std::ratio<24*60*60>> dd = h+y+x;
    cout << dd.count() <<  " days " << endl;

    chrono::milliseconds milli = chrono::duration_cast<chrono::milliseconds>( dd );
    cout << milli.count() <<  " milliseconds" << endl;

    
    /*
     *  chrono::time_point has a clock and a duration  ( system_clock or steady_clock
     *  use steady_clock as a timer and system_clock as a wall clock
     */
    chrono::time_point<chrono::system_clock, chrono::seconds > tp { 5s };
    

    /*
     *  every timepoint is asociated with a clock.. a clock sturcture has timepoint.
     */

    chrono::system_clock::time_point sctp1 = chrono::system_clock::now();
    std::this_thread::sleep_for( 1s );
    chrono::system_clock::time_point sctp2 = chrono::system_clock::now();

    /* time points have a duration underneath.. we can find out , but we can do 
     * a cast to other duration types if necessary as done below
     */
    cout << " difference in nanosec " << chrono::nanoseconds{ sctp2-sctp1}.count() << endl;
    cout << " difference in sec " << chrono::duration_cast<chrono::seconds>( sctp2-sctp1).count() 
         << endl;

    auto tp2 = chrono::time_point_cast<chrono::seconds>( chrono::system_clock::now() );
    cout << "time in seconds since epoch is " 
        << tp2.time_since_epoch().count() << endl;;

    using days = chrono::duration<int, ratio_multiply< ratio<24>, chrono::hours::period>>;
    auto tp3 = chrono::time_point_cast<days>( chrono::system_clock::now() );
    cout << "time in days since epoch is " 
        << tp3.time_since_epoch().count() << endl;;

    return 0;
}
