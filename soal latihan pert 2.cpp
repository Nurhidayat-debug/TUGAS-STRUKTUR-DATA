#include <iostream>
#include <iomanip>  // untuk std::hex
using namespace std;

int main() {
    // 1. char x[12]
    char x1[12];
    unsigned int base1 = 0x1000;  // alamat awal (misal)
    unsigned int addr1 = base1 + (8 * sizeof(char));
    cout << "1. &x[8] = 0x" << hex << addr1 << endl;

    // 2. int x[15]
    int x2[15];
    unsigned int base2 = 0x1000 - (3 * sizeof(int)); // karena diketahui &x[3] = 0x1000
    unsigned int addr2 = base2 + (9 * sizeof(int));
    cout << "2. &x[9] = 0x" << hex << addr2 << endl;

    // 3. float x[5][8]
    float x3[5][8];
    unsigned int base3 = 0x1000; // &x[0][0] = 0x1000
    int i3 = 2, j3 = 4;
    unsigned int offset3 = (i3 * 8 + j3) * sizeof(float);
    unsigned int addr3 = base3 + offset3;
    cout << "3. &x[2][4] = 0x" << hex << addr3 << endl;

    // 4. long x[12][14]
    long x4[12][14];
    unsigned int base4 = 0x1000; // &x[0][0] = 0x1000
    int i4 = 2, j4 = 4;
    unsigned int offset4 = (i4 * 14 + j4) * sizeof(long);
    unsigned int addr4 = base4 + offset4;
    cout << "4. &x[2][4] = 0x" << hex << addr4 << endl;

    // 5. int x[2][3][5]
    int x5[2][3][5];
    unsigned int alamat_114 = 0x12EF;  // &x[1][1][4]
    int I = 1, J = 1, K = 4;
    int I2 = 0, J2 = 0, K2 = 3;
    int dimJ = 3, dimK = 5;

    // Offset elemen
    int offset_114 = (I * dimJ * dimK) + (J * dimK) + K;
    int offset_003 = (I2 * dimJ * dimK) + (J2 * dimK) + K2;
    int selisihOffset = offset_114 - offset_003;
    unsigned int addr5 = alamat_114 - (selisihOffset * sizeof(int));

    cout << "5. &x[0][0][3] = 0x" << hex << addr5 << endl;

    return 0;
}
