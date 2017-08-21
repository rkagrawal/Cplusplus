#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

class SumRanges {
    private:
        vector<pair<int,int>> intVec;

    public:
        SumRanges() {}
        void addNum(int i ) {
            auto cmp = [] (const pair<int,int>& p1, const pair<int,int>& p2 ) {
                return p1.first < p2.first ;
            };

            auto it = lower_bound( begin( intVec), end(intVec), make_pair(i, i ), cmp );

            if( it == end(intVec ) ) {
                if( it == begin(intVec) ) 
                    intVec.insert(it, make_pair(i,i) );
                else {
                    auto pit = it - 1;   
                    if ( pit->second + 1 == i ) {
                        pit->second++;
                    } else if ( pit->second +1 < i ) {
                        intVec.insert(it,make_pair(i,i) );
                    } 
                }
            } else if( it == begin(intVec ) ) {
                if( i+1 == it->first ) {
                   int e = it->second;
                   it = intVec.erase(it ); 
                   intVec.insert( it, make_pair( i,e ) );
                } else {
                   intVec.insert( it, make_pair( i, i ) );
                }
            } else {
                cout<< "it is here \n";
                auto pit = it - 1;
                if ( pit->second + 1 == i && it->first == i + 1 )  {
                        int nb = pit->first;
                        cout << " It is here nb is " << nb << "\n";
                        it = intVec.erase(  pit );
                        it->first = nb ;
                } else if ( pit->second +1 == i ) {
                        pit->second++; 
                } else if ( it->first == i + 1 ) {
                    it->first--;
                } else {
                    intVec.insert(it, make_pair(i,i ) );
                }                
            }
        }

        void print() {
            for ( auto p : intVec ) 
                cout << "["<<p.first<<","<<p.second<<"],";
            cout << endl;
        }
};

int main(int argc, char* argv[] ) {

    SumRanges sr;
    int i;
    while( cin>>i ) {
        sr.addNum(i);    
        sr.print();
    };
    
}
