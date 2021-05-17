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

    pembukaan();
    panduan();
    garisBatas();

    while (jalan != 0) {
        pilihOpsi(opsi);
        if (opsi == "1") {
            inputData();
        } else if (opsi == "2") {
            if (isEmpty(q)) {
                cout << "\n" << setw(30) << setfill(' ') << " ";
                cout << "Belum ada data yang dimasukkan!" << endl;
                garisBatas();
            } else {
                deleteData(q);
            }
        } else if (opsi == "3") {
            if (isEmpty(q)) {
                cout << "\n" << setw(30) << setfill(' ') << " ";
                cout << "Belum ada data yang dimasukkan!" << endl;
                garisBatas();
            } else {
                outputData();
            }
        } else if (opsi == "4") {
            panduan();
            garisBatas();
        } else if (opsi == "5") {
            jalan = 0;
        }
    }
}