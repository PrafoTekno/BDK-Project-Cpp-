
#include <iostream>

using namespace std;

void Main ();

int main () {

    cout << "\n\t======== Nilai Rata-Rata ========\n" << endl;

    Main ();

    return 0;

}

double mean (int banyak) {

    double jumlah = 0;
    double nilai;

    for (int n = 0; n < banyak; n++) {
        cin >> nilai;
        jumlah = jumlah + nilai;
    }

    cout << endl;

    cout << "Nilai rata-rata nya adalah " << jumlah/banyak << endl;

    return jumlah / banyak;
}

/*
double mean_RL (int banyak) {

    double jumlah = 0;
    double nilai;

    for (int n = 0; n < banyak; n++) {
        cin >> nilai;
        jumlah = jumlah + nilai;
    }

    cout << endl;

    cout << "Nilai rata-rata RL adalah " << jumlah/banyak << endl;

    return jumlah / banyak;

}

double mean_Algo (int banyak) {

    double jumlah = 0;
    double nilai;

    for (int n = 0; n < banyak; n++) {
        cin >> nilai;
        jumlah = jumlah + nilai;
    }

    cout << endl;

    cout << "Nilai rata-rata Algo adalah " << jumlah/banyak << endl;

    return jumlah / banyak;

}

double mean_Kalk (int banyak) {

    double jumlah = 0;
    double nilai = 0;

    for (int n = 0; n < banyak; n++) {
        cin >> nilai;
        jumlah = jumlah + nilai;
    }

    cout << endl;

    cout << "Nilai rata-rata Kalk adalah " << jumlah/banyak << endl;

    return jumlah / banyak;

}
*/

void Main () {

    int banyak_nilai;

    cout << "Berapa banyak nilai yang hendak di rerata kan : ";
    cin >> banyak_nilai;

    cout << endl;

    cout << "Masukan " << banyak_nilai << " nilai RL :" << endl;
    mean (banyak_nilai);
    cout << "\nMasukan " << banyak_nilai << " nilai Algo :" << endl;
    mean (banyak_nilai);
    cout << "\nMasukan " << banyak_nilai << " nilai Kalk :" << endl;
    mean (banyak_nilai);

    cout << endl;

}