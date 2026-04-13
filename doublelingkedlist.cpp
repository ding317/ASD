#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct List {
    Node* first;
    Node* last;
};

// Node*(P)->data
// Node*(P)->prev
// Node*(P)->next
// Node*L->first
// Node*L->last

bool IsEmpty(List L){
    return L.first == NULL && L.last == NULL;
}

void CreateEmpty(List *L){
    (*L).first = NULL;
    (*L).last  = NULL;
} 
void Deallocation(address hhh){
    delete hhh;
}

address Allocation(infotype x){
    address NewElmt;
    NewElmt = new Node;
    
    NewElmt->data = x;
    NewElmt->next = NULL;
	NewElmt->prev = NULL;
    
    return NewElmt;
}
void InsertFirst(List *L, infotype x){
    address NewElmnt = Allocation(x);
    // insert ketika List kosong
    if(IsEmpty(*L)){
        (*L).first = NewElmnt;
        (*L).last  = NewElmnt;
        
    // insert ketika List tidak kosong
    } else {
        NewElmnt->next = (*L).first;
        ((*L).first)->prev = NewElmnt;
        (*L).first = NewElmnt;
    }
}

void InsertLast(List *L, infotype x){
    address NewElmnt = Allocation(x);
    
    NewElmnt->prev = (*L).last;
    ((*L).last)->next = NewElmnt;
    (*L).last = NewElmnt;
}

void InsertAfter(List L, infotype x, address temp){
    address NewElmnt = Allocation(x);
    NewElmnt->next = temp->next;
    NewElmnt->prev = temp;
    
    (temp->next)->prev = NewElmnt;
    temp->next = NewElmnt;
}

void DeleteFirst(List *L){
    address temp = (*L).first;
    (*L).first = temp->next;
    (*L).first->prev = NULL;
    temp->next = NULL;
    Deallocation(temp);
}

void DeleteLast(List *L){
    address temp = (*L).last;
    (*L).last = temp->prev;
    ((*L).last)->next = NULL;
    temp->prev = NULL;
    Deallocation(temp);
}

int main(){
    List ll;
    infotype x;
    
    CreateEmpty(&ll); // ll.first = NULL , ll.last = NULL
    
    // Insert First
    cin >> x; // 7
    InsertFirst(&ll, x);
    
    // Insert First
    cin >> x; // 4
    InsertFirst(&ll, x);
    
    // Insert Last
    cin >> x; // 9
    InsertLast(&ll, x);
    
    // posisikan temp
    address temp = ll.first;
    while (temp->data != 4) {
        temp = temp->next;
    }
    // Insert After
    cin >> x; // 5
    InsertAfter(ll, x, temp);
    
    // Delete First
    DeleteFirst(&ll);
    
    // Delete Last
    DeleteLast(&ll);
}