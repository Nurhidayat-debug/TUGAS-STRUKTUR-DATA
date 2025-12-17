#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int kiri = 0, kanan = n - 1, langkah = 0;

    while (kiri <= kanan) {
        langkah++;
        int tengah = (kiri + kanan) / 2;

        if (arr[tengah] == target) {
            cout << "Jumlah langkah: " << langkah << endl;
            return tengah;
        }
        else if (arr[tengah] < target)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    cout << "Jumlah langkah: " << langkah << endl;
    return -1;
}

int main() {
    int data[15] = {2,5,8,12,16,23,38,45,56,72,81,90,101,120,135};
    int cari = 45;

    int hasil = binarySearch(data, 15, cari);
    if (hasil != -1)
        cout << "Data ditemukan di indeks " << hasil << endl;
    else
        cout << "Data tidak ditemukan\n";

    return 0;
}
