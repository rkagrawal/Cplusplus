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

void getLeaves_ptr( TreeNode** node, vector<int>& res ) {
    if ( (*node)-> left == nullptr && (*node)->right == nullptr ) {
        res.push_back( (*node)->val );
        //cout << "pushing node " << (*node)->val << endl;
        delete *node;
        *node = nullptr;
        return;
    }

    if ( (*node)->left != nullptr )  getLeaves_ptr( &((*node)->left), res ) ;
    if( (*node)->right != nullptr )  getLeaves_ptr( &((*node)->right),res ) ;
    
    //copy( begin( res ), end( res), 
    //                ostream_iterator<int>( cout, "," ));
}


void getLeaves_ref( TreeNode*& node, vector<int>& res ) {
    if ( node-> left == nullptr && node->right == nullptr ) {
        res.push_back( node->val );
        //cout << "pushing node " << node->val << endl;
        delete node;
        node = nullptr;
        return;
    }

    if( node->right != nullptr )  getLeaves_ref( node->right,res ) ;
    if ( node->left != nullptr )  getLeaves_ref( node->left, res ) ;
   /* copy( begin( res ), end( res), 
                    ostream_iterator<int>( cout, "," ));
    */
}

vector<vector<int>> findLeaves(TreeNode *root ) {
    vector<vector<int>> results ;
    while ( root != nullptr ) {
        vector<int> l;
        cout << "Before " << endl;
        printTree( root );
        //getLeaves_ptr( &root, l ); 
        getLeaves_ref( root, l ); 
        cout << "After" << endl;
        printTree( root );
        results.push_back(l);
    }
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
    //vector<vector<int>> leaves_array = findLeaves( nullptr );

    for ( int i=0; i< leaves_array.size();i++ ) {
        cout << "[";
        copy( begin( leaves_array[i] ), end( leaves_array[i] ), 
                    ostream_iterator<int>( cout, "," ));
        cout << "]\n";
    }
}


