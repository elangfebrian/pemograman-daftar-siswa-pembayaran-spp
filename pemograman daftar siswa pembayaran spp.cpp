#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan data siswa
struct Siswa {
    string nama;
    string kelas;
    bool statusPembayaran; // true jika sudah bayar, false jika belum bayar
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "===== Aplikasi Daftar Siswa Pembayaran SPP =====" << endl;
    cout << "1. Tambah Data Siswa" << endl;
    cout << "2. Lihat Daftar Siswa" << endl;
    cout << "3. Perbarui Status Pembayaran" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu: ";
}

// Fungsi untuk menampilkan status pembayaran
string cekStatusPembayaran(bool status) {
    return status ? "Sudah Bayar" : "Belum Bayar";
}

int main() {
    const int MAX_SISWA = 100; // Maksimal jumlah siswa
    Siswa daftarSiswa[MAX_SISWA];
    int jumlahSiswa = 0;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer input

        switch (pilihan) {
        case 1: {
            if (jumlahSiswa >= MAX_SISWA) {
                cout << "Daftar siswa sudah penuh!" << endl;
            } else {
                Siswa siswaBaru;
                cout << "Masukkan nama siswa: ";
                getline(cin, siswaBaru.nama);
                cout << "Masukkan kelas siswa: ";
                getline(cin, siswaBaru.kelas);
                siswaBaru.statusPembayaran = false; // Default belum bayar
                daftarSiswa[jumlahSiswa] = siswaBaru;
                jumlahSiswa++;
                cout << "Data siswa berhasil ditambahkan!" << endl;
            }
            break;
        }
        case 2: {
            if (jumlahSiswa == 0) {
                cout << "Belum ada data siswa." << endl;
            } else {
                cout << "===== Daftar Siswa =====" << endl;
                for (int i = 0; i < jumlahSiswa; i++) {
                    cout << i + 1 << ". Nama: " << daftarSiswa[i].nama
                         << ", Kelas: " << daftarSiswa[i].kelas
                         << ", Status: " << cekStatusPembayaran(daftarSiswa[i].statusPembayaran)
                         << endl;
                }
            }
            break;
        }
        case 3: {
            if (jumlahSiswa == 0) {
                cout << "Belum ada data siswa." << endl;
            } else {
                int nomor;
                cout << "Masukkan nomor siswa yang ingin diperbarui statusnya: ";
                cin >> nomor;

                if (nomor < 1 || nomor > jumlahSiswa) {
                    cout << "Nomor siswa tidak valid!" << endl;
                } else {
                    daftarSiswa[nomor - 1].statusPembayaran = true;
                    cout << "Status pembayaran berhasil diperbarui!" << endl;
                }
            }
            break;
        }
        case 4:
            cout << "Keluar dari program. Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;
    } while (pilihan != 4);

    return 0;
}

