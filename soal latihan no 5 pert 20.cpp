#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* next;
};

// Pointer depan dan belakang queue
Node* front = NULL;
Node* rear = NULL;

// Enqueue (tambah antrian)
void enqueue(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    cout << nilai << " masuk antrian\n";
}

// Dequeue (keluar antrian)
void dequeue() {
    if (front == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    Node* hapus = front;
    cout << hapus->data << " keluar antrian\n";
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete hapus;
}

// Menampilkan isi antrian
void tampil() {
    if (front == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    Node* curr = front;
    cout << "Isi antrian: ";
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    cout << "Simulasi Antrian Queue\n\n";

    enqueue(10);
    enqueue(20);
    enqueue(30);
    tampil();

    dequeue();
    tampil();

    enqueue(40);
    tampil();

    dequeue();
    dequeue();
    tampil();

    return 0;
}
