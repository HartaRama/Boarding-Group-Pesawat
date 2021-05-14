#include <iostream>
#include <ctime>

using namespace std;

void sistemTanggal(int& tanggal, int& bulan, int& tahun) {
    tanggal += 1;

    if (tahun % 4 != 0) {
        if (bulan <= 7 && bulan % 2 == 1) {
            if (tanggal == 32) {
                bulan += 1;
                tanggal = 1;
            }
        } else if (bulan >= 8 && bulan % 2 == 0) {
            if (tanggal == 32) {
                bulan += 1;
                tanggal = 1;
            }
        } else if (bulan <= 7 && bulan % 2 == 0) {
            if (bulan != 2 && tanggal == 31) {
                bulan += 1;
                tanggal = 1;
            } else if (bulan == 2 && tanggal == 29) {
                bulan += 1;
                tanggal = 1;
            }
        } else if (bulan >= 8 && bulan % 2 == 1) {
            if (tanggal == 31) {
                bulan += 1;
                tanggal = 1;
            }
        }
    } else if (tahun % 4 == 0) {
        if (bulan <= 7 && bulan % 2 == 1) {
            if (tanggal == 32) {
                bulan += 1;
                tanggal = 1;
            }
        } else if (bulan >= 8 && bulan % 2 == 0) {
            if (tanggal == 32) {
                bulan += 1;
                tanggal = 1;
            }
        } else if (bulan <= 7 && bulan % 2 == 0) {
            if (bulan != 2 && tanggal == 31) {
                bulan += 1;
                tanggal = 1;
            } else if (bulan == 2 && tanggal == 29) {
                bulan += 1;
                tanggal = 1;
            }
        } else if (bulan >= 8 && bulan % 2 == 1) {
            if (tanggal == 31) {
                bulan += 1;
                tanggal = 1;
            }
        }
    }

    if (bulan > 12) {
        tahun += 1;
    }
}

void inputData() {
    string opsi, kepentingan, kode;
    int jalan = 1, j;

    pointerQ newElementQ, pDelQ;

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
        if (j == 0) {
            cout << "\n\nNama: " << nama << endl;
        }
        j = 1;
        cout << "Kepentingan: ";
        cin >> kepentingan;
        if (kepentingan != "1" && kepentingan != "2" && kepentingan != "3" &&
            kepentingan != "4" && kepentingan != "5") {
            j = 0;
            cout << "Tolong masukkan pilihan dengan benar.";
        }
    } while (j == 0);
    cout << "Kode: ";
    cin >> kode;
    cout << endl;

    createElementQ(newElementQ, nama, kepentingan, kode);
    enQueue(q, newElementQ);
}

