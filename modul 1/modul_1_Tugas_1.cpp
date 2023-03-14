# include <iostream> // todo :  mengatur output dan input
# include <string> // todo  : alternatif tipe data selain char

using namespace std; 
// todo : bergunan agar tidak berulang kali membuat namespace di awal
// todo : fungsi pustaka yang diambil

struct Mahasiswa {
  string nama;
  string nim;
  string angkatan;
};

void masukkanData (Mahasiswa mhs[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "Masukkan Data Mahasiswa ke-" << i+1 << ": " << endl;
    cout << "NIM      : " ; getline (cin, mhs[i].nim);
    cout << "NAMA     : "; getline (cin, mhs[i].nama);
    cout << "ANGKATAN : "; getline (cin, mhs[i].angkatan);
  }
};

void tampilkanData (Mahasiswa mhs[], int n) {
  system("cls");
  cout << "\n Data mahasiswa : " << endl;
  for (int i = 0; i < n; i++) {
    cout << "Mahasiswa ke-" << i+1 << ":" << endl;
    cout << "NIM : " << mhs[i].nim << endl;
    cout << "NAMA : " << mhs[i].nama << endl;
    cout << "ANGKATAN : " << mhs[i].angkatan << endl;
  }
}


int main () {
  system("cls");
  int jumlah, pilihan;

  cout << "Masukkan jumlah data : ";cin >> jumlah;

  Mahasiswa Mhs[jumlah]; // todo : Array of Struct jumlah element sebanyak jumlah

  // todo : menu
  do {
    cout << "Menu : " << endl;
    cout << "1. Masukkan data mahasiswa " << endl;
    cout << "2. Tampilkan data mahasiswa " << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    cin.ignore(); // todo : menghapus input sebelumnya agar tidak terjadi bug

    switch (pilihan) {
      case 1 :
      masukkanData(Mhs, jumlah);
      break;
      case 2:
      tampilkanData(Mhs, jumlah);
      break;
      case 3 :
      cout << "Terimakasih!" << endl;
      break;
      default: 
      cout << "Pilihan tidak valid!" << endl;
      cin.get(); // todo : agar tidak langsung keluar sampai ada ENTER di tekan
    }
    }while (pilihan != 3);
}