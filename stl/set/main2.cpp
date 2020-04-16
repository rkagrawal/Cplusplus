#include<set>
#include<iostream>
#include<string>
#include<boost/algorithm/string/case_conv.hpp>
#include<iterator>
#include<algorithm>


struct icompare {
    bool operator() ( const std::string& s1, const std::string& s2 ) {
        return  boost::to_lower_copy(s1) <  boost::to_lower_copy(s2) ;
    }
};


int main() {
#if 0
    std::set<std::string> abc;

    abc.insert( boost::to_lower_copy( std::string("fake")  ));
    abc.insert( boost::to_lower_copy( std::string("SysOPT") ) );

    std::copy( begin(abc), end(abc), std::ostream_iterator<std::string>( std::cout, " " ) );
    std::cout << std::endl;
#endif

    std::set<std::string, icompare > myset;

    myset.insert( "SysOpt" ); myset.insert("faKe" );
    std::copy( begin(myset), end(myset), std::ostream_iterator<std::string>( std::cout, " " ) );
    std::cout << std::endl;

    std::cout << "---- FIND sysopt ---------" << std::endl;

    if ( myset.find( "SYSOPT" ) != myset.end() ) {
         std::cout << "SYSOPT is present" << std::endl;
    }

    std::cout << "---- FIND fake ---------" << std::endl;

    if ( myset.find( "FAKE" ) != myset.end() ) {
         std::cout << "FAKE is present" << std::endl;
    }
}

