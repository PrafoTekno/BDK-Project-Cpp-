
#include <iostream>
#include <cmath>

using namespace std;

// 4 tipe bentuk segitiga siku-siku 

void Tipe_a (int batas) {

    // Siku tegak kiri

    for (int t = 1; t <= batas; t++) {
        for (int i = 0; i < t; i++) {
            cout << " * ";
        }
        cout << endl;
    }

    cout << "\n------------------------------------------\n" << endl;

}

void Tipe_b (int batas) {

    // Siku terbalik kiri

    for (int t = batas; t >= 1; t--) {
        for (int i = 0; i < t; i++) {
            cout << " * ";
        }
        cout << endl;
    }

    cout << "\n------------------------------------------\n" << endl;

}

void Tipe_c (int batas) {

    // Siku tegak kanan

    for (int t = 1; t <= batas; t++) {
        for (int i = batas; i >= t; i--) {
            cout << "   ";
        }
        for (int i = 1; i <= t; i++) {
            cout << " * ";
        }

        cout << endl;
    }

    cout << "\n------------------------------------------\n" << endl;

}

void Tipe_d (int batas) {

    // Siku terbalik kanan

    for (int t = 1; t <= batas; t++) {
        for (int i = 1; i <= t; i++) {
            cout << "   ";
        }
        for (int i = batas; i >= t; i--) {
            cout << " * ";
        }
        cout << endl;
    }

    cout << "\n------------------------------------------\n" << endl;

}

// Buat menghitung luas dan keliling segitiga

double luas_segitiga (double tinggi) {
    return (tinggi * tinggi) / 2; 
}

double keliling_segitiga (int tinggi) {
    double miring = sqrt (tinggi*tinggi + tinggi*tinggi); 
    return tinggi + tinggi + miring;
} 

int main () {

    cout << "\t===== Membuat Segitiga =====\n\n" << endl;

    // Variable yang dibutuhkan
    int tinggi_segitiga;
    char pilih_tipe;

    // Melakukan input 

    cout << "Masukan tinggi segitiga : ";
    cin >> tinggi_segitiga;

    cout << "\nPilih tipe segitiga (a,b,c,d) : "; 
    cin >> pilih_tipe;

    cout << "\n\nIni dia segitiga mu \\^.^/\n" << endl;

    // Memilih tipe segitiga berdasarkan input di atas

    switch (pilih_tipe) {

        case 'a' : 
        Tipe_a (tinggi_segitiga);
        break;

        case 'b' :
        Tipe_b (tinggi_segitiga);
        break;

        case 'c' :
        Tipe_c (tinggi_segitiga);
        break;

        case 'd' :
        Tipe_d (tinggi_segitiga);
        break;

        default : 
        cout << "Pesan Error : Opsi tidak ada !! " << endl;
        break;

    }

    cout << "Luas segitiganya adalah " << luas_segitiga (tinggi_segitiga) << " satuan^2" << endl;
    cout << "\nKeliling segitiganya adalah " << keliling_segitiga (tinggi_segitiga) << " satuan" << endl;

    cout << endl << endl;

    return 0;

}