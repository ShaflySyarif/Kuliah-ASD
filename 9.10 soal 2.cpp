//insertion sort straight

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Pegawai {
    string NIP;
    string nama;
};

Pegawai *Data;

int compareStrings(string str1, string str2) {
    return str1.compare(str2);
}

void StraightInsertSort(int MAX, bool urutkanBerdasarkanNIP, bool urutkanSecaraDescending)
{
    int i, j;
    Pegawai x;
    int comparisons = 0;
    int shifts = 0;

    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;

        while (j >= 0 && ((urutkanBerdasarkanNIP && ((urutkanSecaraDescending && compareStrings(x.NIP, Data[j].NIP) > 0) || (!urutkanSecaraDescending && compareStrings(x.NIP, Data[j].NIP) < 0)))
            || (!urutkanBerdasarkanNIP && ((urutkanSecaraDescending && compareStrings(x.nama, Data[j].nama) > 0) || (!urutkanSecaraDescending && compareStrings(x.nama, Data[j].nama) < 0))))) {
            Data[j + 1] = Data[j];
            j--;
            comparisons++;
        }

        Data[j + 1] = x;
        shifts++;

        cout << "Iterasi " << i << ": "<<endl;
        for (int k = 0; k < MAX; k++) {
            cout << "NIP: " << Data[k].NIP << ", Nama: " << Data[k].nama << endl;
        }
        cout << endl;
    }

    cout << "Total perbandingan: " << comparisons << endl;
    cout << "Total pergeseran: " << shifts << endl;
}

int main()
{
    int i;
    int jumlahPegawaiBaru;

    srand(0);

    cout << "Jumlah pegawai yang ingin ditambahkan (0-5): ";
    cin >> jumlahPegawaiBaru;

    int MAX = 3 + jumlahPegawaiBaru;
    Data = new Pegawai[MAX];

    // Data pegawai default
    Data[0].NIP = "10002";
    Data[0].nama = "Andi";

    Data[1].NIP = "10009";
    Data[1].nama = "Budi";

    Data[2].NIP = "10001";
    Data[2].nama = "Deni";

    // Input data pegawai baru
    for (i = 3; i < MAX; i++) {
        cout << "** Pastikan Nama dimulai dari huruf kapital dan NIP sebanyak 5 digit **" << endl;
        cout << "Masukkan NIP pegawai ke-" << i+1 << ": ";
        cin >> Data[i].NIP;
        cout << "Masukkan Nama pegawai ke-" << i+1 << ": ";
        cin >> Data[i].nama;
    }

    cout << "-- DATA SEBELUM PENGURUTAN --" << endl;
    for (i = 0; i < MAX; i++) {
        cout << "NIP: " << Data[i].NIP << ", Nama: " << Data[i].nama << endl;
    }
    cout << endl;

    cout << "-- DATA SETELAH PENGURUTAN DENGAN METODE INSERTION SORT --" << endl;
    cout << "Berdasarkan NIP (Ascending):" << endl;
    StraightInsertSort(MAX, true, false);
    cout << "Berdasarkan Nama (Ascending):" << endl;
    StraightInsertSort(MAX, false, false);

    delete[] Data;
    return 0;
}
