# include <iostream>

using namespace std;
struct Data {
  string nama;
  Data* next;
  Data* prev;
};

Data* head = NULL;

void masukData (string nama) {
  Data* newData = new Data();

  newData->nama = nama;
  newData->prev = NULL;
  newData->next = head;

  if(head != NULL) {
    head->prev = newData;
  }

  head = newData;
}

void hapus(string key) {
    Data* current = head;

    while (current != NULL && current->nama != key) {
        current = current->next;
    }

    if (current == NULL) {
        cout << "Data tidak ditemukan dalam linked list" << endl;
        return;
    }

    if (current == head) {
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
    }

    delete current;
}

void tampil() {
  Data* curren = head;

  while (curren != NULL) {
    cout << curren->nama << endl;
    curren = curren->next;
  }

}

int main() {
  int pilihan;
  string nama;

  do {
    cout << "1. masukkan data." << endl;
    cout << "2. hapus data." << endl;
    cout << "3. keluar." << endl;
    cout << "4. tampil." << endl;
    cout << "Piliahn : "; cin >> pilihan;
    switch(pilihan) {
      case 1:
        cout << "Masukkan nim : "; cin >> nama;
        masukData(nama);
        break;
      case 2:
        cout << "Masukkan Kata Kunci : " ; cin >> nama;
        hapus(nama);
        break;
      case 3:
        cout << "keluar" << endl;
        break;
      case 4:
        tampil();
        break;
      default:
        cout << "tidakkkk" << endl;
    }
  } while(pilihan != 3);
}