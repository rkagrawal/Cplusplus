#include<iostream>
#include<stdlib.h>

using namespace std;

enum class direction { start, left, right };

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode( int v, TreeNode* l, TreeNode* r ) : val(v), left(l), right(r) {}
};

void printNode( TreeNode* root ) {
    if ( root == nullptr ) return;
    printNode( root->left);
    cout << root->val << endl;
    printNode( root->right);
}

pair<int,int> maxChain( TreeNode* root, direction dir, int& chainLength ) {
    if ( root == nullptr ) return pair<int,int>(0,0);
    
    pair<int,int> lc =   maxChain( root->left, direction::left, chainLength);
    pair<int,int> rc =   maxChain( root->right, direction::right, chainLength);
    

    if ( lc.first + rc.second +1 > chainLength ) {
        chainLength = lc.first + rc.second + 1;
    }

    cout << "For Node " << root->val << " return l chain of " << lc.first << " and rc chain of " << rc.second << endl;
    pair<int,int> retVal;
    if ( dir == direction::left ) retVal.first = lc.first+1;
    if ( dir == direction::right ) retVal.second = rc.second+1;
    return retVal;
}

int main(int argc, const char* argv[] ) {
    

    TreeNode* fourteen = new TreeNode( 14, nullptr, nullptr );
    TreeNode* thirteen = new TreeNode( 13, nullptr, fourteen );
    TreeNode* twelve = new TreeNode( 12, nullptr, thirteen );
    TreeNode* eleven = new TreeNode( 11, nullptr, twelve );
    TreeNode* ten = new TreeNode( 10, nullptr, eleven );

    TreeNode* nine = new TreeNode(9, nullptr, ten);
    TreeNode* eight = new TreeNode(8, nullptr, nullptr);
    TreeNode* five = new TreeNode(5, nullptr, nullptr);
    TreeNode* six = new TreeNode(6, nullptr, nullptr);
    TreeNode* seven = new TreeNode(7, nullptr, nullptr);
    TreeNode* four = new TreeNode(4, eight, nine);
    TreeNode* three = new TreeNode(3, six, seven);
    TreeNode* two = new TreeNode(2, four, five);
    TreeNode* one = new TreeNode(1, two, three);
    

    printNode( one );

    int cl;
    
    cl = 0;
    maxChain( one, direction::start, cl );
    cout << "The max chain length of tree with 1 as root is " << cl << endl << endl;;
   
    cl = 0;
    maxChain( thirteen, direction::start, cl );
    cout << "The max chain length of tree with 13 as root is " << cl << endl << endl;;

    cl = 0;
    maxChain( three, direction::start, cl );
    cout << "The max chain length of tree with 3 as root is " << cl << endl << endl;;

}