void outputData() {
    string namaHari[7];
    int kepentingan;
    int hari, tanggal, bulan, tahun;
    int jalan = 1, j;
    int maxNama = 0;
    int maxOpsi = 0;

    pointerQ newElementQ, pDelQ, pHelpQ;
    pointerS newElementS, pDelL, pHelpS;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    hari = ltm->tm_wday;
    tanggal = ltm->tm_mday;
    bulan = 1 + ltm->tm_mon;
    tahun = 1900 + ltm->tm_year;

    string listHari[7] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
    if (hari == 1) {
        namaHari[0] = listHari[0]; namaHari[1] = listHari[1]; namaHari[2] = listHari[2];
        namaHari[3] = listHari[3]; namaHari[4] = listHari[4]; namaHari[5] = listHari[5];
        namaHari[6] = listHari[6];
    } else if (hari == 2) {
        namaHari[0] = listHari[1]; namaHari[1] = listHari[2]; namaHari[2] = listHari[3];
        namaHari[3] = listHari[4]; namaHari[4] = listHari[5]; namaHari[5] = listHari[6];
        namaHari[6] = listHari[0];
    } else if (hari == 3) {
        namaHari[0] = listHari[2]; namaHari[1] = listHari[3]; namaHari[2] = listHari[4];
        namaHari[3] = listHari[5]; namaHari[4] = listHari[6]; namaHari[5] = listHari[0];
        namaHari[6] = listHari[1];
    } else if (hari == 4) {
        namaHari[0] = listHari[3]; namaHari[1] = listHari[4]; namaHari[2] = listHari[5];
        namaHari[3] = listHari[6]; namaHari[4] = listHari[0]; namaHari[5] = listHari[1];
        namaHari[6] = listHari[2];
    } else if (hari == 5) {
        namaHari[0] = listHari[4]; namaHari[1] = listHari[5]; namaHari[2] = listHari[6];
        namaHari[3] = listHari[0]; namaHari[4] = listHari[1]; namaHari[5] = listHari[2];
        namaHari[6] = listHari[3];
    } else if (hari == 6) {
        namaHari[0] = listHari[5]; namaHari[1] = listHari[6]; namaHari[2] = listHari[0];
        namaHari[3] = listHari[1]; namaHari[4] = listHari[2]; namaHari[5] = listHari[3];
        namaHari[6] = listHari[4];
    } else if (hari == 0) {
        namaHari[0] = listHari[6]; namaHari[1] = listHari[0]; namaHari[2] = listHari[1];
        namaHari[3] = listHari[2]; namaHari[4] = listHari[3]; namaHari[5] = listHari[4];
        namaHari[6] = listHari[5];
    }

    for (int i = 6; i >= 0; i--) {
        createElementS(newElementS, namaHari[i]);
        push(top, newElementS);
    }

    pHelpQ = q.head;
    while (pHelpQ != nullptr) {
        if (pHelpQ->nama.length() > maxNama) {
            maxNama = pHelpQ->nama.length();
            if (maxNama < 4) {
                maxNama += (4 - maxNama);
            }
        }
        pHelpQ = pHelpQ->next;
    }

    pHelpQ = q.head;
    while (pHelpQ != nullptr) {
        if (pHelpQ->prioritas == "1" && maxOpsi < 15) {
            maxOpsi = 15;
        } else if (pHelpQ->prioritas == "2" && maxOpsi < 14) {
            maxOpsi = 14;
        } else if (pHelpQ->prioritas == "3" && maxOpsi < 20) {
            maxOpsi = 20;
        } else if (pHelpQ->prioritas == "4" && maxOpsi < 15) {
            maxOpsi = 15;
        } else if (pHelpQ->prioritas == "5" && maxOpsi < 11) {
            maxOpsi = 11;
        }
        pHelpQ = pHelpQ->next;
    }

    cout << "\n";
    cout << setw(37 + maxOpsi + maxNama) << setfill('-');
    cout << "\n";
    cout << "| ";
    cout << setw(6) << setfill(' ') << "Hari";
    cout << " | ";
    cout << setw(10) << setfill(' ') << "Tanggal";
    cout << " | ";
    cout << setw(maxOpsi) << setfill(' ') << "Kepentingan";
    cout << " | " ;
    cout << setw(maxNama) << setfill(' ') << "Nama";
    cout << " | " ;
    cout << "Kode";
    cout << " |" ;
    cout << "\n";
    cout << setw(37 + maxOpsi + maxNama) << setfill('-');
    cout << "\n";

    pHelpQ = q.head;
    while (pHelpQ != nullptr) {
        if (isEmpty(top)) {
            for (int i = 6; i >= 0; i--) {
                createElementS(newElementS, namaHari[i]);
                push(top, newElementS);
            }
        }
        cout << "| ";
        cout << setw(6) << setfill(' ') << pop(top, pDelL);
        cout << " | ";
        cout << setw(2) << setfill('0') << tanggal << "-";
        cout << setw(2) << setfill('0') << bulan << "-" << tahun;
        cout << " | ";
        cout << setw(maxOpsi) << setfill(' ') << headKepentingan(pHelpQ);
        cout << " | " ;
        cout << setw(maxNama) << setfill(' ') << headNama(pHelpQ);
        cout << " | " ;
        cout << setw(4) << setfill(' ') << headKode(pHelpQ);
        cout << " |" ;
        cout << endl;

        sistemTanggal(tanggal, bulan, tahun);
        pHelpQ = pHelpQ->next;
    }
    cout << setw(36 + maxOpsi + maxNama) << setfill('-') << "-";
    cout << endl;
}

void deleteData(queue& q, string cari) {
    int ada = 1;
    pointerQ delElement, prevElement;

    if (isEmpty(q)) {
        delElement = nullptr;
    } else if (q.head->next == nullptr && q.head->kode == cari) {
        delElement = q.head;
        q.head = nullptr;
        q.tail = nullptr;
    } else if (q.head->next != nullptr && q.head->kode == cari) {
        delElement = q.head;
        q.head = q.head->next;
        delElement->next = nullptr;
    } else {
        delElement = q.head;
        while (delElement->next != nullptr) {
            if (delElement->kode == cari) {
                break;
            }
            prevElement = delElement;
            delElement = delElement->next;
            if (delElement->kode != cari && delElement->next == nullptr) {
                cout << "Kode tidak ditemukan.\n";
                ada = 0;
            }
        } 
        if (ada == 1) {
            if (prevElement != nullptr && delElement->next != nullptr) {
                prevElement->next = delElement->next;
                delElement->next = nullptr;
            } else if (prevElement != nullptr && delElement->next == nullptr) {
                prevElement->next = nullptr;
                q.tail = prevElement;
            }
        }
    }
}