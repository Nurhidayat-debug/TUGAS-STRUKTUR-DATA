/* Program C++ untuk mengimplementasikan operasi dasar pada Stack */

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000  // ukuran maksimum stack

class Stack {
    int top;            // penunjuk elemen teratas
public:
    int a[MAX];         // array untuk menyimpan elemen stack

    Stack() { top = -1; }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow" << endl;
        return false;
    } else {
        a[++top] = x;
        cout << x << " didorong ke dalam tumpukan\n";
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow" << endl;
        return 0;
    } else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        cout << "Tumpukan Kosong" << endl;
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

// Program utama untuk menguji fungsi Stack
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " dikeluarkan dari tumpukan\n";

    cout << "Elemen teratas sekarang: " << s.peek() << endl;

    if (s.isEmpty())
        cout << "Tumpukan kosong" << endl;
    else
        cout << "Tumpukan tidak kosong" << endl;

    return 0;
}
