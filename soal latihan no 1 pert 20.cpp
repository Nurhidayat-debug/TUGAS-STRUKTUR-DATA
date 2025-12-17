#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int data[10];
    srand(time(0));

    // Generate data random
    cout << "Data awal:\n";
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 100;
        cout << data[i] << " ";
    }
    cout << "\n\n";

    cout << "Proses Bubble Sort (setiap pertukaran):\n";

    // Bubble Sort + animasi teks
    for (int i = 0; i < 9; i++) {
        cout << "\nPass ke-" << i + 1 << endl;
        for (int j = 0; j < 9 - i; j++) {
            cout << "Bandingkan " << data[j] 
                 << " dan " << data[j + 1];

            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                cout << " -> ditukar\n";
            } else {
                cout << " -> tidak ditukar\n";
            }

            // Tampilkan kondisi array saat ini
            for (int k = 0; k < 10; k++)
                cout << data[k] << " ";
            cout << endl;
        }
    }

    cout << "\nData setelah diurutkan:\n";
    for (int i = 0; i < 10; i++)
        cout << data[i] << " ";

    return 0;
}
