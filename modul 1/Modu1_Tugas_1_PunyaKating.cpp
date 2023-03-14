#include <iostream>
#include <string>
using namespace std;
struct data
{
  string nama, email;
  long int nim;
};

struct data dataMahasiswa;
int nilaiAwal, pilihanUser;


void DataMahasiswa() {

  cout << "Masukkan Nama         : "; getline (cin >> ws, dataMahasiswa.nama);
  cout << "Masukkan alamat email : "; cin >> dataMahasiswa.email;
  cout << "Masukkan nim          : "; cin >> dataMahasiswa.nim;
  
}

void TampilkanDataMahasiswa(struct data dataMahasiswa) {
  system("cls");
  cout << "==== DATA MAHASISWA YANG TELAH DIMASUKAN ====" << endl;
  cout << "NAMA  :  " << dataMahasiswa.nama << endl;
  cout << "NIM   :  " << dataMahasiswa.nim  << endl;
  cout << "EMAIL :  " << dataMahasiswa.email << endl;
}

int main() {
  system("cls");
  cout << "Masukkan jumlah data yang ingin dimasukkan : "; cin >> pilihanUser;
  if (pilihanUser <= 2) {
    cout << "Inputan Minimal 3";
  } else {
    for (nilaiAwal = 1; nilaiAwal <= pilihanUser; nilaiAwal++) {
      DataMahasiswa();
    }
    cout << "Data Mahasiswa = " << nilaiAwal << endl;
    TampilkanDataMahasiswa(dataMahasiswa);
  }
  // DataMahasiswa();
  // TampilkanDataMahasiswa(dataMahasiswa);
  return 0;
}