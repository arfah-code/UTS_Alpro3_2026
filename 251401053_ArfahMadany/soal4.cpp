
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int poinA = 0, poinB = 0;
    int streakA = 0, streakB = 0;

    for (int i = 0; i < n; i++) {
        char babak = s[i];

        if (babak == 'A') {
            poinA += 3;
            streakA++;
            streakB = 0;
            if (streakA == 3) {
                poinA += 2;
                streakA = 0;
            }
        } else if (babak == 'B') {
            poinB += 3;
            streakB++;
            streakA = 0;
            if (streakB == 3) {
                poinB += 2;
                streakB = 0;
            }
        } else {
            poinA += 1;
            poinB += 1;
            streakA = 0;
            streakB = 0;
        }
    }

    cout << "Poin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;

    if (poinA > poinB)
        cout << "Pemenangnya adalah pemain A" << endl;
    else if (poinB > poinA)
        cout << "Pemenangnya adalah pemain B" << endl;
    else
        cout << "Hasil pertandingan Seri!" << endl;

    return 0;
}
    /*

    1. INPUT
       - Baca N (jumlah babak)
       - Baca S (string hasil babak)

    2. SIAPKAN VARIABEL
       - poinA = 0, poinB = 0
       - streakA = 0, streakB = 0
         (hitung berapa kali berturut-turut menang)

    3. LOOP SETIAP BABAK (i = 0 sampai N-1)
       a. Ambil karakter s[i]
       b. Jika 'A':
          - poinA += 3
          - streakA++, streakB = 0
          - Jika streakA == 3: poinA += 2, streakA = 0
       c. Jika 'B':
          - poinB += 3
          - streakB++, streakA = 0
          - Jika streakB == 3: poinB += 2, streakB = 0
       d. Jika 'C':
          - poinA += 1, poinB += 1
          - streakA = 0, streakB = 0

    4. TAMPILKAN POIN
       - Cetak "Poin A: poinA"
       - Cetak "Poin B: poinB"

    5. TENTUKAN PEMENANG
       - Jika poinA > poinB → "Pemenangnya adalah pemain A"
       - Jika poinB > poinA → "Pemenangnya adalah pemain B"
       - Jika sama         → "Hasil pertandingan Seri!"
    */
