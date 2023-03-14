#include <iostream>

using namespace std;

struct Node {
  string angkatan;
  string nim;
  string hobi;
  Node* next; 
};


class LinkedList {
  private:
  Node* head;

  public:
  LinkedList() {
    head = NULL;
  }

  void add() {
    Node* nodeBaru = new Node;
    cout << "angkatan : " ; cin.ignore(); getline(cin, nodeBaru->angkatan );
    cout << "nim : "; getline(cin, nodeBaru->nim);
    cout << "hobi : "; getline(cin, nodeBaru->hobi);
    nodeBaru->next = NULL;
    
    if(head == NULL) {
      head = nodeBaru;
    } else {
      Node* current = head;
      while(current->next != NULL){
        current = current->next;
      }
      current->next = nodeBaru;
    }
  }

  void clear() {
    while (head != NULL) {
      Node* temp = head;
      temp = temp->next;
      delete temp;
    }
    cout << "semua terhapus" << endl;
  }

  void printData() {
    system("cls");
    if (this->head == NULL) {
      cout << "data is empty" << endl;
    } else {
      Node* sem = head;
      while(sem != NULL) {
        cout << "\n\nangkatan : " << sem->angkatan << endl;
        cout << "nim : " << sem->nim << endl;
        cout << "hobi : " << sem->hobi << endl << endl;
        sem = sem->next;
      }
    }
  }
};


int main () {
  system("cls");
  int pilihan;
  LinkedList ls;

  do {
    cout << "===============" << endl;
    cout << "1. Tambah data." << endl;
    cout << "2. Hapus" << endl;
    cout << "3. tampilkan data " << endl;
    cout << "0. keluar " << endl;
    cout << "pilihan <> "; cin >> pilihan;

    switch(pilihan) {
      case 1:
      ls.add();
      break;
      case 2:
      ls.clear();
      break;
      case 3:
      ls.printData();
      break;
      case 0:
      cout << "terimakasih telah menggunakan progam kami..." << endl;
      break;
      default:
      cout << "menu tidak ada.." << endl;
    }
  } while (pilihan != 0);
}