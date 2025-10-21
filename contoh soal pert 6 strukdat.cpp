#include <iostream>
using namespace std;

#define MAX 100   // kapasitas queue

class Queue {
private:
    int front, rear;
    int ele[MAX];

public:
    Queue() { // inisialisasi queue
        front = 0;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void insertQueue(int item) {
        if (isFull()) {
            cout << "??  Queue Penuh. Tidak bisa insert.\n";
            return;
        }
        rear++;
        ele[rear] = item;
        cout << "? Data " << item << " berhasil dimasukkan ke antrian.\n";
    }

    void deleteQueue() {
        if (isEmpty()) {
            cout << "??  Queue Kosong. Tidak bisa delete.\n";
            return;
        }
        cout << "???  Data " << ele[front] << " dihapus dari antrian.\n";
        front++;
    }

    void resetQueue() {
        front = 0;
        rear = -1;
        cout << "??  Queue telah direset.\n";
    }

    void kondisiQueue() {
        if (isEmpty())
            cout << "?? Kondisi: Queue kosong.\n";
        else if (isFull())
            cout << "?? Kondisi: Queue penuh.\n";
        else if (rear == MAX - 1 && front > 0)
            cout << "?? Kondisi: Queue perlu direset (tidak bisa diisi lagi).\n";
        else
            cout << "?? Kondisi: Queue bisa diisi.\n";
    }

    int jumlahPengantri() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }

    int sisaKolom() {
        return MAX - (rear + 1);
    }
};

int main() {
    Queue q;
    int pilihan, data;
    int counter;

    do {
        cout << "\n=========== MENU LINEAR QUEUE ===========\n";
        cout << "1. Insert (max 10 record)\n";
        cout << "2. Delete (max 10 record)\n";
        cout << "3. Reset Queue\n";
        cout << "4. Cek Kondisi Queue\n";
        cout << "5. Hitung Jumlah Pengantri & Sisa Kolom\n";
        cout << "0. Keluar\n";
        cout << "=========================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            counter = 0;
            while (counter < 10 && !q.isFull()) {
                cout << "Masukkan data ke-" << (counter + 1) << ": ";
                cin >> data;
                q.insertQueue(data);
                counter++;
            }
            if (q.isFull()) {
                cout << "??  Antrian penuh. Proses insert dihentikan.\n";
            }
            break;

        case 2:
            counter = 0;
            while (counter < 10 && !q.isEmpty()) {
                q.deleteQueue();
                counter++;
            }
            if (q.isEmpty()) {
                cout << "??  Antrian kosong. Proses delete dihentikan.\n";
            }
            break;

        case 3:
            q.resetQueue();
            break;

        case 4:
            q.kondisiQueue();
            break;

        case 5:
            cout << "?? Jumlah pengantri saat ini: " << q.jumlahPengantri() << endl;
            cout << "?? Jumlah kolom kosong: " << q.sisaKolom() << endl;
            break;

        case 0:
            cout << "?? Program selesai.\n";
            break;

        default:
            cout << "? Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
