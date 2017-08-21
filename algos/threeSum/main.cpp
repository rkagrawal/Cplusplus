class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(begin(nums), end(nums) );
        set<string> foundset;
        int previ=numeric_limits<int>::max();
        int prevj=numeric_limits<int>::max();
        for( int i=0; i< nums.size(); i++ ) {
            if ( previ == nums[i] ) continue;
            previ=nums[i];
            for(int j=i+1; j< nums.size(); j++ ) {
                if ( prevj == nums[j] ) continue;
                
                previ=nums[i] ; prevj=nums[j];
                int lk=-( nums[i] + nums[j]);
                
               
                auto it = lower_bound( nums.begin() + j+1, end(nums), lk );
                if( it != nums.end() && *it == lk) {
                    
                    results.push_back( vector<int>{nums[i], nums[j], lk });
                }    
            }
        } 
        
        return results;
    }
};
