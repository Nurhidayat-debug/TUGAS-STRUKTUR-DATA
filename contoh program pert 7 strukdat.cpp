#include <iostream>
using namespace std;

#define MAX 5

// ===================== Deklarasi Circular Queue =====================
class CirQueue {
private:
    int front;
    int rear;
    int count;
    int ele[MAX];

public:
    CirQueue();
    int isFull();
    int isEmpty();
    void insertQueue(int item);
    int deleteQueue(int *item);
};

// ===================== Inisialisasi Circular Queue =====================
CirQueue::CirQueue() {
    front = 0;
    rear = -1;
    count = 0;
}

// ===================== Cek Queue Penuh =====================
int CirQueue::isFull() {
    int full = 0;
    if (count == MAX)
        full = 1;
    return full;
}

// ===================== Cek Queue Kosong =====================
int CirQueue::isEmpty() {
    int empty = 0;
    if (count == 0)
        empty = 1;
    return empty;
}

// ===================== Menambahkan Data ke Queue =====================
void CirQueue::insertQueue(int item) {
    if (isFull()) {
        cout << "\n??  Queue Overflow (Penuh)";
        return;
    }
    // rumus circular queue
    rear = (rear + 1) % MAX;
    ele[rear] = item;
    count++;
    cout << "\n? Dimasukkan item : " << item;
}

// ===================== Menghapus Data dari Queue =====================
int CirQueue::deleteQueue(int *item) {
    if (isEmpty()) {
        cout << "\n??  Queue Underflow (Kosong)";
        return -1;
    }
    *item = ele[front];
    front = (front + 1) % MAX;
    count--;
    return 0;
}

// ===================== Program Utama =====================
int main() {
    int item;
    CirQueue q;

    // Uji coba insert lebih dari kapasitas
    q.insertQueue(10);
    q.insertQueue(20);
    q.insertQueue(30);
    q.insertQueue(40);
    q.insertQueue(50);
    q.insertQueue(60); // Ini tidak akan masuk karena queue penuh

    // Uji coba delete beberapa item
    if (q.deleteQueue(&item) == 0)
        cout << "\n???  Item dihapus: " << item << endl;
    if (q.deleteQueue(&item) == 0)
        cout << "\n???  Item dihapus: " << item << endl;
    if (q.deleteQueue(&item) == 0)
        cout << "\n???  Item dihapus: " << item << endl;
    if (q.deleteQueue(&item) == 0)
        cout << "\n???  Item dihapus: " << item << endl;
    if (q.deleteQueue(&item) == 0)
        cout << "\n???  Item dihapus: " << item << endl;

    // Uji coba insert lagi setelah delete
    q.insertQueue(60);

    // Delete lagi
    if (q.deleteQueue(&item) == 0)
        cout << "\n???  Item dihapus: " << item << endl;
    if (q.deleteQueue(&item) == 0)
        cout << "\n???  Item dihapus: " << item << endl;

    cout << "\n";
    return 0;
}
