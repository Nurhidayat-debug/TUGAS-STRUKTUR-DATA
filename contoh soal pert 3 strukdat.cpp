#include <iostream>
#include <cstring>
using namespace std;

// =====================
// STRUCT UNTUK MAHASISWA
// =====================
struct Mahasiswa {
    int noUrut;
    char nama[50];
    int usia;
    char alamat[100];
    float nilai;
};

// =====================
// STRUCT UNTUK BUKU PERPUSTAKAAN
// =====================
struct Buku {
    int nomorAkses;
    char penulis[50];
    char judul[50];
    int jumlah;
    bool diterbitkan;
};

// Array global
Mahasiswa mhs[15];
Buku perpustakaan[100];

// Variabel jumlah data
int jumlahMhs = 0;
int jumlahBuku = 0;

// ==========================
// FUNGSI UNTUK DATA MAHASISWA
// ==========================

// Soal 1
void inputMahasiswa1() {
    Mahasiswa temp;
    cout << "\n=== Input Data Mahasiswa ===\n";
    cout << "Masukkan No Urut   : ";
    cin >> temp.noUrut;
    cin.ignore();
    cout << "Masukkan Nama      : ";
    cin.getline(temp.nama, 50);
    cout << "Masukkan Usia      : ";
    cin >> temp.usia;
    cout << "Masukkan Nilai     : ";
    cin >> temp.nilai;

    cout << "\n=== Data Mahasiswa ===\n";
    cout << "No Urut : " << temp.noUrut << endl;
    cout << "Nama    : " << temp.nama << endl;
    cout << "Usia    : " << temp.usia << endl;
    cout << "Nilai   : " << temp.nilai << endl;
}

// Soal 2
void input5Mahasiswa() {
    cout << "\n=== Input 5 Mahasiswa ===\n";
    for (int i = 0; i < 5; i++) {
        mhs[i].noUrut = i + 1;
        cin.ignore();
        cout << "Masukkan Nama Mahasiswa ke-" << i + 1 << " : ";
        cin.getline(mhs[i].nama, 50);
        cout << "Masukkan Usia: ";
        cin >> mhs[i].usia;
    }
    jumlahMhs = 5;

    cout << "\n=== Data Mahasiswa No Urut 2 ===\n";
    cout << "No Urut : " << mhs[1].noUrut << endl;
    cout << "Nama    : " << mhs[1].nama << endl;
    cout << "Usia    : " << mhs[1].usia << endl;
}

// Soal 3
void input15Mahasiswa() {
    cout << "\n=== Input 15 Mahasiswa ===\n";
    for (int i = 0; i < 15; i++) {
        mhs[i].noUrut = i + 1;
        cin.ignore();
        cout << "Nama Mahasiswa ke-" << i + 1 << " : ";
        cin.getline(mhs[i].nama, 50);
        cout << "Usia : ";
        cin >> mhs[i].usia;
        cin.ignore();
        cout << "Alamat : ";
        cin.getline(mhs[i].alamat, 100);
        cout << "Nilai : ";
        cin >> mhs[i].nilai;
    }
    jumlahMhs = 15;

    cout << "\n=== Data 15 Mahasiswa ===\n";
    for (int i = 0; i < 15; i++) {
        cout << "\nNo Urut : " << mhs[i].noUrut << endl;
        cout << "Nama    : " << mhs[i].nama << endl;
        cout << "Usia    : " << mhs[i].usia << endl;
        cout << "Alamat  : " << mhs[i].alamat << endl;
        cout << "Nilai   : " << mhs[i].nilai << endl;
    }
}

// ==========================
// FUNGSI UNTUK PERPUSTAKAAN
// ==========================

// Tampilkan semua buku
void tampilkanBuku() {
    cout << "\n=== Informasi Buku ===\n";
    if (jumlahBuku == 0) {
        cout << "Belum ada data buku.\n";
        return;
    }
    for (int i = 0; i < jumlahBuku; i++) {
        cout << "\nNomor Akses : " << perpustakaan[i].nomorAkses;
        cout << "\nPenulis     : " << perpustakaan[i].penulis;
        cout << "\nJudul       : " << perpustakaan[i].judul;
        cout << "\nJumlah      : " << perpustakaan[i].jumlah;
        cout << "\nStatus      : " << (perpustakaan[i].diterbitkan ? "Diterbitkan" : "Belum Diterbitkan") << endl;
    }
}

