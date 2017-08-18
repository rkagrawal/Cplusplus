#include<iostream>
#include<map>
#include<vector>

using namespace std;

struct info {
    int i;  
    int count;
    info( int x ): i(x),count(0) {}
};

auto prt = [] (const info& inf ) { cout << inf.i << "|" << inf.count << endl; };
auto prtmap = [] (const pair<int,info>& p ) { cout << p.first << "|" << p.second.count << endl; };

int main(int argc, const char* argv[] ) {
    
    vector<info> vec = { info(1),info(2),info(2),info(3),info(4),info(2),info(4),info(3),info(6)};
    cout << "Printing the vector... \n";
    for_each( begin(vec), end(vec), prt);
    cout << endl;

    map<int,reference_wrapper<info>> m;
    for( auto& e: vec ) {
        if( m.find( e.i ) == m.end() ) m.insert( make_pair ( e.i, std::ref(e) ));

        reference_wrapper<info>& infref = m.at(e.i);
        infref.get().count++;
    }

    cout << "Printing the map... \n";
    for_each( begin(m), end(m), prtmap );
    cout << endl;
    cout << "Printing the vector again... \n";
    for_each( begin(vec), end(vec), prt);
    
    // try remove_if on the vec and get rid of 0 count
    vec.erase(remove_if( begin(vec),end(vec), [](const info& inf) { return inf.count==0; } ),
                vec.end() );
    cout << endl;
    cout << "Printing the vector again...with dup removed \n";
    for_each( begin(vec), end(vec), prt);
    cout << endl;
}
