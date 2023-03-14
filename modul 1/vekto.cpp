#include <iostream>
#include <vector>
using namespace std;

struct DataMahasiswa {
  string nama;
  string email;
  string nim;
};

void InputDataMahasiswa(vector <DataMahasiswa> &data)
{
  int pilihanUser;
  cout << "\n\nMasukkan jumlah data yang ingin dimasukkan : "; cin >> pilihanUser;
  if (pilihanUser <= 1) 
  {
    cout << "Inputan Minimal 3\n";
  } 
  else 
  {
    cout <<"-----------------------------\n";
    cout <<"===== Memasukkan data =======\n";
    cout <<"-----------------------------\n";
    for (int i = 0; i < pilihanUser; i++)
    {
      DataMahasiswa mhs;
      cin.ignore(); 
      cout << "Masukkan Nama         : ";
      getline(cin, mhs.nama);
      cin.ignore();
      cout << "Masukkan alamat email : "; 
      getline (cin, mhs.email);
      cin.ignore();
      cout << "Masukkan nim          : "; 
      getline(cin, mhs.nim); 
      cin.ignore();
      cout << endl;
      data.push_back(mhs);
    }
  }
}

void TampilkanDataMahasiswa(const vector <DataMahasiswa> &data)
{
  int urutan = 1;
  cout << "--------------------------\n";
  cout << "===== Data Mahasiswa =====\n";
  cout << "--------------------------\n";
  for (const auto &mhs : data)
  {
    cout << "Data Mahasiswa ke-" << urutan++ << ":\n";
    cout << "Nama  : " << mhs.nama << endl;
    cout << "Email : " << mhs.email << endl;
    cout << "NIM   : " << mhs.nim << endl << endl;
  }
}

int main()
{
  system("cls");
  vector<DataMahasiswa> data;
  InputDataMahasiswa(data);
  // system("cls");
  TampilkanDataMahasiswa(data);

  return 0;
}
