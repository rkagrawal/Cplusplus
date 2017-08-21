#include<iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;    
    TreeNode* left;
    TreeNode* right;
    TreeNode( int x, TreeNode* l, TreeNode* r ): val(x), left(l), right(r) {}
};

void printTree( TreeNode* root ) {
    if ( root == nullptr ) return;
    else {
        cout << root->val << endl;
        printTree( root -> left);
        printTree( root -> right);
    }
}

int dfs(TreeNode* root, vector<vector<int>>& res){
    if(!root) return 0;
        cout << "going the left subtree for node " << root->val << endl;
        int l1 = dfs( root->left, res );
        cout << "dfs left level with node val  " << root->val << ":" << l1 << endl;
        cout << "going the right subtree for node " << root->val << endl;
        int l2 = dfs( root->right, res );
        cout << "dfs right level with node val  " << root->val << ":" << l2 << endl;
        int level = max( l1, l2) + 1;
       
        //int level = max(dfs(root->left, res), dfs(root->right, res)) + 1;
        if(level > (int)res.size()) res.push_back(vector<int>());
        //cout << "Saving " << root->val << " to level " << level << endl;
        res[level - 1].push_back(root->val);
        //cout << "The level is " << level << endl;
        return level;
}

vector<vector<int>> findLeaves(TreeNode *root ) {
    vector<vector<int>> results ;
    dfs( root, results );
    return results;
}


int main( int argc, const char* argv[] ) {
    
    TreeNode *four = new TreeNode( 4, nullptr, nullptr );
    TreeNode *five = new TreeNode( 5, nullptr, nullptr );
    TreeNode *six = new TreeNode( 6, nullptr, nullptr );
    TreeNode *three = new TreeNode( 3, six, nullptr );
    TreeNode *two = new TreeNode( 2,  four, five );
//    TreeNode *two = new TreeNode( 2,  nullptr, nullptr );
    TreeNode *one = new TreeNode( 1,  two, three );

    printTree( one );
    vector<vector<int>> leaves_array = findLeaves( one );

    for ( int i=0; i< leaves_array.size();i++ ) {
        cout << "[";
        copy( begin( leaves_array[i] ), end( leaves_array[i] ), 
                    ostream_iterator<int>( cout, "," ));
        cout << "]\n";
    }
}


