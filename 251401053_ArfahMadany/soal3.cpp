#include <iostream>
using namespace std;

int main() {
    long long kode;
    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;

    int hari     = kode / 1000000;
    int loyalitas = (kode / 10000) % 100;
    int belanja  = kode % 10000;

    if (hari < 1 || hari > 3) {
        cout << "Kode hari tidak valid!" << endl;
        return 0;
    }
    if (loyalitas < 1 || loyalitas > 3) {
        cout << "Kode loyalitas tidak valid!" << endl;
        return 0;
    }

    string namaHari = "";
    if (hari == 1) namaHari = "Hari kerja (Senin-Jumat)";
    else if (hari == 2) namaHari = "Akhir pekan (Sabtu-Minggu)";
    else namaHari = "Hari libur nasional";

    string namaPelanggan = "";
    if (loyalitas == 1) namaPelanggan = "Biasa";
    else if (loyalitas == 2) namaPelanggan = "Member Silver";
    else namaPelanggan = "Member Gold";

    int poinPer = 0;
    if (hari == 1) {
        if (loyalitas == 1) poinPer = 1;
        else if (loyalitas == 2) poinPer = 2;
        else poinPer = 3;
    } else if (hari == 2) {
        if (loyalitas == 1) poinPer = 2;
        else if (loyalitas == 2) poinPer = 3;
        else poinPer = 5;
    } else {
        if (loyalitas == 1) poinPer = 3;
        else if (loyalitas == 2) poinPer = 5;
        else poinPer = 7;
    }

    int totalPoin = belanja * poinPer;
    long long totalBelanja = (long long)belanja * 100000;

    cout << "Jenis hari      : " << namaHari << endl;
    cout << "Jenis pelanggan : " << namaPelanggan << endl;
    cout << "Jumlah belanja  : Rp " << totalBelanja << endl;
    cout << "Total poin      : " << totalPoin << " poin" << endl;

    return 0;
}

/*
    LANGKAH-LANGKAH PENYELESAIAN:

    1. EKSTRAK KODE TRANSAKSI
       - Kode 8 digit: HH LL BBBB
       - 2 digit pertama (HH) = kode jenis hari        → kode / 1000000
       - 2 digit tengah  (LL) = kode loyalitas          → (kode / 10000) % 100
       - 4 digit terakhir (BBBB) = jumlah belanja x100rb → kode % 10000

    2. VALIDASI KODE
       - Jenis hari   valid: 01, 02, 03
       - Loyalitas    valid: 01, 02, 03
       - Jika salah satu tidak valid → tampilkan error, hentikan program

    3. TENTUKAN NAMA JENIS HARI & PELANGGAN
       - 01 = Hari kerja    | 01 = Biasa
       - 02 = Akhir pekan   | 02 = Silver
       - 03 = Hari libur    | 03 = Gold

    4. TENTUKAN POIN PER Rp100.000
       - Kombinasi jenis hari × loyalitas → lihat tabel poin
         Hari kerja : Biasa=1, Silver=2, Gold=3
         Akhir pekan: Biasa=2, Silver=3, Gold=5
         Libur nas  : Biasa=3, Silver=5, Gold=7

    5. HITUNG TOTAL POIN
       - totalPoin = jumlahBelanja × poinPer100rb

    6. HITUNG TOTAL BELANJA RUPIAH
       - totalBelanja = jumlahBelanja × 100000

    7. TAMPILKAN OUTPUT
       - Jenis hari, jenis pelanggan, jumlah belanja (Rp), total poin
    */
