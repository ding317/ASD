#include <iostream>
#include <stdlib.h>
using namespace std;

typedef float infotype;
struct node {
    infotype data;
    node* next;
};

struct List {
    node* first;
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

void Deallocation(node* hapus){
    delete hapus;
}

node* Allocation(infotype x){
    node* NewElmt;
    // alokasi memory menggunakan "new" agar ruang memory didapat secara permanen
    NewElmt = new node;
    cout << "Alamat NewElmt: " << NewElmt << endl;
    NewElmt->data = x;
    NewElmt->next = NULL;

    return NewElmt;
}

void InsertFirst(List *L, infotype  x){
    node* NewElmt;
    NewElmt = Allocation(x);
    NewElmt->next = L->first;
    L->first = NewElmt;
}

int main(){
    List ll;
    infotype x;

    CreateEmpty(&ll); // ll.first = NULL
    node* NewElmnt;

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

    node* temp;
    temp = ll.first;
    while(temp != NULL){
        cout << temp->data;
        temp = temp->next;
    }
}