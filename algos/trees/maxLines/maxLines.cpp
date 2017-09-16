#include<iostream>
#include<stdlib.h>

using namespace std;

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

void maxLines( TreeNode* node, int left, int right, int& maxleftofcenter, int& maxrightofcenter ) {

    if ( node->left == nullptr && node->right == nullptr ) {
        if ( maxleftofcenter < left-right ) maxleftofcenter = left-right;;
        if ( maxrightofcenter > left-right ) maxrightofcenter = left-right;;
        cout << "max left from center : " << maxleftofcenter << " max right from center: " << maxrightofcenter << " at node " << node->val << endl;
    } 

    if ( node->left != nullptr ) maxLines( node->left, left+1, right, maxleftofcenter , maxrightofcenter );
    if ( node->right != nullptr ) maxLines( node->right, left, right+1, maxleftofcenter , maxrightofcenter );
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

    int left = 0;
    int right = 0;
    int maxleftofcenter = 0;
    int maxrightofcenter = 0;
    maxLines( one, left, right, maxleftofcenter , maxrightofcenter );
    cout << "The total number of vertical lines that goes through all nodes with root " << one->val << 
                                                " is " << abs(maxleftofcenter)+abs(maxrightofcenter)+1 << endl;

    maxleftofcenter = 0;
    maxrightofcenter = 0;
    maxLines( four, left, right, maxleftofcenter , maxrightofcenter );
    cout << "The total number of vertical lines that goes through all nodes with root " << four->val << 
                                                " is " << abs(maxleftofcenter)+abs(maxrightofcenter)+1 << endl;
    maxleftofcenter = 0;
    maxrightofcenter = 0;
    maxLines( five, left, right, maxleftofcenter , maxrightofcenter );
    cout << "The total number of vertical lines that goes through all nodes with root " << five->val << 
                                                " is " << abs(maxleftofcenter)+abs(maxrightofcenter)+1 << endl;
    maxleftofcenter = 0;
    maxrightofcenter = 0;
    maxLines( three, left, right, maxleftofcenter , maxrightofcenter );
    cout << "The total number of vertical lines that goes through all nodes with root " << three->val << 
                                                " is " << abs(maxleftofcenter)+abs(maxrightofcenter)+1 << endl;
    maxleftofcenter = 0;
    maxrightofcenter = 0;
    maxLines( two, left, right, maxleftofcenter , maxrightofcenter );
    cout << "The total number of vertical lines that goes through all nodes with root " << two->val << 
                                                " is " << abs(maxleftofcenter)+abs(maxrightofcenter)+1 << endl;

}
