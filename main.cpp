#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "queue.hpp"
#include "stack.hpp"
#include "fungsi.hpp"

using namespace std;

int main() {
    string opsi, kepentingan;
    int tanggal, bulan, tahun;
    int jalan = 1, j;
    int max = 0;

    pointerQ newElementQ, pDelQ;
    pointerS newElementS, pDelL;

    createQueue(q);
    createStack(top);

    cout << "\n";
    cout << "-----------------------------------" << endl;
    cout << "PROGRAM PENGATUR JADWAL PENERBANGAN" << endl;
    cout << "-----------------------------------\n" << endl;

    while (jalan != 0) {
        do {
            cout << "1. Tambah Data\n";
            cout << "2. Buat Jadwal\n";

            cout << "\nPilih Opsi: ";
            cin >> opsi;
        } while (opsi != "1" && opsi != "2");

        if (opsi == "1") {
            cout << "\nOpsi Tingkat Kepentingan:" << endl;
            cout << "1. Medis/Kesehatan" << endl;
            cout << "2. Militer/Polisi" << endl;
            cout << "3. Pemerintahan/Pejabat" << endl;
            cout << "4. Bisnis/Pedagang" << endl;
            cout << "5. Warga/Turis\n" << endl;

            string nama;
            cout << "Nama: ";
            cin >> ws;
            getline(cin, nama);

            j = 1;
            do {
                j = 1;
                if (j == 0) {
                    cout << "\n\nNama: " << nama << endl;
                }
                cout << "Kepentingan: ";
                cin >> kepentingan;
                if (kepentingan != "1" && kepentingan != "2" && kepentingan != "3" &&
                    kepentingan != "4" && kepentingan != "5") {
                    j = 0;
                    cout << "Tolong masukkan pilihan dengan benar.";
                }
            } while (j == 0);
            cout << endl;
            createElementQ(newElementQ, nama, kepentingan);
            enQueue(q, newElementQ);
        } else if (opsi == "2") {
            if (isEmpty(q)) {
                cout << endl << "Belum ada data yang dimasukkan." << endl;
            } else {
                jalan = 0;
            }
        }
    }
    tampilData();
}