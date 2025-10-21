#include <iostream>
using namespace std;

#define MAX 5

// Deklarasi Double Stack
class DStack {
private:
    int top1;       // penunjuk stack 1
    int top2;       // penunjuk stack 2
    int ele[MAX];   // array penyimpanan data

public:
    DStack();                    // konstruktor
    void pushA(int item);        // push ke stack 1
    void pushB(int item);        // push ke stack 2
    int popA(int *item);         // pop dari stack 1
    int popB(int *item);         // pop dari stack 2
};

// Inisialisasi Double Stack
DStack::DStack() {
    top1 = -1;
    top2 = MAX;
}

// Operasi Push di Stack 1
void DStack::pushA(int item) {
    if (top2 == top1 + 1) {
        cout << "\nStack Overflow Stack1";
        return;
    }
    top1++;
    ele[top1] = item;
    cout << "\nItem disisipkan di Stack1 : " << item;
}

// Operasi Push di Stack 2
void DStack::pushB(int item) {
    if (top2 == top1 + 1) {
        cout << "\nStack Overflow Stack2";
        return;
    }
    top2--;
    ele[top2] = item;
    cout << "\nItem disisipkan di Stack2 : " << item;
}

// Operasi Pop di Stack 1
int DStack::popA(int *item) {
    if (top1 == -1) {
        cout << "\nStack Underflow Stack1";
        return -1;
    }
    *item = ele[top1--];
    return 0;
}

// Operasi Pop di Stack 2
int DStack::popB(int *item) {
    if (top2 == MAX) {
        cout << "\nStack Underflow Stack2";
        return -1;
    }
    *item = ele[top2++];
    return 0;
}

int main() {
    int item = 0;
    DStack s;

    // Push ke Stack 1
    s.pushA(10);
    s.pushA(20);
    s.pushA(30);

    // Push ke Stack 2
    s.pushB(40);
    s.pushB(50);
    s.pushB(60); // Akan Overflow karena MAX = 5

    // Pop dari Stack 1
    if (s.popA(&item) == 0)
        cout << "\nMenghapus Item dari Stack1 : " << item;
    if (s.popA(&item) == 0)
        cout << "\nMenghapus Item dari Stack1 : " << item;
    if (s.popA(&item) == 0)
        cout << "\nMenghapus Item dari Stack1 : " << item;

    // Pop dari Stack 2
    if (s.popB(&item) == 0)
        cout << "\nMenghapus Item dari Stack2 : " << item;
    if (s.popB(&item) == 0)
        cout << "\nMenghapus Item dari Stack2 : " << item;
    if (s.popB(&item) == 0)
        cout << "\nMenghapus Item dari Stack2 : " << item;

    cout << endl;
    return 0;
}
