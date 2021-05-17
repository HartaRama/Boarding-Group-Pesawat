#include "ui.hpp"

void pilihOpsi(string& opsi) {
    int i;
    do {
        i = 1;
        cout << "\n\tMENU UTAMA" << endl;
        cout << "\n\t1. Input Data\n";
        cout << "\t2. Hapus Data\n";
        cout << "\t3. Tampilkan Jadwal\n";
        cout << "\t4. Kosongkan Jadwal\n";
        cout << "\t5. Panduan\n";
        cout << "\t6. Keluar\n";
            
        cout << "\n\tPilih Opsi: ";
        cin >> opsi;

        if (opsi != "1" && opsi != "2" && opsi != "3" && opsi != "4" && opsi != "5" && opsi != "6") {
            garisBatas();
            cout << "\n" << setw(17) << setfill(' ') << " ";
            cout << "Tolong masukkan opsi sesuai dengan pilihan yang tersedia!" << endl;
            i = 0;
            garisBatas();
        }

        if (i != 0) {
            garisBatas();
        }
    } while (opsi != "1" && opsi != "2" && opsi != "3" && opsi != "4" && opsi != "5" && opsi != "6");
}

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
            } else if (bulan == 2 && tanggal == 30) {
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
        bulan = 1;
    }
}

void inputData() {
    string opsi, kepentingan, kode;
    int jumlah, panjang;
    int jalan = 1, j;

    pointerQ newElementQ, pDelQ;

    input();

    string nama;
    cout << "\tNama: ";
    cin >> ws;
    getline(cin, nama);

    j = 1;
    do {
        if (j == 0) {
            input();
            cout << "\n\tNama: " << nama << endl;
        }
        j = 1;
        cout << "\tKepentingan: ";
        cin >> kepentingan;
        if (kepentingan != "1" && kepentingan != "2" && kepentingan != "3" &&
            kepentingan != "4" && kepentingan != "5") {
            j = 0;
            garisBatas();
            cout << "\n" << setw(17) << setfill(' ') << " ";
            cout << "Tolong masukkan opsi sesuai dengan pilihan yang tersedia!" << endl;
            garisBatas();
        }
    } while (j == 0);

    j = 1;
    do {
        if (j == 0) {
            input();
            cout << "\n\tNama: " << nama << endl;
            cout << "\tKepentingan: " << kepentingan << endl;
        }
        j = 1;
        cout << "\tKode: ";
        cin >> kode;
        panjang = (59-kode.length())/2;
        if (panjang % 2 == 1) {
            panjang += 1;
        }
        pointerQ pHelp = q.head;
        while (pHelp != nullptr) {
            if (pHelp->kode == kode) {
                garisBatas();
                cout << "\n";
                cout << setw(panjang) << setfill(' ') << " ";
                cout << "Kode " << kode << " sudah digunakan data lain.\n";
                garisBatas();
                j = 0;
                break;
            }
            pHelp = pHelp->next;
        }
    } while (j == 0);

    j = 1;
    do {
        if (j == 0) {
            input();
            cout << "\n\tNama: " << nama << endl;
            cout << "\tKepentingan: " << kepentingan << endl;
            cout << "\tKode: " << kode << endl;
        }
        j = 1;
        cout << "\tJumlah Penumpang: ";
        cin >> jumlah;
        if (jumlah > 30) {
            j = 0;
            garisBatas();
            cout << "\n" << setw(25) << setfill(' ') << " ";
            cout << "Pesawat hanya bisa menampung 30 penumpang!" << endl;
            garisBatas();
        } else if (jumlah < 1) {
            j = 0;
            garisBatas();
            cout << "\n" << setw(23) << setfill(' ') << " ";
            cout << "Setidaknya harus ada satu penumpang terdaftar!" << endl;
            garisBatas();
        }
    } while (j == 0);

    createElementQ(newElementQ, nama, kepentingan, kode, jumlah);
    enQueue(q, newElementQ);

    panjang = (55-kode.length())/2;
    if (panjang % 2 == 1) {
        panjang += 1;
    }
    garisBatas();
    cout << endl;
    cout << setw(panjang) << setfill(' ') << " ";
    cout << "Data dengan kode " << kode << " sudah ditambahkan.";
    cout << endl;
    garisBatas();
}

