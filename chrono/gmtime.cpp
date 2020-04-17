#include <iomanip>
#include <iostream>
#include <sstream>
#include <chrono>
#include <time.h>

int main() {
   long long milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
   std::cout << "milliseconds since epoch " << milliseconds_since_epoch << std::endl;
   //long long seconds_since_epoch = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
   //time_t seconds_since_epoch = (time_t) std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
   //std::cout << "seconds since epoch " << seconds_since_epoch << std::endl;

   std::cout << "seconds from milli: " << int(milliseconds_since_epoch/1000) << std::endl;
   std::cout << "milli from milli: " << milliseconds_since_epoch % 1000 << std::endl;

   time_t seconds_since_epoch = (time_t) milliseconds_since_epoch / 1000;
   std::cout << "seconds since epoch " << seconds_since_epoch << std::endl;


   struct tm *ptm = gmtime( &seconds_since_epoch );

   std::cout << "yyyy:" << std::setfill('0') << std::setw(4) << ptm->tm_year+1900 << std::endl;
   std::cout << "mm:" << std::setfill('0') << std::setw(2) << ptm->tm_mon +1 << std::endl;
   std::cout << "dd:" << std::setfill('0') << std::setw(2) << ptm->tm_mday << std::endl;
   std::cout << "hh:" << std::setfill('0') << std::setw(2) << ptm->tm_hour << std::endl;
   std::cout << "min:" << std::setfill('0') << std::setw(2) << ptm->tm_min << std::endl;
   std::cout << "sec:" << std::setfill('0') << std::setw(2) << ptm->tm_sec << std::endl;
   std::cout << "msec:" <<  milliseconds_since_epoch % 1000 << std::endl;

   std::stringstream sstr;
   sstr << std::setfill('0') << std::setw(4) << ptm->tm_year+1900
        << std::setfill('0') << std::setw(2) << ptm->tm_mon +1
        << std::setfill('0') << std::setw(2) << ptm->tm_mday << "-"
        << std::setfill('0') << std::setw(2) << ptm->tm_hour << ":"
        << std::setfill('0') << std::setw(2) << ptm->tm_min << ":"
        << std::setfill('0') << std::setw(2) << ptm->tm_sec << "."
        << std::setfill('0') << std::setw(3) << milliseconds_since_epoch % 1000 ;


   std::cout << sstr.str() << std::endl;

}

