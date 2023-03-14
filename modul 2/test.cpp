#include <iostream> // todo : mengatur input dan output
#include <string> // todo : alternatif tipe data selain char

using namespace std; // todo : berguna agar tidak berulang kali membuat namespace di awal
                     // todo : fungsi pustakan yang diambil

struct Musik {
    string judul;
    string penyayi;
    string studio;
    Musik* next;
};

Musik* head = NULL;
Musik* tail = NULL;

void tambahData() {
    system("cls");
    Musik* lagu = new Musik();
    cout << "Masukkan judul lagu: ";
    cin.ignore();
    getline (cin, lagu->judul);
    cout << "Masukkan penyayi: ";
    getline (cin, lagu->penyayi);
    cout << "Masukkan studio: ";
    getline (cin, lagu->studio);
    lagu->next = NULL;
    if (head == NULL) {
        head = tail = lagu;
    }
    else {
        tail->next = lagu;
        tail = lagu;
    }
}

void hapusFifo() {
    system("cls");
    if (head == NULL) {
        cout << "Tidak ada data yang bisa dihapus." << endl;
    }
    else {
        Musik* temp = head;
        head = head->next;
        cout << "Data yang dihapus: " << endl;
        cout << "Judul lagu: " << temp->judul << endl;
        cout << "Penyayi: " << temp->penyayi << endl;
        cout << "Studio: " << temp->studio << endl;
        delete temp;
    }
}

void hapusLifo() {
    system("cls");
    if (head == NULL) {
        cout << "Tidak ada data yang bisa dihapus." << endl;
    }
    else {
        Musik* temp = head;
        Musik* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            head = NULL;
        }
        else {
            prev->next = NULL;
        }
        cout << "Data yang dihapus: " << endl;
        cout << "Judul lagu: " << temp->judul << endl;
        cout << "Penyayi: " << temp->penyayi << endl;
        cout << "Studio: " << temp->studio << endl;
        delete temp;
    }
}

void clear() {
    system("cls");
    while (head != NULL) {
        Musik* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Semua data telah dihapus." << endl;
}

void tampilData() {
    system("cls");
    if (head == NULL) {
        cout << "Tidak ada data yang bisa ditampilkan." << endl;
    }
    else {
        Musik* temp = head;
        while (temp != NULL) {
            cout << "Judul lagu: " << temp->judul << endl;
            cout << "Penyayi: " << temp->penyayi << endl;
            cout << "Studio: " << temp->studio << endl;
            cout << endl;
            temp = temp->next;
            cout << endl;
        }
    }
}

int main() {
    system("cls");
    int pilihan;
    do {
        cout << "======== Menu =======" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data (FIFO)" << endl;
        cout << "3. Hapus Data (LIFO)" << endl;
        cout << "4. Tampil Data" << endl;
        cout << "5. Hapus Semua Data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
          case 1:
          tambahData();
          break;
          case 2:
          hapusFifo();
          break;
          case 3:
          hapusLifo();
          break;
          case 4:
          tampilData();
          break;
          case 5:
          clear();
          break;
          case 6 :
          cout << "Terimakasih telah menggunakan program ini.." << endl;
          break;
          default:
          cout << "Hello Kalian!" << endl;
        }
    } while (pilihan != 6);
}
