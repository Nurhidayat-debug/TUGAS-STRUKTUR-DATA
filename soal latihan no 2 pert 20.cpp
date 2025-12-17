#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* tail = NULL;

// INSERT data ke list
void insert(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;

    if (tail == NULL) {
        tail = baru;
        tail->next = tail;
        cout << "Insert " << nilai << " (list awal)\n";
    } else {
        baru->next = tail->next;
        tail->next = baru;
        tail = baru;
        cout << "Insert " << nilai << endl;
    }
}

// DELETE data tertentu
void hapus(int nilai) {
    if (tail == NULL) {
        cout << "List kosong, tidak bisa menghapus\n";
        return;
    }

    Node* curr = tail->next;
    Node* prev = tail;

    do {
        if (curr->data == nilai) {
            if (curr == tail && curr == tail->next) {
                tail = NULL;
            } else {
                prev->next = curr->next;
                if (curr == tail)
                    tail = prev;
            }
            delete curr;
            cout << "Hapus " << nilai << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    cout << "Data " << nilai << " tidak ditemukan\n";
}

// TRAVERSE list
void traverse() {
    if (tail == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node* curr = tail->next;
    cout << "Isi list: ";
    do {
        cout << curr->data << " -> ";
        curr = curr->next;
    } while (curr != tail->next);
    cout << "(kembali ke awal)\n";
}

int main() {
    insert(10);
    traverse();

    insert(20);
    traverse();

    insert(30);
    traverse();

    hapus(20);
    traverse();

    hapus(10);
    traverse();

    return 0;
}
