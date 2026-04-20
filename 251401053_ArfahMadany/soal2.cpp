#include <iostream>
using namespace std;

int main() {
    long long kode;
    int jamKeluar;

    cout << "Masukkan kode parkir digital (10 digit): ";
    cin >> kode;
    cout << "Masukkan jam keluar (format HHMM): ";
    cin >> jamKeluar;

    int jenis     = kode / 100000000;     
    int waktuMasuk = (kode / 10000) % 10000; 
    int lokasi    = kode % 10000;          

    string namaKendaraan = "";
    if (jenis == 10) namaKendaraan = "Mobil pribadi";
    else if (jenis == 20) namaKendaraan = "Motor";
    else if (jenis == 30) namaKendaraan = "Bus";
    else {
        cout << "Kode tidak valid!" << endl;
        return 0;
    }

    int jamM   = waktuMasuk / 100;
    int menitM = waktuMasuk % 100;
    int jamK   = jamKeluar / 100;
    int menitK = jamKeluar % 100;

    int totalMenitMasuk  = jamM * 60 + menitM;
    int totalMenitKeluar = jamK * 60 + menitK;
    int selisihMenit     = totalMenitKeluar - totalMenitMasuk;

    int durasi = (selisihMenit + 59) / 60;

    int biaya = 0;
    if (jenis == 10) { 
        if (durasi <= 1) biaya = 5000;
        else biaya = 5000 + (durasi - 1) * 3000;
    } else if (jenis == 20) { 
        if (durasi <= 1) biaya = 3000;
        else biaya = 3000 + (durasi - 1) * 2000;
    } else if (jenis == 30) { 
        if (durasi <= 1) biaya = 10000;
        else biaya = 10000 + (durasi - 1) * 7000;
    }

    cout << "\n--- Ringkasan Parkir ---" << endl;
    cout << "Jenis kendaraan: " << namaKendaraan << endl;
    cout << "Waktu masuk: " << jamM << ":" ;
    if (menitM < 10) cout << "0";
    cout << menitM << endl;
    cout << "Waktu keluar: " << jamK << ":";
    if (menitK < 10) cout << "0";
    cout << menitK << endl;
    cout << "Durasi parkir: " << durasi << " jam" << endl;
    cout << "Lokasi parkir: " << lokasi << endl;
    cout << "Total biaya: Rp " << biaya << endl;

    return 0;
}
/*
    LANGKAH-LANGKAH PENYELESAIAN:

    1. EKSTRAK INFORMASI DARI KODE
       - Kode 10 digit: XX HHMM LLLL
       - 2 digit pertama  = jenis kendaraan (bagi 10^8)
       - 4 digit tengah   = jam masuk HHMM (bagi 10^4, ambil 4 digit)
       - 4 digit terakhir = lokasi parkir (sisa % 10^4)

    2. TENTUKAN JENIS KENDARAAN
       - 10 = Mobil pribadi
       - 20 = Motor
       - 30 = Bus
       - Selain itu = tidak valid

    3. HITUNG DURASI PARKIR
       - Pisahkan jam & menit dari HHMM masuk  → jamMasuk  = HHMM / 100
       - Pisahkan jam & menit dari HHMM keluar → jamKlr    = HHMM / 100
       - Hitung total menit masuk  = jamM * 60 + menitM
       - Hitung total menit keluar = jamK * 60 + menitK
       - Selisih menit = menit keluar - menit masuk
       - Durasi (jam) = selisih menit / 60, dibulatkan ke atas
         → pakai: durasi = (selisihMenit + 59) / 60

    4. HITUNG BIAYA
       - Jika durasi == 1: biaya = tarif jam pertama
       - Jika durasi >  1: biaya = tarif pertama + (durasi-1) * tarif berikutnya

    5. TAMPILKAN OUTPUT
       - Jenis kendaraan, waktu masuk, waktu keluar,
         durasi, lokasi parkir, total biaya
    */
