# include <iostream>
# include <string>
# define max 10

using namespace std;

struct DataMusik {
  string judulLagu;
  string penyayi;
  string durasi;
  string studio;
}Musik;

int maksimal[max];
int rear = -1;
int front = -1;

bool isEmpty() {
  if (rear == -1) {
    return true;
  } else {
    return false;
  }
}

bool isFull () {
  if (rear == max-1) {
    return true;
  } else {
    return false;
  }
}

void push () {
  if (isFull()) {
    cout << "Penuh" << endl;
  }else {
    cout << "Judul : "; cin >> Musik.judulLagu;
    cout << "Penyayi : "; cin >> Musik.penyayi;
    cout << "Studio : "; cin >> Musik.studio;
    cout << "Durasi : "; cin >> Musik.durasi;
  }
  
}

void printQueue () {
  if (isEmpty()) {
    cout << "Data Kosong" << endl;
  } else {
    cout<< "Queue" << endl;
    for (int i = 0; i < max; i++) {
      cout << "Judul : " << Musik.judulLagu[i];
      cout << "Penyayi : " << Musik.penyayi[i];
      cout << "Studio : " << Musik.studio[i];
      cout << "Durasi : " << Musik.durasi[i];
    }
  }
}


int main () {
  system("cls");
  int pilihan;

  do {
    cout << "Menu \n";
    cout << "1. push\n";
    cout << "2. dequeue\n";
    cout << "3. pop\n";
    cout << "4. clear\n";
    cout << "5. tampilkan\n";
    cout << "6. keluar\n";
    cout << "Pilihan : ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
      push(); 
      break;
      case 5 :
      printQueue();
      break;
      case 6:
      cout << "Pilihan tidak ada";
      break;
      default: 
      cout << "Pilihan tidak ada!" << endl;
    }
  } while (pilihan != 6);
}