void outputData() {
    string namaHari[7];
    int kepentingan, kapasitasAwal;
    int kapasitas = 0;
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

    cout << "\n\tJADWAL PENERBANGAN" << endl;

    cout << "\n\t";
    cout << setw(49 + maxOpsi + maxNama) << setfill('-');
    cout << "\n";
    cout << "\t| ";
    cout << setw(6) << setfill(' ') << "Hari";
    cout << " | ";
    cout << setw(10) << setfill(' ') << "Tanggal";
    cout << " | ";
    cout << setw(maxOpsi) << setfill(' ') << "Kepentingan";
    cout << " | " ;
    cout << setw(maxNama) << setfill(' ') << "Nama";
    cout << " | " ;
    cout << "Kode";
    cout << " | " ;
    cout << "Penumpang";
    cout << " |" ;
    cout << "\n\t";
    cout << setw(49 + maxOpsi + maxNama) << setfill('-');
    cout << "\n";

    pHelpQ = q.head;
    while (pHelpQ != nullptr) {
        if (isEmpty(top)) {
            for (int i = 6; i >= 0; i--) {
                createElementS(newElementS, namaHari[i]);
                push(top, newElementS);
            }
        }

        kapasitas += pHelpQ->jumlah;
        kapasitasAwal = kapasitas - pHelpQ->jumlah;
        if (kapasitasAwal == 0) {
            cout << "\t| ";
            cout << setw(6) << setfill(' ') << peek(top);
            cout << " | ";
            cout << setw(2) << setfill('0') << tanggal << "-";
            cout << setw(2) << setfill('0') << bulan << "-" << tahun;
            cout << " | ";
            cout << setw(maxOpsi) << setfill(' ') << headKepentingan(pHelpQ);
            cout << " | " ;
            cout << setw(maxNama) << setfill(' ') << headNama(pHelpQ);
            cout << " | " ;
            cout << setw(4) << setfill(' ') << headKode(pHelpQ);
            cout << " | " ;
            cout << setw(9) << setfill(' ') << headJumlah(pHelpQ);
            cout << " |" ;
            cout << endl;

            sistemTanggal(tanggal, bulan, tahun);
            pHelpQ = pHelpQ->next;
        } else if (kapasitasAwal != 0 && kapasitas <= 30) {
            cout << "\t| ";
            cout << setw(6) << setfill(' ') << " ";
            cout << " | ";
            cout << setw(10) << setfill(' ') << " ";
            cout << " | ";
            cout << setw(maxOpsi) << setfill(' ') << headKepentingan(pHelpQ);
            cout << " | " ;
            cout << setw(maxNama) << setfill(' ') << headNama(pHelpQ);
            cout << " | " ;
            cout << setw(4) << setfill(' ') << headKode(pHelpQ);
            cout << " | " ;
            cout << setw(9) << setfill(' ') << headJumlah(pHelpQ);
            cout << " |" ;
            cout << endl;

            pHelpQ = pHelpQ->next;
        } else {
            kapasitas = 0;
            kapasitas += pHelpQ->jumlah;
            pop(top, pDelL);
            cout << "\t| ";
            cout << setw(6) << setfill(' ') << peek(top);
            cout << " | ";
            cout << setw(2) << setfill('0') << tanggal << "-";
            cout << setw(2) << setfill('0') << bulan << "-" << tahun;
            cout << " | ";
            cout << setw(maxOpsi) << setfill(' ') << headKepentingan(pHelpQ);
            cout << " | " ;
            cout << setw(maxNama) << setfill(' ') << headNama(pHelpQ);
            cout << " | " ;
            cout << setw(4) << setfill(' ') << headKode(pHelpQ);
            cout << " | " ;
            cout << setw(9) << setfill(' ') << headJumlah(pHelpQ);
            cout << " |" ;
            cout << endl;

            sistemTanggal(tanggal, bulan, tahun);
            pHelpQ = pHelpQ->next;
        }
    }
    cout << "\t";
    cout << setw(48 + maxOpsi + maxNama) << setfill('-') << "-";
    cout << endl;
    garisBatas();
}

void deleteData(queue& q) {
    int ada = 1, panjang;
    string cari;
    pointerQ delElement, prevElement;

    cout << "\n\tHAPUS DATA" << endl;
    cout << "\n\tKode data yang akan dihapus: ";
    cin >> cari;

    panjang = (69-cari.length())/2;
    if (panjang % 2 == 1) {
        panjang += 1;
    }
    if (isEmpty(q)) {
        delElement = nullptr;
    } else if (q.head->next == nullptr && q.head->kode == cari) {
        delElement = q.head;
        q.head = nullptr;
        q.tail = nullptr;
    } else if (q.head->next == nullptr && q.head->kode != cari) {
        garisBatas();
        cout << "\n";
        cout << setw(panjang) << setfill(' ') << " ";
        cout << "Kode " << cari << " tidak ditemukan!" << endl;
        garisBatas();
        ada = 0;
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
                garisBatas();
                cout << "\n";
                cout << setw(panjang) << setfill(' ') << " ";
                cout << "Kode " << cari << " tidak ditemukan!" << endl;
                garisBatas();
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

    panjang = (59-cari.length())/2;
    if (panjang % 2 == 1) {
        panjang += 1;
    }
    if (ada != 0) {
        garisBatas();
        cout << endl;
        cout << setw(panjang) << setfill(' ') << " ";
        cout << "Data dengan kode " << cari << " sudah dihapus.";
        cout << endl;
        garisBatas();
    }
}

void kosongkan(queue& q) {
    pointerQ pHelp, delElement;

    pHelp = q.head;
    while (!isEmpty(q)) {
        deQueue(q, delElement);
    }
        
    cout << "\n" << setw(33) << setfill(' ') << " ";
    cout << "Jadwal sudah dikosongkan!" << endl;
    garisBatas();
}