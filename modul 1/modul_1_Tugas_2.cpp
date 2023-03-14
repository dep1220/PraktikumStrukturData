# include <iostream>
# define max 50

using namespace std;

int* fibo(int n, int arr[]) {
  arr[0] = 1;
  arr[1] = 1;

  for (int i = 2; i < n; i++) {
    arr [i] = arr[i - 1] + arr[i - 2];
  }
  // todo : ada warning disini karena fungsi mengembalikan memory
  // todo : sedangkan yg ini mengembalikan array
  // todo : solusinya, letakkan variabel ini ke global
  // todo : atau jadikan parameter
  return arr;
}

int main () {
  system("cls");
  int num, *ptr, arr[max];
  cout << "Masukkan Jumlah Fibbonaci : ";
  cin >> num;

  ptr = fibo(num,arr);

  for (int i = 0; i < num; i++) {
    cout << ptr[i] << " ";
  }
}