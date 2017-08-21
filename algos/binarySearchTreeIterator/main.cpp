/* Definition for binary tree
 */
#include <iostream>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class BSTIterator {
private:
   TreeNode *currNode; 
   TreeNode *parent = {nullptr};
   list<int> nextValList; 
   list<int>::const_iterator liter;

   void nextSmallestNumber( TreeNode * root ) {
        
        if( root != nullptr )  {
            nextSmallestNumber( root->right);
            nextValList.insert( nextValList.end(), root->val );
            nextSmallestNumber( root->left);
        }
   }

public:
    BSTIterator(TreeNode *root) {
        if ( root != nullptr ) {
            nextSmallestNumber( root->left );
            nextValList.insert( nextValList.begin(), root->val );
            liter = nextValList.begin();
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return liter != nextValList.end();
    }

    /** @return the next smallest number */
    int next() {
        int retval = *liter; 
        liter++;
        return retval;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

void printTree_InOrder( TreeNode * root ) {
   if ( root != nullptr ) {
        cout << root->val << endl; 
        printTree_InOrder( root->left );
        printTree_InOrder( root->right );
    }
}

void printTree_PreOrder( TreeNode * root ) {
   if ( root != nullptr ) {
        printTree_PreOrder( root->left );
        cout << root->val << endl; 
        printTree_PreOrder( root->right );
    }
}

void printTree_PostOrder( TreeNode * root ) {
   if ( root != nullptr ) {
        printTree_PostOrder( root->left );
        printTree_PostOrder( root->right );
        cout << root->val << endl; 
    }
}

int main( int argc, char * argv[] ) {
    TreeNode *twelve = new TreeNode( 12 );    
    TreeNode *four = new TreeNode( 4 );    
    TreeNode *three = new TreeNode( 3, nullptr, four );    
    TreeNode *seven = new TreeNode( 7 );    
    TreeNode *five = new TreeNode( 5,three,seven );    
    TreeNode *ten = new TreeNode( 10, five, twelve );    

    cout << "\nInOrderTraversal\n";
    printTree_InOrder(ten);
    cout << "\nPreOrderTraversal\n";
    printTree_PreOrder(ten);
    cout << "\nPostOrderTraversal\n";
    printTree_PostOrder(ten);
    cout << "--------------\n";
    BSTIterator bstIter( ten );
    while ( bstIter.hasNext() ) cout << bstIter.next() <<endl;;
}
