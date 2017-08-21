#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x, ListNode* y) : val(x),next(y) {}
    void link( ListNode* p ) {
            p->next = this;
    }
};

void printList( ListNode* l ) {
    while( l != nullptr ) { 
        cout << l->val << "," ;
        l = l->next;
    }
    cout << endl;
}

void printKList( vector<ListNode*> mylist ) {
    for ( auto head  : mylist ) {
        cout<< "Print list \n";
        printList( head );
    }
}

vector<ListNode*>  buildList() {
    int numList;

    cout << "Enter then number of lists " << endl;
    cin >> numList;
    vector<ListNode*> res(numList, nullptr);;

    while( --numList >= 0 ) {
        int numEntries;
        cout << "Enter the number of entries in list num " << numList << endl;
        cin >> numEntries;
        cout << "Enter the integers in ascending order\n";
        int entry;
        ListNode *h;
        cin >> entry;
        h = new ListNode( entry );
        --numEntries; 
        ListNode *prev = h;
        while ( --numEntries >= 0 ) {
            ListNode* n;
            cin >> entry; 
            n = new ListNode( entry );
            n->link( prev );
            prev = n;
        }
        cout << "pushing to vector entry " << numList << "\n";
        res[numList] = h; 
        printList( res[numList] );
    }
    return res;
}

ListNode* mergeHelper( ListNode* l, ListNode* r ) {
    
    ListNode * h= nullptr;
    ListNode * p = nullptr;
    while( l != nullptr && r != nullptr ) {
       ListNode *a;
       if( l->val < r->val ) {
            a = new ListNode( l->val ); l = l->next;
       } else {
            a = new ListNode( r->val ); r = r->next;
       }
       if ( h == nullptr ) {
            h = a;
            p = a;
       } else {
            a->link(p);
            p = a;
       }
    }
    if ( l == nullptr ) {
        while ( r != nullptr ) { ListNode* a = new ListNode( r->val ); r=r->next; a->link(p ); p = a; }
    } else if( r == nullptr ) {
        while ( l != nullptr ) { ListNode* a = new ListNode( l->val ); l=l->next; a->link(p );  p = a;}
    }

    return h;
}

ListNode* mergeRecurse( vector<ListNode*>& myLists, int l, int h ) {
    if ( l == h ) {
        cout << "l==h:" << l << "=="<<h<< endl;
        return myLists[l];
    }

    int mid = l + (h-l)/2;
    
    cout << "Merging left:"<<l <<",right:"<<h << endl;
    ListNode* ll = mergeRecurse( myLists, l, mid );
    cout << "Merging right:"<<mid+1 <<",right:"<<h << endl;
    ListNode* lr = mergeRecurse( myLists,  mid+1, h );
    ListNode * m =  mergeHelper( ll, lr );
    cout << "Merge list is " << endl;
    printList(m);
    return m;
}

ListNode* mergeKSortedList( vector<ListNode*>& myLists ) {

   return mergeRecurse( myLists, 0, myLists.size()-1 ); 
    
}

int main (int argc, const char* argv[] ) {
    vector<ListNode*> myLists=buildList();;
    cout << "Printing list now \n";
    printKList( myLists );

/*    ListNode *aList = mergeHelper ( myLists[0], myLists[1] );
    cout << "The merged list is " << endl;
    printList( aList );    
*/

    cout << "Now merging the K sorted List \n";
    ListNode* mL =  mergeKSortedList( myLists );
    printList( mL );

}
