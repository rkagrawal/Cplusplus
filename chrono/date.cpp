#include <iostream>
#include "date.h"

using namespace std;
using namespace date;
int main( int argc, const char* argv[] ) {

    /*
     * sys_days is day_point ( renamed by Howard Hinnat sometime back 
     */

    //date::year_month_day ymd = 2017_y/may/25;
    auto ymd = 2017_y/may/25;
    cout << ymd << endl; 
    cout << "Next month " << ymd + months {1} << endl;
    auto dp = sys_days{ymd};   // day_point has changed to sys_days
    cout << "dp is " << dp << endl;
    cout << "the sys days from epoch s " << dp.time_since_epoch().count() << endl;

    /*
     *  days is a another duration as defined in chrono using the alias
     *  using days = chrono::duration<int, ratio_multiply< ratio<24>, chrono::hours::period>>;
     *
     *  Below you will be surprised as today is sys_days , but prints a date.
     *  The date library by Howard Hinnat has an overloaded << operator that takes sys_days
     *  and prints year_month_day by converting the sys_dates to ymd.
     *  Look at date.h
     */

    auto today = floor<days>( chrono::system_clock::now() ); // it is in UTC 
    cout << "Today ( is timepoint from sys_clock::now _)  " << today <<  endl;

    using mydays = chrono::duration<int, ratio_multiply< ratio<24> , chrono::hours::period>>;

    auto mytoday = floor<chrono::seconds>( chrono::system_clock::now() );
    cout << "MyToday ( is timepoint from sys_clock::now)" << mytoday <<  endl;

    // mydays is duration...
    mydays xyz {56};
    cout << "xyz ( is duration in days ) " << xyz << endl; 

    // sys_date ( called day_point before ) has the date and the first second of the day.

    auto sd = sys_days{ 2017_y/apr/26 } ;
    cout << "sd is " << sd << endl;
    if ( std::is_same<sys_days, decltype(sd)>::value ) {
        cout << "sd is same as sys_days " << endl;
    } else {
        cout << "sd is NOT same as sys_days " << endl;
    }

    /* 
     * when time is added to sys_date, a time point is created that has the most granular duration 
     * of the time.. So if you add 7h + 45 min, to sd ( created from ymd ) it returns a time point 
     * with duration of min.  If you add seconds to that, it returns a timepoint with the duration of 
     * seconds.. The below tests prove this
     */
  
    /* for some reason, sys_minutes is not defined in date.h */
    using sys_minutes = chrono::time_point<chrono::system_clock, chrono::minutes >;
    auto tpWithMin = sd + 7h + 45min;
    cout << "tpWithMin is after adding hours and min " << tpWithMin << endl;
    if ( std::is_same<sys_minutes, decltype(tpWithMin)>::value ) {
        cout << "tpWithMin is same as sys_minutes" << endl;
    } else {
        cout << "tpWithmin is NOT same as sys_minutes " << endl;
    }

    auto tpWithSec = sd + 7h + 45min + 5s;
    cout << "tpWithSec is after adding 5 seconds " << tpWithSec << endl;
    if ( std::is_same<sys_seconds, decltype(tpWithSec)>::value ) {
        cout << "tpWithSec is same as sys_seconds" << endl;
    } else {
        cout << "tp2 is NOT same as sys_seconds" << endl;
    }

    cout << "the time duration since mid night is in seconds:" << (tpWithSec - sd).count() << " secs\n"; 
    cout << "the time duration since mid night is in Min:" << (tpWithMin - sd).count() << " mins\n";

    // make time utility.

    auto time_from_seconds = make_time( 2000s );
    cout << "time of day from time specified in seconds " << time_from_seconds << endl;
    auto time_from_min = make_time( 24*60min + 5min); // 
    cout << "time of day from time specified in minutes " << time_from_min << endl;
}

