#include <iostream>
using namespace std;

#define MAX 10  // kapasitas maksimum stack

int stack[MAX];
int top = -1;   // posisi awal stack kosong

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty() {
    return top == -1;
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull() {
    return top == MAX - 1;
}

// Fungsi PUSH
void push(int data) {
    if (isFull()) {
        cout << "Stack Penuh" << endl;
    } else {
        stack[++top] = data;
        cout << data << " dimasukkan ke dalam stack" << endl;
    }
}

// Fungsi POP
int pop() {
    if (isEmpty()) {
        cout << "Stack Kosong" << endl;
        return -1;
    } else {
        int data = stack[top--];
        cout << data << " dikeluarkan dari stack" << endl;
        return data;
    }
}

// Menampilkan isi stack
void printStack() {
    if (isEmpty()) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "Isi stack (dari bawah ke atas): ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int data;

    cout << "=== PROGRAM STACK ===" << endl;
    cout << "Masukkan data (999 untuk berhenti)" << endl;

    // ======================== SOAL 1 ===========================
    while (true) {
        cout << "Input data : ";
        cin >> data;

        if (data == 999) {
            cout << "Proses selesai." << endl;
            break;
        }

        if (data >= 60) {
            if (!isFull()) {
                push(data);
            } else {
                cout << "Stack Penuh" << endl;
                break;
            }
        } else {
            if (!isEmpty()) {
                pop();
            } else {
                cout << "Stack Kosong" << endl;
                break;
            }
        }
    }

    cout << endl;
    printStack();

    // ======================== SOAL 2 ===========================
    cout << "\n=== PUSH SAMPAI PENUH DAN POP SAMPAI KOSONG ===" << endl;
    top = -1; // reset stack

    // PUSH sampai penuh atau input 999
    while (true) {
        cout << "Masukkan data (999 untuk berhenti): ";
        cin >> data;
        if (data == 999) break;
        if (isFull()) {
            cout << "Stack Penuh" << endl;
            break;
        }
        push(data);
    }

    cout << "Isi stack setelah PUSH: ";
    printStack();

    // POP sampai kosong
    cout << "Mengeluarkan isi stack..." << endl;
    while (!isEmpty()) {
        pop();
    }

    cout << "Stack sekarang kosong." << endl;

    return 0;
}
