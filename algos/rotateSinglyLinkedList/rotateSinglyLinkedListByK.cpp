#include<iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node( int v, Node* ptr ) : val(v), next(ptr) {}
};

void printList( Node* head ) {
    while( head != nullptr ) {
        cout << head->val << endl;
        head = head->next;
    }
}

Node* insertList( Node* head, int val ) {
    Node* nptr = new Node( val, nullptr );
    if ( head != nullptr ) {
        nptr->next = head ;
    }
    
    return nptr;
}

Node* getTail( Node* head ) {
    Node *tail = head;
    while( tail->next != nullptr ) tail = tail->next;
    return tail;
}

Node* rotateByK( Node* head, int k ) {
    Node * h = head;
    Node * p = nullptr;
    while( k-- > 0 && h != nullptr )  {
        p = h;
        h = h->next;
    }
    
    if ( p != nullptr ) {  // some rotation occurred 
        Node* tail = getTail( head );
        if ( p == tail ) h = head;
        else { 
            tail -> next =  head;
            p->next = nullptr;
        }
    }

    return h;
}


int main( int argc, const char* argv[] ) {
    if ( argc != 2 ) {
        cerr << "Pls specify how many times to rotate counter clockwise\n";
        exit(1);
    }

    int k = atoi(argv[1] );
    
    Node* head = nullptr;
    head = insertList( head, 60 );
    head = insertList( head, 50 );
    head = insertList( head, 40 );
    head = insertList( head, 30 );
    head = insertList( head, 20 );
    head = insertList( head, 10 );
    printList( head );

    head = rotateByK(head, k );
    cout << "Printing after rotate\n";
    printList( head );
}
