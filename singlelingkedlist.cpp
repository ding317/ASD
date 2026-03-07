#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct Node *address;
struct Node {
    infotype data;
    address next;
};

struct List {
    address first;
};

void CreateEmpty(List *L){
    (*L).first = NULL;
}

bool IsEmpty(List L){    
    if(L.first == NULL){
        return true;
    } else {
        return false;
    }
}

void Deallocation(address hapus){
    delete hapus;
}

address Allocation(infotype x){
    address NewElmt;
    // alokasi memory menggunakan "new" agar ruang memory didapat secara permanen
    NewElmt = new Node;

    NewElmt->data = x;
    NewElmt->next = NULL;

    return NewElmt;
}

void InsertFirst(){
     
}

int main(){
    List ll;
    infotype x;

    CreateEmpty(&ll); // ll.first = NULL
    address NewElmnt;
    
    cin >> x; // 7
    NewElmnt = Allocation(x);
    ll.first = NewElmnt;
    
    cin >> x; // 5
    NewElmnt = Allocation(x);
    NewElmnt->next = ll.first; 
    ll.first = NewElmnt;
    
    cin >> x; // 3
    NewElmnt = Allocation(x);
    NewElmnt->next = ll.first;
    ll.first = NewElmnt;
    
    address temp;
    temp = ll.first;
    while(temp != NULL){
        cout << temp->data;
        temp = temp->next;
    }
}