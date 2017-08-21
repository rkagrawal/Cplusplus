#include<iostream>

/*definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode( int x ) : val(x), next( nullptr ){}
};

int addOneToNode( ListNode* node ) {
    if( node->next == nullptr ) {
        if ( node->val == 9 ) {
            node->val = 0;
            return 1;
        } else {
            node->val++;
            return 0;
        }
    } else {
        int x = addOneToNode( node->next );
        if( x ) { 
            if ( node->val == 9 ) { 
                    node->val=0;
                    return 1;
            } else {
                    node->val++;
                    return 0;
            }
        } else return 0;
    }
}


ListNode* plusOne(ListNode* head) {
    if ( addOneToNode( head ) ) {
        ListNode * ano = new ListNode( 1 ); ano->next = head;
        head = ano;
    }
    return head;
}

void print( ListNode * root ) {
    while ( root != nullptr ) { cout<< root->val << "->" ; root= root->next; }
    cout << endl;
}

int main( int argc, const char* argv[] ) {

    ListNode * three = new ListNode( 9 );
    ListNode * two = new ListNode( 9 ); two->next = three; 
    ListNode * one = new ListNode( 9 ); one->next = two;
    
    print ( one );
    ListNode *t = plusOne( one );
    print ( t );

    ListNode * three2 = new ListNode( 9 );
    ListNode * two2 = new ListNode( 8 ); two2->next = three2; 
    ListNode * one2 = new ListNode( 9 ); one2->next = two2;
    
    
    print ( one2 );
    ListNode *t2 = plusOne( one2 );
    print ( t2 );
};

