#include <iostream>
using namespace std;

int main() {
    long long kartu;
    cout << "Masukkan nomor kartu digital: ";
    cin >> kartu;

    long long temp = kartu;
    int digit, total = 0, hitung = 0;

    int panjang = 0;
    long long depan = kartu;

    while (depan >= 100) {
        depan = depan / 10;
        panjang++;
    }
    panjang += 2;

    int awal = depan;

    int validFormat = 0;
    string jenis = "";

    if (panjang == 14 && awal == 65) {
        validFormat = 1;
        jenis = "NUSANTARA";
    }
    else if (panjang == 16 && (awal == 77 || awal == 78)) {
        validFormat = 1;
        jenis = "GARUDA";
    }
    else if (panjang == 15 && awal == 91) {
        validFormat = 1;
        jenis = "MERDEKA";
    }

    if (validFormat == 0) {
        cout << "Tipe kartu: TIDAK DIKETAHUI" << endl;
        cout << "Nomor kartu TIDAK VALID." << endl;
        return 0;
    }

    cout << "Tipe kartu: " << jenis << endl;

    while (temp > 0) {
        digit = temp % 10;

        if (hitung % 2 == 1) {
            digit = digit * 2;
            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }

        total += digit;
        temp = temp / 10;
        hitung++;
    }

    if (total % 10 == 0) {
        cout << "Nomor kartu VALID." << endl;
    } else {
        cout << "Nomor kartu TIDAK VALID." << endl;
    }

    return 0;
}

/*
LANGKAH-LANGKAH PENYELESAIAN:

1. INPUT
   - Minta user memasukkan nomor kartu (tipe long long)

2. MENENTUKAN PANJANG DAN 2 DIGIT DEPAN
   - Salin nilai kartu ke variabel lain (depan)
   - Gunakan perulangan untuk membagi angka sampai tersisa 2 digit
   - Hitung panjang digit selama proses tersebut
   - Simpan 2 digit depan sebagai "awal"

3. VALIDASI FORMAT KARTU
   - Jika panjang 14 dan awal 65 → NUSANTARA
   - Jika panjang 16 dan awal 77 atau 78 → GARUDA
   - Jika panjang 15 dan awal 91 → MERDEKA
   - Jika tidak memenuhi → kartu tidak valid (format salah)

4. TAMPILKAN TIPE KARTU
   - Jika format valid, tampilkan jenis kartu

5. VALIDASI ANGKA (ALGORITMA NUSANTARA / LUHN MODIFIKASI)
   - Gunakan perulangan dari belakang (pakai %10 dan /10)
   - Ambil digit terakhir satu per satu
   - Setiap digit ke-2 dikali 2
   - Jika hasil > 9 → jumlahkan digitnya (contoh 12 → 1+2)
   - Tambahkan semua ke variabel total

6. CEK HASIL AKHIR
   - Jika total % 10 == 0 → VALID
   - Jika tidak → TIDAK VALID

7. OUTPUT
   - Tampilkan hasil akhir validasi
*/
