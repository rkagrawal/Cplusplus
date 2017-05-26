#include <iostream>
#include "date.h"

using namespace std;
using namespace date;
int main( int argc, const char* argv[] ) {

    //date::year_month_day ymd = 2017_y/may/25;
    auto ymd = 2017_y/may/25;
    cout << ymd << endl; 
    cout << "Next month " << ymd + months {1} << endl;
    auto dp = sys_days{ymd};   // day_point has changed to sys_days
    cout << "dp is " << dp << endl;
    cout << "the sys date is " << dp.time_since_epoch().count() << endl;

    auto today = floor<days>( chrono::system_clock::now() ); // it is in UTC 
    cout << "Today is " << today <<  endl;
    
}
