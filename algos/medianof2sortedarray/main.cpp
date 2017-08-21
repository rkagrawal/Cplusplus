#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        int s1,s2;
        if( sz1 % 2 == 0) {
            s1 = (nums1[ sz1/2 - 1 ] +  nums1[ sz1/2 ] ) ;
        } else {
            s1 = nums1[ floor( sz1/2 ) ];
        }

        if( sz2 % 2 == 0) {
            s2 = (nums2[ sz2/2 - 1 ] +  nums2[ sz2/2 ] ) ;
        } else {
            s2 = nums2[ floor( sz2/2 ) ];
        }
        
        double average = (double(s1)+double(s2))/2; 
        return average;
        
    }
};

int main( int argc, char* argv[] ) {
    Solution mysol;
    //vector<int> v1 = { 1,3,6,2,6 };
    //vector<int> v2 = { 9,2,1,8,5,7};
    vector<int> v1={1,3};
    vector<int> v2={2};
    sort(begin(v1), end(v1) );
    sort(begin(v2), end(v2) );
    
    auto prt=[](const vector<int>& v) { for ( auto n: v ) cout<< n << " " ; cout << endl; };
    cout << "The median of sorted arrays is " << mysol.findMedianSortedArrays(v1,v2) << endl;
}
