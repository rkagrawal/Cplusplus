#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<utility>

using namespace std;

using mypair = pair<int,int>;

auto prt = [] (const vector<mypair>& v ) { 
    for( auto p: v ) {
        cout << "["<<p.first<<","<<p.second<<"]" << " ";
    }
    cout << endl;
};


class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       auto cmp = [] ( const mypair& p1, const mypair& p2) { 
                        return (p1.first+p1.second > p2.first+p2.second);}; 
        

       priority_queue<mypair, vector<mypair>, decltype( cmp )> pq(cmp);
       vector<mypair> res;
       for( auto i: nums1 ) {
            for( auto j: nums2 ) {
                pq.emplace( i,j );
            }
       }
       
       for (int i=0; i<k && !pq.empty(); i++) { res.push_back( pq.top() ); pq.pop(); }
       return res; 
    }
};

int main( int argc, char* argv[] ) {
    Solution mysol;
    vector<int> v1 = { 3,5,1};
    vector<int> v2 = { 9,2,7};
    vector<pair<int,int>> r = mysol.kSmallestPairs( v1, v2, 100 );
    prt( r );    
}
