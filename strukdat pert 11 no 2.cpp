#include <iostream>
#include <string>
#include <cstdlib> // Untuk system("cls") atau system("clear")
#include <limits>  // Untuk std::numeric_limits

using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string NAMA;
    string NIM;
    string GENDER;
    float NILAI_STRUKTUR_DATA;
};

// Node (elemen) dari Linked List
struct Node {
    Mahasiswa data;
    Node *next; // Pointer ke node berikutnya
};

// Pointer ke elemen teratas (TOP) Stack. TIDAK ADA pointer Head terpisah.
Node *top = NULL; 

// Fungsi untuk membuat node baru
Node *buatNode(Mahasiswa mhs) {
    Node *baru = new Node;
    baru->data = mhs;
    baru->next = NULL;
    return baru;
}

// Fungsi untuk mengecek apakah Stack kosong
bool isEmpty() {
    return top == NULL;
}

// Operasi Stack: PUSH (INSERT DATA)
void pushData(Mahasiswa mhs) {
    Node *baru = buatNode(mhs);
    baru->next = top; // Node baru menunjuk ke top lama
    top = baru;        // Node baru menjadi top
    cout << "\n? Data Mahasiswa berhasil di-INSERT (Push)!" << endl;
}

// Operasi Stack: POP (HAPUS DATA)
void popData() {
    if (isEmpty()) {
        cout << "\n?? Stack kosong, tidak ada data untuk di-HAPUS (Pop)." << endl;
        return;
    }
    Node *hapus = top;         // Simpan node yang akan dihapus
    Mahasiswa mhsHapus = top->data; // Simpan data mahasiswa yang dihapus
    top = top->next;           // Top pindah ke node berikutnya
    delete hapus;              // Hapus node dari memori

    cout << "\n? Data Mahasiswa berhasil di-HAPUS (Pop)!" << endl;
    cout << "   NIM: " << mhsHapus.NIM << " | Nama: " << mhsHapus.NAMA << endl;
}

// Operasi Stack: CETAK DATA (Display)
void cetakData() {
    if (isEmpty()) {
        cout << "\n?? Stack kosong, tidak ada data untuk ditampilkan." << endl;
        return;
    }
    Node *bantu = top;
    int no = 1;
    cout << "\n*** DATA MAHASISWA (Urutan Stack: Atas ke Bawah) ***" << endl;
    cout << "------------------------------------------------------" << endl;
    while (bantu != NULL) {
        cout << "No. " << no++ << endl;
        cout << "  NIM: " << bantu->data.NIM << endl;
        cout << "  Nama: " << bantu->data.NAMA << endl;
        cout << "  Gender: " << bantu->data.GENDER << endl;
        cout << "  Nilai Struktur Data: " << bantu->data.NILAI_STRUKTUR_DATA << endl;
        cout << "------------------------------------------------------" << endl;
        bantu = bantu->next;
    }
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear");
    #endif
    
    cout << "============================================" << endl;
    cout << "  PROGRAM STACK (LINKED LIST) TANPA HEAD    " << endl;
    cout << "============================================" << endl;
    cout << "1. INSERT DATA (Push)" << endl;
    cout << "2. HAPUS DATA (Pop)" << endl;
    cout << "3. CETAK DATA (Display)" << endl;
    cout << "4. EXIT" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Pilih menu (1-4): ";
}

// Fungsi utama program
int main() {
    int pilihan;
    Mahasiswa mhsBaru;

    do {
        tampilkanMenu();
        // Cek jika input menu bukan angka
        if (!(cin >> pilihan)) {
            cout << "\n?? Input tidak valid! Masukkan angka menu (1-4)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilihan = 0;
        }

        switch (pilihan) {
            case 1: // INSERT DATA (Push)
                // --- BAGIAN INI YANG DIPERBAIKI/DILENGKAPI ---
                cout << "\n--- INSERT DATA MAHASISWA (PUSH) ---" << endl; 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                
                cout << "Masukkan NIM: ";
                getline(cin, mhsBaru.NIM); 
                
                cout << "Masukkan Nama: ";
                getline(cin, mhsBaru.NAMA);

                cout << "Masukkan Gender (L/P): ";
                getline(cin, mhsBaru.GENDER);
                
                cout << "Masukkan Nilai Struktur Data: ";
                if (!(cin >> mhsBaru.NILAI_STRUKTUR_DATA)) {
                    cout << "\n?? Nilai tidak valid. Pembatalan Input." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break; 
                }

                pushData(mhsBaru);
                break;
            // ----------------------------------------------
                
            case 2: // HAPUS DATA (Pop)
                cout << "\n--- HAPUS DATA MAHASISWA (POP) ---" << endl;
                popData();
                break;
            case 3: // CETAK DATA (Display)
                cetakData();
                break;
            case 4: // EXIT
                cout << "\nProgram selesai. Terima kasih!" << endl;
                break;
            default:
                if (pilihan != 0) {
                    cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                }
        }
        
        if (pilihan != 4) {
            cout << "\nTekan ENTER untuk melanjutkan...";
            // Bersihkan buffer dan tunggu ENTER
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cin.get(); 
        }

    } while (pilihan != 4);

    return 0;
}
