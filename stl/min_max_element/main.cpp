//
//  main.cpp
//  min_max_element
//
//  Created by Rajesh Agrawal on 6/18/16.
//  Copyright © 2016 Rajesh Agrawal. All rights reserved.
//

#include <iostream>
#include <list>
#include <algorithm>



class record {
public:
    record( const std::string& n, const std::string& d, float g, float m):name(n),date(d),gallons(g), miles(m){}
    std::string name;
    std::string date;
    float gallons;
    float miles;
    
    void print() {
        std::cout << name << " " << date << " " << gallons << " " << miles << std::endl;
    }
};

namespace std {
    template<> struct less<record> {
        bool operator() (const record& r1, const record& r2) {
            return r1.date < r2.date;
        }
    };
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::list<record> recordlist;
    
    record r1("R", "2016/01/02", 2, 3);
    record r2("R", "2016/01/01", 2, 3);
    
    record r3("S", "2016/01/03", 2, 3);
    record r4("S", "2016/01/01", 2, 3);
    record r5("S", "2017/01/01", 4, 5);
    
    
    recordlist.push_back(r1);
    recordlist.push_back(r2);
    recordlist.push_back(r3);
    recordlist.push_back(r4);
    recordlist.push_back(r5);

    std::cout << "recordlist after  after creation -- print using lambda\n";
    for_each( recordlist.begin(), recordlist.end(), []( record& a) { a.print(); } );

    
    auto p = std::min_element( recordlist.begin(), recordlist.end(), std::less<record>() );
    std::cout << "The min element is "; p->print() ; std::cout << std::endl;
    
    
    auto p2 = std::max_element( recordlist.begin(), recordlist.end(), std::less<record>() );
    std::cout << "The max element is "; p2->print() ; std::cout << std::endl;
    
    // unique behaves like remove.. it returns the logical end.. so we need to erase
    auto last = std::unique(recordlist.begin(), recordlist.end(), std::less<record>()); 
    recordlist.erase( last, recordlist.end());

    std::cout << "recordlist after unique call is -- print using lambda\n";
    for_each( recordlist.begin(), recordlist.end(), []( record& a) { a.print(); } );
    
    std::cout << "print using bind\n";
    for_each( recordlist.begin(), recordlist.end(), std::bind( &record::print, std::placeholders::_1) );

    std::cout << "print using lambda\n";
    for_each( recordlist.begin(), recordlist.end(), []( record& a) { a.print(); } );
    
}
