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

    vector<string> strvec = { "abc", "efg", "klm" };
    cout << "The size of strvec is " << strvec.size() << endl;

    vector<vector<string>> xyz(4, vector<string>() );
   for( int i=0; i< 4; i++ ) 
	xyz[i].assign( strvec.begin(), strvec.end() );

   
   for( int i=0; i< 4; i++ ) {
	cout << "The size is " << xyz[i].size() << endl;
	for ( int j=0; j<xyz[i].size(); j++ ) 
		cout << "*" <<xyz[i][j] << endl;
   }
}
