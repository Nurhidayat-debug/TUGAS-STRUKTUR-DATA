#include <iostream>
#include <cmath>    // untuk fungsi sqrt dan pow
using namespace std;

int main() {
    // ====================== 1. Menyimpan dan mencetak tiga nilai ======================
    cout << "=== Soal 1: Input tiga nilai (int, char, float) ===" << endl;
    int intValue;
    char charValue;
    float floatValue;

    cout << "Masukkan nilai (int char float): ";
    cin >> intValue >> charValue >> floatValue;

    cout << "Nilai integer: " << intValue << endl;
    cout << "Nilai karakter: " << charValue << endl;
    cout << "Nilai float: " << floatValue << endl;

    cout << "\n";

    // ====================== 2. Luas dan keliling persegi panjang ======================
    cout << "=== Soal 2: Luas dan keliling persegi panjang ===" << endl;
    float lebar, tinggi;
    cout << "Masukkan lebar: ";
    cin >> lebar;
    cout << "Masukkan tinggi: ";
    cin >> tinggi;

    float luas = lebar * tinggi;
    float keliling = 2 * (lebar + tinggi);

    cout << "Luas persegi panjang: " << luas << endl;
    cout << "Keliling persegi panjang: " << keliling << endl;

    cout << "\n";

    // ====================== 3. Konversi skor ke nilai huruf ======================
    cout << "=== Soal 3: Konversi skor ke nilai huruf ===" << endl;
    int skor;
    cout << "Masukkan skor (0 - 100): ";
    cin >> skor;

    if (skor == 100) {
        cout << "Skor sempurna!" << endl;
    } else if (skor >= 90) {
        cout << "Nilai: A" << endl;
    } else if (skor >= 80) {
        cout << "Nilai: B" << endl;
    } else if (skor >= 70) {
        cout << "Nilai: C" << endl;
    } else if (skor >= 60) {
        cout << "Nilai: D" << endl;
    } else {
        cout << "Nilai: F" << endl;
    }

    cout << "\n";

    // ====================== 4. Jarak antara dua titik ======================
    cout << "=== Soal 4: Jarak antara titik A dan B ===" << endl;
    float x1, y1, x2, y2;
    cout << "Masukkan koordinat titik A (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Masukkan koordinat titik B (x2 y2): ";
    cin >> x2 >> y2;

    float jarak = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Jarak antara A dan B: " << jarak << endl;

    cout << "\n";

    // ====================== 5. Menukar nilai A dan B ======================
    cout << "=== Soal 5: Menukar nilai A dan B ===" << endl;
    int A, B, temp;
    cout << "Masukkan nilai A: ";
    cin >> A;
    cout << "Masukkan nilai B: ";
    cin >> B;

    // Menukar nilai
    temp = A;
    A = B;
    B = temp;

    cout << "Setelah ditukar: " << endl;
    cout << "Nilai A: " << A << endl;
    cout << "Nilai B: " << B << endl;

    return 0;
}
