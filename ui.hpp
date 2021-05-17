void pembukaan() {
    cout << "\n";
    cout << setw(91) << setfill('-') << "-" << endl;

    cout << setw(28) << setfill(' ') << " ";
    cout << "PROGRAM PENGATUR JADWAL PENERBANGAN" << endl;

    cout << setw(40) << setfill(' ') << " ";
    cout << "PULAU KODOMO" << endl;

    cout << setw(91) << setfill('-') << "-" << endl;

    cout << "\n\n";

    cout << "\tProgram ini dibuat untuk mempermudah pengaturan jadwal penerbangan" << endl;
    cout << "\tdi Pulau Kodomo yang hanya melayani penerbangan sekali sehari." << endl;
}

void panduan() {
    cout << "\n\tPANDUAN" << endl;
    cout << "\n\tBerikut panduan penggunaan aplikasi.\n" << endl;
    cout << "\tInput Data       : Menginput data baru" << endl;
    cout << "\tHapus Data       : Menghapus data yang sudah diinput" << endl;
    cout << "\tTampilkan Jadwal : Menampilkan jadwal berdasarkan data yang sudah diinput" << endl;
    cout << "\tPanduan          : Menampilkan panduan" << endl;
    cout << "\tKeluar           : Menutup aplikasi" << endl;
}

void input() {
    cout << "\n\tINPUT DATA" << endl;
    cout << "\n\tOpsi Tingkat Kepentingan:" << endl;
    cout << "\t1. Medis/Kesehatan" << endl;
    cout << "\t2. Militer/Polisi" << endl;
    cout << "\t3. Pemerintahan/Pejabat" << endl;
    cout << "\t4. Bisnis/Pedagang" << endl;
    cout << "\t5. Warga/Turis\n" << endl;
}

void garisBatas() {
    cout << "\n\n";
    cout << setw(91) << setfill('=') << "=";
    cout << "\n\n";
}