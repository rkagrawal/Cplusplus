
#include <iostream>
using namespace std;
class Solution {
private:
    int dfs(TreeNode* root, vector<vector<int>>& res){
        if(!root) return 0;
        int level = max(dfs(root->left, res), dfs(root->right, res)) + 1;
        if(level > (int)res.size()) res.push_back(vector<int>());
        res[level - 1].push_back(root->val);
        return level;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
};
