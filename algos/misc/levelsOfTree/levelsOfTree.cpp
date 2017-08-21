#include<iostream>
#include<vector>

using namespace std;
struct TreeNode  {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode( int x ): val(x), left(nullptr),right(nullptr) {}
    TreeNode( int x, TreeNode* l, TreeNode* r ) : val(x), left(l), right(r) {}
};


void print( TreeNode* root ) {
    if ( root == nullptr ) 
        return;
    print( root->left);
    cout << root->val << endl;    
    print( root->right);

}

int getLevelsFromLeaves( TreeNode* root, vector<vector<int>>& nodesAtLevel ) {
    if ( root == nullptr ) 
        return 0;

    int levelleft = getLevelsFromLeaves( root->left, nodesAtLevel );
    int levelright = getLevelsFromLeaves( root->right, nodesAtLevel );

    int l = max( levelleft, levelright ) + 1;
    cout << "level " << l << " for node " << root->val << endl;
    if ( nodesAtLevel.size() < l ) nodesAtLevel.push_back( vector<int>() );
    nodesAtLevel[l-1].push_back( root->val );
    
    return max( levelleft, levelright) + 1;
}

void  getLevelsFromRoot( TreeNode* root, int level, vector<vector<int>>& nodesAtLevel ) {
    if ( root == nullptr ) return;

    if( nodesAtLevel.size() < level ) nodesAtLevel.push_back( vector<int>());
    nodesAtLevel[ level-1 ].push_back( root->val );
    level++;
    getLevelsFromRoot( root->left, level, nodesAtLevel );
    getLevelsFromRoot( root->right, level, nodesAtLevel );
}

int main(int argc, const char* argv[] ) {
    
    TreeNode *sixteen = new TreeNode( 16, nullptr, nullptr );
    TreeNode *twelve = new TreeNode( 12, nullptr, nullptr );
    TreeNode *fourteen = new TreeNode( 14, twelve, sixteen );
    TreeNode *six = new TreeNode( 6, nullptr, nullptr );
    TreeNode *eleven = new TreeNode( 11, six, fourteen );
    TreeNode *five = new TreeNode( 5, nullptr, nullptr );
    TreeNode *ten = new TreeNode( 10, five, eleven );

    print( ten );
    vector<vector<int>> nodesAtLevel;
    getLevelsFromLeaves( ten, nodesAtLevel ) ;
    for( int i=0; i < nodesAtLevel.size(); i++ ) {
        cout << "Nodes at the level "<< i << "are: \n";
        for ( auto e : nodesAtLevel[i] )
            cout << e << ",";
        cout << endl;
    }

    vector<vector<int>> nodesFromRoot;
    getLevelsFromRoot( ten, 1, nodesFromRoot );
    for( int i=0; i < nodesFromRoot.size(); i++ ) {
        cout << "Nodes at the level "<< i << "are: \n";
        for ( auto e : nodesFromRoot[i] )
            cout << e << ",";
        cout << endl;
    }
}
