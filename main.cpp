#include <iostream>
#include <limits>

using namespace std;
struct Node {
    int data;
    Node* next;
};

struct List {
    Node* first;
};

void createempty(List* L) {
    L->first = nullptr;
}
Node* Allocation(int x) {
    Node*NewElmnt=new Node;
    NewElmnt ->data = x;
    NewElmnt ->next = nullptr;
    return NewElmnt;
}
void deletelist(List* L) {
    Node* temp = L->first;
    while (temp != nullptr)
    {
        Node* next = temp->next;
        delete temp; // bebaskan memori
        temp = next;
    }
    L->first = nullptr;
}

void insertfirst(int x, List *L) {
    Node*NewElmnt=Allocation(x);
    NewElmnt->next = L->first;
    L->first = NewElmnt;
}
void insertlast(int x, List *L) {
    Node*NewElmnt=Allocation(x);
    if (L->first ==nullptr
        )
    {
        L->first = NewElmnt;
    }else
    {
        Node*temp = L->first;
        while (temp->next != nullptr)
        {
            temp = temp -> next;
        }
        temp -> next = NewElmnt;
    }
}
void printlist(const List *L)
{
    Node* temp = L->first;
    while(temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << ", ";
        }else
        {
            cout << "  " ;
        }
        temp = temp->next;
    }
}
void insertafter(int cari, int x,const List *L)
{
    Node* temp = L->first;

    // cari node yang datanya = cari
    while (temp != nullptr && temp->data != cari)
    {
        temp = temp->next;
    }

    if (temp == nullptr
        )
    {
        cout << "Data " << cari << " tidak ditemukan!" << endl;
        return;
    }

    Node* NewElmnt = Allocation(x);
    NewElmnt->next = temp->next; // sambung ke node setelahnya
    temp->next = NewElmnt;       // sambung node cari ke node baru
}
void insertbefore(const int cari, const int x, const List *L)
{
    Node*temp = L->first;
    // cari node yang datanya = cari
    while (temp !=nullptr && temp->data == cari)
    {
        temp = temp ->next;
    }
    if (temp == nullptr)
    {
        cout << "Data"<<cari<<" tidak ditemukan!" << endl;
        return;
    }
    Node*NewElmnt = Allocation(x);
    NewElmnt->next = temp->next;
    temp->next = NewElmnt;
}

int main()
{
    List L{};
    int x;
    cout <<"Masukkan data: ";
    createempty(&L);
    for (int i = 0; i < 5; i++){
        while (!(cin >> x)) {
            cout << "Input tidak valid, masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        insertlast(x,&L);
    }
    insertfirst(10, &L);
    insertafter(2,5,&L);
    printlist(&L);
    deletelist(&L);
    return 0;
}