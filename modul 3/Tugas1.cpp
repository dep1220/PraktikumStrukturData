#include <iostream>
#include <string>
using namespace std;

struct node{
  public:
  string nama;
  string nim;
  node* next;
};

class linkeList {
  private:
  node* head;

  public:
  linkeList() {
    head = NULL;
  }

  void add_node (string nim, string nama) {
    system("cls");
    node* new_node = new node();
    new_node->nama = nim;
    new_node->nim = nama;
    new_node->next = NULL;

    if (head == NULL) {
      head = new_node;
    } else {
      node* current = head;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = new_node;
    }
  }

  void print_node () {
    system("cls");
    node* current = head;
    while(current != NULL) {
      cout << "NAMA: " << current->nim << endl;
      cout << "NIM:  " << current->nama << endl;
      current = current->next;
    }
  }
};

int main () {
  system("cls");
  linkeList myList;
  int pilihan;
  do {
    string nama;
    string nim;
    cout << "==== MENU ===" << endl;
    cout << "1. masukkan data." << endl;
    cout << "2. tampilkan data." << endl;
    cout << "0. keluar." << endl;
    cout << "PIlIHAN <> ";
    cin >> pilihan;
    switch(pilihan) {
      case 1:
      cout << "Nama : "; cin.ignore() ;getline(cin, nama); 
      cout << "NIM : "; cin >> nim;
      myList.add_node(nim,nama);
      break;
      case 2:
      myList.print_node();
      break;
      case 3:
      cout << "anda keluar." << endl;
      default:
      cout << "pilihan salah." << endl;
    }


  }while(pilihan != 0);
  return 0;
}