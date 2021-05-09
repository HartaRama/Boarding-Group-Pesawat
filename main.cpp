#include <iostream>
#include <iomanip>

#include "queue.hpp"
#include "stack.hpp"

using namespace std;

int main() {
    string nama, opsi;
    int kepentingan, hapus;
    int jalan = 1, j;

    pointerQ newElementQ, pDelQ;
    pointerS newElementS, pDelL;

    string namaHari[7] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};

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

            do {
                j = 1;
                cout << "Nama: ";
                cin >> nama;

                cout << "Kepentingan: ";
                cin >> kepentingan;
                if (kepentingan < 1 || kepentingan > 5) {
                    j = 0;
                    cout << "Tolong masukkan pilihan dengan benar.";
                }
            } while (j != 1);
            cout << endl;
            createElementQ(newElementQ, nama, kepentingan);
            enQueue(q, newElementQ);
        } else if (opsi == "2") {
            jalan = 0;
        }
    }

    cout << "\n";
    cout << setw(66) << setfill('-');
    cout << "\n";
    cout << "| ";
    cout << setw(10) << setfill(' ') << "Hari";
    cout << " | ";
    cout << setw(25) << setfill(' ') << "Kepentingan";
    cout << " | " ;
    cout << setw(20) << setfill(' ') << "Nama";
    cout << " |" ;
    cout << "\n";
    cout << setw(66) << setfill('-');
    cout << "\n";

    while (!isEmpty(q)) {
        if (isEmpty(top)) {
            for (int i = 6; i >= 0; i--) {
                createElementS(newElementS, namaHari[i]);
                push(top, newElementS);
            }
        }
        cout << "| ";
        cout << setw(10) << setfill(' ') << pop(top, pDelL);
        cout << " | ";
        cout << setw(25) << setfill(' ') << headPenting(q);
        cout << " | " ;
        cout << setw(20) << setfill(' ') << dequeue(q, pDelQ);
        cout << " |" ;
        cout << endl;
    }
    cout << setw(65) << setfill('-') << "-";
}