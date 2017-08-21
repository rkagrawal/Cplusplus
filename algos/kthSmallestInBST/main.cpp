#include<iostream>
#include <vector>
#include <stdlib.h>

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
        printTree( root -> left);
        cout << root->val << endl;
        printTree( root -> right);
    }
}

void  getKthSmallestNode( TreeNode *root, int& k, int& val ) {
    if ( root == nullptr ) return ;

    getKthSmallestNode( root->left, k, val );
    k--;
    //cout << "k is " << k << " cur val is " << root->val << endl;
    if (  k==0 ) { 
        val = root->val;;
        return;
    } else if ( k>0 )  { 
        getKthSmallestNode( root->right, k, val );
    }
}

int main( int argc, const char* argv[] ) {
    
    if( argc != 2 ) {
        cerr << "Usage: enter number to specify the kth smallest in BST\n";
        exit(1);
    }

    int k = atoi( argv[1] );
    
    TreeNode *twentyeight = new TreeNode( 28, nullptr, nullptr );
    TreeNode *twentytwo = new TreeNode( 22, nullptr, nullptr );
    TreeNode *twentyfive = new TreeNode( 25, twentytwo, twentyeight );
    TreeNode *sixteen = new TreeNode( 16, nullptr, nullptr );
    TreeNode *fourteen = new TreeNode( 14, nullptr, nullptr );
    TreeNode *six = new TreeNode( 6, nullptr, nullptr );
    TreeNode *ten = new TreeNode( 10, six, fourteen );
    TreeNode *nineteen = new TreeNode( 19, sixteen, nullptr );
    TreeNode *fifteen = new TreeNode( 15, ten, nineteen );
    TreeNode *twenty = new TreeNode( 20, fifteen, twentyfive );

    printTree( twenty );
    int kthsmallest= -1;
    getKthSmallestNode( twenty, k, kthsmallest );
    cout << "kth smallest is " << kthsmallest << endl;

}


