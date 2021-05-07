#include <iostream>
#include "queue.hpp"
#include "stack.hpp"

using namespace std;

int main() {
    string nama;
    int kepentingan, opsi;
    int jalan = 1;

    pointerQ newElementQ;
    pointerL newElementL, pDel;

    string namaHari[7] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};

    createQueue(q);
    createStack(top);

    for (int i = 6; i >= 0; i--) {
        createElement(newElementL, namaHari[i]);
        push(top, newElementL);
    }

    cout << "\n";
    cout << "-----------------------------------" << endl;
    cout << "PROGRAM PENGATUR JADWAL PENERBANGAN" << endl;
    cout << "-----------------------------------\n" << endl;

    while (jalan != 0) {
        cout << "1. Tambah Data\n";
        cout << "2. Buat Jadwal\n";

        cout << "\nPilih Opsi: ";
        cin >> opsi;

        if (opsi == 1) {
            cout << "\nOpsi Tingkat Kepentingan:" << endl;
            cout << "1. Medis/Kesehatan" << endl;
            cout << "2. Militer/Polisi" << endl;
            cout << "3. Pemerintahan/Pejabat" << endl;
            cout << "4. Bisnis/Pedagang" << endl;
            cout << "5. Warga/Turis\n" << endl;

            cout << "Nama: ";
            cin >> nama;
            cout << "Kepentingan: ";
            cin >> kepentingan;
            cout << endl;

            createElement(newElementQ, nama, kepentingan);
            enQueue(q, newElementQ);
        } 
        else if (opsi == 2) {
            jalan = 0;
        }
    }

    pointerQ pHelp = q.head;
    if (!isEmpty(q)) {
        cout << "\n";
        do {
            cout << pop(top, pDel) <<":" << pHelp->data << ":" << pHelp->priority << endl;
            pHelp = pHelp->next;
        } while (pHelp != nullptr);
    }
}