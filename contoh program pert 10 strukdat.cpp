// Program C++ untuk mengimplementasikan Stack (Tumpukan)
// Menggunakan Singly Linked List

#include <bits/stdc++.h>
using namespace std;

// Deklarasikan node linked list
struct Node {
    int data;
    Node* link;
};

Node* top = NULL;  // pointer top stack

// Fungsi push: menambahkan elemen ke stack
void push(int data) {
    Node* temp = new Node();

    // Cek jika heap penuh (jarang terjadi di C++)
    if (!temp) {
        cout << "\nHeap Overflow";
        exit(1);
    }

    // Isi data dan link
    temp->data = data;
    temp->link = top;

    // Jadikan temp sebagai top baru
    top = temp;
}

// Fungsi isEmpty: cek apakah stack kosong
bool isEmpty() {
    return top == NULL;
}

// Fungsi peek: melihat elemen teratas tanpa menghapus
int peek() {
    if (!isEmpty()) {
        return top->data;
    } else {
        cout << "\nStack kosong!";
        exit(1);
    }
}

// Fungsi pop: menghapus elemen teratas stack
void pop() {
    if (top == NULL) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    } else {
        Node* temp = top;
        top = top->link;
        temp->link = NULL;
        delete temp;  // pakai delete (bukan free) karena new dipakai
    }
}

// Fungsi display: menampilkan semua elemen stack
void display() {
    if (top == NULL) {
        cout << "\nStack Underflow";
        return;
    } else {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->link;
        }
        cout << "NULL" << endl;
    }
}

// Fungsi utama
int main() {
    // Push elemen ke dalam stack
    push(11);
    push(22);
    push(33);
    push(44);

    // Menampilkan elemen stack
    cout << "Isi Stack: ";
    display();

    // Mencetak elemen stack paling atas
    cout << "Elemen Top adalah " << peek() << endl;

    // Hapus dua elemen teratas stack
    pop();
    pop();

    // Menampilkan elemen stack setelah pop
    cout << "Isi Stack setelah 2x pop: ";
    display();

    // Cetak elemen stack paling atas
    cout << "Elemen Top adalah " << peek() << endl;

    return 0;
}
