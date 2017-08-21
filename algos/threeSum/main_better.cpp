class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n  = nums.size();
        if(n<3) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int begin = i+1;
            int end = n-1;
            int target = -nums[i];
            while(begin<end){
                if(nums[begin]+nums[end]==target){
                    res.push_back(vector<int>{nums[i],nums[begin],nums[end]});
                    begin++;
                    end--;
                    while(begin < end && nums[begin]==nums[begin-1]) begin++;
                    while(begin < end && nums[end]==nums[end+1]) end--;
                }
                else if(nums[begin]+nums[end] > target){
                    end--;
                }else{
                    begin++;
                }
            }
        }
        return res;
    }
};
