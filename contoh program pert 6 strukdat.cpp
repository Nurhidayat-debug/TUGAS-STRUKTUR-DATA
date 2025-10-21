#include <iostream>
using namespace std;

#define MAX 5   // Ukuran maksimal queue

class Queue {
private:
    int front, rear;
    int ele[MAX];

public:
    // Konstruktor (Inisialisasi queue)
    Queue() {
        front = 0;
        rear = -1;
    }

    int isFull();
    int isEmpty();
    void insertQueue(int item);
    int deleteQueue(int *item);
};

// Mengecek apakah queue penuh
int Queue::isFull() {
    int full = 0;
    if (rear == MAX - 1)
        full = 1;
    return full;
}

// Mengecek apakah queue kosong
int Queue::isEmpty() {
    int empty = 0;
    if (front > rear)   // kondisi jika antrian kosong
        empty = 1;
    return empty;
}

// Menambahkan item ke queue (enqueue)
void Queue::insertQueue(int item) {
    if (isFull()) {
        cout << "\nQueue OverFlow" << endl;
        return;
    }

    ele[++rear] = item;
    cout << "\nNilai yang disisipkan: " << item;
}

// Menghapus item dari queue (dequeue)
int Queue::deleteQueue(int *item) {
    if (isEmpty()) {
        cout << "\nQueue Underflow" << endl;
        return -1;
    }

    *item = ele[front++];
    return 0;
}

// Program utama
int main() {
    int item = 0;
    Queue q;

    // Menambahkan elemen ke queue
    q.insertQueue(10);
    q.insertQueue(20);
    q.insertQueue(30);
    q.insertQueue(40);
    q.insertQueue(50);
    q.insertQueue(60); // Ini akan overflow

    // Menghapus elemen dari queue satu per satu
    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item;

    if (q.deleteQueue(&item) == 0)
        cout << "\nItem dihapus: " << item; // Ini akan underflow

    cout << endl;
    return 0;
}
