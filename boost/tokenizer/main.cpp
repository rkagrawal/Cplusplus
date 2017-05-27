#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;
int main(int argc, char *argv[] ) {
    if( argc != 2 ) {
        cerr << "Usage: main.out <filename>\n";
        exit(1);
    }

    fstream inp( argv[1], ios::in );

    string line;
    boost::char_separator<char> sep( "|" );
    using tokenizer = boost::tokenizer< boost::char_separator<char>> ;
    while( getline( inp, line)  ) {

        tokenizer tok( line, sep );
        using token_iterator = boost::tokenizer< boost::char_separator<char>>::iterator;
        for( token_iterator iter=tok.begin(); iter != tok.end(); iter++ ) 
            cout << *iter << endl;
    }
}

