#include <iostream>
#include <assert.h>
#include <date.h>
#include <tz.h>

using namespace std;
using namespace date;
int main( int argc, const char* argv[] ) {
    auto tz = date::current_zone();
    cout << tz->name() << endl;

    tz = date::locate_zone( "Australia/Sydney" );
    cout << tz->name() << endl;

    /*
     * sys_days is alwasy with respect to UTC
     * local_days has no timezone infomation.
     */

    date::local_days ld { feb/28/2016_y }; 
    auto ldWithTime = ld + 7h +36min;
    cout << "date::local_days is " << ld << endl;
    cout << "date::local_days with Time is " << ldWithTime << endl;

    /*
     * make_zoned returns a time point with seconds as the granularith of the duration.
     */
     
    auto zt = date::make_zoned( date::current_zone(), ldWithTime );
    cout << "Zoned Time is " << zt << endl;
    if ( std::is_same <zoned_time<chrono::seconds>, decltype(zt) >::value ) {
        cout << "type of zt is zone_time<chrono::seconds> " << endl;
    } else {
        cout << "type of zt is NOT zone_time<chrono::seconds> " << endl;
    }
    // what is the type of zt


    // now_in_utc below is a time_point -- so it has not get_local_time method.
    auto now_in_utc = chrono::system_clock::now();
    cout << "UTC now is " << format( "%a, %b %d %y at %I:%M %p %Z", now_in_utc) << endl;

    // est_now is a zone_time ( time_point with zone ) .. this will have a get_local_time.
    auto est_now = date::make_zoned( date::current_zone(), now_in_utc );
    cout << "EST now is " << format( "%a, %b %d %y at %I:%M %p %Z", est_now) << endl;


    /*
     * system_clock::now is not a zoned_time object.. so there is no get_local_time defined on it.
     */ 

    //date::local_time<chrono::seconds> lt_from_utc_now = est_now.get_local_time();
    auto lt_from_utc_now = est_now.get_local_time();
    //  No %Z below as local time has no time zone parameter
    cout << "local time from utc now is " << format( "%a, %b %d %y at %I:%M %p", lt_from_utc_now) << endl;
    cout << "local time from est now is " << format( "%a, %b %d %y at %I:%M %p", est_now.get_local_time() ) << endl;

    if( std::is_same< date::local_time<chrono::microseconds>, decltype(lt_from_utc_now) >::value )  {
        cout << "The type returned from get_local_time is local_time<microseconds>\n";
    } else {
        cout << "The type returned from get_local_time is NOT local_time<microseconds>\n";
    }

    return 0;

}
