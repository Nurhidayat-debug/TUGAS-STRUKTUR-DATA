#include <iostream>
using namespace std;

#define MAX 20   // kapasitas maksimal circular queue

class CirQueue {
private:
    int front;
    int rear;
    int ele[MAX];
    int count; // hanya untuk pengecekan cepat

public:
    CirQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == MAX;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insertQueue(int item) {
        if (isFull()) {
            cout << "\nQueue Overflow - Antrian penuh!" << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        ele[rear] = item;
        count++;
        cout << "Record " << item << " berhasil dimasukkan ke antrian." << endl;
    }

    bool deleteQueue(int *item) {
        if (isEmpty()) {
            cout << "\nQueue Underflow - Antrian kosong!" << endl;
            return false;
        }
        *item = ele[front];
        front = (front + 1) % MAX;
        count--;
        return true;
    }

    // Hitung jumlah elemen terisi TANPA menggunakan variabel count
    int hitungIsiTanpaCount() {
        if (rear == -1) return 0;
        if (rear >= front)
            return (rear - front + 1);
        else
            return (MAX - front + rear + 1);
    }

    void tampilkanIsi() {
        if (isEmpty()) {
            cout << "Antrian kosong.\n";
            return;
        }
        cout << "Isi antrian: ";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << ele[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CirQueue q;
    int item;
    int jumlahInput = 10;   // jumlah record maksimal dimasukkan
    int jumlahDelete = 10;  // jumlah record maksimal dihapus

    cout << "=== INSERT hingga 10 record atau antrian penuh ===" << endl;
    for (int i = 1; i <= jumlahInput; i++) {
        if (q.isFull()) {
            cout << "Antrian sudah penuh sebelum 10 record.\n";
            break;
        }
        int nilai;
        cout << "Masukkan record ke-" << i << ": ";
        cin >> nilai;
        q.insertQueue(nilai);
    }

    cout << "\n=== TAMPILKAN ISI ANTRIAN ===" << endl;
    q.tampilkanIsi();

    cout << "\nJumlah elemen terisi (tanpa counter): " << q.hitungIsiTanpaCount() << endl;

    cout << "\n=== DELETE hingga 10 record atau antrian kosong ===" << endl;
    for (int i = 1; i <= jumlahDelete; i++) {
        if (!q.deleteQueue(&item)) {
            cout << "Antrian kosong sebelum 10 record dihapus.\n";
            break;
        }
        cout << "Record ke-" << i << " dihapus: " << item << endl;
    }

    cout << "\n=== KONDISI AKHIR ANTRIAN ===" << endl;
    q.tampilkanIsi();
    cout << "Jumlah elemen terisi (tanpa counter): " << q.hitungIsiTanpaCount() << endl;

    return 0;
}
