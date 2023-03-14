#include <iostream>
#include <string>
using namespace std;

struct Data{
  string kelas;
  string nim;
  string angkatan;
  Data* next;
};

Data* head = NULL;
Data* tail = NULL;

void display () {
  Data* node = new Data;
  cout << "Kelas : " ;getline(cin, node->kelas);
  node->next = tail;
  if (head == NULL) {
    head = tail = node;
  } else {
    Data* Saatini = head;
    while(Saatini != NULL) {
      Saatini = Saatini->next;
      Saatini = tail;
    }
  }
}

void printList() {

  if(head == NULL) {
    cout << "Tidak" << endl;
  } else {
    Data* temp = head;
    while(temp != NULL) {
    cout << "Kelas : " << temp->kelas << endl;
    temp = temp->next;
    }
  }
}

int main () {
  system("cls");
  display();
  printList();
}