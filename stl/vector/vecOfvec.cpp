#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct MyStruct {
    string key;
    vector< vector<double> > vv{9, vector<double>(3) };
};

int main( int argc, const char* argv[] ) {
    vector<vector<string>> vs(9, vector<string>(3) );
    MyStruct ms;
    ms.vv[0][0] = -0.789;
    vs[8][2] = "Rajesh";
    cout << ms.vv[0][0] << endl;
    cout << vs[8][2] << endl;
}
