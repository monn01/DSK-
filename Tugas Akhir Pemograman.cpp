#include <iostream>
#include <fstream>
using namespace std;

struct Member {
    char nama[50];
    char noID[20];
    char email[50];
    char noTelp[15];
    char alamat[100];
    int bulanKeanggotaan; // Bulan bergabung
};

Member daftarMember[1000];
int jumlahMember = 0;
const int kapasitasGym = 1000;

void bacaDataDariFile() {
    ifstream file("dataMemberGym.txt");
    if (file.is_open()) {
        jumlahMember = 0;
        while (!file.eof() && jumlahMember < kapasitasGym) {
            file.getline(daftarMember[jumlahMember].nama, 50);
            file.getline(daftarMember[jumlahMember].noID, 20);
            file.getline(daftarMember[jumlahMember].email, 50);
            file.getline(daftarMember[jumlahMember].noTelp, 15);
            file.getline(daftarMember[jumlahMember].alamat, 100);
            file >> daftarMember[jumlahMember].bulanKeanggotaan;
            file.ignore();
            jumlahMember++;
        }
        file.close();
    }
}

void simpanDataKeFile() {
    ofstream file("dataMemberGym.txt");
    if (file.is_open()) {
        for (int i = 0; i < jumlahMember; i++) {
            file << daftarMember[i].nama << endl;
            file << daftarMember[i].noID << endl;
            file << daftarMember[i].email << endl;
            file << daftarMember[i].noTelp << endl;
            file << daftarMember[i].alamat << endl;
            file << daftarMember[i].bulanKeanggotaan << endl;
        }
        file.close();
    } else {
        cout << "Gagal membuka file untuk menyimpan data.\n";
    }
}

void daftarMemberBaru() {
    int jumlahBaru;
    cout << "Masukkan jumlah member baru: ";
    cin >> jumlahBaru;
    cin.ignore();
    for (int i = 0; i < jumlahBaru; i++) {
        if (jumlahMember >= kapasitasGym) {
            cout << "\nKapasitas gym penuh. Tidak dapat menambahkan member lagi.\n";
            break;
        }
        cout << "\nMember Ke-" << (jumlahMember + 1) << ":\n";
        cout << "Masukkan nama: ";
        cin.getline(daftarMember[jumlahMember].nama, 50);
        cout << "Masukkan No ID: ";
        cin.getline(daftarMember[jumlahMember].noID, 20);
        cout << "Masukkan email: ";
        cin.getline(daftarMember[jumlahMember].email, 50);
        cout << "Masukkan No Telp: ";
        cin.getline(daftarMember[jumlahMember].noTelp, 15);
        cout << "Masukkan alamat: ";
        cin.getline(daftarMember[jumlahMember].alamat, 100);
        daftarMember[jumlahMember].bulanKeanggotaan = 1; // Bulan pertama bergabung
        cout << "Keanggotaan dimulai dari bulan ke-1.\n";
        jumlahMember++;
    }
    cout << "\nData member berhasil disimpan.\n";
}

void tampilkanDataMember() {
    if (jumlahMember == 0) {
        cout << "\nTidak ada data member.\n";
        return;
    }
    for (int i = 0; i < jumlahMember; i++) {
        cout << "\n===== Member Ke-" << (i + 1) << " =====\n";
        cout << "Nama           : " << daftarMember[i].nama << endl;
        cout << "No ID          : " << daftarMember[i].noID << endl;
        cout << "Email          : " << daftarMember[i].email << endl;
        cout << "No Telp        : " << daftarMember[i].noTelp << endl;
        cout << "Alamat         : " << daftarMember[i].alamat << endl;
        cout << "Bulan Keanggotaan: " << daftarMember[i].bulanKeanggotaan << endl;
    }
}

void tampilkanInfoGym() {
    int memberAktif = jumlahMember;
    int kapasitasTersedia = kapasitasGym - memberAktif;
    cout << "\nTotal kapasitas gym: " << kapasitasGym << endl;
    cout << "Member aktif       : " << memberAktif << endl;
    cout << "Kapasitas tersisa  : " << kapasitasTersedia << endl;
}

int main() {
    bacaDataDariFile();
    int pilihan;
    do {
        cout << "\n==========================================\n";
        cout << "PENGELOLAAN DATA MEMBER GYM\n";
        cout << "1. Daftar Member Baru\n";
        cout << "2. Tampilkan Data Member\n";
        cout << "3. Informasi Kapasitas Gym\n";
        cout << "4. Simpan & Keluar\n";
        cout << "==========================================\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                daftarMemberBaru();
                break;
            case 2:
                tampilkanDataMember();
                break;
            case 3:
                tampilkanInfoGym();
                break;
            case 4:
                simpanDataKeFile();
                cout << "\nTerima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);
    return 0;
}

