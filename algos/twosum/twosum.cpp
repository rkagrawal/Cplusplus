#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>

using namespace std;
auto prt= [] ( const vector<int>& v) { for(auto m: v) cout << m << " " ; cout << endl; };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;;
        for( auto iter = nums.begin(); iter!=nums.end(); iter++ ) {
            int d = target - (*iter);
            auto s = iter;
            auto e = nums.end();

            auto iter2=std::find( iter+1, e, d ) ;
            if( iter2 !=  e ) {
              res.push_back( iter - nums.begin() );
              res.push_back(iter2 - nums.begin() );
              break;
            }
        }
        return res;
    }
};

int main( int argc, char* argv[] ) {
    vector<int> v = { 3,2,4};
    int t = 5;
    Solution mysol;
    auto r = mysol.twoSum(v,t) ;
    prt( r );
}
