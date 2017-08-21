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


void  getLevelsFromRoot( TreeNode* root, int level, vector<vector<int>>& nodesAtLevel ) {
    if ( root == nullptr ) return;

    if( nodesAtLevel.size() < level ) nodesAtLevel.push_back( vector<int>());
    nodesAtLevel[ level-1 ].push_back( root->val );
    level++; 
    getLevelsFromRoot( root->left, level, nodesAtLevel );
    getLevelsFromRoot( root->right, level, nodesAtLevel );
}


void print( TreeNode* root ) {
    if ( root == nullptr ) 
        return;
    print( root->left);
    cout << root->val << endl;    
    print( root->right);

}

TreeNode * build( const vector<int>& arr, int l, int h ) {
    cout << "l:"<<l<<"h:"<<h<<endl;
    if ( l == h ) {
        return new TreeNode( arr[l], nullptr, nullptr );
    } else if ( l > h ) {
        return nullptr;
    }

    int mid = (h-l)/2;
    cout << "Creating the left subtree with l:"<<l<<"h:"<<l+mid-1<<endl;
    TreeNode* left  = build( arr, l, l+mid-1 );
    cout << "Creating the right subtree with l:"<<l+mid+1<<"h:"<<h<<endl;
    TreeNode* right  = build( arr, l+mid+1, h );
    TreeNode* newNode = new TreeNode( arr[l+mid], left, right );
    cout << "creating a node with val " << arr[l+mid] << endl;
    //cout << "with left " << left->val << " and right as " << right->val << endl;
    return newNode;
}


TreeNode * build2( const vector<int>& arr, int l, int h ) {
    cout << "l:"<<l<<"h:"<<h<<endl;
    if ( l > h ) {
        return nullptr;
    }

    int mid = (h-l)/2;
    cout << "Creating the left subtree with l:"<<l<<"h:"<<l+mid-1<<endl;
    TreeNode* left  = build( arr, l, l+mid-1 );
    cout << "Creating the right subtree with l:"<<l+mid+1<<"h:"<<h<<endl;
    TreeNode* right  = build( arr, l+mid+1, h );
    TreeNode* newNode = new TreeNode( arr[l+mid], left, right );
    cout << "creating a node with val " << arr[l+mid] << endl;
    //cout << "with left " << left->val << " and right as " << right->val << endl;
    return newNode;
}

int main(int argc, const char* argv[] ) {
    
    vector<int> vec = { 9,1,4,6,0,5,2,8,3,7 };
//    vector<int> vec = { 1,2 };
    sort( begin(vec), end(vec));

    TreeNode* root = build2( vec, 0, vec.size() -1 );
    print ( root );

    vector<vector<int>> nodesFromRoot;
    getLevelsFromRoot( root, 1, nodesFromRoot );
    for( int i=0; i < nodesFromRoot.size(); i++ ) {
        cout << "Nodes at the level "<< i << "are: \n";
        for ( auto e : nodesFromRoot[i] )
            cout << e << ",";
        cout << endl;
    }

}


