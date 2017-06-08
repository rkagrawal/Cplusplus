#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int main(int argc, char* argv[] ) {

    vector<string> strvec = { "Rod Steward",  "Paula Abdul", "Michael Jackson", "Eric Clapton",
                              "Jay Z", "Michale Bolton", "Bruno Mars", "Paula Abdul", 
                              "Rod Steward", "George Michael", "Elton John",  };

    
    sort( begin(strvec), end(strvec) );
    cout << "origina strvec\n";
    copy( begin(strvec), end(strvec), ostream_iterator<string>( cout , "->" ) ); cout << "\n";

    auto p1 = lower_bound( begin(strvec), end(strvec), "Paula Abdul" );
    auto p2 = upper_bound( begin(strvec), end(strvec), "Paula Abdul" );

    rotate( begin( strvec ), p1, end(strvec) );
    cout << "strvec after rotate\n";
    copy( begin(strvec), end(strvec), ostream_iterator<string>( cout , "->" ) ); cout << "\n";

    sort( begin(strvec), end(strvec) );

    auto p3=find( begin(strvec), end(strvec), "Bruno Mars" );
    auto p4=find( begin(strvec), end(strvec), "Elton John" );
    
    cout << "\noriginal strvec\n";
    copy( begin(strvec), end(strvec), ostream_iterator<string>( cout , "->" ) ); cout << "\n";
    cout<< "p3 " << *p3 << endl;
    cout<< "p4 " << *p4 << endl;
    rotate( p3, p4, p4+1 );
    copy( begin(strvec), end(strvec), ostream_iterator<string>( cout , "->" ) ); cout << "\n";

}
