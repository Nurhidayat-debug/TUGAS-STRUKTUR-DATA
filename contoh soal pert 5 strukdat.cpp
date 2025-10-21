#include <iostream>
using namespace std;

#define MAX 10   // ukuran array maksimal

class DStack {
private:
    int top1;          // posisi stack 1
    int top2;          // posisi stack 2
    int ele[MAX];      // array penyimpanan

public:
    // Konstruktor
    DStack() {
        top1 = -1;
        top2 = MAX;
    }

    // PUSH ke Stack 1
    void push1(int item) {
        if (top1 + 1 == top2) {
            cout << "Stack1 Overflow! Tidak bisa push.\n";
            return;
        }
        top1++;
        ele[top1] = item;
        cout << "Item " << item << " berhasil dimasukkan ke Stack1.\n";
    }

    // PUSH ke Stack 2
    void push2(int item) {
        if (top2 - 1 == top1) {
            cout << "Stack2 Overflow! Tidak bisa push.\n";
            return;
        }
        top2--;
        ele[top2] = item;
        cout << "Item " << item << " berhasil dimasukkan ke Stack2.\n";
    }

    // POP dari Stack 1
    int pop1() {
        if (top1 == -1) {
            cout << "Stack1 Underflow! Tidak ada data.\n";
            return -1;
        }
        int item = ele[top1--];
        cout << "Item " << item << " dihapus dari Stack1.\n";
        return item;
    }

    // POP dari Stack 2
    int pop2() {
        if (top2 == MAX) {
            cout << "Stack2 Underflow! Tidak ada data.\n";
            return -1;
        }
        int item = ele[top2++];
        cout << "Item " << item << " dihapus dari Stack2.\n";
        return item;
    }

    // Cetak semua isi Stack 1 & kosongkan
    void cetakStack1() {
        cout << "\nMengambil semua isi Stack1:\n";
        while (top1 != -1) {
            cout << pop1() << " ";
        }
        cout << "\nStack1 sekarang kosong.\n";
    }

    // Cetak semua isi Stack 2 & kosongkan
    void cetakStack2() {
        cout << "\nMengambil semua isi Stack2:\n";
        while (top2 != MAX) {
            cout << pop2() << " ";
        }
        cout << "\nStack2 sekarang kosong.\n";
    }

    // Mengecek kondisi stack
    void kondisiStack() {
        if (top1 + 1 == top2)
            cout << ">> Kondisi: STACK PENUH\n";
        else if (top1 == -1 && top2 == MAX)
            cout << ">> Kondisi: KEDUA STACK KOSONG\n";
        else
            cout << ">> Kondisi: STACK BISA DIISI\n";
    }
};

int main() {
    DStack s;
    int pilihan, item;

    do {
        cout << "\n========== MENU DOUBLE STACK ==========\n";
        cout << "1. PUSH Stack1\n";
        cout << "2. PUSH Stack2\n";
        cout << "3. POP Stack1\n";
        cout << "4. POP Stack2\n";
        cout << "5. Cetak & Kosongkan Stack1\n";
        cout << "6. Cetak & Kosongkan Stack2\n";
        cout << "7. Cek Kondisi Stack\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan nilai untuk Stack1: ";
            cin >> item;
            s.push1(item);
            break;
        case 2:
            cout << "Masukkan nilai untuk Stack2: ";
            cin >> item;
            s.push2(item);
            break;
        case 3:
            s.pop1();
            break;
        case 4:
            s.pop2();
            break;
        case 5:
            s.cetakStack1();
            break;
        case 6:
            s.cetakStack2();
            break;
        case 7:
            s.kondisiStack();
            break;
        case 0:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
