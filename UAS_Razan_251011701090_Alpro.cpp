#include <iostream>
#include <iomanip>
using namespace std;

struct pegawaiData {
    string Nama;
    int JamKerja;
    int GajiPokok;
    int GajiLembur;
    int TotalGaji;
};

class HitungGaji {
public:
    const int GAJI_POKOK = 30000;
    const int LEMBUR_PER_JAM = 2000;
    const int JAM_STANDAR = 7;

    void prosesGaji(pegawaiData &p) {
        p.GajiPokok = GAJI_POKOK;

        if (p.JamKerja > JAM_STANDAR) {
            int lembur = p.JamKerja - JAM_STANDAR;
            p.GajiLembur = lembur * LEMBUR_PER_JAM;
        } else {
            p.GajiLembur = 0;
        }

        p.TotalGaji = p.GajiPokok + p.GajiLembur;
    }
};

int main() {
    char ulang;
    HitungGaji hitung;

    do {
        int jumlahPegawai;
        cout << "\nInput jumlah pegawai: ";
        cin >> jumlahPegawai;

        pegawaiData *data = new pegawaiData[jumlahPegawai];

        for (int i = 0; i < jumlahPegawai; i++) {
            cout << "\nData Pegawai ke-" << i + 1 << endl;
            cout << "Nama        : ";
            cin >> data[i].Nama;
            cout << "Jam Kerja   : ";
            cin >> data[i].JamKerja;

            hitung.prosesGaji(data[i]);
        }

        cout << "\n===============================================================\n";
        cout << "PT. Meriang Sejahtera\n";
        cout << "Tanggal : 12 Januari 2026\n";
        cout << "===============================================================\n";

        cout << left << setw(5) << "No"
             << setw(15) << "Nama"
             << setw(12) << "Gaji Pokok"
             << setw(12) << "Jam"
             << setw(15) << "Lembur"
             << setw(12) << "Total" << endl;

        cout << "===============================================================\n";

        int totalSemua = 0;

        for (int i = 0; i < jumlahPegawai; i++) {
            cout << left << setw(5) << i + 1
                 << setw(15) << data[i].Nama
                 << setw(12) << data[i].GajiPokok
                 << setw(12) << data[i].JamKerja
                 << setw(15) << data[i].GajiLembur
                 << setw(12) << data[i].TotalGaji << endl;

            totalSemua += data[i].TotalGaji;
        }

        cout << "===============================================================\n";
        cout << "Total Gaji Seluruh Pegawai : Rp " << totalSemua << endl;

        cout << "\nInput data lagi? (y/n): ";
        cin >> ulang;

        delete[] data;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nProgram telah selesai.\n";
    return 0;
}
