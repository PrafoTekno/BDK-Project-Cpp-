
#include <iostream>

using namespace std;

int main () {

    cout << "\n\t======== Mencari Angka Random ========\n" << endl;

    int angka_random [3];

    srand (time(0));

    cout << "Random pertama kali : ";

    for (int n = 0; n < 3; n++) {
        angka_random[n] = 1 + rand () % 6;
        cout << angka_random[n] << ", ";
    }

    // Penyaringan kedua

    int tampung;

    for (int n = 0; n < 3; n++) {
        for (int m = n+1; m < 3; m++) {

            tampung = angka_random[n];

            if (tampung == angka_random[m]) {
                angka_random[m] = 1 + rand () % 6;
                tampung = angka_random[m];
            }
            
        }
    }

    // Menampilkan angka random setelah filter kedua

    cout << "\nRandom setelah filter : ";

    for (int n = 0; n < 3; n++) {
       cout << angka_random[n] << ", ";
    }

    cout << endl << endl;

    int pilih_angka, index_tampung = -1;

    cout << "Pilih angka yang mau di cari : ";
    cin >> pilih_angka;

    for (int n = 0; n < 3; n++) {
        if (angka_random[n] == pilih_angka) {
            index_tampung = n;
            break; 
        }
    }

    if (index_tampung == -1) {
        cout << pilih_angka << " tidak ada " << endl;
    }
    else {
        cout << "Angka " << pilih_angka << " ada di index " << index_tampung << endl;
    }
    
    cout << endl;

    return 0;

}