// Tambah buku
void tambahBuku() {
    cout << "\n=== Tambah Buku Baru ===\n";
    perpustakaan[jumlahBuku].nomorAkses = jumlahBuku + 1;
    cin.ignore();
    cout << "Masukkan Penulis : ";
    cin.getline(perpustakaan[jumlahBuku].penulis, 50);
    cout << "Masukkan Judul   : ";
    cin.getline(perpustakaan[jumlahBuku].judul, 50);
    cout << "Masukkan Jumlah  : ";
    cin >> perpustakaan[jumlahBuku].jumlah;
    perpustakaan[jumlahBuku].diterbitkan = false;
    jumlahBuku++;
}

// Cari buku berdasarkan penulis
void cariPenulis() {
    char cariPenulis[50];
    cout << "\nMasukkan nama penulis: ";
    cin.ignore();
    cin.getline(cariPenulis, 50);
    cout << "\n=== Buku Penulis " << cariPenulis << " ===\n";
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].penulis, cariPenulis) == 0) {
            cout << "- " << perpustakaan[i].judul << " (" << perpustakaan[i].jumlah << " buku)\n";
        }
    }
}

// Cari jumlah buku berdasarkan judul
void cariJudul() {
    char cariJudul[50];
    cout << "\nMasukkan judul buku: ";
    cin.ignore();
    cin.getline(cariJudul, 50);
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(perpustakaan[i].judul, cariJudul) == 0) {
            cout << "Jumlah buku \"" << cariJudul << "\": " << perpustakaan[i].jumlah << endl;
        }
    }
}

// Hitung total buku
void totalBuku() {
    int total = 0;
    for (int i = 0; i < jumlahBuku; i++) {
        total += perpustakaan[i].jumlah;
    }
    cout << "\nTotal semua buku di perpustakaan: " << total << endl;
}

// Terbitkan buku
void terbitkanBuku() {
    int no;
    cout << "\nMasukkan Nomor Akses buku yang ingin diterbitkan: ";
    cin >> no;
    for (int i = 0; i < jumlahBuku; i++) {
        if (perpustakaan[i].nomorAkses == no && perpustakaan[i].jumlah > 0) {
            perpustakaan[i].diterbitkan = true;
            perpustakaan[i].jumlah--;
            cout << "Buku berhasil diterbitkan.\n";
            return;
        }
    }
    cout << "Buku tidak ditemukan atau stok habis.\n";
}

// ==========================
// MENU UTAMA
// ==========================
int main() {
    int menuUtama;
    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Program Mahasiswa (No.1)\n";
        cout << "2. Program Mahasiswa 5 Data (No.2)\n";
        cout << "3. Program Mahasiswa 15 Data (No.3)\n";
        cout << "4. Program Perpustakaan (No.4 & 5)\n";
        cout << "0. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> menuUtama;

        switch (menuUtama) {
            case 1: inputMahasiswa1(); break;
            case 2: input5Mahasiswa(); break;
            case 3: input15Mahasiswa(); break;
            case 4: {
                int pilih;
                do {
                    cout << "\n=== MENU PERPUSTAKAAN ===\n";
                    cout << "1. Tampilkan informasi buku\n";
                    cout << "2. Tambahkan buku baru\n";
                    cout << "3. Tampilkan semua buku penulis tertentu\n";
                    cout << "4. Tampilkan jumlah buku dengan judul tertentu\n";
                    cout << "5. Tampilkan jumlah total buku di perpustakaan\n";
                    cout << "6. Terbitkan buku\n";
                    cout << "0. Kembali ke menu utama\n";
                    cout << "Pilih: ";
                    cin >> pilih;

                    switch (pilih) {
                        case 1: tampilkanBuku(); break;
                        case 2: tambahBuku(); break;
                        case 3: cariPenulis(); break;
                        case 4: cariJudul(); break;
                        case 5: totalBuku(); break;
                        case 6: terbitkanBuku(); break;
                    }
                } while (pilih != 0);
                break;
            }
        }
    } while (menuUtama != 0);

    cout << "\nProgram selesai.\n";
    return 0;
}
