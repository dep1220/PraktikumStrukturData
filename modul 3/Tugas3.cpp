#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next; 
};

Node* head = NULL;

void tambahDepan (int data) {
    Node* newData = new Node;
    newData->data = data;
    newData->prev = NULL;
    newData->next = head;

    if(head != NULL) {
        head->prev = newData;
    }
    head = newData;
}

void tambahBelakang (int data) {
    Node* newData = new Node();

    newData->data = data;
    newData->next = NULL;

    if(head == NULL) {
        newData->prev = NULL;
        head = newData;
        return;
    }

    Node* sm = head;
    while (sm->next != NULL) {
        sm = sm->next;
    }

    sm->next = newData;
    newData->prev = sm;
}

void tampil () {
    if (head == NULL) {
        cout << "Data Kosong" << endl;
    } else {
        Node* sm = head;
        while(sm != NULL) {
            cout << sm->data << endl;
            sm = sm->next;
        }
    }
} 

int main () {
    system("cls");
    // tambahBelakang(12);
    // tambahBelakang(2);
    // tambahBelakang(2);
    tambahDepan(44);
    tambahDepan(7);
    tambahBelakang(2);
    tampil();
    return 0;
}