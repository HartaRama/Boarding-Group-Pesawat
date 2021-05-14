#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "queue.hpp"
#include "stack.hpp"
#include "fungsi.hpp"

using namespace std;

int main() {
    string opsi, cari;
    int jalan = 1;

    pointerQ newElementQ, pDelQ;

    createQueue(q);
    createStack(top);

    cout << "\n";
    cout << "-----------------------------------" << endl;
    cout << "PROGRAM PENGATUR JADWAL PENERBANGAN" << endl;
    cout << "-----------------------------------\n" << endl;

    while (jalan != 0) {
        do {
            cout << "1. Tambah Data\n";
            cout << "2. Hapus Data\n";
            cout << "3. Tampilkan Jadwal\n";
            cout << "4. Tutup Aplikasi\n";

            cout << "\nPilih Opsi: ";
            cin >> opsi;
        } while (opsi != "1" && opsi != "2" && opsi != "3" && opsi != "4");

        if (opsi == "1") {
            inputData();
        } else if (opsi == "2") {
            cout << "Kode data: ";
            cin >> cari;
            deleteData(q, cari);
        } else if (opsi == "3") {
            if (isEmpty(q)) {
                cout << endl << "Belum ada data yang dimasukkan." << endl;
            } else {
                outputData();
            }
        } else if (opsi == "4") {
            jalan = 0;
        }
    }
}